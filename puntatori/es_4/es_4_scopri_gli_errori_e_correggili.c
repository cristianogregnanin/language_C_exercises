#include <stdio.h>
#include <limits.h>

int popola(int numeri[],int *n)
{
	int valore = 0;
	printf("inserisci un valore. Premi -1 per terminare l'inserimento\n");
	while(valore != -1)
	{
		scanf("%d", &valore);
		if(valore != -1)
		{numeri[*n] = valore;
		(*n)++;
	} 
	}
	return *n;
}

void stampa(int array[], int **n)
{
    int i;
	for ( i = 0; i < **n ;i++)
		printf("Il valore in posizione %d è: %d\n", i, array[i]);
}

void stampa_inversa(int array[], int **n)
{
    int p= **n;
	for (int i = (**n)-1; i >= 0; i--)
		printf("Il valore in posizione %d è: %d\n", i, array[i]);
}

int ricerca(int array[], int **n, int *valore)
{
int i;
	for ( i = 0; i < **n; i++)
	{
		if (array[i] == *valore)
		{
			return i; 
		}
	}

	return -1;
}

int inserisci_in_posizione(int array[], int **n, int *posizione, int *valore)
{

	(**n)++;
	for (int i = **n; i > *posizione; i--)
	{
		array[i] = array[i - 1];
	}
	array[*posizione] = *valore;
	return *posizione;
}

int inserisci_in_coda(int array[], int **n, int *numero)
{

	
	array[**n] = *numero;
	(**n)++;
	return **n;
}

int modifica(int array[], int *posizione, int *valore)
{

	array[*posizione] = *valore;
	return *posizione;
}

int elimina(int array[], int **n, int *posizione)
{
 int i;
 
 if(array[(*posizione)+1] == 0 )
  array[*posizione] = 0;
 else
{	for ( i = (*posizione); i <= **n; i++)
	{
		array[i] = array[i + 1];
	}
}
	(**n)--;
	return *posizione;
}

void esegui_operazione(int *s, int numeri[], int *n)
{

switch(*s)
	{
	 case 1:
		stampa(numeri, &n);break;
	
	 case 2:
	{	int numero, posizione;
		printf("\ninserisci un numero:\n");
		scanf("%d", &numero);
		posizione = inserisci_in_coda(numeri,&n, &numero);
		printf("\nValore inserito in posizione: %d", posizione);
	}break;
	 case 3:
	{	int valore, posizione;
		printf("\nInserisci il valore da sostituire:\n ");
		scanf("%d", &valore);

		if ((posizione = ricerca(numeri, &n, &valore)) > 0)
		{
			printf("\nInserisci il nuovo valore:\n ");
			scanf("%d", &valore);
			modifica(numeri, &posizione, &valore);
		}
		else
		{
			printf("\nvalore non esistente\n");
		}
	}break;
	 case 4:
	{	int valore, posizione;
		printf("\nInserisci il valore da eliminare: \n");
		scanf("%d", &valore);

		if (posizione = ricerca(numeri, &n, &valore) > -1)
		{
			elimina(numeri, &n, &posizione);
		}
		else
		{
			printf("\nvalore non esistente\n");
		}
	}break;
	 case 5:
	{	int posizione, valore;
		printf("Inserisci il valore da ricercare: ");
		scanf("%d", &valore);
		if (posizione = ricerca(numeri, &n, &valore) > -1)
		{
			printf("\nvalore trovato in posizione %d", posizione);
		}
		else
		{
			printf("\nvalore non esistente\n");
		}   
	}break;
	 case 6:
	{	int valore, posizione;
		printf("\nInserisci il valore da aggiungere:\n ");
		scanf("%d", &valore);
		printf("\nInserisci la posizione:\n ");
		scanf("%d", &posizione);

		if (posizione < *n)
		{
			inserisci_in_posizione(numeri, &n, &posizione, &valore);
		}
		else
		{
			printf("\nvalore non esistente\n");
		}
	    
	}break;
	 case 7:
		stampa_inversa(numeri, &n); break;
	
	}
}
int menu()
{
	int scelta;

	printf("\n\npremere 1 per mostrare il contenuto dell'array\n");
	printf("premere 2 per inserire un elemento in coda\n");
	printf("premere 3 per modificare un elemento\n");
	printf("premere 4 per eliminare un elemento\n");
	printf("premere 5 per ricercare un elemento\n");
	printf("premere 6 per inserire un elemento in una certa posizione\n");
	printf("premere 7 per mostrare il contenuto dell'array all'inverso\n");
	printf("premere 0 per terminare\n");

	scanf("%d", &scelta);

	return scelta;
}
int main(int argc, char *argv[])
{
	int scelta = 1, numeri[SHRT_MAX], n = 0;
n = popola(numeri, &n);
	do 
	{
		scelta = menu();
		esegui_operazione(&scelta, numeri, &n);
	}while (scelta != 0);
	
	printf("\nprogramma terminato\n");
			return 0;
}
