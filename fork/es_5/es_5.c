#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>


#define NOME_LENGHT 21
#define COGNOME_LENGHT 21
#define RUOLO_LENGHT 21
#define MAX_LENGHT 25

typedef struct
{
    char nome[NOME_LENGHT];
    char cognome[COGNOME_LENGHT];
    char ruolo[RUOLO_LENGHT];
} Giocatore_t;

int LeggiFile(char nomeFile[], int *numGiocatori, Giocatore_t giocatori[])
{
    FILE *stream;
    if ((stream = fopen(nomeFile, "r")) == NULL)
    {
        exit(1);
    }

    for (int i = 0; !feof(stream); i++)
    {
        fscanf(stream, "%s %s %s\n", giocatori[*numGiocatori].nome, giocatori[*numGiocatori].cognome, giocatori[*numGiocatori].ruolo);
        (*numGiocatori)++;
    }

    fclose(stream);

    return 0;
}

void main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Argomenti errati!");
        exit(0);
    }

    int pid, numGiocatori = 0;
    Giocatore_t giocatori[MAX_LENGHT];

    LeggiFile(argv[1], &numGiocatori, giocatori);

    pid = fork();
    if (pid == 0)
    {
        for (int i = 0; i < numGiocatori; i++)
            if (strcmp(giocatori[i].ruolo, "attaccante") == 0)
                printf("%s %s %s\n", giocatori[i].nome, giocatori[i].cognome, giocatori[i].ruolo);
    }
    else
    {
        wait(&pid);
        exit(0);
    }
}
