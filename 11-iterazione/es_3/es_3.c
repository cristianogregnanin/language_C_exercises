#include <stdio.h>

/**
 * @brief Funzione principale del programma.
 *
 * Chiede all'utente di inserire un numero intero non negativo e poi stampa tutti i numeri dispari compresi tra 1 e quel numero.
 * Se l'utente inserisce un numero negativo, il programma continua a chiedere l'input finché non viene inserito un numero positivo.
 *
 * @return 0 se il programma termina correttamente.
 */
int main(int argc, char *argv[])
{
    int n, i = 1;

    do
    {
        printf("Immetti un numero: ");
        scanf("%d", &n);
    } while (n < 0);

    printf("I numeri dispari compresi fra %d e %d sono:\n\n", i, n);
    do
    {
        printf("%d\n", i);
        i = i + 2;
    } while (i <= n);

    return 0;
}
