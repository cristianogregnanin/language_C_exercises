#include <stdio.h>
#include <limits.h>

void popola(int array[], int *n){	
	int valore;
	do{
		printf("inserisci un valore. Premi -1 per terminare l'inserimento\n");	
		scanf("%d", &valore);
		array[*n] = valore;
		*n++;
	}while(valore!=-1);
}

void stampa(int array[], int n){	


}
	
	
	
void esegui_operazione(int s, int a[], int n){
	
	if(s==1)
		stampa(a,n);
	if(s==2)
		inserisci(a,n);
	if(s==3)
		modifica(a,n);	
	if(s==4)
		elimina(a,n);	
	if(s==5)
		ricerca(a,n);	
			
}	
	
void menu(int array[], int n){

	int scelta;
	do{
		printf("premere 1 per mostrare il contenuto dell'array");
		printf("premere 2 per inserire un elemento");
		printf("premere 3 per modificare un elemento");
		printf("premere 4 per eliminare un elemento");
		printf("premere 5 per ricercare un elemento");		
		
		scanf("%d",scelta);
		
		esegui_operazione(scelta,array,n);
	
	} while (scelta != 0)
	


}


int main(){
	
	int array[SHRT_MAX];
	int n;
	
	popola(array, &n);
	
	menu(array,n);
		
	
	printf("programma terminato\n\n");
	return 0;
}
