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

void controllaParametri(int argc, char *argv[])
{
	if (argc != 4)
	{
		printf("Non hai inserito i parametri necessari \n");
		printf("Uso: $./client <server-ip> <porta> <carattere>\n");
		exit(0);
	}
}

int main(int argc, char *argv[])
{

	controllaParametri(argc, argv);

	struct sockaddr_in servizio;
	int socketfd;
	char carattere;
	memset((char *)&servizio, 0, sizeof(servizio));

	servizio.sin_family = AF_INET;
	servizio.sin_addr.s_addr = inet_addr(argv[1]);
	servizio.sin_port = htons(atoi(argv[2]));

	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
	printf("Stabilita la connessione con il server..\n");

	write(socketfd, &argv[3][0], sizeof(argv[3][0]));

	// ricevere i dati dal server
	read(socketfd, &carattere, sizeof(carattere));

	// chiusura socket
	close(socketfd);

	printf("\n\t\tConvertito carattere %c in %c\n\n", argv[3][0], carattere);

	return 0;
}