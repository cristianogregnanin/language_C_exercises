// es.5 
#include <stdio.h>

int main(int argc, char *argv[])
{

	int n1, n2;
	do
	{
		do
		{
			printf("inserire n1");
			scanf("%d", &n1);
		} while (n1 < 0);

		do
		{
			printf("inserire n2");
			scanf("%d", &n2);
		} while (n2 < 0);
	} while (n2 <= n1);

	do
	{
		printf("%d", n1);
		n1++;
	}(n1 <= n2);
}