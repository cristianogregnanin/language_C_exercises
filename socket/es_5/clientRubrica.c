#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define NOME_LENGHT 21
#define COGNOME_LENGHT 21
#define TELEFONO_LENGHT 11
#define MAX_LENGHT 100

typedef struct
{
	char nome[NOME_LENGHT];
	char cognome[COGNOME_LENGHT];
	char telefono[TELEFONO_LENGHT];
} Contatto_t;

int LeggiFile(char nomeFile[], int *numContatti, Contatto_t contatti[])
{
	FILE *stream;
	if ((stream = fopen(nomeFile, "r")) == NULL)
	{
		exit(1);
	}

	for (int i = 0; !feof(stream); i++)
	{
		fscanf(stream, "%s %s %s\n", contatti[*numContatti].nome, contatti[*numContatti].cognome, contatti[*numContatti].telefono);
		(*numContatti)++;
	}

	fclose(stream);

	return 0;
}

void Visualizza(Contatto_t contatti[], int num)
{

	for (int i = 0; i < num; i++)
	{
		printf("%s %s %s\n", contatti[i].nome, contatti[i].cognome, contatti[i].telefono);
	}
}

void ScriviFile(char nomeFile[], Contatto_t contatti[], int num)
{
	FILE *stream;

	if ((stream = fopen(nomeFile, "w")) == NULL)
	{
		printf("errore nell'apertura del file output");
		exit(0);
	}
	for (int i = 0; i < num; i++)
	{
		fprintf(stream, "%s %s %s\n", contatti[i].nome, contatti[i].cognome, contatti[i].telefono);
	}
	fclose(stream);
}

int main(int argc, char *argv[])
{
	if (argc != 5)
	{
		printf("Argomenti errati!");
		exit(0);
	}

	struct sockaddr_in server_addr;
	int nread, socketfd, numContatti = 0;

	Contatto_t contatti[MAX_LENGHT];
	char nome[MAX_LENGHT], cognome[MAX_LENGHT], telefono[MAX_LENGHT];

	LeggiFile(argv[3], &numContatti, contatti);

	memset((char *)&server_addr, 0, sizeof(server_addr));

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);

	socketfd = socket(AF_INET, SOCK_STREAM, 0);

	connect(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

	write(socketfd, &numContatti, sizeof(numContatti));
	write(socketfd, contatti, sizeof(contatti));

	nread = read(socketfd, contatti, sizeof(contatti));

	close(socketfd);

	Visualizza(contatti, numContatti);

	ScriviFile(argv[4], contatti, numContatti);

	return 0;
}
