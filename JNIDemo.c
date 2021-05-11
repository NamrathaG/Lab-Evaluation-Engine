#include "JNIDemo.h"
#include <sys/socket.h>
#include <netinet/in.h>//inet_addr ntoa etc
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>//for perror
#include <string.h>
#include <sys/types.h>//for ---_t datatypes
#include <fcntl.h>

int sd;
//const String name;
char chat[5000]="\0";
JNIEXPORT void JNICALL Java_JNIDemo_compile(JNIEnv * env, jobject obj)
{
 
 //printf("\nEnter the name of the .c file you wish to compile");
 // scanf("%s",fname); 
 char fname[100];
  memset(fname,'\0',100);


strcpy(fname,"a.c");
  char filename[100];
  memset(filename,'\0',100);
  strcat(filename,"cc ");
  strcat(filename,fname);
  strcat(filename," &> comp.txt");

  system(filename);
}

JNIEXPORT void JNICALL Java_JNIDemo_run(JNIEnv * env, jobject obj)

{
/*
char fname[100];
  memset(fname,'\0',100);


strcpy(fname,"a.c");
  char filename[100];
  memset(filename,'\0',100);
  strcat(filename,"cc ");
  strcat(filename,fname);
  strcat(filename," -o output.out");
system(strcat("cat check.txt < ",filename));
  system(filename);
  //memset(filename,'\0',100);
 // strcat(filename," ./output.out > run.txt"); 
  system("./output.out > run.txt");
*/

system("echo hi");
char filename[200];

memset(filename,'\0',200);
  strcat(filename,"cc ");
  strcat(filename,"a.c");
  strcat(filename," -o output.out");


  strcat(filename," && ./output.out  > run.txt"); 
char echoing[300]="echo ";
memset(echoing,'\0',300);
strcat(echoing,filename);
system(echoing);


  system(filename);


 }


int main()
{
return 0;
}




/*
fucntion upload()
{
    system("ftp 10.75.3.68");
  //printf("\nWaiting for the teacher to send the result\n");
  //printf("\nResult=");
  int recvbytes3=recv(sd,buf,sizeof(buf),0); //score

}

*/
   


JNIEXPORT void JNICALL Java_JNIDemo_recv(JNIEnv * env,jobject obj)
{

 
system("ls");
sleep(25);
system("ls");
 //const char *name = (*env)->GetStringUTFChars(env, name1, 0);
    //printf("%s", name);
//const  int sd=(int)sd1;
int sockfd=sd;
char recv_buf[100];
char buf[10];
char hello[100]="4hello";

sprintf(buf, "%d", sd);
strcat(hello,buf);
int fo2=open("sd1.txt",O_RDWR);
int fg2=write(fo2,hello,10);
close(fo2);

while(1)
{

       int  nbyte_recvd = recv(sockfd, recv_buf,100, 0);

strncat(chat,recv_buf,nbyte_recvd);
strcat(chat,"\n");
        //recv_buf[nbyte_recvd] = '\0';
        //printf("%s",recv_buf);
strcat(hello,recv_buf);

int fo2=open("sd1.txt",O_RDWR);
int fg2=write(fo2,hello,10);
close(fo2);
          
int fo1=open("recvbuf.txt",O_RDWR);
int fg1=write(fo1,recv_buf,100);
close(fo1);



int fo=open("chatbox.txt",O_RDWR);
int fg=write(fo,chat,5000);
close(fo);
 }     
       // fflush(stdout);
    }




                       
 // (*env)->ReleaseStringUTFChars(env, name1, name);







JNIEXPORT void JNICALL Java_JNIDemo_getquestion(JNIEnv * env, jobject obj)

{





  char buf[1024],fname[1024];
  char filename[100];
  int choice=0;
  memset(filename,'\0',100);
  struct sockaddr_in address;
  int len=sizeof(address);
  sd=socket(AF_INET,SOCK_STREAM,0);



char hello[10]="ghello";

sprintf(buf, "%d", sd);
strcat(hello,buf);
int fo2=open("sd1.txt",O_RDWR);
int fg2=write(fo2,hello,10);

close(fo2);

  address.sin_family=AF_INET;
  address.sin_addr.s_addr=inet_addr("10.76.1.94");
  address.sin_port=htons(9701);
  int result=connect(sd,(struct sockaddr*)&address,len);

  int recvbytes=recv(sd,buf,sizeof(buf),0);
/*char mysd[10]="";
memset(mysd,'\0',10);
puts(buf[0]);

strcat(mysd,buf[0]+"hello");
*/
/*
char mysd[10]="";
memset(mysd,'\0',10);
strcat(mysd,"hello");
strcat(mysd,buf[0]);
*/
char mysd[10];
memset(mysd,'\0',10);
memcpy(mysd, buf, 1);
mysd[1] = '\0'; 





int fo1=open("socket.txt",O_RDWR);
if(fo1==-1)
{
system("ls");
}

int fg1=write(fo1,mysd,O_RDWR);
close(fo1);

int fo=open("question.txt",O_RDWR);
int fg=write(fo,buf,recvbytes);
close(fo);
////4Write a program to print hello?
//put the question in question .txt
//go to your clientui
//open question.txt and put it on a label
 


}

JNIEXPORT void JNICALL Java_JNIDemo_sendv(JNIEnv * env,jobject obj,jstring msg1)
{


const char *msg = (*env)->GetStringUTFChars(env, msg1, 0);
int sockfd=sd;

//char nsend_buf[100];
 strcat(chat,msg);
strcat(chat,"\n"); //WORKS!
 send(sockfd, msg, (int)strlen(msg), 0);
int fo=open("chatbox.txt",O_RDWR);
int fg=write(fo,chat,5000);

(*env)->ReleaseStringUTFChars(env, msg1, msg);
//relaese here

}


