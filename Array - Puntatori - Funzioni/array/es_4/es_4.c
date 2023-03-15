#include <stdio.h>
#include <string.h>

void inverti(char s[])
{

	char tmp;
	int i, j = strlen(s) - 1;

	for (i = 0; i < j; i++)
	{

		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;

		j--;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Numero argomenti errato\n");
		return -1;
	}

	inverti(argv[1]);

	printf("stringa invertita: %s\n", argv[1]);

	return 0;
}
