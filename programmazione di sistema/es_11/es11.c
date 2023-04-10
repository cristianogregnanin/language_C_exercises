#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char** argv)
{
	if(argc!=2)
	{
		printf("Errore numero parametri");
		return -1;
	}
	
	int p1p2[2], pid, pid2, status, art1;
	char buffer[1024], articolo[1024];

	pid=fork();
	
			
	if(pid==0)
	{


		while(1)
		{
			printf("Inserisci l'articolo da ricercare:\n");
			scanf("%s", articolo);
			if(strcmp(articolo, "esci")!=0)
			{
				pipe(p1p2);
				pid2=fork();
				if(pid2!=0)
				{
					close(p1p2[0]);	
					write(p1p2[1], articolo, strlen(articolo));					
					wait(&status);	
				}

				
				if(pid2==0)
				{	
					close(p1p2[1]);
					read(p1p2[0], buffer, sizeof(art1));
					art1=atoi(buffer);

					sprintf(buffer, "(?<=ART. %d.)(?s).*(?=ART. %d.)", art1, art1+1);
					execl("/usr/bin/grep", "grep", "-o", "-z", "-P", buffer, argv[1], NULL);
					return -1;	
				}
			}
			else
			{			
				exit(0);
			}
		}
	}
		
	wait(&status);
}
