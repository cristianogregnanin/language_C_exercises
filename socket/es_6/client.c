#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

void controllaParametri(int argc, char *argv[])
{
	if (argc != 5)
	{
		printf("Non hai inserito i parametri necessari \n");
		printf("Uso: $./client <server-ip> <porta> <stringa> <carattere>\n");
		exit(0);
	}
}

int main(int argc, char *argv[])
{

	controllaParametri(argc, argv);

	struct sockaddr_in servizio;
	char stringaout1[strlen(argv[3])];
	int socketfd;

	printf("Stringa %s carattere %c \n", argv[3], argv[4][0]);

	memset((char *)&servizio, 0, sizeof(servizio));

	servizio.sin_family = AF_INET;
	servizio.sin_addr.s_addr = inet_addr(argv[1]);
	servizio.sin_port = htons(atoi(argv[2]));

	socketfd = socket(AF_INET, SOCK_STREAM, 0);

	connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

	write(socketfd, argv[3], strlen(argv[3]));

	write(socketfd, &argv[4][0], sizeof(argv[4][0]));

	read(socketfd, stringaout1, sizeof(stringaout1));

	printf("La stringa senza il carattere %c e': %s\n", argv[4][0], stringaout1);

	close(socketfd);
	return 0;
}
