#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    char stringa[1000];
    char conta[1000];
    int p1p0[2];
    int contatot = 0;
    int pid = fork();
    pipe(p1p0);
    while (1)
    {
        printf("Inserire la parola ");
        scanf("%s", stringa);

        if (strcmp(stringa, "fine") == 0)
        {
            close(p1p0[1]);
            close(p1p0[0]);           
            exit(1);
        }

        if (pid == 0)
        {
            close(p1p0[0]);
            close(1);
            dup(p1p0[1]);
            close(p1p0[1]);

            execl("/usr/bin/grep", "grep", stringa, argv[1], (char *)0);
            return -1;
        }
        read(p1p0[0], conta, sizeof(conta));
        printf("Il file ha %d '%s' \n", atoi(conta), stringa);
        contatot += atoi(conta);
    }

    return 0;
}
