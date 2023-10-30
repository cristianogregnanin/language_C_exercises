#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>

#define SERVER_PORT 40005
#define SOCKET_ERROR ((int)-1)
#define DIMBUFF 512

int main(int argc, char *argv[])
{

	struct sockaddr_in servizio, rem_indirizzo;
	struct hostent *host;
	int ct, nread, soa, socketfd, client_len, fd, on = 1, fromlen = sizeof(servizio);
	char carattere, buffer[DIMBUFF];

	memset((char *)&servizio, 0, sizeof(servizio));

	servizio.sin_family = AF_INET;
	servizio.sin_addr.s_addr = htonl(INADDR_ANY);
	servizio.sin_port = htons(SERVER_PORT);

	socketfd = socket(AF_INET, SOCK_STREAM, 0);

	// Bind
	setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
	bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

	listen(socketfd, 10);

	// attensa del client
	for (;;)
	{
		ct = 0;
		printf("\nServer in ascolto...\n");

		soa = accept(socketfd, (struct sockaddr *)&rem_indirizzo, &fromlen);

		// risoluzione del client
		host = gethostbyaddr((char *)&rem_indirizzo.sin_addr, sizeof(rem_indirizzo.sin_addr), AF_INET);
		printf("\n\tStabilita la connessione con il client %s", host->h_name);

		nread = read(soa, &carattere, sizeof(carattere));
		printf("\n\tRicevuto carattere %c\n", carattere);

		while ((nread = read(soa, buffer, sizeof(buffer))) > 0)
		{
			for (int i = 0; i < strlen(buffer); i++)
			{
				if (buffer[i] == carattere)
				{
					ct++;
				}
			}
		}

		char ct_string[DIMBUFF];
		sprintf(ct_string, "%d\n", ct);

		printf("\n\til carattere %c compare %s volte \n", carattere, ct_string);

		// fin qua ok

		write(soa, ct_string, strlen(ct_string));

		close(soa);
	}

	close(socketfd);
	return 0;
}
