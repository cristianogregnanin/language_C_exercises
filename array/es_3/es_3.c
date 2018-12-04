#include <stdio.h>
#define DIM 10

int main(){
	
	int i,resto;
	int a[DIM];
	
	for(i=0;i<DIM; i++){
		printf("Inserisci un numero :");
		scanf("%d", &a[i]);
	}
	
		
	for(i=0;i<DIM;i++){
		resto = a[i] % 2;
		if(resto == 0)
			printf("%d è pari\n",a[i]);
	}
	
	
	for(i=0;i<DIM;i++){
		resto = a[i] % 2;
		if(resto != 0)
			printf("%d è dispari\n",a[i]);
	}
	return 0;
	

}
