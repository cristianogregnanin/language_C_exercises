/**
 * @brief Dato N un numero intero positivo, generare e visualizzare in ordine crescente i primi N numeri interi positivi.
 * 
 * @param argc Numero di argomenti passati al programma da linea di comando.
 * @param argv Array di stringhe contenente gli argomenti passati al programma.
 * 
 * @return 0 Indica che il programma è terminato correttamente
 */

#include <stdio.h>

int main(int argc, char *argv[])
{

	int n, i = 0;
	do
	{
		printf("inserisci un numero: \n");
		scanf("%d", &n);
	} while (n <= 0);

	do
	{
		i++;
		printf("%d\n", i);

	} while (i < n);

	return 0;
}
