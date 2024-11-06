#include <stdio.h>

/**
 * @brief Un negozio applica uno sconto del 5% per acquisti fino a 50 euro,
 * uno sconto del 10% per acquisti tra 50 e 100 euro e
 * uno sconto del 20% per acquisti superiori a 100 euro.
 * Progettare un algoritmo che, a partire dall'importo totale dell'acquisto,
 * determini lo sconto e il prezzo scontato da pagare.
 *
 * @param argc Numero di argomenti della riga di comando.
 * @param argv Array di stringhe contenente gli argomenti.
 *
 * @return ritorna zero.
 */

int main(int argc, char *argv[])
{
    float importo, sconto, prezzoScontato;

    printf("Inserisci l'importo totale dell'acquisto: ");
    scanf("%f", &importo);

    if (importo <= 50)
    {
        sconto = importo * 0.05;
    }
    else if (importo > 50 && importo <= 100)
    {
        sconto = importo * 0.10;
    }
    else
    {
        sconto = importo * 0.20;
    }
    prezzoScontato = importo - sconto;

    printf("Sconto applicato: %.2f euro\n", sconto);
    printf("Prezzo scontato da pagare: %.2f euro\n", prezzoScontato);

    return 0;
}
