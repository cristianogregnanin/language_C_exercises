#include <stdio.h>
#include <string.h> 
int main(int argc, char *argv[])
{
    char consumazione[13];                       
    int bevande = 0, ristorazione = 0;          
    int sommaBevande = 0, sommaConsumazioni = 0; 
    float prezzoBevanda, prezzoConsumazioni;
    float mediaBevande, mediaRistorazione;
    do
    {
        printf("Scegli tipo consumazione \n");
        scanf("%s", &consumazione);
        if (strcmp(consumazione, "esci") == 0)
        {
            break;
        }
        else
        {
            if (strcmp(consumazione, "bevande") == 0)
            {
                bevande++; 
                do
                {
                    printf("Inserire prezzo della bevanda \n");
                    scanf("%f", &prezzoBevanda); 
                } while (prezzoBevanda <= 0);
                sommaBevande = prezzoBevanda + sommaBevande;
            }
            else if (strcmp(consumazione, "ristorazione") == 0)
            {
                ristorazione++;
                do
                {
                    printf("Inserire prezzo del piatto \n");
                    scanf("%f", &prezzoConsumazioni); 
                } while (prezzoConsumazioni <= 0);
                sommaConsumazioni = sommaConsumazioni + prezzoConsumazioni; 
            }
            else
            {
                printf("scelta non valida \n");
            }
        }
    } while (1);
    if (bevande != 0)
    {
        mediaBevande = (float)sommaBevande / (float)bevande;                       
        printf("La media delle bevende vendute equivale a %2.f \n", mediaBevande); 
    }
    else
    {
        printf("Non si hanno venduto bevande \n");
    }
    if (ristorazione != 0)
    {
        mediaRistorazione = (float)sommaConsumazioni / (float)ristorazione;
        printf("La media dei piatti venduti equivale a %2.f \n", mediaRistorazione); 
    }
    else
    {
        printf("Non si hanno venduto piatti \n");
    }
    if (bevande < ristorazione)
    {
        printf("Hai venduto più piatti \n");
    }
    else
    {
        printf("Hai venduto più bevande \n");
    }
    return 0;
}
