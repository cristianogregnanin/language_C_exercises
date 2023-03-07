// es.4
#include <stdio.h>

int main(int argc, char *argv[])
{

	int i; 
	int n; 

	do
	{										  
		printf("inserire un numero maggiore o uguale a 0: "); 
		scanf("%d", &n);					   
	} while (n < 0);						   

	i = 0; 
	{									   
		printf("il numero vale: %d\n", i); 
		i = i + 2;						   
	} while (i <= n);					   

	return 0; 
}