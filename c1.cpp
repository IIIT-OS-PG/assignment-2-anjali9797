#include <stdio.h>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <ctype.h>
#include <arpa/inet.h>
using namespace std;
//struct sockaddr_in{
 //   short sin_family;//code for address family
   // u_short sin_port;//port number
    //struct in_addr sin_addr;//ip address of host
    //char sin_zero[8];
//};
#define bcopy(s1, s2, n) memmove((s2), (s1), (n))
#define bzero(s, n) memset((s), 0, (n))


void error(const char *msg)
{
    perror(msg);
    exit(0);
}
using namespace std;
int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    if (argc < 2) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    int enter=1;
    while(true)
    {
    portno = atoi(argv[1]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname("127.0.0.1");
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
   // bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,  (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    int status=connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    if(enter==0)
    {
      n = read(sockfd, buffer, 255);
    
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n", buffer);
    enter=1;
}

    if (status < 0) 
        error("ERROR connecting");
     bzero(buffer,256);
    printf("Please enter the message: ");
    scanf("%[^\n]%*c",buffer);
   // cout<<buffer;
  // bzero(buffer,256);
   //getting the input

   //mpdification starts
  /*  FILE *fp = fopen("ccf.txt","rb");
   fseek(fp,0,SEEK_END);
   int size=ftell(fp);
   rewind(fp);
   int file_size;
   send(sockfd,&file_size,sizeof(file_size),0);*/
   send(sockfd,&buffer,sizeof(buffer),0);
   bzero(buffer,256);
   
   n=read(sockfd,buffer,255);
   cout<<buffer<<endl;
 /*  char buff[4096];
   
   while((n=fread(buff,sizeof(char),4096,fp))>0 && size>0)
   {
    send(sockfd,buff,n,0);
    memset(buff,'\0',4096);
    size=size-n;
   }
    fgets(buffer,255,stdin);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
         error("ERROR writing to socket");
   bzero(buffer,256);*/
    

    close(sockfd);
}
    
   /* while(true)
    {
        string command;
        cin>>command;
        if(command=="create_user")
        {
            createuser();
        }
        else if(command=="login")
        {
            login();
        }
        else if(command=="create_group")
        {
            group_create();
        }
        else if(command=="join_group")
        {
            group_join();
        }
        else if(command=="leave_group")
        {
            group_leave();
        }
        else if(command=="list_requests")
        {
            showpending();
        }
        else if(command=="accept_request")
        {
            accgroupjoin();
        }
        else if(command=="list_groups")
        {
            list_groups();

        }
        else if(command=="list_files")
        {
            list_filesingroup();
        }
        else if(command=="upload files")
        {
            uploader();
        }
        else if(command=="download files")
        {
            downloader();
        }
        else if(command=="logout")
        {
            loggoff();
        }
        else if(command=="Show_downloads")
        {
            status();
        }
        else if(command=="stop_share")
        {
            stopsharing();
        }
    }//endofwhile*/








    return 0;
}