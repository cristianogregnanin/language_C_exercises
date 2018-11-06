#include <stdio.h>
/*
 * Dato N un numero intero positivo, generare e
 * visualizzare in ordine crescente i numeri compresi
 * maggiori uguali di -N e minori uguali di N.
* */
int main(){
	
	int i; 
	int n; 
	
	do{ 
		printf("Inserisci un numero >= 0 : "); 
		scanf("%d", &n); 
	}while(n<0); 
	
	i = -n; 
	do{ 
		printf("il numero vale: %d\n", i); 
		i = i + 1; 
	}while(i<=n); 
	
	return 0;	
}
