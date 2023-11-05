#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>

#define SOCKET_ERROR ((int)-1)
#define DIMBUFF 3

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
	struct hostent *host;
	int ct, nread, soa, socketfd, client_len, fd, on = 1, fromlen = sizeof(servizio);
	char carattere, buffer[3];

	memset((char *)&servizio, 0, sizeof(servizio));

	servizio.sin_family = AF_INET;
	servizio.sin_addr.s_addr = htonl(INADDR_ANY);
	servizio.sin_port = htons(atoi(argv[1]));

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
		printf("\n\t nread: %d\n", nread);

		printf("\n\tRicevuto carattere %c\n", carattere);

		int sizebuffer = sizeof(buffer);
		int ll = strlen(buffer);
		printf("size: %d, strlen: %d", sizebuffer, ll);
		printf("\n\til carattere: %c \n", carattere);

		while ((nread = read(soa, buffer, sizeof(buffer))) > 0)
		{
			fflush(stdout); // make sure everything makes it to the output
			printf("\n\til carattere: %c \n", carattere);
			fflush(stdout); // make sure everything makes it to the output

			buffer[nread] = '\0';
			int l = strlen(buffer);
			printf("\n\t nread: %d\n", nread);
			printf("\n\t buffer: %s, lunghezza:  %d\n", buffer, l);
			printf("\t buffer[0]: %c\n", buffer[0]);
			printf("\t buffer[1]: %c\n", buffer[1]);
			printf("\t buffer[2]: %c\n", buffer[2]);
		//	printf("\t buffer[3]: %c\n", buffer[3]);
//			printf("\t buffer[4]: %c\n", buffer[4]);
//			printf("\t buffer[5]: %c\n", buffer[5]);
			fflush(stdout); // make sure everything makes it to the output

			printf("\n\til carattere: %c \n", carattere);

			for (int i = 0; i < strlen(buffer); i++)
			{			printf("\n\t\t\til carattere: %c \n", carattere);

				if (buffer[i] == carattere)
				{
					ct++;
				}
			}
			buffer[0] = '\0';
		}

		char ct_string[DIMBUFF];
		sprintf(ct_string, "%d", ct);
		fflush(stdout); // make sure everything makes it to the output

		printf("\n\til carattere %c compare %s volte \n", carattere, ct_string);

		// fin qua ok

		write(soa, ct_string, strlen(ct_string) + 1);

		close(soa);
	}

	close(socketfd);
	return 0;
}
