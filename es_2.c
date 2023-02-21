#include <stdio.h>
int main(int argc, char *argv[])
{
// //*Progettare un algoritmo che effettui le seguenti operazioni:
// • continui a leggere da tastiera due valori numerici, fermandosi quando uno dei due numeri è
// 0 (zero)
// • per ogni coppia di numeri letti:
// ◦ calcoli il prodotto dei due numeri e ne stampi il valore
// ◦ sommi il prodotto calcolato ad una variabile che memorizzi la somma di tutti i prodotti
// • all’uscita del ciclo, stampi il valore della somma
int num1, num2, prodotto, sommaprod = 0;
int fine = 0;
do {
    printf("inserire primo numero\n");
        scanf("%d", &num1);
        
        printf("inserire secondo numero\n");
        scanf("%d", &num2);
         
        prodotto = num1*num2;
        sommaprod = prodotto + sommaprod;
        
}while (num1 != 0 && num2 != 0);
printf("la somma dei prodotti è %d \n",sommaprod);
return 0;
}