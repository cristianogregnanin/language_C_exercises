#include <stdio.h>
#include <unistd.h>
<<<<<<< HEAD
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1
#define LENGTH_ART 15   // dimensione per articolo_iniziale e articolo_finale
#define LENGTH_GREP 100 // dimensione per l'argomento della grep

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Numero argomenti non valido.\n");
        exit(1);
    }

    char ricerca[4];
    int p1p2[2]; // pipe utilizzata per salvare l'articolo da ricercare
    pipe(p1p2);

    while (1)
    {
        int pid = fork();
        if (pid == 0) // apertura P1
        {
            close(p1p2[READ]);
            printf("Inserisci numero articolo da ricercare : ");
            scanf("%s", ricerca);

            write(p1p2[WRITE], ricerca, sizeof(ricerca));
            exit(0);
        }
        wait(&pid);

        read(p1p2[READ],ricerca,sizeof(ricerca));
        if (strcmp(ricerca, "esci") == 0) //uscita dal ciclo e conseguente chiusura del programma
        {
            printf("Chiusura del programma.\n");
            close(p1p2[READ]);
            close(p1p2[WRITE]);
            break;
        }

        pid = fork();
        if (pid == 0) // apertura P2
        {
            close(p1p2[WRITE]);
            read(p1p2[READ], ricerca, sizeof(ricerca));

            // Controllo del range degli articoli. In più, viene controllato se atoi va a buon fine o meno
            //(la funzione atoi ritorna 0 in caso di conversione in int non riuscita).
            if (atoi(ricerca) < 1 || atoi(ricerca) > 139)
            {
                printf("Articolo non esistente.");
                exit(1);
            }

            char articolo_iniziale[LENGTH_ART], articolo_finale[LENGTH_ART], argomento_grep[LENGTH_GREP];
            sprintf(articolo_iniziale, "ART. %d.", atoi(ricerca));
            sprintf(articolo_finale, "ART. %d.", (atoi(ricerca) + 1));
            sprintf(argomento_grep, "(?<=%s)(?s).*(?=%s)", articolo_iniziale, articolo_finale);

            execl("/usr/bin/grep", "grep", "-z", "-o","-P", argomento_grep, argv[1], NULL);
            return -1;
        }
    }
    
=======
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <ctype.h>

int vocale(char lettera)
{
    lettera = tolower(lettera);
    if (lettera == 'a' || lettera == 'i' || lettera == 'u' || lettera == 'o' || lettera == 'e')
    {
        return 0;
    }

    return -1;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }

    int p1p2[2], p2p0[2], pid;
    char str_vocali[10];

    pipe(p1p2);

    pid = fork();
    if (pid == 0)
    {
        close(p1p2[0]);

        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);

        execl("/usr/bin/cat", "cat", argv[1], NULL);
        return -1;
    }

    close(p1p2[1]);

    pipe(p2p0);
    pid = fork();
    if (pid == 0)
    {
        close(p2p0[0]);

        int vocali = 0;
        char carattere;

        while (read(p1p2[0], &carattere, sizeof(carattere)) > 0)
        {
            if (vocale(carattere) == 0)
            {
                vocali++;
            }
        }

        close(p1p2[0]);
        sprintf(str_vocali, "%d", vocali);

        write(p2p0[1], str_vocali, strlen(str_vocali));

        close(p2p0[1]);
        exit(0);
    }

    read(p2p0[0], str_vocali, sizeof(str_vocali));

    close(p2p0[0]);
    close(p2p0[1]);

    close(p1p2[0]);
    wait(&pid);
    wait(&pid);

    printf("Il file %s contiene %s vocali\n", argv[1], str_vocali);

>>>>>>> refs/remotes/origin/master
    return 0;
}
