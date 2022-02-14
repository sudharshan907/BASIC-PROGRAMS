
#include <stdio.h>

#include <stdlib.h>

#include <string.h>


#include <unistd.h>

#include <arpa/inet.h>



  char *ip = "127.0.0.1";
 // char *ip="192.168.250.247";
  int port;



  int sock;

  struct sockaddr_in addr;

  socklen_t addr_size;

  char buffer[1024];

  int n;

  char video[20]="GivemeyourVideo";



 void chat(){



 while(1){



  printf("Enter option\n");

  bzero(buffer, 1024);

  scanf("%[^\n]%*c",buffer);

  printf("you entered: %s\n",buffer);

  send(sock, buffer, strlen(buffer), 0);

  if(strcmp(buffer,video)==0){
    bzero(buffer, 1024);
  //receive video from server
     FILE *fp;
     char dummy[10];  strcpy(dummy,"received");
            fp = fopen("receivedVideo.mp4", "w");
            int bytes,i=0;
            char msg[500];
            while(1)
            {
                bytes = recv(sock, msg, sizeof(msg), 0);
                if(strcmp(msg, "file transfer finished\n")==0)
                    break;
                    //confirmation dummy msg
                send(sock, &dummy, sizeof(dummy), 0);
                fwrite(msg, 1, bytes, fp);
                i+=500;
                if(i%5000000==0) printf("%d MB received\n", i/1000000);
            }
            printf("Video file received\n");
            bzero(msg, sizeof(msg));
  }





  else if(strcmp(buffer,"Bye")==0){

  bzero(buffer,1024);

    close(sock);

    printf("closed socket\n");

  printf("expected to get disconnected from the server.\n");

   break ;

         }



  else{

  bzero(buffer,1024);

  //receiving meaningless terms from server

  recv(sock,buffer,sizeof(buffer),0);

  printf("From server: %s\n",buffer);

  }



   }



  }



int main(int argc,char **argv){

 if(argc!=2){

 printf("please give port number also\n");

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

  addr.sin_port = port;

  addr.sin_addr.s_addr = inet_addr(ip);



  if(connect(sock, (struct sockaddr*)&addr, sizeof(addr))!=0){

  printf("connection failed\n");

  return 0;

  }

  printf("Connected to the server.\n");

  chat();

  return 0;

}

