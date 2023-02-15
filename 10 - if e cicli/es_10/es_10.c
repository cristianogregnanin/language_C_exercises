//Davide Aggio
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int contaMedia = 0, contaRistorazioni = 0, contaBevande = 0, contaMagg = 0;
    float sommaB = 0, sommaR = 0, b, r;
    float mB = 0, mR = 0;
    char tipo[20];
    do
    {
        printf("Inserisci la consumazione: Bevande o Ristorazioni. esci per uscire \n");
        scanf("%s", tipo);
        if (strcmp(tipo,"ristorazioni")==0)
        {
            contaMagg++;
            contaRistorazioni++;
            printf("importo della ristorazione: \n");
            scanf("%f", &r);
            sommaR = sommaR + r;
        }
        if (strcmp(tipo,"bevande")==0)
        {
            contaBevande++;
            contaMedia++;
            printf("importo delle bevande: \n");
            scanf("%f", &b);
            sommaB = sommaB + b;
        }
    } while (strcmp(tipo,"esci")!=0);
    mB = sommaB / contaMedia;
    mR = sommaR / contaRistorazioni;
    printf("La media delle bevande è %1.f \n", mB);
    printf("La media delle ristorazioni è %1.f \n", mR);
    printf("La somma delle ristorazioni è %1.f \n", sommaR);
    printf("La somma delle bevande è %1.f \n", sommaB);
    if (contaBevande > contaMaggiore)
    {
        printf("si son vendute più bevande \n");
    }
    else
    {
        printf("si son vendute più ristorazioni \n");
    }
    return 0;
}
