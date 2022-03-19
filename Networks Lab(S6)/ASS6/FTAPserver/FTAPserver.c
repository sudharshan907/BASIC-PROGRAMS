#include<stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include<time.h>

#define BUFF_MAX 500
//#define PORT_NUMBER 8041
#define SA struct sockaddr
#define MAX_LINE 500
#define BUFFSIZE 500

char* itoa(int i, char b[]){
    char const digit[] = "0123456789";
    char* p = b;
    if(i<0){
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    do{ //Move to where representation ends
        ++p;
        shifter = shifter/10;
    }while(shifter);
    *p = '\0';
    do{ //Move back, inserting digits as u go
        *--p = digit[i%10];
        i = i/10;
    }while(i);
    return b;
}

void writefile(FILE *fp,int sockfd)
{
printf("[+]file receiving started\n");
	char buff1[BUFF_MAX], buff2[BUFF_MAX], buffer[500];
	int k  = 0;
	ssize_t total=0;

	int nb = read(sockfd, &buffer, 500);
	int x = atoi(buffer);
	nb = 0;
	while (total <= x)
	{
		memset(buff2, 0, MAX_LINE);
		nb = read(sockfd, buff2, MAX_LINE);
		total+=nb;
		if (fwrite(buff2, sizeof(char), nb, fp) != nb)
		{
			perror("Write File Error");
			exit(1);
		}
		if(total >= x)
			break;

	}
	fclose(fp);
	printf("[+]The file receiving finished\n");
	return;
}

void sendfile(FILE *fp, int sockfd)
{
printf("[+]File sending started\n");
    int n;
	ssize_t total=0;
    char sendline[MAX_LINE] = {0};
    while ((n = fread(sendline, sizeof(char), MAX_LINE, fp)) > 0)
    {
	    total+=n;
        if (n != MAX_LINE && ferror(fp))
        {
            perror("Read File Error");
            exit(1);
        }
        if (send(sockfd, sendline, n, 0) == -1)
        {
            perror("Can't send file");
            exit(1);
        }
        memset(sendline, 0, MAX_LINE);
    }
      printf("[+]File sending finished\n");
	return;
}

void listdir(int connfd)
{
char buff1[500];
		DIR *d;
            struct dirent *dir;
            int file_cnt=0;
            d = opendir(".");
            if (d) {
                while ((dir = readdir(d)) != NULL) {

                    file_cnt++;
                }
                closedir(d);
            }
            sprintf(buff1, "%d", file_cnt);
            write(connfd, buff1, sizeof(buff1));
            printf("sent count of files=[%s]\n",buff1);
            d = opendir(".");
            if (d) {
            int ct=1;
                while ((dir = readdir(d)) != NULL) {
                    strcpy(buff1,dir->d_name);
                    write(connfd, buff1, sizeof(buff1));
                     printf("%d.[%s]\n",ct,dir->d_name);
                     ct++;
                }
                closedir(d);
            }

}



int main(int argc,char **argv){
   if(argc!=2){
    printf("please provide port number also\n");
    exit(0);
 }
         int PORT_NUMBER=atoi(argv[1]);
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;
	char buff1[BUFF_MAX], buff2[BUFF_MAX], bu[32];
	int n;
	// socket create and verification ; IpV4 PROTOCOL; TCP; IP=0
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created.\n");

	memset(&servaddr,0, sizeof(servaddr));
	char *ip="127.0.0.1";
	servaddr.sin_addr.s_addr = inet_addr(ip);
	servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT_NUMBER);

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) {
		printf("Socket bind failed\n");
		exit(0);
	}
	else
		printf("Socket successfully binded to port number %d\n",PORT_NUMBER);

	// Now server is ready to listen and verification
	if ((listen(sockfd, 5)) != 0) {
		printf("Listen failed\n");
		exit(0);
	}
	else
		printf("Server listening On port number=%d\n",PORT_NUMBER);
	len = sizeof(cli);

	// Accept the data packet from client and verification
	connfd = accept(sockfd, (SA*)&cli, &len);
	if (connfd < 0) {
		printf("Accepting client failed\n");
		exit(0);
	}
	else{
	        //actually here server should send 200 msg in ass pdf to client but left it
		printf("[+]Client connected\n");


		}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//receives USERN first and then <username> not combined command.looks not good.
	char * line = NULL; size_t len2 = 0;   ssize_t nbb;  int flag = 0;
	FILE *ap = fopen("logincred.txt", "r");
	if(ap == NULL){
	printf("logincred.txt file not found in server directory");
		exit(0);
		}
	else
	{
		while(flag!=1){
			recv(connfd, &buff1, 500, 0);
			buff1[strcspn(buff1, "\n")] = 0; //dont know why this is required
			FILE *ap = fopen("logincred.txt", "r");
			while ((nbb = getline(&line, &len2, ap)) != -1) {
			if(strstr(line, buff1)!=NULL)
			{
				strcpy(buff2, "OK");
				send(connfd, buff2, strlen(buff2)+1, 0);
				recv(connfd, &buff1, 500, 0);
				buff1[strcspn(buff1, "\n")] = 0;
				if(strstr(line, buff1)!=NULL)
				{
					strcpy(buff2, "OK");
					send(connfd, buff2, strlen(buff2)+1, 0);
					flag = 1;
					break;
				}
				else
				{
					bzero(buff2, sizeof(buff2));
					strcpy(buff2, "givversi");
					send(connfd, buff2, strlen(buff2)+1, 0);
				}
			}

   			}
		   if(flag == 0)
			{
				bzero(buff2, sizeof(buff2));
				strcpy(buff2, "nousername");
				send(connfd, buff2, strlen(buff2)+1, 0);
				FILE *ap = fopen("logincred.txt", "r");
			}
		}
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////


    char filename[32];

	while(1)
	{
		bzero(buff1,500);
		bzero(buff2,500);
		bzero(filename,32);
		int r=recv(connfd, &buff1, 500, 0);
		char b[500];
		strcpy(b,buff1);
		b[strcspn(b,"\n")] = 0;  //removes last newline in the string and makes it null
		printf("received=[%s]\n",b);
		if(r < 0){
			perror("Error in recv()");
			exit(0);
			}
		else if(strcmp(buff1, "QUIT\n") == 0)
		{
		printf("QUIT is received;closing both connection and socket and terminating the process\n");
			close(connfd);
			close(sockfd); //not required bcz already closing outside end of loop
			exit(0);
		}
		else if(strcmp(buff1,"CREATEFILE\n")==0){
		bzero(filename,32);
		recv(connfd,&filename,32,0);
		FILE *fp=fopen(filename,"w");
		//what happens if given filename already exists in the directory,this is a corner case,handle it if required
		char m[30];
if(fp==NULL){
printf("error in creating file with given filename\n");
strcpy(m,"file error");
send(connfd,&m,30,0);
return 0;
}
printf("%s file created successfully\n",filename);
	strcpy(m,"file created");
send(connfd,&m,30,0);
		fclose(fp);


		}
		else if(strcmp(buff1, "GETFILE\n") ==0){

     memset(filename, 0, sizeof(filename));
			recv(connfd,&filename,32, 0);

				FILE *fp = fopen(filename, "r");
				char er[5];
	                      if(fp == NULL){
	                      bzero(er,5);
	                      strcpy(er,"no");
	                      send(connfd,er,5, 0);
					printf("client requested a file which is not present\n");
					continue;
				}
				bzero(er,5);
				 strcpy(er,"yes");
	                      send(connfd,er,5, 0);
				struct stat st;
				char buffer[500];
				stat(filename, &st);
				int sz = st.st_size;
				itoa(sz, buffer);
				send(connfd, buffer, sizeof(buffer), 0);
				clock_t t=clock();
				sendfile(fp,connfd);
				t=clock()-t;
				double time=((double)t)/CLOCKS_PER_SEC;
				printf("%f seconds to send file\n",time);
		}
		else if(strcmp(buff1, "STOREFILE\n") ==0)
		{
			memset(filename, 0, sizeof(filename));
			recv(connfd, &filename,32, 0);
			if(strcmp(filename,"no")==0){
			printf("received msg to stop,so file not received from client\n");
			continue;
			}
			FILE *fp = fopen(filename, "w");
			writefile(fp, connfd);
		}
		else if(strcmp(buff1, "LISTDIR\n") ==0)
		{
			listdir(connfd);

		}
		else if(strcmp(buff1,"\n")==0){
		printf("received newline character\n");
		continue;
		}
		else
		{
		        buff1[strcspn(buff1, "\n")] = 0;  //removes last newline in the string and makes it null
			printf("received this invalid command:[%s]\n",buff1);
			bzero(buff1,500);
			strcpy(buff1,"505 Command not supported");
			send(connfd, buff1, strlen(buff1)+1, 0);
		}
	}

}

