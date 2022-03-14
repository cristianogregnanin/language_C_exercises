#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXCHAR 80
#define DELIMITATORE " "

typedef struct
{
	char nome[20];
	char cognome[20];
	int eta;

} studente_t;

studente_t calcola_vecchio(studente_t studenti[], int n)
{
	int i, max = studenti[0].eta;
	studente_t studente;
	for (i = 1; i < n; i++)
		if (max < studenti[i].eta)
			studente = studenti[i];

	return studente;
}

double calcola_media(studente_t studenti[], int n)
{
	int i, somma = 0;

	for (i = 0; i < n; i++)
		somma = somma + studenti[i].eta;

	return (double)somma / (double)i;
}

int main(int argc, char *argv[])
{
	FILE *fd;
	char str[MAXCHAR], nome[20], *token;
	int eta, i = 0;
	studente_t studente, studenti[5], vecchio;
	double media;

	printf("sono presenti %d argomenti\n\n", argc);
	printf("il nome del programma in esecuzione è: %s\n\n", argv[0]);
	printf("il nome del file da leggere è: %s\n\n", argv[1]);

	fd = fopen(argv[1], "r");

	while (fgets(str, MAXCHAR, fd) != NULL)
	{

		token = strtok(str, DELIMITATORE);
		strcpy(studente.nome, token);

		token = strtok(NULL, DELIMITATORE);
		strcpy(studente.cognome, token);

		token = strtok(NULL, DELIMITATORE);
		studente.eta = atoi(token);

		studenti[i] = studente;
		i++;
	}

	fclose(fd);

	vecchio = calcola_vecchio(studenti, i);
	media = calcola_media(studenti, i);

	printf("Lo studente piu vecchio è: %s\n", vecchio.nome);
	printf("La media delle eta è: %f\n\n", media);

	return 0;
}
