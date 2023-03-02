#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Numero parametri errato\n");
        exit(1);
    }

    char ricerca[1000];
    char conta[5];
    int p1p0[2];
    int contaTOT = 0;

    pipe(p1p0);
    while (1)
    {
        printf("Che parola vuoi cercare? ");
        scanf("%s", ricerca);

        if (strcmp(stringa, "fine") == 0) //chiusura del programma nel caso venga digitato FINE
        {
            close(p1p0[1]);
            close(p1p0[0]);
            printf("Trovate %d parole dentro %s\n", contaTOT,argv[1]);
            break;
        }
        
        int pid = fork();
        if (pid == 0)
        {
            close(p1p0[0]);
            close(1);//chiusura STDOUT
            dup(p1p0[1]);//duplicazione del canale di scrittura di p1p0 utilizzato come STDOUT
            close(p1p0[1]);
            //execl di GREP -C: viene scritto nel STDOUT il numero di volte la stringa RICERCA nel file inserito in ARGV[1]
            execl("/usr/bin/grep", "grep", "-c", ricerca, argv[1], (char *)0);
            return -1;//STDERR
        }
        
        wait(&pid);
        read(p1p0[0], conta, sizeof(cnt)); //leggo il numero di volte che la stringa compare nel file
        printf("Trovato '%s' %d volta/e '%s' \n", ricerca, atoi(conta));
        contaTOT += atoi(conta);
    }

    return 0;
}
