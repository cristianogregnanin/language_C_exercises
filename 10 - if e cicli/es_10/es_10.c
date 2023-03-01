#include <stdio.h>
#include <string.h>
int main()
{
    char ope[20];
    float input, mediab = 0, mediar = 0, sommab = 0, sommar = 0;
    int contb = 0, contr = 0;
    do
    {
        printf("inserisci la tipologia\n");
        scanf("%s", ope);
        if (strcmp(ope, "bevande") == 0)
        {
            printf("inserisci l'importo\n");
            scanf("%f", &input);
            sommab = sommab + input;
            contb++;
        }
        else if (strcmp(ope, "ristorazione") == 0)
        {
            printf("inserisci l'importo\n");
            scanf("%f", &input);
            sommar = sommar + input;
            contr++;
        }
        else if (strcmp(ope, "esci") != 0)
        {
            printf("operazione non valido\n");
        }
    } while (strcmp(ope, "esci") != 0);
    mediab = sommab / contb;
    mediar = sommar / contr;
    printf("la media dell'incasso delle bevande vendute: %f\n", mediab);
    printf("la media dell'incasso delle ristorazione vendute: %f\n", mediab);
    if (contb == contr)
    {
        printf("sono stati venduti uguali\n");
    }
    else if (contb < contr)
    {
        printf("sono state vendute piu ristorazioni\n");
    }
    else
    {
        printf("sono state vendute più bevande\n");
    }
}