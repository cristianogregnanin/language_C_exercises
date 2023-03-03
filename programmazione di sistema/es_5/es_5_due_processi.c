#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{

    int p1p0[2], p2p0[2];
    char buff[10], importo[10], *punt;
    double tot = 0;

    
    pipe(p1p0);
    int pid1 = fork();
    if (pid1 == 0)
    {
        close(p1p0[0]);
        close(1);
        dup(p1p0[1]);
        close(p1p0[1]);
        execl("/bin/cat", "cat", argv[1], NULL);

        return -1;
    }
pipe(p2p0);
    pid1 = fork();

    
    if (pid1 == 0)
    {
        close(p1p0[1]);
        close(0);
        dup(p1p0[0]);
        close(p1p0[0]);

        close(p2p0[0]);
        close(1);
        dup(p2p0[1]);
        close(p2p0[1]);

        execl("/bin/awk", "awk", "{print $3}", NULL);
        return -1;
    }

    close(p1p0[1]);
    close(p1p0[0]);
    close(p2p0[1]);

    while (read(p2p0[0], buff, sizeof(buff)) > 0)
    {

        strncat(importo, &buff[0], sizeof(buff[0]));

        if (buff[0] == '\n')
        {
            printf("%s", importo);
            tot = tot + strtod(importo, &punt);
            importo[0] = '\0';
        }
    }

    close(p2p0[0]);

    printf("Il totale delle fatture è: %.2lf\n", tot);
    return 0;
}
