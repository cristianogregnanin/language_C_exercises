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
    char tipo[12];
    double importo, mediaB, mediaR, sommaB = 0, sommaR = 0;
    int bevande = 0, ristorazione = 0;

    do
    {
        do
        {
            printf("Inserisci la tipologia: \n");
            scanf("%s",& tipo);
        } while (strcmp("esci", tipo) != 0 && strcmp(tipo, "bevande") != 0 && strcmp(tipo, "ristorazione") != 0);

        do
        {
            printf("Inserisci l' importo: \n");
            scanf("%f", &importo);
        } while (importo <= 0);

        if (strcmp(tipo, "bevande") == 0)
        {
            bevande++;
            sommaB = sommaB + importo;
        }

        if (strcmp(tipo, "ristorazione") == 0)
        {
            ristorazione++;
            sommaR = sommaR + importo;
        }

    } while (strcmp("esci", tipo) != 0);

    if (ristorazione > bevande)
    {
        printf("Sono state vendute più ristorazioni");
    }
    else
    {
        printf("Sono state vendute più bevande");
    }

    mediaB = sommaB / (double)bevande;
    mediaR = sommaR / (double)ristorazione;

    printf("La media delle bevande è: %f\n", mediaB);
    printf("La media delle ristorazioni è: %f\n", mediaR);
}
