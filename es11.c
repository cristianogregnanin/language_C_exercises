#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	int articolo;
	char articolo_inizio[20];
	char articolo_fine[20];
	char argomento_grep[100];
	int p1p0[2];
   	 int pid = 0;

	

	while (1) {
    	printf("Inserisci il numero dell'articolo che vuoi ricercare (-1 per uscire): ");
    	scanf("%d", &articolo);

    	

    	sprintf(articolo_inizio, "ART. %d.", articolo);
    	sprintf(articolo_fine, "ART. %d.", articolo + 1);

    	sprintf(argomento_grep, "-z -o -P '(?<=%s)(?s).*(?=%s)' %s", articolo_inizio, articolo_fine, argv[1]);
	pipe(p1p0);
	close(p1p0[0]);
	
    	pid = fork();
	write(p1p0[1], articolo, strlen(articolo));
    	if (pid == 0) {  
		close(p1p0[1]);
		read(p1p0[0], articolo, strlen(articolo));
        	execl("/usr/bin/grep", "grep", argomento_grep, argv[1], (char *)0);
        	
        	exit(1);
    	} 
        	wait(&pid);
		close(p1p0[1]);
		close(p1p0[0]);
    
	}

	return 0;
}
