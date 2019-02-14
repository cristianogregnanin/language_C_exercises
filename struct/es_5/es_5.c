#include <stdio.h>
#include <string.h>

#define DIM 3

typedef struct {
	char nome[20];
	char matricola[5];
	int eta;
	
	} studente_t;
	
	
int cerca(char matricola[], studente_t studenti[]){
	
	int i;
	for(i=0;i<DIM;i++)
		if(strcmp(matricola, studenti[i].matricola)==0)
			return i;			
	return -1;
}

int main (int argc, char **argv){

	char matricola[5];
	int i;
	studente_t studenti[DIM];

	for(i=0;i<DIM;i++){
		
		printf("inserisci matricola: ");
		scanf("%s", studenti[i].matricola);		
		
		printf("inserisci nome: ");
		scanf("%s", studenti[i].nome);
		
		printf("inserisci eta: ");
		scanf("%d", &studenti[i].eta);
	}

	printf("inserisci matricola da modificare: ");
	scanf("%s", matricola);

	int pos = cerca(matricola, studenti);


	if(pos>=0)	{
		
		printf("inserisci il nuovo nome: ");
		scanf("%s", studenti[pos].nome);
		
		printf("inserisci la nuova eta: ");
		scanf("%d", &studenti[pos].eta);
		
		printf("studente modificato");
		
	}else{
		printf("Studente non trovato\n");
	}



	return 0;
}
