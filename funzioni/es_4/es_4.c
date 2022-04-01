#include <stdio.h>
#include <string.h>

int ricerca_vocali(char stringa[])
{

    int vocali = 0;

    for (int k = 0; k < strlen(stringa); k++)
    {

        if (stringa[k] == 'a' || stringa[k] == 'i' || stringa[k] == 'u' || stringa[k] == 'o' || stringa[k] == 'e')
        {
            vocali++;
        }
    }
    return vocali;
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Numero argomenti sbagliato\n");
        return -1;
    }

    int vocali, consonanti, totvocali = 0, totconsonanti = 0;

    for (int i = 1; i < argc; i++)
    {
        vocali = ricerca_vocali(argv[i]);
        consonanti = strlen(argv[i]) - vocali;

        totvocali = totvocali + vocali;
        totconsonanti = totconsonanti + consonanti;
    }

    printf("vocali: %d, consonanti: %d\n", totvocali, totconsonanti);

    return 0;
}
