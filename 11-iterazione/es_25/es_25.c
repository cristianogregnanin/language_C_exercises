#include <stdio.h>
#include <math.h>

/**
 * @brief Calcola la media geometrica di un insieme di numeri forniti dall'utente.
 *
 * Questo programma richiede all'utente di inserire un numero positivo che rappresenta
 * quanti numeri verranno forniti. Per ciascun numero, l'utente deve inserire solo valori
 * positivi. Alla fine, il programma calcola e mostra la media geometrica.
 *
 * @param argc Numero di argomenti da riga di comando.
 * @param argv Array di stringhe degli argomenti da riga di comando.
 * @return il programma restituisce sempre 0.
 */
int main(int argc, char *argv[])
{
    int n;               
    double prodotto = 1; 
    int x;              
    double media;       

    
    do
    {
        printf("Inserisci il numero di numeri da inserire: ");
        scanf("%d", &n);
    } while (n <= 0); 

    
    for (int i = 0; i < n; i++)
    {
        
        do
        {
            printf("Inserisci un numero: ");
            scanf("%d", &x);
        } while (x <= 0); 

        prodotto *= x; 
    }

    
    media = pow(prodotto, 1.0 / n); 

return 0;
}
