
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_STR_LEN 100 // lunghezza massima della stringa inserita dall'utente

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pid_t pid1, pid2;
    int pipefd[2]; // pipe per la comunicazione tra P0 e P1
    char input_str[MAX_STR_LEN];
    char argomento_grep[MAX_STR_LEN + 54]; // 54 è la lunghezza fissa del pattern di grep

    if (pipe(pipefd) == -1)
    { // creazione della pipe
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        printf("Inserisci l'articolo di costituzione da cercare (scrivi 'esci' per uscire): ");
        fgets(input_str, MAX_STR_LEN, stdin);
        input_str[strlen(input_str) - 1] = '\0'; // rimuove il carattere \n dalla fine della stringa

        if (strcmp(input_str, "esci") == 0)
        { // l'utente ha scritto "esci"
            break;
        }
        else
        {
            sprintf(argomento_grep, "-P '(?<=ART. %s. ART. %d.)(?s).*(?=ART. %d. ART. %d.)'", input_str, atoi(input_str) + 1, atoi(input_str) + 1, atoi(input_str) + 2); // prepara l'argomento per execl con sprintf
            pid1 = fork();                                                                                                                                               // crea P1
            if (pid1 == -1)
            { // errore nella fork
                perror("fork");
                exit(EXIT_FAILURE);
            }
            else if (pid1 == 0)
            { // codice P1
                close(pipefd[0]);                                                       // chiude la lettura della pipe
                dup2(pipefd[1], STDOUT_FILENO);                                         // redefine STDOUT sulla scrittura della pipe
                execl("/usr/bin/grep", "-z", "-o", argomento_grep, argv[1], (char *)0); // esegue grep con execl
                perror("execl");                                                        // in caso di errore, stampa il messaggio e termina il processo
                exit(EXIT_FAILURE);
            }
            else
            { // codice P0
                close(pipefd[1]);                  // chiude la scrittura della pipe
                wait(NULL);                        // aspetta che P1 finisca
                char output_str[1024];             // buffer per leggere l'output di P1 dalla pipe
                read(pipefd[0], output_str, 1024); // legge l'output di P1 dalla pipe
                printf("\n%s\n", output_str);      // stampa l'output a video
            }
        }
    }

    return 0;
}