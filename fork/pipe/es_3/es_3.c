#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{

    int pid, p1p2[2];
    pipe(p1p2);

    pid = fork();

    if (pid == 0)
    {
        close(p1p2[0]);
        int numero;
        printf("Inserisci un numero: ");
        scanf("%d", &numero);
        write(p1p2[1], &numero, sizeof(numero));
        exit(0);
    }

    pid = fork();

    if (pid == 0)
    {
        int numero;
        char quadrato[10];
        close(p1p2[1]);
        read(p1p2[0], &numero, sizeof(numero));
        numero = numero * numero;
        close(p1p2[0]);

        sprintf(quadrato, "%d", numero);

        write(1, quadrato, strlen(quadrato));
        write(1, "\n", strlen("\n"));
        exit(0);
    }

    wait(&pid);
    wait(&pid);

    return 0;
}
