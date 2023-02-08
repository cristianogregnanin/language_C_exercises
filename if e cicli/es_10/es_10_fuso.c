#include <stdio.h>
#include <string.h>

/*
    Una birreria a fine serata deve conteggiare l’incasso. La cassiera accende il software gestionale il quale le chiede di inserire una alla volta le consumazioni servite.
    Le consumazioni si dividono in bevande e ristorazione. La cassiera per ogni consumazione deve inserire la tipologia di consumazione e il suo importo.

    Quando la cassiera inserisce la stringa “esci” il software deve mostrare a video le seguenti informazioni:
    1.	La media dell’incasso delle bevande
    2.	La media dell’incasso della ristorazione
    3.	Deve indicare se sono state vendute più bevande o più ristorazioni
*/

int main(int argc, char *argv[])
{
    float sommaBevande = 0, sommaRistorazione = 0, num, media;
    int iBevande = 0, iRistorazione = 0;
    char string[100];
    printf("Benvenuta al software gestionale. Inserisci una alla volta le consumazioni.\n");
    while (1)
    {
        printf("Inserisci la tipologia (bevande, ristorazione) o esci: ");
        scanf("%s", string);
        while (strcmp(string, "bevande") != 0 && strcmp(string, "ristorazione") != 0 && strcmp(string, "esci") != 0)
        {
            printf("Non conosco questa categoria, reinserisci: ");
            scanf("%s", string);
        }
        if (strcmp(string, "esci") == 0)
        {
            break;
        }
        printf("Inserisci l'importo: ");
        scanf("%f", &num);
        while (num <= 0)
        {
            printf("Non puoi inserire un numero negativo o nullo. Reinserisci: ");
            scanf("%f", &num);
        }

        if (strcmp(string, "bevande") == 0)
        {
            sommaBevande += num;
            iBevande++;
        }
        else
        {
            sommaRistorazione += num;
            iRistorazione++;
        }
    }
    if (iBevande + iRistorazione == 0)
    {
        printf("Non hai inserito articoli.\n");
    }
    else
    {
        printf("Degli articoli che hai inserito:\n");
        if (iRistorazione == 0 || iBevande == 0)
        {
            if (iRistorazione == 0)
            {
                printf("- Non hai inserito incassi da ristorazione.\n");
            }
            else
            {
                media = sommaRistorazione / (float)iRistorazione;
                printf("- La media dell'incasso della ristorazione è %.2f\n", media);
            }
            if (iBevande == 0)
            {
                printf("- Non hai inserito incassi da bevande.\n");
            }
            else
            {
                media = sommaBevande / (float)iBevande;
                printf("- La media dell'incasso delle bevande è %.2f\n", media);
            }
        }
        else
        {
            if (iBevande == iRistorazione)
            {
                printf("- Sono state vendute a pari numero bevande e ristorazioni\n");
            }
            else if (iBevande > iRistorazione)
            {
                printf("- Sono state venute più bevande\n");
            }
            else
            {
                printf("- Sono state ventute più consumazioni\n");
            }
        }
    }
    return 0;
}
