/**
 * @brief Progettare un algoritmo che calcoli la temperatura percepita a partire dalla temperatura reale
   e dalla velocità del vento.
 *
 * @param argc Numero degli elementi passati da riga di comando.
 * @param argv Array di stringhe degli argomenti passati da righa di comando.
 * @return La funzione ritorna sempre 0.
 */

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    float T_reale, t_percepita, velocità_vento;

    printf("Inserisci la temperatura reale (°C).\n");
    scanf("%f", &T_reale);

    do
    {
        printf("Inserisci la velocità del vento (mph).\n");
        scanf("%f", &velocità_vento);

        if (velocità_vento < 5)
        {
            printf("Valore non accettabile.\nVengono accettati valori solo superiori alle 5 mph.\n");
        }

    } while (velocità_vento < 5);

    t_percepita = 33 + (0, 45 + (0, 29 * sqrt(velocità_vento)) - 0, 02 * velocità_vento) - (T_reale - 33);

    printf("La temperatura percepita è: %.2f", t_percepita);

    return 0;
}