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

#define SERVER_PORT 1313
#define SOCKET_ERROR ((int)-1)
#define DIMBUFF 512

int main()
{

	struct sockaddr_in servizio, rem_indirizzo;
	int nread, soa, socketfd, client_len, fd, on = 1, fromlen = sizeof(servizio);
	struct hostent *host;
	char carattere, risposta;

	memset((char *)&servizio, 0, sizeof(servizio));

	servizio.sin_family = AF_INET;
	servizio.sin_addr.s_addr = htonl(INADDR_ANY);
	servizio.sin_port = htons(SERVER_PORT);

	socketfd = socket(AF_INET, SOCK_STREAM, 0);

	//Bind
	setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
	bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

	listen(socketfd, 10);

	//attensa del client
	for (;;)
	{
		printf("\n\nServer in ascolto...\n");
		fflush(stdout);

		//accept
		soa = accept(socketfd, (struct sockaddr *)&rem_indirizzo, &fromlen);

		//risoluzione del client
		host = gethostbyaddr((char *)&rem_indirizzo.sin_addr, sizeof(rem_indirizzo.sin_addr), AF_INET);
		printf("\n\n Stabilita la connessione con il client %s", host->h_name);

		//ricevere i dati dal client
		nread = read(soa, &carattere, sizeof(carattere));

		printf("\n\tRicevuto: %c\n", carattere);
		risposta = toupper(carattere);
		printf("\tconvertito %c in %c\n\n\n", carattere, risposta);

		//scrittura del carattere all'interno della socket
		write(soa, &risposta, sizeof(risposta));

		//chiusura socket
		close(soa);

		//close(socketfd);
	}

	return 0;
}
