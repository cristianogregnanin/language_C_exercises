#include <stdio.h>
#include <math.h>


int main(){
	
	int a,b;
	double r;
	
	do {
		r = 0; 
		printf("inserisci a\n");
		scanf("%d",&a);
		printf("inserisci b\n");
		scanf("%d",&b);
				
		if(a>b)
			r = (double)b/(double)a;
		else
			r = (double)a/(double)b;
			
		if (r>0)
		{
			r = sqrt(r);
			printf("radice quadrata del rapporto: %f\n\n", r);
		}
	}while(r>0);
		
	printf("non è possibile calcolare la radice di un numero negativo\n\n");
		
	return 0;
}
