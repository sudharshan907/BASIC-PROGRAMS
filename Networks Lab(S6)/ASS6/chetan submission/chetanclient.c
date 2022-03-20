#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <dirent.h>
#include <time.h>
#define MAX 80
#define PORT 4035
#define SA struct sockaddr



void chat(int sockfd){
    char buff[MAX];
    printf("WELCOME TO FILE TRANSFER APPLICATION\n");
    printf("----------------------------\n\n");

    printf("Use the following commands to use the application\n");
    printf("To Create a new file-        CreateFile <name of file>\n");
    printf("To view the list of files-   ListDir\n");
    printf("To Store a file-             StoreFile <name of file>\n");
    printf("To download a file-          GetFile <name of file>\n");
    printf("To quit the application-     Quit\n");
    printf("------------------------------------------------------\n\t\t    WELCOME\n");


    while(1){
        printf("------------------------------------------------------\n");
        scanf("%s",buff);
        write(sockfd, buff, sizeof(buff));
        if(strcmp(buff,"CreateFile")==0){
            scanf("%s",buff);
            write(sockfd, buff, sizeof(buff));
            continue;
        }
        if(strcmp(buff,"ListDir")==0){
            int file_cnt;
            read(sockfd, buff, sizeof(buff));
            file_cnt=atoi(buff);
            while(file_cnt--){
                read(sockfd, buff, sizeof(buff));
                printf("%s\n",buff);
            }
            continue;
        }

        if(strcmp(buff,"StoreFile")==0){
            scanf("%s",buff);
            write(sockfd, buff, sizeof(buff));
            FILE *fp;
			fp = fopen(buff, "r");
			char msg[500];
			int bytes;
			printf("Initiating file transfer\n");
			clock_t begin = clock();
			while((bytes = fread(msg, 1, 500, fp)) >= 1){
				send(sockfd, &msg, bytes,0);
				recv(sockfd, &buff, 10, 0);
			}
			clock_t end = clock();
            double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
			strcpy(msg, "File transfer finished\n");
			printf("%s", msg);
			printf("Time taken for sending file: %f seconds\n",time_spent);
			write(sockfd, msg, sizeof(msg));

            continue;
        }

        if(strcmp(buff,"GetFile")==0){
            scanf("%s",buff);
            write(sockfd, buff, sizeof(buff));
            FILE *fp;
            fp = fopen(buff, "w");
            int bytes;
            char msg[500];
            printf("Initiating file transfer\n");
            clock_t begin = clock();
            while(1){
                bytes = recv(sockfd, msg, sizeof(msg), 0);
                if(strcmp(msg, "file transfer finished\n")==0)break;

                char buf[10];
                strcpy(buf, "received");

                send(sockfd, &buf, sizeof(buf), 0);
                fwrite(msg, 1, bytes, fp);
            }
            clock_t end = clock();
            printf("File transfer finished\n");
            double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
			printf("Time taken for receiving the file: %f seconds\n",time_spent);
            bzero(msg, sizeof(msg));

            continue;
        }
        if(strcmp(buff,"Quit")==0){
            write(sockfd, buff, sizeof(buff));
            return ;
        }
        printf("505 Command not supported\n");
    }
}

void fun(int sockfd){
	char buff[MAX];
	char uname[50];
	while(1){
        printf("USERNAME: ");
        scanf("%s",buff);
        if(strcmp(buff,"USERN")!=0){
            printf("505 Command not supported\n");
            continue;
        }
        scanf("%s",uname);
        int i,j;

        write(sockfd, uname, sizeof(uname));
        read(sockfd, buff, sizeof(buff));
        printf("%s\n",buff);
        printf("----------------------------\n");
        if(strcmp(buff,"300 Correct Username; Need password")==0){
            printf("PASSWORD: ");
            char pswd[50];
            scanf("%s",buff);
            scanf("%s",pswd);
            if(strcmp(buff,"PASSWD")!=0)strcpy(pswd,"cont");
            write(sockfd, pswd, sizeof(pswd));
            if(strcmp(buff,"PASSWD")!=0){
                printf("505 Command not supported\n");
                continue;
            }
            read(sockfd, buff, sizeof(buff));
            printf("%s\n",buff);
            printf("----------------------------\n");
            if(strcmp(buff,"305 User Authenticated with password")==0){
                break;
            }
        }
	}
	chat(sockfd);
	return ;
}

int main()
{
	int sockfd, connfd;
	struct sockaddr_in serv, cli;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("Socket Creation Failed/n");
		exit(0);
	}
	else printf("Socket Created Successfully\n");
	memset(&serv,0,sizeof(serv));

	serv.sin_family = AF_INET;
	serv.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv.sin_port = htons(PORT);

	char temp[100];

	printf("Enter 'START' to get started\n");
	printf("----------------------------\n");
	scanf("%s",temp);

	if(strcmp(temp,"START")==0){
        if (connect(sockfd, (SA*)&serv, sizeof(serv)) != 0) {
            printf("Connection with the server Failed\n");
            exit(0);
        }
        else printf("200\tOK Connection is set up\n");
        printf("----------------------------\n\n");

        fun(sockfd);
	}
	else{
        printf("505\tCommand not supported\n");
	}
	close(sockfd);
}
