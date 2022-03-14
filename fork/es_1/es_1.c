#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <ctype.h>

int main(int argc, char *argv[])
{

	int pid;

	pid = fork();

	if (pid == 0)
	{
		printf("Il carattere in maiuscolo è: %c\n", toupper(argv[1][0]));
		sleep(5);
		exit(2);
	}
	else
	{
		wait(&pid);
	}

	printf("\n\nMio figlio ha terminato\n\n");
	return 0;
}
