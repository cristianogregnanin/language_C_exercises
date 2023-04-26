#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>


int main(int argc, char **argv)
{
   char stringa[3], articolo_iniziale[10], articolo_finale[10], argomento_grep[40], articolo[5], buff[20];
   int pid, nread;
   int p1p2[2];


   if (argc != 2)
   {
       printf("Numero argomenti sbagliato\n");
       exit(1);
   }


   while (1)
   {
       printf("Inserisci il numero dell’articolo che vuoi ricercare: \n");
       scanf("%s", stringa);
       if (strcmp(stringa, "esci") == 0)
           exit(0);


       sprintf(articolo_iniziale, "ART. %s.", stringa);
       sprintf(articolo_finale, "ART. %d.", atoi(stringa) + 1);
       sprintf(argomento_grep, "(?<=%s)(?s).*(?=%s)", articolo_iniziale, articolo_finale);


       pipe(p1p2);
       pid = fork();


       if (pid == 0)
       {
           close(p1p2[0]);
           close(1);
           dup(p1p2[1]);
           close(p1p2[1]);
           execl("/usr/bin/grep", "-z", "-o", "-P", argomento_grep, argv[1], (char *)0);
           return -1;
       }


       close(p1p2[1]);
       while (nread = read(p1p2[0], buff, strlen(buff)))
       {
           write(1, buff, nread);
       }
       close(p1p2[0]);
   }
   return 0;
}



