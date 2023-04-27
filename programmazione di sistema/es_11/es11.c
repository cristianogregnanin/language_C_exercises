#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXLEN 1000

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    char inizio[MAXLEN], fine[MAXLEN];
    char argomento_grep[MAXLEN];
    sprintf(argomento_grep, "-P '(?<= %s)(?s).*(?= %s)'", inizio, fine);

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // processo figlio
        while (1) {
            printf("Inserisci l'articolo da cercare (in forma ART. X): ");
            scanf("%s", inizio);
            if (strcmp(inizio, "esci") == 0)
                break;

            sprintf(fine, "ART. %d", atoi(&inizio[4])+1);
            execl("/bin/grep", "-z", "-o", argomento_grep, argv[1], (char *)0);
            perror("execl");
            exit(1);
        }
    } else {
        // processo padre
        wait(NULL);
    }
    return 0;
}
