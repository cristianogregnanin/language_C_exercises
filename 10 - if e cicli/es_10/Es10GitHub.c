/*Una birreria a fine serata deve conteggiare l’incasso.
La cassiera accende il software gestionale il quale le chiede di inserire una alla volta le consumazioni servite.
Le consumazioni si dividono in bevande e ristorazione. La cassiera per ogni consumazione deve inserire la tipologia di consumazione e il suo importo.
Quando la cassiera inserisce la stringa “esci” il software deve mostrare a video le seguenti informazioni:
1.	La media dell’incasso delle bevande
2.	La media dell’incasso della ristorazione
3.	Deve indicare se sono state vendute più bevande o più ristorazioni*/
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