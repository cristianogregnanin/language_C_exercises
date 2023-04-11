#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define DIM 100
// definiamo grandezza stringa
int Main(int argc, char *argv[])
{
    if (argc != 2)
    {
        // controllo argomenti con argc
        printf("Numero di argomenti inseriti errato \n");
        return -1;
    }

    char stringa[DIM], contatore[DIM];
    int p1p0[2], contatoreTotale = 0;
    pipe(p1p0);

    while (1)
    {
        printf("Inserire parola da ricercare \n");
        scanf("%s", stringa);

        if (strcmp(stringa, "fine") == 0)
        {
            // chiudiamo tuttssssi i canali della pipe
            close(p1p0[0]);
            close(p1p0[1]);
            printf("Numero totale di occorrenze: %d \n", contatoreTotale);
            return 0;
        }
        pid_t pid = fork();
        // usiamo pid_t per definire il nostro pid
        if (pid == 0)
        {
            close(p1p0[0]);
            close(1);
            dup(p1p0[1]);
            close(p1p0[1]);
            execl("/usr/bin/grep", "grep", "-c", stringa, argv[1], NULL);
            return -1;
        }

        read(p1p0[0], contatore, sizeof(contatore));
        contatoreTotale = contatoreTotale + atoi(contatore);
        printf("La parola %s è stata trovata %d volte \n", stringa, contatoreTotale);
    }
    return 0;
}