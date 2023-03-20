#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Inserire un numero di parametri pari a 2\n");
        exit(1);
    }

    int pid;           // int per eseguire la fork
    int p1p2[2];       // pipe per i processi p1 e p2
    char stringa[100]; // stringa per leggere
    pipe(p1p2);        // creazione della pipe p1p2

    pid = fork();
    if (pid == 0) // processo p1
    {
        close(p1p2[0]); // chiudiamo canale di lettura della pipe

        printf("inserisci una stringa");
        scanf("%s", stringa);                // prendo in input la stringa
        while (strcmp(stringa, "esci") != 0) // itero fino a quando non inserisco la stringa fine
        {
            strcat(stringa, "\n");                    // concateno alla stringa il carattere /n per andare a capo e creare una riga
            write(p1p2[1], stringa, strlen(stringa)); // scrivo all'interno della pipe la stringa e la mando al processo p2
        }

        exit(1);
    }
    close(p1p2[1]); // chiudo canale di scrittura della pipe

    pid = fork();
    if (pid == 0) // processo p2
    {
        close(0);     // chiudo canale di input
        dup(p1p2[0]); // duplico lettura della pipe
        close(p1p2[0]);
        close(1); // chiudo standard output

        open(argv[1], O_WRONLY | O_CREAT);    // apertura del file in cui scrivere i risultati al posto dello standard output
        execl("/usr/bin/sort", "sort", NULL); // execl per eseguire il comando sort
        exit(1);                              // esco dal processo p2
    }

    close(p1p2[0]); // chiudiamo il canale di lettura della pipe
    wait(&pid);     // aspettiamo che il processo p2 esegua e termini

    return 0;
}