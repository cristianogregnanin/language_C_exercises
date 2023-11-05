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
#include <unistd.h>
#include <ctype.h>


void controllaParametri(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Non hai inserito i parametri necessari \n");
		printf("Uso: $./server <porta>\n");
		exit(0);
	}
}

int main(int argc, char *argv[])
{

	controllaParametri(argc, argv);

	struct sockaddr_in servizio, rem_indirizzo;
	int soa, socketfd, client_len, on = 1, fromlen = sizeof(servizio);
	char carattere, risposta;

	memset((char *)&servizio, 0, sizeof(servizio));

	servizio.sin_family = AF_INET;
	servizio.sin_addr.s_addr = htonl(INADDR_ANY);
	servizio.sin_port = htons(atoi(argv[1]));

	socketfd = socket(AF_INET, SOCK_STREAM, 0);

	// Bind
	setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
	bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

	listen(socketfd, 10);

	for (;;)
	{
		printf("\n\nServer in ascolto...\n");

		soa = accept(socketfd, (struct sockaddr *)&rem_indirizzo, &fromlen);

		read(soa, &carattere, sizeof(carattere));

		printf("\n\tRicevuto: %c\n", carattere);
		risposta = toupper(carattere);
		printf("\tconvertito %c in %c\n\n\n", carattere, risposta);

		write(soa, &risposta, sizeof(risposta));

		close(soa);
	}

	close(socketfd);
	return 0;
}