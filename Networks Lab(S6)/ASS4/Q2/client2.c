#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include <arpa/inet.h>

 
//data items
  int sock;
  struct sockaddr_in server_addr;
  socklen_t addr_size;
  char buffer[1024];
  int n,port;
  char *ip = "127.0.0.1";
  //end

 void chat(){
 
 
     while(1){
  printf("Enter valid query or exit\n");
  //  invalid query can lead to seg fault/undefined behaviour in server
  bzero(buffer, 1024);
  scanf("%[^\n]%*c",buffer);
       if(strcmp(buffer,"exit")==0){
       
        send(sock, buffer, strlen(buffer), 0);
       printf("to server:%s\n",buffer);
            close(sock);
       printf("Disconnected from the server.\n");
         break;
         
              } 
  else {
  //2nd condition start
  //note invalid inputs are strictly not allowed bcz they are not handled by server.
    send(sock, buffer, strlen(buffer), 0);
    printf("to server:%s\n",buffer);
    bzero(buffer, 1024);
    recv(sock,buffer,sizeof(buffer),0);
    printf("from server:%s\n",buffer);
  //2nd condition end
  }
 }}
 
 
int main(int argc,char **argv){
 if(argc!=2){
 printf("provide port number also\n");
 exit(0);
 }
port=atoi(argv[1]);
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0){
    perror("[-]Socket error");
    exit(1);
  }
  printf("[+]TCP client socket created.\n");

  memset(&server_addr, '\0', sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port =htons(port);
  server_addr.sin_addr.s_addr = inet_addr(ip);

  if(connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr))!=0){
  printf("connection failed\n");
  close(sock);
  return 0;
  }
  printf("Connected to the server.\n");
  chat();
  return 0;
}