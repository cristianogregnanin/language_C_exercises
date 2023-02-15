#include <stdio.h>
#include <string.h>

int main(int argv, char *argc[])
{
    float bev = 0, rist = 0;
    int bevC = 0, ristC = 0;
    char risp[20];
    printf("Inserire la tipologia di consumazione(bevande/ristorazione/esci):\n");
    scanf("%s", risp);
    while (strcmp(risp, "esci") != 0)
    {
        if (strcmp(risp, "bevande") == 0)
        {
            printf("Inserire l'importo della bevanda:\n");
            scanf("%f", &bev);
            bev += bev;
            bevC++;
        }
        else if (strcmp(risp, "ristorazione") == 0)
        {
            printf("Inserire l'importo della ristorazione:\n");
            scanf("%f", &rist);
            rist += rist;
            ristC++;
        }
        else
        {
            printf("E' stata inserita un operazione non disponibile\nRipetere l'inserimento dell'operazione");
        }
        printf("Inserire la tipologia di consumazione (bevande/ristorazione/esci)\n");
        scanf("%s", risp);
    }

    if (bevC < ristC)
    {
        printf("Sono state consumate più ristorazoni");
        printf("La media delle bevande è: %.2f\n", bev / (float)bevC);
        printf("La media delle Ristorazione è: %.2f\n", rist / (float)ristC);
    }
    else if (bevC > ristC)
    {
        printf("Sono state consumate più bevande");
        printf("La media delle bevande è: %.2f\n", bev / bevC);
        printf("La media delle Ristorazione è: %.2f\n", rist / ristC);
    }
    else
    {
        printf("Non sono state inserite conumazioni");
    }
    return 0;
}
