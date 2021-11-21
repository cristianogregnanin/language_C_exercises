#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define DIM 100

void sostituisciCarattere(char parole[DIM][DIM], char carattere, char sostituto, int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < strlen(parole[j]); i++)
        {
            if (parole[j][i] == carattere)
                parole[j][i] = sostituto;
        }
    }
}

void scriviFile(char parole[DIM][DIM], int n, char *argv[])
{
    FILE *stream;

    if ((stream = fopen(argv[2], "w")) == NULL)
    {
        printf("errore nell'apertura del file output");
        exit(4);
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(stream, "%s ", parole[i]);
    }

    fclose(stream);
}

void leggiFile(char fileName[], char parole[DIM][DIM], int *n)
{
    FILE *stream;

    if ((stream = fopen(fileName, "r")) == NULL)
    {
        printf("errore nell'apertura del file input");
        exit(3);
    }

    while (!feof(stream))
    {
        fscanf(stream, "%s ", parole[*n]);
        ++(*n);
    }

    fclose(stream);
}

void controllaArgomenti(int argc, char *argv[])
{

    if (argc != 6)
    {
        printf("Argomenti errati");
        exit(1);
    }

    if (argv[3][1] != 's')
    {
        printf("Metodo errato");
        exit(2);
    }
}

int main(int argc, char *argv[])
{

    char parole[DIM][DIM];
    int n = 0;

    controllaArgomenti(argc, argv);

    leggiFile(argv[1], parole, &n);

    sostituisciCarattere(parole, argv[4][0], argv[5][0], n);
    scriviFile(parole, n, argv);

    return 0;
}
