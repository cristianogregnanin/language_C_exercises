#include <stdio.h>

int main(int argc, char *argv[])
{
    int n;
    do
    {
        printf("Inserisci N: ");
        scanf("%d", &n);
    } while (n <= 0);

    for (int i = -n; i <= n; i++)
    {
        printf("%d\n", i);
    }

    return 0;
}