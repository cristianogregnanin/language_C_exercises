#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <ctype.h>

int main (){
	
	char c;
	int pid;
	printf("Inserisci un carattere: \n");
	scanf("%c",&c);
	
	pid = fork();
	
	if(pid==0){
		printf("Il carattere in maiuscolo è: %c\n", toupper(c));
		sleep(5);
		exit(2);
	}else{
		wait(&pid);
	}
	
	printf("\n\nMio figlio ha terminato\n\n");
	return 0;

}
