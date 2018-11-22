#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <ctype.h>

int main(){
	int pid, padre;
	
	pid = fork();
	
	if(pid==0){
		padre = getppid();
		printf("\n\tmio padre ha pid: %d\n", padre);	
		sleep(60);
		exit(0);
	}else{
		wait(&pid);
	}
	
	printf("\n\nProgramma terminato\n\n");

	return 0;	
}
