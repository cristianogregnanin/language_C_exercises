// Una birreria a fine serata deve conteggiare l’incasso. La cassiera accende il software gestionale il quale le chiede di inserire una alla volta le consumazioni servite.
// Le consumazioni si dividono in bevande e ristorazione. La cassiera per ogni consumazione deve inserire la tipologia di consumazione e il suo importo.

// Quando la cassiera inserisce la stringa “esci” il software deve mostrare a video le seguenti informazioni:
// 1.	La media dell’incasso delle bevande
// 2.	La media dell’incasso della ristorazione
// 3.	Deve indicare se sono state vendute più bevande o più ristorazioni
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    // bevanda + soldi, ristorazione + soldi
    char bevRist[20]; // bisogna definire la lunghezza
    char risposta[20];
    int importoB = 0, importoR = 0,mediaB=0,mediaR=0,totR=0,totB=0,j=0,i=0;
    ;
    do
    {
        printf("Bevanda o ristoriazione?\n");
            scanf("%s", &bevRist);
        if (strcmp(bevRist,"Bevanda") == 0)
        {
            printf("Inserisci l'importo\n");
            scanf("%d", &importoB);
            i++;//contatore bevande
            totB=totB+importoB;
        }
        else if (strcmp(bevRist,"Ristorazione") == 0)
        {
            printf("Inserisci l'importo\n");
            scanf("%d", &importoR);
            j++;//contatore ristorazione
            totR=totR+importoR;
        }
        else
        {
            printf("errore\n");
        }
        printf("Se hai finito scrivi 'esci'\n");
        scanf("%s", &risposta);
    } while (strcmp(risposta,"esci") != 0);
    mediaB=totB+i;
    mediaR=totR+i;
    printf("La media delle bevande è: %d\n",mediaB);
    printf("La media della ristorazione è: %d\n",mediaR);
    if (i>j)
    {
        printf("Sono state inserite più bevande");
    }
    else
    {
        printf("Sono state inserite più ristorazioni");
    }
    
    return 0;
}