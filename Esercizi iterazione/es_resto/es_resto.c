#include <stdio.h>

#define DIM 100



int main (int argc, char **argv){

	
	double monete[]={20,10,5,2,1,0.5,0.2,0.1,0.05,0.02,0.01}, prezzo;
	
	sscanf(argv[1], "%lf", &prezzo);
	
	double resto = DIM - prezzo;
	int i, banconote;
	
	sscanf(argv[1], "%lf", &resto); //REMOVE ME
	
	
	for (i=0;i<5;i++){
		banconote = resto / monete[i];
				
		resto = (int)resto % (int)monete[i];
		
		if(banconote>0)
			printf("banconote da %2.f: %d\n", monete[i], banconote);
		
	}
	

	resto = 4.7;
	int monetine;
	for (i=5;i<11;i++){
		monetine = (resto*100) / (monete[i] * 100);
				
		resto = (int)(resto*100) % (int)(monete[i]*100);
		
		if(monetine>0)
			printf("monete da %f: %d\n", monete[i], monetine);
	

		
	}
		
        	
	
	return 0;

}
