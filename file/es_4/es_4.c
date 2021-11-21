#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DIM 100

typedef struct
{
    char nome[DIM];
    char cognome[DIM];
    char numero[DIM];
} Persona_t;

void LeggiFile(char *argv[], Persona_t persone[], int *i)
{
    FILE *file;

    file = fopen(argv[1], "r");
    *i = 0;
    Persona_t persona;
    while ((fscanf(file, "%s %s %s", persona.nome, persona.cognome, persona.numero)) != EOF)
    {
        persone[(*i)] = persona;
        (*i)++;
    }
    fclose(file);
}

void StampaLista(Persona_t persone[], int dim)
{
    Persona_t persona;
    for (int i = 0; i < dim; i++)
    {
        persona = persone[i];
        printf("%s %s %s\n", persona.nome, persona.cognome, persona.numero);
    }
}

void AggiungiContatto(Persona_t persone[], int *dim)
{
    Persona_t persona;
    printf("inserisci il nome\n");
    scanf("%s", persona.nome);
    printf("inserisci il cognome\n");
    scanf("%s", persona.cognome);
    printf("inserisci il numero\n");
    scanf("%s", persona.numero);
    persone[*dim] = persona;
    (*dim)++;
    printf("persona aggiunta correttamente\n");
}

void Scrivi(Persona_t persone[], int dim, char output[])
{
    FILE *stream = fopen(output, "w");
    Persona_t persona;
    for (int i = 0; i < dim; i++)
    {
        persona = persone[i];
        fprintf(stream, "%s %s %s\n", persona.nome, persona.cognome, persona.numero);
    }
    fclose(stream);
}

void EliminaContatto(Persona_t persone[], int *dim, char output[])
{
    char numero[DIM];
    StampaLista(persone, *dim);
    printf("scrivi il numero della persona da cancellare\n");
    scanf("%s", numero);
    Persona_t persona;
    for (int i = 0; i < *dim; i++)
    {
        persona = persone[i];
        if (strcmp(persona.numero, numero) == 0)
        {
            for (int j = i; j < (*dim) - 1; j++)
                persone[j] = persone[j + 1];
            (*dim)--;
            printf("il contato è stato eliminato\n");
        }
    }
}

int main(int argc, char *argv[])
{

    Persona_t lista[DIM];
    char output[DIM];
    int scelta, dim = 0;

    if (argc != 2 && argc != 4)
    {
        printf("Errore argomenti\n");
        exit(1);
    }

    if ((argc == 4) && (strcmp(argv[2], "-f") != 0))
    {
        printf("Errore argomenti\n");
        exit(1);
    }

    if (argc == 4)
        strcpy(output, argv[3]);
    else
        strcpy(output, argv[1]);

    LeggiFile(argv, lista, &dim);

    do
    {

        printf("\nsegli l'azione da eseguire:\n\n1) mostrare la rubrica a video\n2) aggiungere un contatto alla rubrica\n3) eliminare un contatto dalla rubrica dopo averlo ricercato con il suo numero di telefono\n0)esci\n\n");
        scanf("%d", &scelta);
        switch (scelta)
        {
        case 1:
            StampaLista(lista, dim);
            break;
        case 2:
            AggiungiContatto(lista, &dim);
            Scrivi(lista, dim, output);
            break;
        case 3:
            EliminaContatto(lista, &dim, output);
            Scrivi(lista, dim, output);
            break;
        case 0:
            exit(1);
        }
    } while (scelta != 0);

    return 0;
}
