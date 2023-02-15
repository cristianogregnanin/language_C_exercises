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
    float bevanda = 0, ristorazione = 0, importo, importoTot = 0, mediaBev, mediaRist;
    char esci[5], tipoCons[13];
    do
    {
        printf("Inserisci il tipo di consumazione: \n");
        scanf("%s", tipoCons);
        if (strcmp(tipoCons, "bevanda") != 0)
        {
            bevanda++;
        }
        else
        {
            ristorazione++;
        }
        printf("Inserisci l'importo\n");
        scanf("%f", importo);
        importoTot = importoTot + importo;
        printf("Inserisci esci per terminare il programma\n");
        scanf("%s", esci);
    } while (strcmp(esci, "esci") != 0);
    mediaBev = (importoTot) / bevanda;
    mediaRist = (importoTot) / ristorazione;
    printf("La media dell'incasso delle bevande è: %f\n", mediaBev);
    printf("La media dell'incasso della ristorazione è: %f\n", mediaRist);
    if (bevanda > ristorazione)
    {
        printf("Sono state vendute più bevande");
    }
    else
    {
        printf("Sono state vendute più ristorazioni");
    }
    return 0;
}