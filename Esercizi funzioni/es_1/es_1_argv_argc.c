#include <stdio.h>
#include <stdlib.h>


int verifica_input(int valore){
	if(valore>0){
		return valore;
	}else{
		printf("%d is invalid\n", valore);
		exit(0);
	}
}

int calcola_somma(int n1, int n2){
	return n1 + n2;
}

int main(int argc, char *argv[]){
		
	int a,b,somma;
	a = verifica_input(atoi(argv[1]));
	b = verifica_input(atoi(argv[2]));
	
	
	somma = calcola_somma(a,b);
	
	printf("la somma è: %d\n", somma);		
	
	return 0;
}
