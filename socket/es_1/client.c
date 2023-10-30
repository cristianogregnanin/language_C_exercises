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
	int socketfd;
	char carattere;
	memset((char *)&servizio, 0, sizeof(servizio));

	servizio.sin_family = AF_INET;
	servizio.sin_port = htons(atoi(argv[3]));
	servizio.sin_addr.s_addr = inet_addr(argv[2]);

	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
	printf("Stabilita la connessione con il server..\n");

	write(socketfd, &argv[1][0], sizeof(argv[1][0]));

	// ricevere i dati dal client
	read(socketfd, &carattere, sizeof(carattere));

	// chiusura socket
	close(socketfd);

	printf("\n\t\tConvertito carattere %c in %c\n\n", argv[1][0], carattere);

	return 0;
}