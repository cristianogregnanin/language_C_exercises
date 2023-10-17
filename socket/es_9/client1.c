#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>


#define DIMBUFF 512
#define SERVER_PORT 40000


int main(int argc, char *argv[])
{


   if (argc != 4)
   {
       printf("Numero argomenti sbagliato\n");
       exit(1);
   }
   struct sockaddr_in servizio;
   int nread, socketfd;
   char buff[1];
   memset((char *)&servizio, 0, sizeof(servizio));// la memset copia i caratteri della string


   servizio.sin_family = AF_INET;
   servizio.sin_port = htons(atoi(argv[3]));//in argv[3] vuole la porta
   servizio.sin_addr.s_addr = inet_addr(argv[2]);// in argv[2] vuole l'indirzzo ip che quello localhost è "127.0.0.1"


   socketfd = socket(AF_INET, SOCK_STREAM, 0);
   connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
   printf("Stabilita la connessione con il server..\n");


   write(socketfd, argv[1], sizeof(argv[1]));//argv[1] chiede il file


   while (nread = read(socketfd, buff, sizeof(buff)) > 0)
   {
       write(1, buff, nread);
   }
   printf("dopo il while ma prima della close\n");
   close(socketfd);
   printf("dopo  della close\n");
   return 0;
}
