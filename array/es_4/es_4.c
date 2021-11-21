#include <stdio.h>
#include <string.h>

void inverti(char s[])
{

	char tmp;
	int i, length = strlen(s), j = length - 1;

	for (i = 0; i < j; i++)
	{

		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;

		j--;
	}
}

int main(int argc, char **argv)
{

	char stringa[strlen(argv[1])];

	strcpy(stringa, argv[1]);

	inverti(stringa);

	printf("stringa invertita: %s\n", stringa);

	return 0;
}
