//ANDREA BARBIN 3°E ES 1 CARTELLA 12 - ARGC ARGV 12 MODIFICATO

/*Scrivi un programma che legge da argv[1] un numero intero positivo (N) e poi
disegna a terminale un quadrato vuoto composto di asterischi (‘*’)
con il lato lungo N:

Per N pari a 3 il programma stampa:

***
* *
***
Per N pari a 5 il programma stampa:

*****
*   *
*   *
*   *
***** 

*/


//INIZIO 


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    
    /*Argv è un vettore di caratteri e la sua dimensione è indicata da argc*/
    
    //VERIFICA ERRORE, se la dimensione è diversa da 2, deve apparire l'errore.
    /*Dentro argv devono essere memorizzati il nome del programma e il parametro del lato.*/
    
    if (argc != 2)
    {
        printf("Errore argomenti\n");
        exit(0);
    }

    int n = atoi(argv[1]);

    if (n <= 0)
    {
        printf("argv[1] deve essere maggiore di 0\n");
        exit(0);
    }

    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) 
            {
                printf(" *");
            }
            else 
            {
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}

//FINE

