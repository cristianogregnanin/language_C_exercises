#include <stdio.h>
#define DIM 20

int main(int argc, char *argv[])
{
	int a[DIM];

	printf("l'indirizzo di A é: %p\n", a);
	printf("l'indirizzo di A é: %p\n", &a);
	printf("l'indirizzo di A é: %p\n\n", &a[0]);

	printf("\nCio implica che se passo un'array ad una funzione, se essa lo modifica questa avrà effetto sull'array originale.\n\n");
}
