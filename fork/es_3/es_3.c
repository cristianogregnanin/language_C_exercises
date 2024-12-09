#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <ctype.h>
#include <string.h>

void converti(char str[])
{	
	for (int i = 0; i < strlen(str); i++)
	{
		str[i] = toupper(str[i]);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Numero di argomenti inseriti non valido");
		exit(0);
	}

	int pid = fork();

	if (pid == 0)
	{
		converti(argv[1]);
		printf("la stringa in maiuscolo è: %s\n\n", argv[1]);
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
