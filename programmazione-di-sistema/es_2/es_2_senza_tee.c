#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define DIM_BUFFER 1024

// In questa soluzione si usano le system call per scrivere nel file wc.txt

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero argomenti sbagliato!\n");
        exit(1);
    }

    int fd, p1p0[2], pid, p2p0[2], nread;
    char buff[DIM_BUFFER];

    pipe(p1p0);   // creo la prima pipe
    pid = fork(); // primo figlio
    if (pid == 0)
    {
        close(p1p0[0]); // chiudo la lettura
        close(1);       // chiudo lo stdout
        dup(p1p0[1]);   // duplico la scrittura
        close(p1p0[1]); // chiudo la scrittura

        execl("/bin/cat", "cat", argv[1], (char *)0); // eseguo cat
        return -1;                                    // uscita con errore
    }

    pipe(p2p0);   // creo la seconda pipe
    pid = fork(); // secondo figlio
    if (pid == 0)
    {
        close(p1p0[1]); // chiudo la scrittura
        close(0);       // chiudo lo stdin
        dup(p1p0[0]);   // duplico la lettura
        close(p1p0[0]); // chiudo la lettura

        close(p2p0[0]); // chiudo la lettura
        close(1);       // chiudo lo stdout
        dup(p2p0[1]);   // duplico la scrittura
        close(p2p0[1]); // chiudo la scrittura

        execl("/bin/wc", "wc", (char *)0); // eseguo wc
        return -1;                         // uscita con errore
    }

    // chiudo i canali di comunicazione
    close(p1p0[1]);
    close(p1p0[0]);
    close(p2p0[1]);

    fd = open("wc.txt", O_WRONLY | O_CREAT, 0777); // apro il file wc.txt
    while ((nread = read(p2p0[0], buff, sizeof(buff))) > 0)
    {
        write(fd, buff, nread); // scrivo su wc.txt
    }
    close(p2p0[0]); // chiudo la lettura
    close(fd);      // chiudo il file

    return 0; // uscita con successo
}
