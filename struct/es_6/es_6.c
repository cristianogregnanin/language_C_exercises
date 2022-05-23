#include <stdio.h>
#define N 3
typedef struct
{
    char nome[20];
    char cognome[20];
    int eta;
} persona_t;
persona_t popola()
{
    persona_t persona;
    printf("Inserisci nome: \n");
    scanf("%s", persona.nome);
    printf("Inserisci cognome: \n");
    scanf("%s", persona.cognome);
    printf("Inserisci età: \n");
    scanf("%d", &persona.eta);
    return persona;
}
persona_t vecchio(persona_t persone[], int n)
{
    int indice_max = 0;
    for (int i = 1; i < n; i++)
    {
        if (persone[indice_max].eta < persone[i].eta)
            indice_max = i;
    }
    return persone[indice_max];
}
int main()
{
    persona_t persone[N];
    for (int i = 0; i < N; i++)
    {
        persone[i] = popola();
    }
    persona_t persona = vecchio(persone, N);
    printf("La persona più vecchia è: %s %s\n", persona.cognome, persona.nome);
    return 0;
}