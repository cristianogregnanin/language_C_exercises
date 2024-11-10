/**
 * @brief Dato un numero intero positivo N verificare se N e' un numero primo.
 * Un numero e' considerato primo solo se e' maggiore o uguale a 1, o se ha come divisori 1 e se stesso.
 * 
 * @param argc Numero di argomenti da riga di comando
 * @param argv Array di stringhe contenente gli argomenti da riga di comando
 * 
 * @return la funzione restituisce sempre 0
 */

#include <stdio.h>

int main(int argc, char * argv[]) {

  int n, i, resto;

  do {
    printf("Inserisci un numero > 1 : ");
    scanf("%d", & n);
  } while (n < 2);

  for (i = n - 1; i > 1; i = i - 1) {
    resto = n % i;
    if (resto == 0) {
      printf("Il numero non è primo\n");
      return 0;
    }
  }

  printf("Numero Primo\n");

  return 0;
}
