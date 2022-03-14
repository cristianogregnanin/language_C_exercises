#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define DIMBUFF 512
#define SERVER_PORT 1313

int main(int argc, char *argv[])
{

	struct sockaddr_in servizio;

	int nread, socketfd;
	char carattere[strlen(argv[1])];

	memset((char *)&servizio, 0, sizeof(servizio));

	servizio.sin_family = AF_INET;
	servizio.sin_addr.s_addr = htonl(INADDR_ANY);
	servizio.sin_port = htons(SERVER_PORT);

	socketfd = socket(AF_INET, SOCK_STREAM, 0);

	connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

	//scrittura del carattere all'interno della socket
	//carattere = 'a';//argv[1];
	strcpy(carattere, argv[1]);

	write(socketfd, &carattere, sizeof(carattere));

	//ricevere i dati dal client
	nread = read(socketfd, &carattere, sizeof(carattere));

	//chiusura socket
	close(socketfd);

	printf("\n\n\t\tconvertito %s in %s\n\n", argv[1], carattere);

	return 0;
}
