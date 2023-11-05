#include <stdio.h>

int main(int argc, char *argv[])
{

    int i = 0, somma = 0, a, b, n;
    double media;
    do
    {
        printf("inserisci a\n");
        scanf("%d", &a);
        printf("inserisci b\n");
        scanf("%d", &b);
    } while (b < a);

    while (1)
    {
        printf("inserisci un numero\n");
        scanf("%d", &n);

        if (n >= a && n <= b)
        {
            somma = somma + n;
            i++;
        }
        else
        {
            break;
        }
    }

    media = (double)somma / (double)i;

    printf("\nla media è: %f\n\n", media);

    return 0;
}
