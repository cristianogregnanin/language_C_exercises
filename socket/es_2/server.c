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

#define SERVER_PORT 1313
#define SOCKET_ERROR ((int)-1)
#define DIMBUFF 512

void inverti(char str[], char newstr[], int n)
{

	int i, j = 0;
	for (i = n - 1; i >= 0; i--)
	{
		newstr[j] = str[i];
		j++;
	}
}

int main(int argc, char *argv[])
{

	struct sockaddr_in servizio, rem_indirizzo;
	struct hostent *host;
	int nread, soa, socketfd, client_len, fd, on = 1, fromlen = sizeof(servizio);
	char str[DIMBUFF] = "";

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
		printf("\n\nServer in ascolto...");

		// accept
		soa = accept(socketfd, (struct sockaddr *)&rem_indirizzo, &fromlen);

		// risoluzione del client
		host = gethostbyaddr((char *)&rem_indirizzo.sin_addr, sizeof(rem_indirizzo.sin_addr), AF_INET);
		printf("\n\n Stabilita la connessione con il client %s", host->h_name);

		// ricevere i dati dal client
		nread = read(soa, &str, sizeof(str));

		printf("\n\tRicevuta stringa %s dimensione: %d\n", str, nread);

		int len = strlen(str);
		char newstr[len];
		inverti(str, newstr, len);

		printf("\n\tstringa invertita: %s\n\n", newstr);

		// scrittura dell stringa all'interno della socket
		write(soa, newstr, sizeof(newstr));

		// chiusura socket
		close(soa);
	}

	return 0;
}
