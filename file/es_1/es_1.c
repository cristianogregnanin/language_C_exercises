#include <stdio.h>

int main(){
	
	FILE * fd;
	char contenuto[5];
	
	//apro file
	fd = fopen("testo.txt","r");
	
	//leggo il file
	fscanf(fd,"%s", contenuto);
	
	//chiudo il file
	fclose(fd);
	printf("Il contenuto del file è: %s\n\n", contenuto);		
	
	fd = fopen("TESTO.TXT","w"); 
	fprintf(fd,"%s","ecco un nuovo file");
	fclose(fd);
		
}
