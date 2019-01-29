#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

int main(){
	
	int p=100,i;
	int banconote[]={50,20,10,5};
	float_t monete[]={2,1,0.5,0.2,0.1,0.05,0.02,0.01};
	float_t n,resto;  


    do{
		printf ("inserisci l'importo:\n");
		scanf ("%f",&n);
    }while(n<=0);
    
    resto=p-n+0.0001;
    printf("il resto è %.2f\n",resto);
    
    int monetine =  100 * (resto-(int)resto);
    
    printf("\n");

    
    for  (i=0;i<4;i++){
		if((int)resto/(int)banconote[i]){
			printf("le banconote da %d euro sono %d\n",banconote[i],(int)resto/(int)banconote[i]);
			resto=(int)resto%(int)banconote[i];
		}
	}  
	
    printf("\n");
    
	for  (i=0;i<2;i++){
		if(resto/monete[i]){
			printf("le monete da %.0f euro sono %.0f\n",monete[i],(resto)/(monete[i]));
			resto=(int)(resto)%(int)(monete[i]);
		}		
	}  

    printf("\n");

	resto = monetine;
	for  (i=2;i<8;i++){
		if((int)resto/(int)(monete[i]*100)){
			printf("le monete da %.2f euro sono %d\n",monete[i],(int)resto/(int)(monete[i]*100));
			resto=(int)(resto)%(int)(monete[i]*100);
		}		
	}  
  
    return 0;
}
