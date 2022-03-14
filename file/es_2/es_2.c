#include <stdio.h>
#include <string.h>
#define PERSONE 2

typedef struct
{
	char nome[30];
	int eta;
} persona_t;

persona_t crea_persona()
{

	persona_t persona;
	int i;

	printf("inserisci il nome:\n");
	scanf("%s", persona.nome);

	printf("inserisci l'eta di %s:\n", persona.nome);
	scanf("%d", &persona.eta);

	return persona;
}

persona_t calcola_vecchio(persona_t persone[])
{

	persona_t vecchio;
	int i, max = persone[0].eta;

	for (i = 1; i < PERSONE; i++)
	{
		if (persone[i].eta > max)
		{
			strcpy(vecchio.nome, persone[i].nome);
			vecchio.eta = persone[i].eta;
		}
	}

	return vecchio;
}

int main(int argc, char *argv[])
{

	persona_t persone[PERSONE], persona, vecchio;
	int i;
	FILE *fd;

	for (i = 0; i < PERSONE; i++)
	{
		persone[i] = crea_persona();
	}

	vecchio = calcola_vecchio(persone);

	printf("\nla persona piu vecchia e': %s \n", vecchio.nome);
	printf("la sua eta e': %d \n", vecchio.eta);

	fd = fopen("vecchio.txt", "w");
	fprintf(fd, "%s\t%d\n", vecchio.nome, vecchio.eta);

	fclose(fd);

	return 0;
}
