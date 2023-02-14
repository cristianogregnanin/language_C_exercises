/*Una birreria a fine serata deve conteggiare l’incasso. La cassiera accende il software gestionale il quale le chiede di inserire una alla volta le consumazioni servite.
Le consumazioni si dividono in bevande e ristorazione. La cassiera per ogni consumazione deve inserire la tipologia di consumazione e il suo importo.

Quando la cassiera inserisce la stringa “esci” il software deve mostrare a video le seguenti informazioni:
1.	La media dell’incasso delle bevande
2.	La media dell’incasso della ristorazione
3.	Deve indicare se sono state vendute più bevande o più ristorazioni*/
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char tipologia[20];
    int bevande, sommaBevande = 0, ristorazione, sommaRistorazione = 0, cont1 = 0, cont2 = 0;
    float mediaBevande = 0, mediaRistorazione = 0;
    do
    {
        printf("Inserisci la tipologia del consumo\n");
        scanf("%s", tipologia);
        if (strcmp(tipologia, "bevande") == 0)
        {
            printf("Inserisci l'importo delle bevande\n");
            scanf("%d", &bevande);
            sommaBevande = sommaBevande + bevande;
            cont1++;
        }
        else
        {
            if (strcmp(tipologia, "ristorazione") == 0)
            {
                printf("Inserisci l'importo delle ristorazioni\n");
                scanf("%d", &ristorazione);
                sommaRistorazione = sommaRistorazione + ristorazione;
                cont2++;
            }
            else
            {
                printf("Hai inserito una tipologia errata\n");
            }
        }
    } while (strcmp(tipologia, "esci") != 0);
    if (cont1 != 0)
    {
        mediaBevande = sommaBevande / cont1;
        printf("La media delle bevande sono: %f\n", mediaBevande);
    }
    else
    {
        printf("Non hai comprato le bevande\n");
    }
    if (cont2 != 0)
    {
        mediaRistorazione = sommaRistorazione / cont2;
        printf("La media delle ristorazioni sono: %f\n", mediaRistorazione);
    }
    else
    {
        printf("Non hai comprato le ristorazioni\n");
    }
    if (mediaBevande > mediaRistorazione)
    {
        printf("è piu venduto la bevanta\n");
    }
    else
    {
        if (mediaRistorazione > mediaBevande)
        {
            printf("è piu venduto la ristorazione\n");
        }
        else
        {
            printf("il guadagno è uguale\n");
        }
    }
}