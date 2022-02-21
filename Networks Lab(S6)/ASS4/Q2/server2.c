#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include <arpa/inet.h>

void reverse(char str[], int length)
{ int start = 0;  int end = length -1;   char f;
    while (start < end){  f=*(str+start);  *(str+start)=*(str+end);  *(str+end)=f;  start++;    end--; }
}

char* itoa(int num, char* str, int base)  {
    int i = 0;  int isNegative = 0;   if (num == 0)   {  str[i++] = '0';   str[i] = '\0';  return str;  }
    if (num < 0 && base == 10)   {   isNegative = 1;  num = -num; }
    while (num != 0){   int rem = num % base;    str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';  num = num/base;  }
    if (isNegative==1) str[i++] = '-';  str[i] = '\0';   reverse(str, i);  return str;   }

int evaluate(char s[]){
//this function might not work properly for some edge cases
int i=0,j=strlen(s)-1,m=-1,x,l;
char first[20],second[20];
for(i=1;i<=j;i++){   //not checking 1st index bcz - can be there
    if(s[i]>='0' && s[i]<='9'){}
    else{ m=i; break;  }
}
//1st number [0,m-1],operator index [m],2nd number [m+1,j]
l=m;
for(i=0,x=0;i<l;x++,i++)   first[i]=s[x];
l=j-m+1;
for(i=0,x=m+1;i<l;x++,i++)  second[i]=s[x];
int a,b,ans;
a=atoi(first); b=atoi(second);
if(s[m]=='+') ans=a+b;  else if(s[m]=='-')  ans=a-b;   else if(s[m]=='*')  ans=a*b;   else if(s[m]=='/')  ans=a/b;
//printf("a=%d b=%d op=%c\n",a,b,s[m]);
return ans;
}


//global data items(these will also be copied to all child processes.no common data b/w processes,even though they are running parallelly one after other in random order
 int server_sock, client_sock;
  struct sockaddr_in server_addr, client_addr;
  socklen_t addr_size=sizeof(client_addr);
    char *ip = "127.0.0.1";
  int port;
  int n; char buffer[1024];
 int count=0;
//end global data items


void chat(){

while(1){
    //accepting will always be done by parent process
    client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_size);
               if(client_sock<0){
             printf("accept failed\n");
            close(server_sock);
             return ;  }
  /*
  int p=ntohs(client_addr.sin_port) ; strcpy(buffer,inet_ntoa(client_addr.sin_addr));
  putting client structure in accept fn call fills the structure with accepted client values.
  */
          count++;
          printf("[+]Client%d connected\n",count);
///////////////////////////////////////////////////////////////////////////
         if(fork()==0){
         //only new process executes inside this if clause.bcz new process only returns 0 for fork().  
         //every client gets one child process and parent process continous to accept clients.
         while(1){
           bzero(buffer, 1024);
          recv(client_sock, buffer, sizeof(buffer), 0);
          printf("from client%d:%s\n",count,buffer);
          
          if(strcmp(buffer,"exit")==0){
          printf("[-]Client%d disconnected\n",count);
           break;                     }   
           else {
         //gives seg fault if invalid expression received in buffer from client
         int ans=evaluate(buffer);  bzero(buffer,1024);  itoa(ans,buffer,10);
             send(client_sock, buffer, strlen(buffer), 0);
                printf("to client%d:%s\n",count,buffer);
            }
               }
                  }
/////////////////////////////////////////////////////////////////////////
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
  server_addr.sin_port =htons(port);
  server_addr.sin_addr.s_addr = inet_addr(ip);

  n = bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
  if (n < 0){
    perror("[-]Bind error");
    exit(1);
  }
  printf("[+]Binded to the port number: %d\n", port);

  if(listen(server_sock, 5)!=0){
    printf("listen failed\n");
     close(server_sock);
     return 0;
  
  }
  printf("Listening...\n");
 chat();
  return 0;
}