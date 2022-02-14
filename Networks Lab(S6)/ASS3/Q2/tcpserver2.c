#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <arpa/inet.h>
#include<time.h>

void fillrandom(char *s){
  int i=0,n;
	char str[] ="1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()+{}|:";

	n = sizeof(str)-1;
	srand(time(0));
	for(i=0;i<8;i++)
		s[i] = str[rand() % n];

}

 int server_sock, client_sock;
  struct sockaddr_in server_addr, client_addr;
  socklen_t addr_size;

   char *ip = "127.0.0.1";
 // char *ip="192.168.250.247";
  int port;
  int n;
  char buffer[1024],video[20]="GivemeyourVideo";

void chat(){
//printf("1");
addr_size = sizeof(client_addr);
client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_size);
if(client_sock<0){
printf("accept failed\n");
close(server_sock);
return ;
}
    printf("[+]Client connected.\n");
 while(1){
     bzero(buffer, 1024);
    recv(client_sock, buffer, sizeof(buffer), 0);
    printf("received %s from client\n",buffer);

 if(strcmp(buffer,video)==0){
 //send video file 0f 50 mb to client
      char dummy[10];
			FILE *fp;
			fp = fopen("video.mp4", "r");
			char msg[500];
			int i=0,bytes;
			printf("Initiating file transfer\n");
			while((bytes = fread(msg, 1, 500, fp)) >= 1)
			{
				send(client_sock, &msg, bytes,0);
				//confirmation
				recv(client_sock, &dummy, 10, 0);
				i+=500;
				if(i%5000000==0)
					printf("%d MB sent\n", i/1000000);
			}
			strcpy(msg,"file transfer finished\n");
			send(client_sock,&msg, sizeof(msg),0);
			printf("%s", msg);
		}


else if(strcmp(buffer,"Bye")==0){
//close tcp connection of this client
    bzero(buffer, 1024);
    close(client_sock);
    printf("[+]Client disconnected.\n\n");
     listen(server_sock, 5);
    printf("Listening again...\n");
     client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_size);
    printf("[+]Client connected.\n");
    bzero(buffer, 1024);
  }


  else{
  //send meaningless words to client
  bzero(buffer,1024);
  fillrandom(buffer);
   send(client_sock, buffer, strlen(buffer), 0);
    printf("To client:%s\n",buffer);
    }

}
}

int main(int argc,char **argv){
 if(argc!=2){
 printf("provide port number also\n");
 exit(0);
 }

port=atoi(argv[1]);


  server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock < 0){
    perror("[-]Socket error");
    exit(1);
  }
  printf("[+]TCP server socket created.\n");

  memset(&server_addr, '\0', sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = port;
  server_addr.sin_addr.s_addr = inet_addr(ip);

  n = bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
  if (n < 0){
    perror("[-]Bind error");
    exit(1);
  }
  printf("[+]Binded to the port number: %d\n", port);

  listen(server_sock, 5);
  printf("Listening...\n");
 chat();
  return 0;
}
