#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    // if (strcmp(val,"stringa")== 0) metodo
    char *esci[5], *ti[20];
    int cos, rist = 0, bevan = 0, mb, mr, gb = 0, gr = 0;
    do
    {
        printf("inserisci la tipo di consumazione\n");
        scanf("%s", ti);
        if (strcmp(ti, "ristorazione") == 0 || strcmp(ti, "bevande") == 0)
        {
            printf("\ninserisci il costo di consumazioni\n");
            scanf("%d", &cos);
            if (strcmp(ti, "ristorazione") == 0)
            {
                rist = rist + cos;
                gr++;
            }
            else
            {
                bevan = bevan + cos;
                gb++;
            }
            printf("\nse finito l'inserimento esci scrivendo esci se no inserisci un qualsiasi carratere diverso \n");
            scanf("%s", &esci);
        }
        else
        {
            printf("\ntipo inserito errato\n");
        }
    } while (strcmp(esci, "esci") != 0);
    mb = bevan / gb;
    mr = rist / gr;
    printf("\nla media dell'incasso delle bevande è %d\n", mb);
    printf("la media dell'incasso delle ristorazioni è %d\n", mr);
    if (bevan >= rist)
    {
        if (bevan == rist)
        {
            printf("l'incasso delle ristorazioni e uguale a quello delle bevande");
        }
        else
        {
            printf("l'incasso delle bevande maggiore a quelle delle ristorazioni");
        }
    }
    else
    {
        printf("l'incasso delle ristorazioni maggiore a quelle delle bevande");
    }
}