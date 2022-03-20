#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#define MAX 80
#define PORT 4035
#define SA struct sockaddr


void chat(int connfd){
    char buff[MAX];
    while(1){
        read(connfd, buff, sizeof(buff));
        if(strcmp(buff,"CreateFile")==0){
            read(connfd, buff, sizeof(buff));
            FILE* file_ptr = fopen(buff, "w");
            fclose(file_ptr);
            continue;
        }
        if(strcmp(buff,"ListDir")==0){
            DIR *d;
            struct dirent *dir;
            int file_cnt=0;
            d = opendir(".");
            if (d) {
                while ((dir = readdir(d)) != NULL) {
                    //printf("%s\n",dir->d_name);
                    file_cnt++;
                }
                closedir(d);
            }
            sprintf(buff, "%d", file_cnt);
            write(connfd, buff, sizeof(buff));
            d = opendir(".");
            if (d) {
                while ((dir = readdir(d)) != NULL) {
                    strcpy(buff,dir->d_name);
                    write(connfd, buff, sizeof(buff));
                }
                closedir(d);
            }
            continue;
        }
        if(strcmp(buff,"StoreFile")==0){
            read(connfd, buff, sizeof(buff));
            FILE *fp;
            fp = fopen(buff, "w");
            int bytes;
            char msg[500];
            while(1)
            {
                bytes = recv(connfd, msg, sizeof(msg), 0);
                if(strcmp(msg, "file transfer finished\n")==0)
                    break;

                char buf[10];
                strcpy(buf, "received");
                send(connfd, &buf, sizeof(buf), 0);
                fwrite(msg, 1, bytes, fp);
            }
            printf("Video file received\n");
            bzero(msg, sizeof(msg));
            continue;
        }
        if(strcmp(buff,"GetFile")==0){
            read(connfd, buff, sizeof(buff));
            FILE *fp;
			fp = fopen(buff, "r");
			char msg[500];
			int bytes;
			while((bytes = fread(msg, 1, 500, fp)) >= 1)
			{
				send(connfd, &msg, bytes,0);
				recv(connfd, &buff, 10, 0);
			}
			strcpy(msg, "file transfer finished\n");
			write(connfd, msg, sizeof(msg));
            continue;
        }
        if(strcmp(buff,"Quit")==0){
            return ;
        }
    }
}

void fun(int connfd){

	char buff[MAX];
	memset(buff,0,sizeof(buff));

	while(1){

        FILE *in_file = fopen("../logincred.txt", "r");

        struct stat sb;
        stat("logincred.txt", &sb);

        char *file_contents = malloc(sb.st_size);
        read(connfd, buff, sizeof(buff));
        int j=0,ch=0,i;
        while (fscanf(in_file, "%[^\n] ", file_contents) != EOF) {
            ch=0;
            char temp[100];
            for(i=0;i<strlen(file_contents);i++){
                if(file_contents[i]==','){
                    j=i+1;
                    break;
                }
                temp[i]=file_contents[i];
            }
            temp[i]='\0';
            if(strcmp(temp,buff)!=0)ch=1;
            if(ch==0)break;
        }
        if(ch==0){
            strcpy(buff,"300 Correct Username; Need password");
            write(connfd, buff, sizeof(buff));
            memset(buff,0,sizeof(buff));
            read(connfd, buff, sizeof(buff));
            if(strcmp(buff,"cont")==0)continue;

            int k=0,flag=0;
            //printf("%s\n",file_contents);
            for(i=j;i<strlen(file_contents)-1;i++){
                if(file_contents[i]!=buff[k]){
                    flag=1;
                    printf("WAit\n");
                    break;
                }
                k++;
            }
            if(flag==0){
                strcpy(buff,"305 User Authenticated with password");
                write(connfd, buff, sizeof(buff));
                break;
            }
            else{
                strcpy(buff,"310 Incorrect password");
                write(connfd, buff, sizeof(buff));
                continue;
            }
        }
        else{
            strcpy(buff,"301 Incorrect Username");
            write(connfd, buff, sizeof(buff));
            continue;
        }
	}
	chat(connfd);
	printf("Socket Closed\n");
}

int main()
{
	int sockfd, connfd;
	struct sockaddr_in serv, cli;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd<0) {
		printf("socket creation failed...\n");
		exit(0);
	}
	else printf("Socket successfully created..\n");
	memset(&serv,0, sizeof(serv));
	memset(&cli,0, sizeof(cli));

	serv.sin_family = AF_INET;
	serv.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv.sin_port = htons(PORT);

    int chk=bind(sockfd, (SA*)&serv, sizeof(serv));
	if (chk < 0) {
		printf("Socket Binding Failed\n");
		exit(0);
	}
	else
		printf("Socket Binded Successfully\n");

	chk=(listen(sockfd, 5));
	if (chk < 0) {
		printf("Listen Failed\n");
		exit(0);
	}
	else printf("Server Listening\n");
	int len = sizeof(cli);

	connfd = accept(sockfd,(SA*) &cli, &len);
	if (connfd < 0) {
		printf("Server Accept Failed...\n");
		exit(0);
	}
	else printf("Server Accepted Client...\n");


	fun(connfd);

	close(sockfd);
}
