#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("I parametri inseriti sono errati\n");
        exit(1);
    }
    int tmp;
    if((tmp= open(argv[1], O_RDONLY))== -1)
    {
        printf("Il file specificato non esiste\n");
        exit(1);
    }
    close(tmp);
    char cerca[1000];
    char conta[1000];
    int n_conta;
    int p1p0[2];
    int conta_tot = 0;
    pipe(p1p0);
    do
    {
        printf("Inserisci la parola da cercare: ");
        scanf("%s", cerca);
        if (strcmp(cerca, "fine") == 0)
        {
            close(p1p0[1]);
            close(p1p0[0]);
            printf("Stringhe trovate: %d\n", conta_tot);
            exit(1);
        }
        int pid = fork();
        if (pid == 0)
        {
            close(p1p0[0]);
            close(1);
            dup(p1p0[1]);
            close(p1p0[1]);
            execl("/usr/bin/grep", "grep", "-c", cerca, argv[1], NULL);
            return -1;
        }
        read(p1p0[0], conta, sizeof(conta));
        n_conta = atoi(conta);
        printf("Il file ha %d '%s' \n", n_conta, cerca);
        conta_tot += n_conta;
    }while(1);
    return 0;
}
