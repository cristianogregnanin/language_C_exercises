#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define READ 0
#define WRITE 1


int main(int argc, char *argv[])
{
   int p0p1[2], p1p2[2],p2p3[2], pid;
   char *punt,tempo[10];
   double tot;
   char stringa;
   
    if (argc != 2)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }

pipe(p0p1);
pid = fork();

if (pid == 0)
{
  close(p0p1[READ]);                // 0 = lettura 1 = scrittura
  close(WRITE);
  dup(p0p1[WRITE]);
  close(p0p1[WRITE]);
  execl("/usr/sbin/traceroute", "traceroute", argv[1], NULL);

  return -1;
}

pipe(p1p2);
pid = fork();

if(pid == 0)
{
close(p0p1[WRITE]);
close(READ);
dup(p0p1[READ]);
close(p0p1[READ]);

close(p1p2[READ]);
close(WRITE);
dup(p1p2[WRITE]);
close(p1p2[WRITE]);

 execl("/usr/bin/awk", "awk", "{print $4}", NULL);
 return -1;
}

close(p0p1[READ]);
close(p0p1[WRITE]);

pipe(p2p3);
pid = fork();

if(pid == 0)
{
close(p1p2[WRITE]);
close(READ);
dup(p1p2[READ]);
close(p1p2[READ]);

close(p2p3[READ]);
close(WRITE);
dup(p2p3[WRITE]);
close(p2p3[WRITE]);

  execl("/usr/bin/tail", "tail", "-n", "+2", NULL);
        return -1;
}
close(p1p2[WRITE]);
close(p1p2[READ]);
close(p2p3[WRITE]);

 while (read(p2p3[0], &stringa, sizeof(stringa)) > 0)
    {
        strncat(tempo, &stringa, sizeof(stringa));
        if (stringa == '\n')
        {
            printf("Tempo parziale: %s", tempo);
            tot = tot + strtod(tempo, &punt);
            tempo[0] = '\0';
        }
    }

    close(p2p3[0]);
    printf("\nIl tempo totale impiegato è: %.2lf ms\n", tot);
    return 0;



    return 0;
}
