/**
 * @brief Calcolo somma radici quadrate
 *
 * Progettare un algoritmo che risolve il seguente problema. Si desidera
 * calcolare la somma delle radici quadrate di N valori numerici inseriti
 * dall’utente, con N inserito in input.
 * L’algoritmo deve stampare la somma calcolata. L’algoritmo deve terminare
 * con un messaggio di errore quando viene inserito un numero che non
 * permette di effettuare il calcolo (nel dominio dei numeri reali).
 * 
 * @param argc numero di argomenti passati da riga di comando
 * @param argv argomenti passati da riga di comando
 * 
 * @return il programma ritorna sempre 0
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])

{

    int n, numero, i = 0;

    double somma = 0;

    do
    {

        printf("Inserisci N maggiore di zero: ");

        scanf("%d", &n);

    } while (n <= 0);

    do
    {

        printf("Inserisci un numero: \n");

        scanf("%d", &numero);

        i++;

        if (numero >= 0)
        {

            somma = somma + sqrt(numero);
        }
        else
        {

            printf("Hai inserito un numero negativo\n");
        }

    } while (i < n && numero >= 0);

    printf("La somma è: %f", somma);

    return 0;
}
