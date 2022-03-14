#include <stdio.h>
#include <string.h>
#define DIM 4

typedef struct
{
	int eta;
	char nome[20];
	char cognome[20];
} studente_t;

studente_t older(studente_t a[], int n)
{

	int i, max, pos;
	studente_t studente = a[0];

	for (i = 1; i < n; i++)
		if (a[i].eta > studente.eta)
			studente = a[i];

	return studente;
}

studente_t crea_studente()
{

	studente_t studente;

	printf("Inserisci il nome: ");
	scanf("%s", studente.nome);

	printf("Inserisci il cognome: ");
	scanf("%s", studente.cognome);

	printf("Inserisci l'eta: ");
	scanf("%d", &studente.eta);

	return studente;
}

int main(int argc, char *argv[])
{

	studente_t studenti[DIM];
	int i;

	for (i = 0; i < DIM; i++)
		studenti[i] = crea_studente();

	studente_t studente = older(studenti, DIM);

	printf("\nIl piu vecchio é: %s %s\n\n", studente.nome, studente.cognome);
}
