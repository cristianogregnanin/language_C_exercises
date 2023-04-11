#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define costante 50
#define read 0
#define write 1

int main(int argc, char *argv[]) 
{
    
    char stringa[costante];
    int pid;
    int p1p2[2];
    char articolo_iniziale[costante];
    char articolo_finale[costante];

   
    while(1)
    {
        if (argc != 2)
    {
        printf("errore");
        exit(1);
    }
    pipe(p1p2);
    pid = fork();

     if (pid == 0)
      {
        close(p1p2[read]); 
        
            printf("Inserisci il numero dell'articolo che vuoi ricercare:\n");
            scanf(%s,stringa);

            if (strcmp(stringa, "esci") == 0)
            {
                printf("termine del programma\n");
                exit(1);
            }

             

      
    
        pid = fork();

            
        if (pid == 0) 
        {
            sprintf(articolo_iniziale, "ART. %s.", stringa);
            sprintf(articolo_finale, "ART. %d.", atoi(stringa) + 1);
            sprintf(argomento_grep, "-P '(?<= %s)(?s).*(?= %s)'", articolo_iniziale, articolo_finale);
            execl("/usr/bin/grep", "-z", "-o", "-P", '(?<=articolo_iniziale)(?s).*(?=articolo_finale)', argv[1], NULL);
            return -1;
                
        } 
                
        close(pipefd[read]);
        close(p1p2[write]);
        wait(&pid); 
        wait(&pid);
            
        

    

    return 0;

    }
    
}


