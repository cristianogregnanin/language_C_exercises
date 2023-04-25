#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char * argv[])
{
   int p1p0[2], pid, p0p1[2];
   int y;
   char * art_cercare[50];
   char * art_iniz[50];
   char * buffer[50];
   char * art_finale[50];
   char * argomento_grep[100];
   char * buffer_output[50];


   pipe(p0p1);
   pipe(p1p0);


   close(p0p1[0]);
   close(0);
   dup(p0p1[1]);


   while(1)
   {
       printf("Inserisci l'articolo da cercare\n");
       scanf("%s", &art_cercare);


       if(strcmp(art_cercare, "esci") == 0)
       {
           exit(1);
       }
       else
       {
           write(p0p1[1], art_cercare, strlength(art_cercare));
       }
   }


   pid = fork();


   if(pid == 0)
   {
       close(p0p1[1])/7;
       close(1);
       read(p0p1[0], &buffer, sizeof(buffer));


       sprintf(art_iniz, "ART.%s.", buffer);
       y = atoi(buffer) + 1;
       sprintf(art_finale, "ART.%d.", y);
       sprintf(argomento_grep, "-P '(? <= %s)(?s).*(? = %s)' ", art_iniz, art_finale);


       close(p1p0[0]);
       close(0);
       dup(p1p0[1]);


       execl("/usr/bin/grep", "-z", "-o", argomento_grep, argv[1], (char*)0);
       return -1;


       close(p1p0[1]);
   }


   close(p0p1[1]);
   close(1);
   read(p1p0[0], &buffer_output, sizeof(buffer_output));
   printf("Articolo: %s\n", buffer_output);
   return 0;
}
