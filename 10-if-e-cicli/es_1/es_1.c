#include <stdio.h>
/** 
* @brief Progettare un algoritmo che effettui la lettura da tastiera di una serie di coppie di valori numerici.
*L’algoritmo deve calcolare e stampare il rapporto tra il valore minore e quello maggiore dei due.
* Il programma termina quando uno dei due valori o entrambi sono uguali a zero.
*/

int main(int argc, char *argv[])
{
    int a, b;
    double rapporto = 0;

    do{
        printf("Inserire il primo numero \n");
    scanf("%d", &a);

    printf("Inserire il secondo numero  \n");
    scanf("%d", &b);

    if (a > b) {
            rapporto = (double) b / a;
        } else {
            rapporto = (double) a / b;
        }

        printf("Il rapporto è %f \n", rapporto);

    } while(a != 0 && b != 0);
    
}