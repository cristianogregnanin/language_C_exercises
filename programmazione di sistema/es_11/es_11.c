#include <stdio.h>
#include <unistd.h>
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
        int vocali = 0;
        char buffer;

        while (read(p1p2[0], &buffer, sizeof(buffer)) > 0)
        {
            if (vocale(buffer) == 0)
            {
                vocali++;
            }
        }

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

    return 0;
}