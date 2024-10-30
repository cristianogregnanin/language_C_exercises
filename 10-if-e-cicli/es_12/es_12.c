/** 
*@brief Lo spazio s espresso in metri di frenata di un'automobile - supposto essere di 1 secondo
il tempo di reazione del guidatore - è stimato mediante la seguente formula: s = v^2 / 250*f
dove v è la velocità in km/h ed f un coefficente relativo alle condizioni stradali:

Condizioni stradali     f
asfalto ruvido          0,6
asfalto liscio          0,5
asfalto bagnato         0,4
asfalto ghiacciato      0,1

Progettare un algoritmo che calcoli lo spazio di frenata a partire dalla velocità v e dalla
condizione dell'asfalto (ruvido, liscio, ecc.).
*@param argc, numeri do argomenti da riga di comando
*@param argv, array di stringhe (vettori di caratteri) contenente gli argomenti da riga di comando
*@return, la funzione ritorna sempre 0
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

    switch(condizione)
    {
        case 1:
        f = 0.6;
        break;
        case 2:
        f = 0.5;
        break;
        case 3:
        f = 0.4;
        break;
        case 4:
        f = 0.1;
        break;
        default:
            printf("Condizione inserita non valida");
            return 1;
    }
    spazio = (velocita * velocita) / (250 * f);

    printf("Lo spazio di frenata è: %.2f metri\n", spazio);

    return 0;
}