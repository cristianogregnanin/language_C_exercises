/**
 * @brief Una birreria a fine serata deve conteggiare l’incasso. La cassiera accende il software gestionale il quale le chiede di inserire una alla volta le consumazioni servite.
 * Le consumazioni si dividono in bevande e ristorazione. La cassiera per ogni consumazione deve inserire la tipologia di consumazione e il suo importo.
 *
 * Quando la cassiera inserisce la stringa “esci” il software deve mostrare a video le seguenti informazioni:
 * 1.	La media dell’incasso delle bevande 
 * 2.	La media dell’incasso della ristorazione
 * 3.	Deve indicare se sono state vendute più bevande o più ristorazioni
 * 
 * @param argv Array di stringhe contenente gli argomenti passati attraverso la riga di comando
 * @param argc Numero di argomenti  passati attraverso la riga di comando
 * 
 * @return la funzione restituisce 0
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char tipologia[12];
    double importo, mediaBevande, mediaRistorazioni, sommaBevande = 0, sommaRistorazione = 0;
    int bevande = 0, ristorazione = 0;

    while (1)
    {
        do
        {
            printf("Inserisci la tipologia: \n");
            scanf("%s", tipologia);
        } while (strcmp("esci", tipologia) != 0 && strcmp(tipologia, "bevande") != 0 && strcmp(tipologia, "ristorazione") != 0);

        if (strcmp("esci", tipologia) == 0)
        {
            printf("\nChiusura cassa");
            break;
        }

        do
        {
            printf("Inserisci l' importo: \n");
            scanf("%lf", &importo); //%lf perchè altrimenti il valore letto non viene assegnato alla variabile double
        } while (importo <= 0);

        if (strcmp(tipologia, "bevande") == 0)
        {
            bevande++;
            sommaBevande = sommaBevande + importo;
        }

        if (strcmp(tipologia, "ristorazione") == 0)
        {
            ristorazione++;
            sommaRistorazione = sommaRistorazione + importo;
        }
    }

    if (ristorazione > bevande)
    {
        printf("\n\nSono state vendute più ristorazioni");
    }
    else if (bevande > ristorazione)
    {
        printf("\n\nSono state vendute più bevande");
    }
    else
    {
        printf("\n\nSono state vendute tante bevande quante ristorazioni");
    }

    if (bevande > 0)
    {
        mediaBevande = sommaBevande / (double)bevande;
        printf("\n\nLa media delle bevande è: %f", mediaBevande);
    }
    else
    {
        printf("\n\nMedia non disponibile. Nessuna bevanda acquistata");
    }

    if (ristorazione > 0)
    {
        mediaRistorazioni = sommaRistorazione / (double)ristorazione;
        printf("\nLa media delle ristorazioni è: %f\n", mediaRistorazioni);
    }
    else
    {
        printf("\nMedia non disponibile. Nessuna ristorazione acquistata");
    }

    return 0;
}