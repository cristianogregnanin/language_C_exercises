#include <stdio.h>
#include <string.h>
#define DIM 5

typedef struct
{
    char nome[20];
    char ruolo[20];
    char squadra[20];
} calciatore_t;

calciatore_t crea_calciatore()
{
    calciatore_t calciatore;
    printf("Inserisci il nome del calciatore\n");
    scanf("%s", calciatore.nome);

    printf("Inserisci il ruolo del calciatore\n");
    scanf("%s", calciatore.ruolo);

    printf("Inserisci la squadra del calciatore\n");
    scanf("%s", calciatore.squadra);

    return calciatore;
}
void stampa_squadra(calciatore_t calciatori[], char squadra[])
{
    for (int i = 0; i < DIM; i++)
        if (strcmp(calciatori[i].squadra, squadra) == 0)
            printf("\t%s\n", calciatori[i].nome);
}
void stampa_calciatori(calciatore_t calciatori[], char carattere)
{
    for (int i = 0; i < DIM; i++)
        if (calciatori[i].nome[0] == carattere)
            printf("\t%s\n", calciatori[i].nome);
}
int main(int argc, char *argv[])
{

    calciatore_t calciatori[DIM];
    for (int j = 0; j < DIM; j++)
    {
        calciatori[j] = crea_calciatore();
    }

    printf("Calciatori appartenenti al milan:\n");
    stampa_squadra(calciatori, "milan");

    printf("Calciatori il cui nome inizia per 'c':\n");
    stampa_calciatori(calciatori, 'c');

    return 0;
}
