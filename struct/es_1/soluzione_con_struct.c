#include <stdio.h>
#include <string.h>
#define DIM 4


typedef struct{
	int eta;
	char nome[20];
	char cognome[20];
} studente_t;


int older(studente_t a[], int n){
	
	int i,max = a[0].eta, pos;
	studente_t studente;
	
	for(i=1;i<n;i++){
		studente = a[i];
		if (studente.eta>max){
			max = studente.eta;
			pos = i;
		}			
	}	
	return pos;	
}

studente_t crea_studente(){
	
	studente_t studente;

	printf("Inserisci il nome: ");	
	scanf("%s", studente.nome);
	
	printf("Inserisci il cognome: ");	
	scanf("%s", studente.cognome);
	
	printf("Inserisci l'eta: ");	
	scanf("%d", &studente.eta);
	
	return studente;
		
}

int main(){
	
	studente_t studenti[DIM];
	int i;
	
	for(i=0;i<DIM;i++)
		studenti[i] = crea_studente();
	
	int pos = older(studenti, DIM);

	printf("\nIl piu vecchio é: %s %s\n\n", studenti[pos].nome, studenti[pos].cognome);

}
