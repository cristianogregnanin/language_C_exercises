#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define DIM 100

int ricerca(char s,char a[]){
	for(int i=0;i<strlen(a);i++){
		if(!isspace(s)){
			if(s==a[i])
				return i;
		}
	}
	return -1;
}

int calcola(int pos,int s){
	if(pos>=18)
		return (21%pos)-1;
	else
		return pos+s;	
}

void cesare(char s[], int salto){  
	char alfabeto[21] = {'a','b','c','d','e','f','g','h','i','l','m','n','o','p','q','r','s','t','u','v','z'};
	int i,posizione;
	
	for(i=0;i<strlen(s);i++)
	{	
		posizione = ricerca(s[i],alfabeto);
		
		if (posizione>0){
			posizione = calcola(posizione,salto);

			s[i]=alfabeto[posizione];
		}
		
	}
}


int main(){

	char s[DIM];

	printf("inserisci una stringa\n");
	scanf("%[^\n]s",s);
	
	cesare(s,3);
	
	printf("La stringa codificata è: %s\n", s);
	
	return 0;
}
