#include <stdio.h>

int main(){
	
	int n,h,m,s;
	do{
		printf("Inserisci un numero positivo: ");
		scanf("%d",&n);
				
	}while(n<1);
		
	m = n / 60;
	s = n % 60;
	h = m / 60;
	m = m % 60;
	
	printf("%dh %dm %ds\n\n", h,m,s);	
	
	
	
	
	return 0;
	}
