#include <stdio.h>
#include <string.h> // libreria inclusa per utilizzare le stringhe
int main(int argc, char *argv[])
{
    char consumazione[13];                       // per far inserire la stringa all'utente
    int bevande = 0, ristorazione = 0;           // per fare la media dopo
    int sommaBevande = 0, sommaConsumazioni = 0; // per fare la media del totale
    float prezzoBevanda, prezzoConsumazioni;
    float mediaBevande, mediaRistorazione;
    // inizio ciclo
    do
    {
        // scelta tipo di consumazione
        printf("Scegli tipo consumazione \n");
        scanf("%s", &consumazione); // inserimento della stringa
        // per terminare ciclo
        if (strcmp(consumazione, "esci") == 0)
        {
            break;
        }
        // nel caso non abbia scritto "esci"
        else
        {
            // scelta bevande
            if (strcmp(consumazione, "bevande") == 0)
            {
                bevande++; // per fare la media

                do
                {
                    printf("Inserire prezzo della bevanda \n");
                    scanf("%f", &prezzoBevanda); // inserimetno prezzo della bevanda
                } while (prezzoBevanda <= 0);
                sommaBevande = prezzoBevanda + sommaBevande; // calcolo totale dei prezzi
            }
            // scelta ristorazione
            else if (strcmp(consumazione, "ristorazione") == 0)
            {
                ristorazione++; // per fare la media
                do
                {
                    printf("Inserire prezzo del piatto \n");
                    scanf("%f", &prezzoConsumazioni); // inserimento prezzo del piatto
                } while (prezzoConsumazioni <= 0);

                sommaConsumazioni = sommaConsumazioni + prezzoConsumazioni; // calcolo totale dei prezzi
            }
            // nel caso di una scelta non valida
            else
            {
                printf("scelta non valida \n");
            }
        }
    } while (1);
    // fine ciclo
    // calcolo delle medie
    if (bevande != 0)
    {
        mediaBevande = (float)sommaBevande / (float)bevande;                       // si usa il casting per variabili tutte dello stesso tipo
        printf("La media delle bevende vendute equivale a %2.f \n", mediaBevande); // stampa della media
    }
    // nel caso non si abbiano venduto bevande
    else
    {
        printf("Non si hanno venduto bevande \n");
    }
    if (ristorazione != 0)
    {
        mediaRistorazione = (float)sommaConsumazioni / (float)ristorazione;          // si usa il casting per variabili tutte dello stesso tipo
        printf("La media dei piatti venduti equivale a %2.f \n", mediaRistorazione); // stampa della media
    }
    // nel caso non si abbiano venduto piatti
    else
    {
        printf("Non si hanno venduto piatti \n");
    }
    if (bevande != ristorazione)
    {
        if (bevande < ristorazione)
        {
            printf("Hai venduto più piatti \n");
        }
        else
        {
            printf("Hai venduto più bevande \n");
        }
    }
    else
    {
        printf("Hai venduto lo stesso numero di bevande e di piatti");
    }

    return 0;
}