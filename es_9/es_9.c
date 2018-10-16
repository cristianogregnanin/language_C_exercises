#include <stdio.h>
#include <limits.h>

int main(){
	int a,b,c,min=INT_MAX,max=0; 
	
	do{
		printf("\ninserisci a\n");
		scanf("%d",&a);
		printf("inserisci b\n");
		scanf("%d",&b);
		printf("inserisci c\n");
		scanf("%d",&c);
		
		if(a<b && b<c){
			
			if (a<min)
				min = a;
			if (c>max)
				max = c;
		}else{
			printf("terna non valida\n");
		}
		
	}while (a>=0 && b>=0 && c>=0);
		
	printf("\nmax: %d\n", max);
	printf("\nminimo: %d\n\n", min);
		
	return 0;
}
