#include <stdio.h>
#include <string.h>

#define DIM 3

typedef struct
{
	char nome[20];
	char matricola[5];
	int eta;

} studente_t;

int cerca(char matricola[], studente_t studenti[])
{

	for (int i = 0; i < DIM; i++)
		if (strcmp(matricola, studenti[i].matricola) == 0)
			return i;
	return -1;
}
studente_t popola()
{
	studente_t studente;
	printf("inserisci matricola: ");
	scanf("%s", studente.matricola);

	printf("inserisci nome: ");
	scanf("%s", studente.nome);

	printf("inserisci eta: ");
	scanf("%d", &studente.eta);
	return studente;
}
void modifica(studente_t studenti[], int pos)
{
	printf("inserisci il nuovo nome: ");
	scanf("%s", studenti[pos].nome);

	printf("inserisci la nuova eta: ");
	scanf("%d", &studenti[pos].eta);

	printf("studente modificato\n");
}
int main(int argc, char *argv[])
{

	char matricola[5];
	int i;
	studente_t studenti[DIM];

	for (i = 0; i < DIM; i++)
	{
		studenti[i] = popola();
	}

	printf("inserisci matricola da modificare: ");
	scanf("%s", matricola);

	int pos = cerca(matricola, studenti);

	if (pos >= 0)
	{
		modifica(studenti, pos);
		for (i = 0; i < DIM; i++)
		{
			printf("%s\n", studenti[i].matricola);
			printf("%s\n", studenti[i].nome);
			printf("%d\n\n", studenti[i].eta);
		}
	}
	else
	{
		printf("Studente non trovato\n");
	}

	return 0;
}
