#include <stdio.h>

int main(){
	
	int a = 1,b = 1;
	double r = 0;
	
	while(a != 0 || b!=0 ){
		printf("inserisci a\n");
		scanf("%d",&a);
		printf("%d",a);
		printf("inserisci b\n");
		scanf("%d",&b);
		printf("%d",b);
		
		if(a>b)
			r = b/a;
		else
			r = a/b;
		printf("\n\tIl risultato è: %lf\n\n", r);
	}
	return 0;
}
