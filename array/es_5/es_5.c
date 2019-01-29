#include <stdio.h>
#include <string.h>


int main (int argc, char **argv){


	int i,len=0,k=0,j;
	
	for(i=1; i<argc; i++){
		len = len + strlen(argv[i]);
	}
	
	len = len + argc - 2;
	printf("la stringa è lunga %d\n",len);
	
	char str[len];

	for(i=1;i<argc;i++){
		
		for(j=0;j<strlen(argv[i]); j++){
			str[k] = argv[i][j];
			k++;
		}
		str[k] = ' ';
		k++;
	}
	
	str[k-1]='\0';
	printf("%s\n", str);
	
	return 0;

}
