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
    int r = 1;
    if (b < 0 || e < 0)
    {
        printf("I numeri inseriti non sono validi");
        exit(0);
    }
    printf("il risultato di %d^%d è ", b, e);
    for (int i = 0; i < e; i++)
    {
        r = r * b;
        if (e == 0)
        {
            b = 1;
            break;
        }
    }
    printf("%d", r);
    return 0;
}