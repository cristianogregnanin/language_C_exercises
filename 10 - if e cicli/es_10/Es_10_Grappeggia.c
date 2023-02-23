#include <stdio.h>
#include <string.h>
void main()
{
    float bev, rist, mediaB, mediaR, totB = 0, totR = 0;
    int contB = 0, contR = 0;
    // string esci = "";
    // string consumazione = "";
    char esci[100];
    char consumazione[100];

    do
    {
        printf("\nInserire il tipo di consumazione(bevanda/ristorazione): ");
        scanf("%s", consumazione);
        if (strcmp (consumazione, "bevanda") == 0)  // Uso string compare
        {
            contB++;
            printf("\nInserisca l'importo della bevanda: ");
            scanf("%f", &bev);
            totB = totB + bev;
        }
        else if (strcmp (consumazione, "ristorazione") == 0)
        {
            contR++;
            printf("\nInserisca l'importo della ristorazione: ");
            scanf("%f", &rist);
            totR = totR + rist;
        }
        else
        {
            printf("\nErrore d'inserimento");
        }
        printf("\nDesidera continuare?(si/no) ");
        scanf("%s", esci);
    } while (strcmp (esci, "si") == 0);

    // Risultati
    mediaB = totB / contB;
    mediaR = totR / contR;
    printf("\nLa media delle bevande è di: %.2f", mediaB);
    printf("\nLa media delle ristorazioni è di: %.2f", mediaR);
    if (contB > contR)
    {
        printf("\nSono state vendute più bevande");
    }
    else if (contR > contB)
    {
        printf("\nSono state vendute più ristorazioni");
    }
    else {
        printf("\nSono state vendute tante bevande quante ristorazioni");
    }
}