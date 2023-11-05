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
#include <arpa/inet.h>
#include <sys/wait.h>

#define DIMBUFF 4096

void controllaParametri(int argc, char *argv[])
{
	if (argc != 5)
	{
		printf("Non hai inserito i parametri necessari \n");
		printf("Uso: $./client <server-ip> <porta> <path> <carattere> \n");
		exit(0);
	}
}

int main(int argc, char *argv[])
{

	controllaParametri(argc, argv);

	struct sockaddr_in servizio;

	int socketfd, pid;
	char occorrenze[DIMBUFF];

	memset((char *)&servizio, 0, sizeof(servizio));

	servizio.sin_family = AF_INET;
	servizio.sin_addr.s_addr = inet_addr(argv[1]);
	servizio.sin_port = htons(atoi(argv[2]));

	socketfd = socket(AF_INET, SOCK_STREAM, 0);

	connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

	write(socketfd, &argv[4][0], sizeof(argv[4][0]));

	pid = fork();
	if (pid == 0)
	{
		close(1);
		dup(socketfd);
		close(socketfd);

		execl("/usr/bin/cat", "cat", argv[3], NULL);
		return -1;
	}

	// read(socketfd, occorrenze, sizeof(occorrenze));

	printf("\n\til carattere %s compare %s volte nel file %s\n\n", argv[4], occorrenze, argv[3]);

	close(socketfd);
	return 0;
}
