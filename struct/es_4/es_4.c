#include <stdio.h>
#include <string.h>
#define DIM 5

typedef struct
{
	char nome[20];
	char ruolo[20];
	char squadra[20];
} calciatore_t;

int main(int argc, char *argv[])
{

	calciatore_t calciatori[DIM];

	int i;

	for (i = 0; i < DIM; i++)
	{
		printf("Inserisci il nome del calciatore\n");
		scanf("%s", calciatori[i].nome);

		printf("Inserisci il ruolo del calciatore\n");
		scanf("%s", calciatori[i].ruolo);

		printf("Inserisci la squadra del calciatore\n");
		scanf("%s", calciatori[i].squadra);
	}

	printf("Calciatori appartenenti al milan:\n");
	for (i = 0; i < DIM; i++)
		if (strcmp(calciatori[i].squadra, "milan") == 0)
			printf("\t%s\n", calciatori[i].nome);

	printf("Calciatori il cui nome inizia per 'c':\n");
	for (i = 0; i < DIM; i++)
		if (calciatori[i].nome[0] == 'c')
			printf("\t%s\n", calciatori[i].nome);
}
