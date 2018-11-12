#include <stdio.h>

int main(){
	
	int n,i,somma; 
	do{ 
		printf("Inserisci un numero positivo: \n");
		scanf("%d",&n);
		
	}while(n<0);
	
	somma = 0;
	i=0;
	do {
		somma = somma + i;
		i = i + 2;	
	}while(i<=n);
	printf("La somma vale: %d\n\n", somma);
	
	return 0;
}
