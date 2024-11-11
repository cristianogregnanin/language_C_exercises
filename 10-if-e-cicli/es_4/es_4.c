#include <math.h>
#include <stdio.h>


/**
* @brief Progettare un algoritmo che effettui la lettura da tastiera di una serie
* di coppie di valori numerici reali (sia positivi che negativi che zero).
* Per ciascuna coppia, l’algoritmo deve calcolare e stampare il valore
* della radice quadrata del rapporto tra il valore maggiore e quello
* minore dei due. Il programma termina quando vengono inseriti dei valori
* che non permettono di svolgere il calcolo nel dominio dei numeri reali.
* Prima di terminare si richiede di stampare un messaggio che indichi la
* ragione per cui non è stato possibile svolgere il calcolo.


* @param argv Array di stringhe contenente gli argomenti passati attraverso la riga di comando
* @param argc Numero di argomenti passati attraverso la riga di comando
*
* @return La funzione restituisce 0
*/


int main(int argc, char *argv[]) {


  int a, b;
  double rapporto;


  do {
    printf("inserisci a\n");
    scanf("%d", &a);
    printf("inserisci b\n");
    scanf("%d", &b);


    if (a < b) {
      if (a == 0) {
        printf("non si puo' dividere un numero per 0\n");
        break;
      }
      rapporto = (double)b / (double)a;
    } else {
      if (b == 0) {
        printf("non si puo' dividere un numero per 0\n");
        break;
      }
      rapporto = (double)a / (double)b;
    }


    if (rapporto >= 0) {
      rapporto = sqrt(rapporto);
      printf("\n\nradice quadrata del rapporto: %f\n\n", rapporto);
    } else {
      printf("\n\nnon è possibile calcolare la radice di un numero negativo\n\n");
    }
  } while (rapporto >= 0);


  return 0;
}
