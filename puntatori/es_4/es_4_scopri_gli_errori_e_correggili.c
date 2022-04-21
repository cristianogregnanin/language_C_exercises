#include <stdio.h>
#include <limits.h>

int popola(int numeri[])
{
	int valore = 0, n = 0;
	while (1)
	{
		scanf("%d", &valore);
		if (valore == -1)
		{
			return n;
		}

		numeri[n] = valore;
		n++;
	}
}

void stampa(int array[], int n)
{
	for (int i = 0; i < n; i++)
		printf("Il valore in posizione %d è: %d\n", i, array[i]);
}

void stampa_inversa(int array[], int n)
{
	for (int i = n - 1; i >= 0; i--)
		printf("Il valore in posizione %d è: %d\n", i, array[i]);
}

int ricerca(int array[], int n, int valore)
{
	for (int i = 0; i < n; i++)
	{
		if (array[i] == valore)
		{
			return i;
		}
	}

	return -1;
}

void inserisci_in_posizione(int array[], int *n, int posizione, int valore)
{

	(*n)++;
	for (int i = *n; i > posizione; i--)
	{
		array[i] = array[i - 1];
	}
	array[posizione] = valore;
}

int inserisci_in_coda(int array[], int *n, int numero)
{
	array[*n] = numero;
	(*n)++;
	return *n;
}

void modifica(int array[], int posizione, int valore)
{

	array[posizione] = valore;
}

void elimina(int array[], int *n, int posizione)
{

	for (int i = posizione; i < *n; i++)
	{
		array[i] = array[i + 1];
	}
	(*n)--;
}

void esegui_operazione(int s, int numeri[], int *n)
{

	if (s == 1)
	{
		stampa(numeri, *n);
	}
	else if (s == 2)
	{
		int numero, posizione;
		printf("inserisci un numero: ");
		scanf("%d", &numero);
		posizione = inserisci_in_coda(numeri, n, numero);
		printf("Valore inserito in posizione: %d", posizione);
	}
	else if (s == 3)
	{
		int valore, posizione;
		printf("Inserisci il valore da sostituire: ");
		scanf("%d", &valore);
		posizione = ricerca(numeri, *n, valore);
		if (posizione > -1)
		{
			printf("Inserisci il nuovo valore: ");
			scanf("%d", &valore);
			modifica(numeri, posizione, valore);
		}
		else
		{
			printf("valore non esistente");
		}
	}
	else if (s == 4)
	{
		int valore, posizione;
		printf("Inserisci il valore da eliminare: ");
		scanf("%d", &valore);
		posizione = ricerca(numeri, *n, valore);
		if (posizione > -1)
		{
			elimina(numeri, n, posizione);
		}
		else
		{
			printf("valore non esistente");
		}
	}
	else if (s == 5)
	{
		int posizione, valore;
		printf("Inserisci il valore da ricercare: ");
		scanf("%d", &valore);
		posizione = ricerca(numeri, *n, valore);
		if (posizione > -1)
		{
			printf("valore trovato in posizione %d", posizione);
		}
		else
		{
			printf("valore non esistente");
		}
	}
	else if (s == 6)
	{
		int valore, posizione;
		printf("Inserisci il valore da aggiungere: ");
		scanf("%d", &valore);
		printf("Inserisci la posizione: ");
		scanf("%d", &posizione);

		if (posizione < *n)
		{
			inserisci_in_posizione(numeri, n, posizione, valore);
		}
		else
		{
			printf("valore non esistente");
		}
	}
	else if (s == 7)
	{
		stampa_inversa(numeri, *n);
	}
}

int menu(int scelta)
{
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
	printf("Inserisci una serie di valori. Per terminare l'inserimento inserisci -1\n");
	int scelta, numeri[SHRT_MAX], n = popola(numeri);

	while (1)
	{
		scelta = menu(scelta);

		if (scelta == 0)
		{
			printf("\tProgramma terminato\n");
			return 0;
		}
		esegui_operazione(scelta, numeri, &n);
	}
}
