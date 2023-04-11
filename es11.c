#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	int articolo;
	char articolo_inizio[20];
	char articolo_fine[20];
	char argomento_grep[100];
    int pid = 0;

	if (argc != 2) {
    	printf("Usage: %s <file_name>\n", argv[0]);
    	exit(1);
	}

	while (1) {
    	printf("Inserisci il numero dell'articolo che vuoi ricercare (-1 per uscire): ");
    	scanf("%d", &articolo);

    	if (articolo == -1) {
        	break;
    	}

    	sprintf(articolo_inizio, "ART. %d.", articolo);
    	sprintf(articolo_fine, "ART. %d.", articolo + 1);

    	sprintf(argomento_grep, "-z -o -P '(?<=%s)(?s).*(?=%s)' %s", articolo_inizio, articolo_fine, argv[1]);

    	pid = fork();

    	if (pid == 0) {  
        	execl("/usr/bin/grep", "grep", argomento_grep, argv[1], (char *)0);
        	printf("Errore durante l'esecuzione di grep\n");
        	exit(1);
    	} 
        	wait(&pid);
    
	}

	return 0;
}
