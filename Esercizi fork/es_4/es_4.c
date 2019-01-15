#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <ctype.h>
#include <string.h>


int ricerca(int numeri[], int n, int numero){
	int posizione;

	//INSERT YOUR CODE HERE
	
	return posizione;
}

int main (int argc, char **argv){
	
	int numeri[] = {10,20,30};
	int posizione;
	int numero = atoi(argv[1]);
	
	
	printf("\n\nMio figlio ha terminato. Il numero %d si trova in posizione %d nell'array \n\n", numero, posizione);
	return 0;

}
