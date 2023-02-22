#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    if (argc > 3)
    {
        printf("Valore non valido");
        exit(0);
    }
    int b = atoi(argv[1]);
    int e = atoi(argv[2]);
    if (b < 0 || e < 0)
    {
        printf("I numeri inseriti non sono validi");
        exit(0);
    }
    printf("il risultato di %d^%d è ", b, e);
    if (e == 0)
    {
        b = 1;
    }
    for (int i = 0; i < e - 1; i++)
    {
        b = b * b;
    }
    printf("%d", b);
    return 0;
}
