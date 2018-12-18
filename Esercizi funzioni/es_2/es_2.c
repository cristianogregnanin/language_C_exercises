#include <stdio.h>
#include <stdlib.h>

int calcola_somma(int n, char *argv[]){
	int i, somma=0;
	
	for(i=1;i<n;i++)
		somma = somma + atoi(argv[i]);
		
	return somma;
	
}

int main(int argc, char *argv[]){
		
	int somma;
	double media;
		
	somma = calcola_somma(argc, argv);
	
	media = somma / (argc-1);
	
	printf("la media è: %f\n", media);		
	
	
	return 0;
}


