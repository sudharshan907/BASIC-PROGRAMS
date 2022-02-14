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
 // send(sock, buffer, strlen(buffer), 0);  better to first check what entered and then send to server.
  if(strcmp(buffer,f)==0){
    sendto(sock, buffer, strlen(buffer), 0,(struct sockaddr*)&addr,sizeof(addr));
    printf("to server:%s\n",buffer);
    bzero(buffer, 1024);
  //1st condition start

  char a[30],b[30],number[10],name[10];
recvfrom(sock,buffer,sizeof(buffer),0,(struct sockaddr*)&addr,&addr_size);
printf("from server:%s\n",buffer);
printf("enter name and count in seperate line\n");
scanf(" %[^\n]%*c",name);
scanf("%[^\n]%*c",number);
sendto(sock,name,sizeof(name),0,(struct sockaddr*)&addr,sizeof(addr));
printf("to server:%s\n",name);
sendto(sock,number,sizeof(number),0,(struct sockaddr*)&addr,sizeof(addr));
printf("to server:%s\n",number);
bzero(buffer,sizeof(buffer));
recvfrom(sock,buffer,sizeof(buffer),0,(struct sockaddr*)&addr,&addr_size);
printf("from server:%s\n",buffer);
  //1st condition end
  }
  else if(strcmp(buffer,iln)==0){
    sendto(sock, buffer, strlen(buffer), 0,(struct sockaddr*)&addr,sizeof(addr));
    printf("to server:%s\n",buffer);
     bzero(buffer, 1024);
    recvfrom(sock, buffer, sizeof(buffer), 0,(struct sockaddr*)&addr,&addr_size);
    printf("%s\n",buffer);
  //2nd option ends here
  }
  else if(strcmp(buffer,"exit")==0){
   // sendto(sock, buffer, strlen(buffer), 0,(struct sockaddr*)&addr,sizeof(addr));
  //no need of sending any exit to server bcz udp is connectionless
  close(sock);

 printf("client process terminated after closing socket created\n");
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
  sock = socket(AF_INET, SOCK_DGRAM, 0);
  if (sock < 0){
    perror("[-]Socket error");
    exit(1);
  }
  printf("[+]TCP server socket created.\n");

  memset(&addr, '\0', sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port =htons(port);
  addr.sin_addr.s_addr = inet_addr(ip);

//no connect in udp
  addr_size=sizeof(addr);
  chat();
  return 0;
}
