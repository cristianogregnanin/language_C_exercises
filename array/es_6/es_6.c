#include <stdio.h>
#include <string.h>

int palindroma(char parola[])
{
	int i, k = strlen(parola) - 1;

	for (i = 0; i <= k; i++)
	{
		if (parola[i] != parola[k])
			return -1;
		k--;
	}

	return 1;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Numero argomenti sbagliato\n");
		return -1;
	}

	if (palindroma(argv[1]) > 0)
		printf("%s è una parola palindroma\n", argv[1]);
	else
		printf("%s non è una parola palindroma\n", argv[1]);

	return 0;
}
