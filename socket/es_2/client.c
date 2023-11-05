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

void controllaParametri(int argc, char *argv[])
{
	if (argc != 4)
	{
		printf("Non hai inserito i parametri necessari \n");
		printf("Uso: $./client <server-ip> <porta> <path>\n");
		exit(0);
	}
}

int main(int argc, char *argv[])
{

	controllaParametri(argc, argv);
	struct sockaddr_in servizio;

	int socketfd;
	char str[DIMBUFF];

	FILE *fd;

	// apro file
	fd = fopen(argv[3], "r");

	// leggo il file
	fscanf(fd, "%s", str);

	// chiudo il file
	fclose(fd);

	printf("\til contenuto del file è: %s\n", str);

	memset((char *)&servizio, 0, sizeof(servizio));

	servizio.sin_family = AF_INET;
	servizio.sin_addr.s_addr = inet_addr(argv[1]);
	servizio.sin_port = htons(atoi(argv[2]));

	socketfd = socket(AF_INET, SOCK_STREAM, 0);

	connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

	// scrittura del carattere all'interno della socket
	write(socketfd, str, strlen(str));

	// ricevere i dati dal client
	read(socketfd, str, sizeof(str));

	// chiusura socket
	close(socketfd);

	printf("\tla string convertita è: %s\n\n", str);

	return 0;
}
