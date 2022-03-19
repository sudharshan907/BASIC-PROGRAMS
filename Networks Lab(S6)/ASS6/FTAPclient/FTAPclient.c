#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/stat.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include<time.h>

#define BUFF_MAX 500
#define SIZE 500
///#define PORT 8041
#define SA struct sockaddr_in
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
}

void listdir(int sockfd)
{
char buff1[500];
			     int file_cnt;
            read(sockfd, buff1, sizeof(buff1));
            file_cnt=atoi(buff1);
            printf("Number of files in server directory=%d\n",file_cnt);
            int ct=1;
            while(file_cnt--){
                read(sockfd, buff1, sizeof(buff1));
                printf("%d.[%s]\n",ct,buff1);
                ct++;
            }
}



int main(int argc,char **argv){
   if(argc!=2){
    printf("please provide port number also beside ./a.out\n");
    exit(0);
 }
         int PORT=atoi(argv[1]);
	int sockfd, connfd;
	struct sockaddr_in servaddr, cli;
	printf("Enter START to establish the connection to server\n");
	char  bu[32];
	int n, len;
	fgets(bu, 32, stdin);
  	if(strcmp(bu,"START\n") == 0)
		len = 1;
	else
		exit(0);

	// socket create and varification

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
    servaddr.sin_port = htons(PORT);

	/* Connect to server */
	if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
		printf("connection with the server failed...\n");
		exit(0);
	}
	else{
		printf("200 OK Connection is setup\n");

	//actually here server should send above msg but ignored that facility and just printed here bcz of lazyness

		}
		char  buff1[BUFF_MAX], buff2[BUFF_MAX],filename[32];
//actually below all numbered msgs inside while loop should be sent by server but simply printing here bcz of laziness
//here user must type USERN first and then <username>,looks not good,better to update to like USERN username processing in client
//like splitting it and doing required steps automatically
	while(1)
	{
	                bzero(buff1, sizeof(buff1));
			bzero(buff2, sizeof(buff2));
		fgets(bu, 32, stdin);
		if(strcmp(bu,"USERN\n") == 0)
		{

			fgets(buff1, 500, stdin);
			send(sockfd, buff1, strlen(buff1), 0);
			recv(sockfd, &buff2, 500, 0);
			if(strcmp(buff2, "OK") == 0)
			{
				printf("300 Correct Username;Need password\n");
				fgets(bu, 32, stdin);
				if(strcmp(bu,"PASSWD\n") == 0)
				{
					fgets(buff2, 500, stdin);
					send(sockfd, buff2, strlen(buff1), 0);
					recv(sockfd, &buff2, 500, 0);
					if(strcmp(buff2, "OK") == 0)
					{
						printf("305 password authentication successful\n");
						break;
					}
					else
					{
						printf("310 Incorrect password(again type from USERN)\n");
						continue;
					}
				}
				else{
				printf("505 Command not supported(again type from USERN)\n");
			}
			}
			else
			{
				printf("301 Incorrect Username(again type from USERN)\n");
				continue;
			}
		}
		else
		{
			printf("505 Command not supported(again type from USERN)\n");
			continue;
		}
	}

	buff1[strcspn(buff1, "\n")] = 0;  //removes last newline in the string and makes it null
	printf("Welcome,%s!\n", buff1);

////////////////////////////////////////////////////////////////////////////////////////////////
	while(1)
    {
        memset(buff1, 0, sizeof(buff1));
        memset(buff2, 0, sizeof(buff2));
		printf("$$");
        fgets(buff1, 500, stdin);
        send(sockfd, buff1, strlen(buff1), 0);
        if (strcmp(buff1 , "QUIT\n") == 0)
        {
            printf("You have requested to stop connection with the Server.\n");
            printf("closing socket..\n");
            close(sockfd);
            exit(0);
        }
        else if(strcmp(buff1,"CREATEFILE\n")==0){
        //code this on own
        char file[20];
        bzero(file,20);
        printf("enter filename to be created in server(.txt only):");
        fgets(file,20, stdin);
        file[strcspn(file, "\n")] = 0; //removes last newline and makes it null
        send(sockfd,file, sizeof(file), 0);
         bzero(file,20);
        recv(sockfd,file,sizeof(file),0);
        printf("server:%s\n",file);
        }

           else if(strcmp(buff1,"GETFILE\n") == 0){
			memset(filename, 0, sizeof(filename));
				fgets(filename, 32, stdin);
				filename[strcspn(filename, "\n")] = 0;
				send(sockfd, filename,32, 0);
				char er[5];
				bzero(er,5);
				 recv(sockfd,er,5,0);
				if(strcmp(er,"no")==0){
				printf("no file with given filename in server directory\n");
				continue;
				}
				else if (strcmp(er,"yes")==0){
				printf("file present in server\n");
			FILE *fp = fopen(filename, "w");
			    writefile(fp,sockfd);
			    }
			    else{
			    printf("this msg about file existence in server received=[%s]\n",er);
			    }
                       }
			else if (strcmp(buff1 , "STOREFILE\n") == 0)
			{

				memset(filename, 0, sizeof(filename));
				fgets(filename, 32, stdin);
			filename[strcspn(filename, "\n")] = 0;
				FILE *fp = fopen(filename, "r");
					if(fp == NULL)
				{
				bzero(filename,32);
				strcpy(filename,"no");
				send(sockfd, filename,32, 0);
					printf("entered file does not exist in directory,so not sent to server\n");
					continue;
				}
				send(sockfd,filename,32, 0);
				struct stat st;
				char buffer[500];
				stat(filename, &st);
				int sz = st.st_size;
				itoa(sz, buffer);
				send(sockfd, buffer, sizeof(buffer), 0);

				clock_t t=clock();
				sendfile(fp,sockfd);
				t=clock()-t;
				double time=((double)t)/CLOCKS_PER_SEC;

				printf("%f seconds to send file\n",time);


			}

			else if (strcmp(buff1 , "LISTDIR\n") == 0)
			{
				listdir(sockfd);
			}
			else if(strcmp(buff1,"\n")==0){
		printf("you entered newline character\n");
		continue;
		}
            else
            {
            //may be this is for server sending invalid command msg to client
                memset(&buff2, 0, sizeof(buff2));
                read(sockfd, &buff2, 500);
				printf("From server:%s\n", buff2);

            }


        }
	close(sockfd);
}



