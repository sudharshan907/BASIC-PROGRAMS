#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

 char *ip = "127.0.0.1";
  int port ;
//data items
  int sock;
  struct sockaddr_in addr;
  socklen_t addr_size;
  char buffer[1024];
  int n;
  char f[7]="Fruits",iln[14]="SendInventory";
  //end

 void chat(){
     while(1){
  printf("Enter option\n");
  bzero(buffer, 1024);
  scanf("%[^\n]%*c",buffer);
 // send(sock, buffer, strlen(buffer), 0);  
 //better to first check what entered and then send to server.so send is ppaced inside if else if...
  if(strcmp(buffer,f)==0){
    send(sock, buffer, strlen(buffer), 0);
    printf("to server:%s\n",buffer);
    bzero(buffer, 1024);
  //1st condition start

  char a[30],b[30],number[10],name[10];
recv(sock,buffer,sizeof(buffer),0);
printf("from server:%s\n",buffer);
printf("enter name and count in seperate line\n");
scanf(" %[^\n]%*c",name);
scanf("%[^\n]%*c",number);
send(sock,name,sizeof(name),0);
printf("to server:%s\n",name);
send(sock,number,sizeof(number),0);
printf("to server:%s\n",number);
bzero(buffer,sizeof(buffer));
recv(sock,buffer,sizeof(buffer),0);
printf("from server:%s\n",buffer);
  //1st condition end
  }
  else if(strcmp(buffer,iln)==0){
    send(sock, buffer, strlen(buffer), 0);
    printf("to server:%s\n",buffer);
     bzero(buffer, 1024);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s\n",buffer);
  //2nd option ends here
  }
  else if(strcmp(buffer,"exit")==0){
    send(sock, buffer, strlen(buffer), 0);
    printf("to server:%s\n",buffer);
  close(sock);
  printf("Disconnected from the server.\n");
  break;
  }
  else{
 
  printf("invalid option entered\n");
 }
 }
 }
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
  printf("[+]TCP server socket created.\n");

  memset(&addr, '\0', sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port =htons(port);
  addr.sin_addr.s_addr = inet_addr(ip);

  if(connect(sock, (struct sockaddr*)&addr, sizeof(addr))!=0){
  printf("connection failed\n");
  close(sock);
  return 0;
  }
  printf("Connected to the server.\n");
  chat();
  return 0;
}
