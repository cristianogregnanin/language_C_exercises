#include <stdio.h>

/**
* @brief Una leggenda orientale narra di un matematico che, in cambio di alcuni servigi resi al re,
*        chiese la seguente ricompensa: <<un chicco di riso per la prima casella di una scacchiera ,
*        due chicchi di riso per la seconda casella di una scacchiera ,
*        quattro chicchi di riso per la terza casella... e cosi' via per tutte le 64 caselle della scacchiera>>.
*        Progettare un algoritmo che, a partire dal numero n di caselle che si intendono riempire,
*        calcoli il numero complessivo di chicchi di riso che spettano come ricompensa.
*
* @param argc e' il numero di elementi inseriti dalla linea di comando
* @param argv e' un array di stringhe con gli argomenti passati da riga di comando
*
* @return ritorna 0
*/

int main(int argc, char *argv[])
{
    int n;
    double chicchiDiRiso = 1;
    double chicchiCasella = 1;

    do
    {
        printf("Quante n caselle intendi riempire?\n");
        scanf("%d", &n);
    } while (n > 64 || n < 0);

    for (int i = 1; i < n; i++)
    {
        chicchiDiRiso = chicchiDiRiso + chicchiCasella;
        chicchiCasella = chicchiCasella * 2;
    }
    printf("\nIl numero di chicchi di riso complessivo che spettano come ricompensa è : %.0f\n", chicchiDiRiso);
    return 0;
}
