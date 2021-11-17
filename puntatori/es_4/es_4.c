#include <stdio.h>
#include <limits.h>

void popola(int array[], int *n)
{
	int valore;
	do
	{
		printf("inserisci un valore. Premi -1 per terminare l'inserimento\n");
		scanf("%d", &valore);
		if (valore != -1)
		{
			array[*n] = valore;
			++(*n);
		}
	} while (valore != -1);
}

void stampa(int array[], int ***n)
{
	int i;
	for (i = 0; i < (***n); i++)
		printf("Il valore è: %d\n", array[i]);
}

void stampa_inversa(int array[], int ***n)
{
	int i;
	(***n)--;
	for (i = ***n; i >= 0; i--)
		printf("Il valore è: %d\n", array[i]);
}

int ricerca(int array[], int ***n)
{

	int numero, posizione = -1, i;
	printf("inserisci il numero: ");
	scanf("%d", &numero);

	for (i = 0; i < (***n); i++)
	{
		if (array[i] == numero)
		{
			printf("il numero ricercato si trova in posizione: %d\n", i);
			posizione = i;
			break;
		}
	}

	return posizione;
}

void inserisci_in_posizione(int array[], int ***n)
{

	int numero, posizione, i;
	printf("inserisci un numero: ");
	scanf("%d", &numero);

	do
	{
		printf("inserisci la posizione: ");
		scanf("%d", &posizione);
	} while (posizione > ***n);

	(***n)++;
	for (i = (***n); i > posizione; i--)
	{
		array[i] = array[i - 1];
	}
	array[posizione] = numero;
	printf("il numero %d è stato inserito in posizione %d\n", numero, posizione);
}

void inserisci_in_coda(int array[], int ***n)
{

	int numero, posizione;
	printf("inserisci un numero: ");
	scanf("%d", &numero);
	posizione = (***n)++;
	array[posizione] = numero;
	printf("Valore inserito in posizione: %d", posizione);
}

void modifica(int array[], int ***n)
{

	int nuovo_valore;
	int posizione = ricerca(array, &(*n));
	if (posizione > 0)
	{
		printf("Inserisci il nuovo valore: ");
		scanf("%d", &nuovo_valore);
		array[posizione] = nuovo_valore;
		printf("valore modificato");
	}
	else
	{
		printf("Il valore non esiste.");
	}
}

void elimina(int array[], int ***n)
{
	int posizione = ricerca(array, *(&n));

	if (posizione > 0)
	{
		int i;
		for (i = posizione; i < (***n); i++)
		{
			array[i] = array[i + 1];
		}
		(***n)--;
	}
	else
	{
		printf("Il numero che vuoi eliminare non esiste.");
	}
}
void esegui_operazione(int s, int a[], int **n)
{

	if (s == 1)
		stampa(a, &n);
	if (s == 2)
		inserisci_in_coda(a, &n);
	if (s == 3)
		modifica(a, &n);
	if (s == 4)
		elimina(a, &n);
	if (s == 5)
		ricerca(a, &n);
	if (s == 6)
		inserisci_in_posizione(a, &n);
	if (s == 7)
		stampa_inversa(a, &n);
}

void menu(int array[], int *n)
{

	int scelta;

	printf("\npremere 1 per mostrare il contenuto dell'array\n");
	printf("premere 2 per inserire un elemento in coda\n");
	printf("premere 3 per modificare un elemento\n");
	printf("premere 4 per eliminare un elemento\n");
	printf("premere 5 per ricercare un elemento\n");
	printf("premere 6 per inserire un elemento in una certa posizione\n");
	printf("premere 7 per mostrare il contenuto dell'array all'inverso\n");

	scanf("%d", &scelta);

	esegui_operazione(scelta, array, &n);
}

int main()
{

	int array[SHRT_MAX];
	int n, scelta = 1;

	popola(array, &n);

	while (scelta != 0)
	{
		menu(array, &n);
		printf("\n\npremi 0 per uscire oppure 1 per continuare ");
		scanf("%d", &scelta);
	}

	printf("\n\n\nprogramma terminato\n\n");

	return 0;
}
