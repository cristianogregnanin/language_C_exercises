/*Una birreria a fine serata deve conteggiare l’incasso. La cassiera accende il software gestionale
il quale le chiede di inserire una alla volta le consumazioni servite.
Le consumazioni si dividono in bevande e ristorazione. La cassiera per ogni consumazione deve inserire
la tipologia di consumazione e il suo importo.

Quando la cassiera inserisce la stringa “esci” il software deve mostrare a video le seguenti informazioni:
1.	La media dell’incasso delle bevande
2.	La media dell’incasso della ristorazione
3.	Deve indicare se sono state vendute più bevande o più ristorazioni*/
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char inserimento[12];
    float importo, mediaBevande, mediaRistorazioni, sommaBevande = 0, sommaRistorazione = 0;
    int bevande = 0, ristorazione = 0;

    do
    {
        do
        {
            printf("Inserire bevande o una ristorazione. Esci per terminare l'inserimento.\n");
            scanf("%s", inserimento);
        } while (strcmp("esci", inserimento) != 0 && strcmp(inserimento, "bevande") != 0 && strcmp(inserimento, "ristorazione") != 0);
        if (strcmp (inserimento, "esci")==0)
        {
            break;
        }
        do
        {
            printf("Inserire l' importo: \n");
            scanf("%f", &importo);
        } while (importo <= 0);

        if (strcmp(inserimento, "bevande") == 0)
        {
            bevande++;
            sommaBevande = sommaBevande + importo;
        }

        if (strcmp(inserimento, "ristorazione") == 0)
        {
            ristorazione++;
            sommaRistorazione = sommaRistorazione + importo;
        }

    } while (1);
    if (ristorazione > bevande)
    {
        printf("Sono state vendute più ristorazioni\n");
    }
    else
    {
        printf("Sono state vendute più bevande\n");
    }

    mediaBevande = sommaBevande / (float)bevande;
    mediaRistorazioni = sommaRistorazione / (float)ristorazione;

    printf("La media dell'incasso delle bevande è: %f\n", mediaBevande);
    printf("La media dell'incasso delle ristorazioni è: %f\n", mediaRistorazioni);
}