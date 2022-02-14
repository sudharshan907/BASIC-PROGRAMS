#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <arpa/inet.h>

void reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    char f;
    while (start < end)
    {
      f=*(str+start);
      *(str+start)=*(str+end);
      *(str+end)=f;
        //swap(*(str+start), *(str+end));
        start++;
        end--;
    }
}

char* itoa(int num, char* str, int base)
{
    int i = 0;
    int isNegative = 0;
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    if (num < 0 && base == 10)
    {
        isNegative = 1;
        num = -num;
    }
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
    if (isNegative==1)
        str[i++] = '-';
    str[i] = '\0';
    reverse(str, i);
    return str;
}


//global data items
 int server_sock;
  struct sockaddr_in server_addr, client_addr;
  socklen_t addr_size;
    char *ip = "127.0.0.1";
  int port;
  int n;
//end
void chat(){
//server database
char buffer[1024],f[7]="Fruits",iln[14]="SendInventory";
char name[10],b1[50],x[10]="=",number[20],buf[20];
char list[5][7]={ "apple","mango","banana","chikoo","papaya" };
int ct[5],i=0;
char msg[50];ct[0]=200;ct[1]=200;ct[2]=200;ct[3]=200;ct[4]=200;
//end

    addr_size = sizeof(client_addr);
   
 while(1){
 printf("waiting to receive msg from any client\n");

    bzero(buffer, 1024);
    recvfrom(server_sock, buffer, sizeof(buffer), 0,(struct sockaddr*)&client_addr, &addr_size);
    printf("from client:%s\n",buffer);
 if(strcmp(buffer,f)==0){
 //if user entered fruits
 bzero(buffer, 1024);
  strcpy(buffer,"Enter the name of the fruit");
 sendto(server_sock, buffer, strlen(buffer), 0,(struct sockaddr*)&client_addr, addr_size);
 printf("To client:%s\n",buffer);
 //receiving fruit name and count
recvfrom(server_sock,name,sizeof(name),0,(struct sockaddr*)&client_addr, &addr_size);
printf("from client:%s\n",name);
recvfrom(server_sock,number,sizeof(number),0,(struct sockaddr*)&client_addr, &addr_size);
printf("from client:%s\n",number);
int count=atoi(number);
int found=-1;
for(i=0;i<5;i++){
if(strcmp(name,list[i])==0)    found=i;
}
i=0;
if(found==-1){
bzero(msg,sizeof(msg));
strcpy(msg,"please enter valid fruit name");
sendto(server_sock,msg,sizeof(msg),0,(struct sockaddr*)&client_addr, addr_size);
printf("To client:%s\n",msg);
continue;
}

bzero(msg,sizeof(msg));
if(count>ct[found]){
strcpy(msg,"Not available");
}
else{
printf("decremented count of %s fruit from %d to %d\n",list[found],ct[found],ct[found]-count);
ct[found]=ct[found]-count;
strcpy(msg,"successful decrement");
}
sendto(server_sock,msg,sizeof(msg),0,(struct sockaddr*)&client_addr, addr_size);
printf("To client:%s\n",msg);
 //ending 1st condition
 }
 
 
 
 else if(strcmp(buffer,iln)==0){
 //if client entered sendinventory

bzero(buffer, 1024);
 for(int i=0;i<5;i++){
 strcat(buffer,list[i]);
 strcat(buffer,x);
 bzero(buf,20);
 strcat(buffer,itoa(ct[i], buf,10    ));
  strcat(buffer," ");
 }
 sendto(server_sock, buffer, strlen(buffer), 0,(struct sockaddr*)&client_addr, addr_size);
 printf("To client:%s\n",buffer);
 //2nd option ends
 }
 
 else{
   printf("invalid option received\n");
 }
 
  }
}
int main(int argc,char **argv){
   if(argc!=2){
    printf("provide port number also\n");
    exit(0);
 }
port=atoi(argv[1]);
  server_sock = socket(AF_INET, SOCK_DGRAM, 0);
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
  
 chat();
  return 0;
}
