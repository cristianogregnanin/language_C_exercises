#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXCHAR 80
#define DELIMITATORE " "

typedef struct{
	char nome[20];
	char cognome[20];
	int eta;	
	
	}studente_t;


int main(){
	FILE * fd;
	char str[MAXCHAR], nome[20], *token;
	int eta, i=0;
	studente_t studente, studenti[5], vecchio;
	double media;
	
	fd = fopen("studenti.txt", "r");	
	
    while (fgets(str, MAXCHAR, fd) != NULL){
        
		token=strtok(str, DELIMITATORE);
		strcpy(studente.nome, token);
		
		token=strtok(NULL, DELIMITATORE);
		strcpy(studente.cognome, token);
		
		token=strtok(NULL, DELIMITATORE);
		studente.eta = atoi(token);
	
		studenti[i] = studente;
		i++;
	}
	
    	
	fclose(fd);
/*	
	vecchio = calcola_vecchio(studenti);
	media = calcola_media(studenti);
	
	printf("Lo studente piu vecchio è: %s", vecchio.nome);
	printf("La media delle eta è: %f", media);
*/
	
	return 0;
	
}






