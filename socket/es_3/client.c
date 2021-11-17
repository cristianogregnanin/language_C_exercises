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

int main(int argc, char **argv)
{

	struct sockaddr_in servizio;

	int nread, socketfd;
	char str[DIMBUFF], occorrenze[DIMBUFF];
	char carattere[strlen(argv[2])];
	strcpy(carattere, argv[2]);

	FILE *fd;

	//apro file
	fd = fopen(argv[1], "r");

	//leggo il file
	fscanf(fd, "%s", str);

	//chiudo il file
	fclose(fd);

	printf("il contenuto del file è: %s\n\n\n", str);
	printf("il carattere da ricercare è: %s\n\n\n", carattere);

	memset((char *)&servizio, 0, sizeof(servizio));

	servizio.sin_family = AF_INET;
	servizio.sin_addr.s_addr = htonl(INADDR_ANY);
	servizio.sin_port = htons(SERVER_PORT);

	socketfd = socket(AF_INET, SOCK_STREAM, 0);

	connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

	//scrittura del carattere all'interno della socket
	write(socketfd, str, strlen(str));
	read(socketfd, &nread, sizeof(int));

	write(socketfd, carattere, sizeof(carattere));

	//ricevere i dati dal client
	read(socketfd, &occorrenze, sizeof(occorrenze));

	//chiusura socket
	close(socketfd);

	printf("\n\til carattere %s compare %s volte nella stringa %s\n\n", carattere, occorrenze, str);

	return 0;
}
