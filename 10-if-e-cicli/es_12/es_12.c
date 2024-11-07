/**
*@brief Lo spazio s espresso in metri di frenata di un'automobile - supposto essere di 1 secondo
*il tempo di reazione del guidatore - è stimato mediante la seguente formula: s = v^2 / 250*f
*dove v è la velocità in km/h ed f un coefficente relativo alle condizioni stradali:
* - Condizioni stradali     f
* - asfalto ruvido          0,6
* - asfalto liscio          0,5
* - asfalto bagnato         0,4
* - asfalto ghiacciato      0,1
*
*Progettare un algoritmo che calcoli lo spazio di frenata a partire dalla velocità v e dalla
*condizione dell'asfalto (ruvido, liscio, ecc.).
*@param argc Numero di argomenti da riga di comando
*@param argv Array di stringhe (vettori di caratteri) contenente gli argomenti da riga di comando
*@return La funzione ritorna sempre 0
*/

#include <stdio.h>

int main(int argc, char *argv)
{
    float velocita, f, spazio;
    int condizione;
    printf("inserire velocità auto in km/h\n");
    scanf("%f", &velocita);

    printf("Scegli la condizione dell'asfalto\n");
    printf("1 - Asfalto ruvido\n");
    printf("2 - Asfalto liscio\n");
    printf("3 - Asfalto bagnato\n");
    printf("4 - Asfalto ghiacciato\n");
    printf("Scegliere la condizione dell'asfalto mediante il numero corrispondente\n");
    scanf("%d", &condizione);
    if (condizione < 0 || condizione > 4)
    {
        printf("Scelta non valida\n");
        return 1;
    }
    else
    {
        if (condizione == 1)
        {
            f = 0.6;
        }
        else if (condizione == 2)
        {
            f = 0.5;
        }
        else if (condizione == 3)
        {
            f = 0.4;
        }
        else if (condizione == 4)
        {
            f = 0.1;
        }
        spazio = (velocita * velocita) / (250 * f);

        printf("Lo spazio di frenata è: %.2f metri\n", spazio);
    }
    return 0;
}
