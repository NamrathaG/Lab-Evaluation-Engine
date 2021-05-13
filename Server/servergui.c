//Server code with GUI 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include<errno.h>
#include <dirent.h>   
#include<pthread.h>

#define PORT 4950
#define BUFSIZE 1024
char q[1000];

void substring(char s[], char sub[], int p, int l) {
   int c = 0;
   while (c < l) {
      sub[c] = s[p+c-1];
      c++;
                 }
   sub[c] = '\0';
                                                    }
void *counting()
{


sleep(120);

printf("********SORRY EVALUATION TIMED OUT************");     
 
    system ("ls /home/morty > /home/viseshini/Documents/TheFile.txt");
    char filesarray[100][100];
int i=0;
  FILE *fp = fopen("/home/viseshini/Documents/TheFile.txt", "r");

if(fp==NULL)
         {
printf("\nOh dear, something went wrong with fopen()! %s\n", strerror(errno));
fclose(fp);
exit(0);
        }


    char * line = NULL;
    size_t len = 0;
    ssize_t read;



   while ((read = getline(&line, &len, fp)) != -1) {
    int len=strlen(line);   
   strncpy(filesarray[i++],line,len-1);
                                                   }





  fclose(fp);
int j;
for(j=0;j<i;j++)
{
char str[100];
memset(str,'\0',100);
strcat(str,"sudo chmod 0777 /home/morty/");
strcat(str,filesarray[j]);
//printf("\nnearchmod %s",filesarray[j]);
system(str);
}

int g;char filehere[100];
for(g=0;g<i;g++)
{
memset(filehere,'\0',100);
strcat(filehere,"cc /home/morty/");
strcat(filehere,filesarray[g]);
strcat(filehere," -o output.out");

system(filehere);
system("./output.out");

sleep(5);
//printf("\nEnter the marks for %d:");
//char mark[5];
//gets(mark);

char *str=filesarray[g];
//str=k;
char *p=str;

char *h=p+4;


char *end=p+(strlen(str)-3);
long val=strtol(h,&end,10);




int sd=(int)val;

printf("\nEnter the marks for %d:",sd);
char mark[5];
gets(mark);


printf("\nYou entered marks %s for the student %d",mark,sd);
//send(sd,mark,sizeof(mark),0);


}///



//}



pthread_exit(0);
}


void send_to_all(int j, int i, int sockfd, int nbytes_recvd, char *recv_buf, fd_set *master)
{
    if (FD_ISSET(j, master)){
        if (j != sockfd && j != i) {
            if (send(j, recv_buf, nbytes_recvd, 0) == -1) {
                perror("send");
            }
        }
    }
}
       
void send_recv(int i, fd_set *master, int sockfd, int fdmax)
{
    int nbytes_recvd, j;
    char recv_buf[BUFSIZE];
   
    if ((nbytes_recvd = recv(i, recv_buf, BUFSIZE, 0)) <= 0) {
        if (nbytes_recvd == 0) {
            printf("socket %d hung up\n", i);
        }else {
            perror("recv");
        }
        close(i);
        FD_CLR(i, master);
    }else {
     printf("%s\n", recv_buf);
        for(j = 0; j <= fdmax; j++){
            send_to_all(j, i, sockfd, nbytes_recvd, recv_buf, master );
        }
    }   
}
       
void connection_accept(fd_set *master, int *fdmax, int sockfd, struct sockaddr_in *client_addr)
{
    socklen_t addrlen;
    int newsockfd;
   
    addrlen = sizeof(struct sockaddr_in);
    if((newsockfd = accept(sockfd, (struct sockaddr *)client_addr, &addrlen)) == -1) {
        perror("accept");
        exit(1);
    }else {
        FD_SET(newsockfd, master);
        if(newsockfd > *fdmax){
            *fdmax = newsockfd;
        }
        printf("\nNew connection from %s on port %d on socket %d \n",
inet_ntoa(client_addr->sin_addr), ntohs(client_addr->sin_port),newsockfd);
   
char q1[1000];

memset(q1,'\0',sizeof(q1));
char sdes[10];
sprintf(sdes,"%d",newsockfd);

//
//sprintf(sdes,"file%d",newsockfd);
//printf("%s",sdes);
strcat(q1,sdes);
strcat(q1,q);
//strcat(q1," store it in a file named:");
//strcat(q1,sdes);

puts(q1);

send(newsockfd,q1,sizeof(q1),0);






}
}
   
void connect_request(int *sockfd, struct sockaddr_in *my_addr)
{
    int yes = 1;
       
    if ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket");
        exit(1);
    }
       
    my_addr->sin_family = AF_INET;
    my_addr->sin_port = htons(9701);
    my_addr->sin_addr.s_addr = inet_addr("172.16.59.40");
    memset(my_addr->sin_zero, '\0', sizeof my_addr->sin_zero);
       
    if (setsockopt(*sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        perror("setsockopt");
        exit(1);
    }
       
    if (bind(*sockfd, (struct sockaddr *)my_addr, sizeof(struct sockaddr)) == -1) {
        perror("Unable to bind");
        exit(1);
    }
    if (listen(*sockfd, 10) == -1) {
        perror("listen");
        exit(1);
    }
    printf("\nTCPServer Waiting for client on port 9701\n");
    fflush(stdout);
}

/*
int main()
{


    fd_set master;
    fd_set read_fds;
    int fdmax, i;
    int sockfd= 0;
    struct sockaddr_in my_addr, client_addr;
   
    FD_ZERO(&master);
    FD_ZERO(&read_fds);
    connect_request(&sockfd, &my_addr);
    FD_SET(sockfd, &master);
 








printf("\nEnter a Question for the Students\n");
gets(q);



pthread_t tid;
pthread_attr_t attr;

pthread_attr_init(&attr);
pthread_create(&tid,&attr,counting,NULL);




   
    fdmax = sockfd;
    while(1){
        read_fds = master;
        if(select(fdmax+1, &read_fds, NULL, NULL, NULL) == -1){
            perror("select");
            exit(4);
        }
       
        for (i = 0; i <= fdmax; i++){
            if (FD_ISSET(i, &read_fds)){
                if (i == sockfd)
                    connection_accept(&master, &fdmax, sockfd, &client_addr);
                else
                    send_recv(i, &master, sockfd, fdmax);
            }
        }
    }
    return 0;
}










       
    if (bind(*sockfd, (struct sockaddr *)my_addr, sizeof(struct sockaddr)) == -1) {
        perror("Unable to bind");
        exit(1);
    }
    if (listen(*sockfd, 10) == -1) {
        perror("listen");
        exit(1);
    }
    printf("\nTCPServer Waiting for client on port 4950\n");
    fflush(stdout);
}


*/
int main()
{


    fd_set master;
    fd_set read_fds;
    int fdmax, i;
    int sockfd= 0;
    struct sockaddr_in my_addr, client_addr;
   
    FD_ZERO(&master);
    FD_ZERO(&read_fds);
    connect_request(&sockfd, &my_addr);
    FD_SET(sockfd, &master);
 


  printf("my sock fd is %d",sockfd);





printf("\nenter a question for the clients\n");
gets(q);


//threading
pthread_t tid;
pthread_attr_t attr;

//pthread_attr_init(&attr);
//pthread_create(&tid,&attr,counting,NULL); 
//to test chatting 




   printf("my sock fd is %d",sockfd);
    fdmax = sockfd;
    while(1){
        read_fds = master;
        if(select(fdmax+1, &read_fds, NULL, NULL, NULL) == -1){
            perror("select");
            exit(4);
        }
       
        for (i = 0; i <= fdmax; i++){
            if (FD_ISSET(i, &read_fds)){
                if (i == sockfd)
                    connection_accept(&master, &fdmax, sockfd, &client_addr);
                else
                    send_recv(i, &master, sockfd, fdmax);
            }
        }
    }
    return 0;
}
