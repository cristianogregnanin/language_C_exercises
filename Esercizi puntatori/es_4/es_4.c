#include <stdio.h>
#include <limits.h>

void popola(int array[], int * n){	
	int valore;
	do{
		printf("inserisci un valore. Premi -1 per terminare l'inserimento\n");	
		scanf("%d", &valore);
		if(valore!=-1){
			array[*n] = valore;
			++(*n);
		}
	}while(valore!=-1);
}

void stampa(int array[], int n){	
	int i;
	for(i=0;i<n;i++)	
		printf("Il valore è: %d\n", array[i]);

}

int ricerca(int array[], int n){
	
	int numero, posizione = -1, i;
	printf("inserisci il numero da cercare: ");
	scanf("%d", &numero);
	
	for(i=0;i<n;i++){
		if (array[i] == numero ){
			printf("il numero ricercato si trova in posizione: %d", i);
			posizione = i;
			break;
		}
	}
		
	return posizione;
}
	
	
	
void esegui_operazione(int s, int a[], int n){
		
	if(s==1)
		stampa(a,n);
	if(s==2)
		//inserisci(a,n);
	if(s==3)
		//modifica(a,n);	
	if(s==4)
		//elimina(a,n);	
	if(s==5)
		ricerca(a,n);	
			
}	
	
void menu(int array[], int n){

	int scelta;
	
	printf("\npremere 1 per mostrare il contenuto dell'array\n");
	printf("premere 2 per inserire un elemento\n");
	printf("premere 3 per modificare un elemento\n");
	printf("premere 4 per eliminare un elemento\n");
	printf("premere 5 per ricercare un elemento\n");		
	
	scanf("%d", &scelta);
	
	esegui_operazione(scelta,array,n);
	
}


int main(){
	
	int array[SHRT_MAX];
	int n,scelta = 1;
	
	popola(array, &n);
	
	while(scelta!=0){
		menu(array,n);
		printf("\n\npremi 0 per uscire oppure 1 per continuare ");
		scanf("%d", &scelta);
	}
	
	printf("\n\n\nprogramma terminato\n\n");
	return 0;
}
