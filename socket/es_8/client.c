#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define DIM 20

void controllaParametri(int argc, char *argv[])
{
	if (argc != 6)
	{
		printf("Non hai inserito i parametri necessari \n");
		printf("Uso: $./client <server-ip> -p <porta> <stringa> <carattere>\n");
		exit(0);
	}

	if (strcmp(argv[2], "-p") != 0)
	{
		printf("Hai inserito i parametri in maniera errata \n");
		exit(1);
	}
}

int main(int argc, char *argv[])
{

	controllaParametri(argc, argv);

	struct sockaddr_in servizio;
	char stringaint1[DIM], stringaout1[DIM], c;
	int socketfd;

	strcpy(stringaint1, argv[4]);
	strcpy(&c, argv[5]);
	printf("Stringa %s carattere %c \n", stringaint1, c);

	memset((char *)&servizio, 0, sizeof(servizio));

	servizio.sin_family = AF_INET;
	servizio.sin_addr.s_addr = inet_addr(argv[1]);
	servizio.sin_port = htons(atoi(argv[3]));

	socketfd = socket(AF_INET, SOCK_STREAM, 0);

	connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

	write(socketfd, stringaint1, sizeof(stringaint1));
	write(socketfd, &c, sizeof(c));

	read(socketfd, stringaout1, sizeof(stringaout1));

	printf("La stringa senza il carattere %c e': %s\n", c, stringaout1);

	close(socketfd);
}
