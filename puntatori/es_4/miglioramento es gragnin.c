#include <stdio.h>
#include <limits.h>

void popola(int array[], int *n)
{
int valore;
do
{
scanf("%d", &valore);
if (valore != -1)
{
array[*n] = valore;
++(*n);
}
} while (valore != -1);
}

void stampa(int array[], int ***n)
{
int i;
for (i = 0; i < (***n); i++)
printf(" %d\n", array[i]);
}

void stampa_inversa(int array[], int ***n)
{
int i;
(***n)--;
for (i = ***n; i >= 0; i--)
printf(" %d\n", array[i]);
}

int ricerca(int array[], int ***n)
{

int numero, posizione = -1, i;
scanf("%d", &numero);

for (i = 0; i < (***n); i++)
{
if (array[i] == numero)
{
printf("il numero ricercato si trova in posizione: %d\n", i);
posizione = i;
break;
}
}

return posizione;
}

void inserisci_in_posizione(int array[], int ***n, int numeroinposizione, int positiontwo)
{
int  i;
(***n)++;
for (i = (***n); i > positiontwo; i--)
{
array[i] = array[i - 1];
}
array[positiontwo] = numeroinposizione;
}

int inserisci_in_coda(int array[], int ***n, int numero)
{

int posizione;
posizione = (***n)++;
array[posizione] = numero;

return posizione;
}

int modifica(int array[], int ***n,int nuovovalore)
{

int posizione = ricerca(array, &(*n));
if (posizione > 0)
{
array[posizione] = nuovovalore;
}
return posizione;
}

void elimina(int array[], int ***n)
{
int posizione = ricerca(array, *(&n));

if (posizione > 0)
{
int i;
for (i = posizione; i < (***n); i++)
{
array[i] = array[i + 1];
}
(***n)--;
}
else
{
printf("Il numero che vuoi eliminare non esiste.");
}
}
void esegui_operazione(int s, int a[], int **n)
{
int numero,position,nuovovalore,positionmod,numeroinposizione,positiontwo;

if (s == 1)
stampa(a, &n);

if (s == 2)
{
printf("inserisci un numero: ");
scanf("%d", &numero);
position=inserisci_in_coda(a, &n,numero);
printf("il numero:%d è stato inserito nella posizone : %d\n",numero,position);
}

if (s == 3)
{
printf("inserisci il nuovo valore\n");
scanf("%d",&nuovovalore);
modifica(a, &n,nuovovalore);
}

if (s == 4)
elimina(a, &n);

if (s == 5)
printf("inserisci il numero: ");
ricerca(a, &n);

if (s == 6)
{
printf("inserisci un numero: ");
scanf("%d", &numeroinposizione);
printf("inserisci la posizione: ATTENZIONE NON DEVE SUPERARE %d \n",n);
scanf("%d", &positiontwo);
inserisci_in_posizione(a, &n,numeroinposizione,positiontwo);
printf("il numero %d è stato inserito in posizione %d\n", numeroinposizione, positiontwo);
}

if (s == 7)
stampa_inversa(a, &n);
}

void menu(int array[], int *n)
{

int scelta;

printf("\npremere 1 per mostrare il contenuto dell'array\n");
printf("premere 2 per inserire un elemento in coda\n");
printf("premere 3 per modificare un elemento\n");
printf("premere 4 per eliminare un elemento\n");
printf("premere 5 per ricercare un elemento\n");
printf("premere 6 per inserire un elemento in una certa posizione\n");
printf("premere 7 per mostrare il contenuto dell'array all'inverso\n");

scanf("%d", &scelta);

esegui_operazione(scelta, array, &n);
}

int main(int argc, char *argv[])
{

int array[SHRT_MAX];
int n, scelta = 1;

printf("inserisci un valore. Premi -1 per terminare l'inserimento\n");
popola(array, &n);

while (scelta != 0)
{
menu(array, &n);
printf("\n\npremi 0 per uscire oppure 1 per continuare ");
scanf("%d", &scelta);
}

printf("\n\n\nprogramma terminato\n\n");

return 0;
}