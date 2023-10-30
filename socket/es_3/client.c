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

int main(int argc, char *argv[])
{
	if (argc != 5)
	{
		printf("Numero argomenti sbagliato\n");
		// exit(1);
	}

	struct sockaddr_in servizio;

	int socketfd, fd, pid;
	ssize_t nread;
	char occorrenze[DIMBUFF];

	memset((char *)&servizio, 0, sizeof(servizio));

	servizio.sin_family = AF_INET;
	servizio.sin_port = htons(atoi(argv[4]));
	servizio.sin_addr.s_addr = inet_addr(argv[3]);

	socketfd = socket(AF_INET, SOCK_STREAM, 0);

	connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

	write(socketfd, &argv[2][0], sizeof(argv[2][0]));

	pid = fork();
	if (pid == 0)
	{
		close(1);
		dup(socketfd);
		close(socketfd);
		execl("/usr/bin/cat", "cat", argv[1], NULL);
		return -1;
	}

	// fin qua ok

	read(socketfd, occorrenze, sizeof(occorrenze));

	printf("\n\til carattere %s compare %s volte nel file %s\n\n", argv[2], occorrenze, argv[1]);

	close(socketfd);
	return 0;
}
