#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{

	int a, b;
	double r;

	do
	{
		printf("inserisci a\n");
		scanf("%d", &a);
		printf("inserisci b\n");
		scanf("%d", &b);

		if (a < b){
            r = (double)b / (double)a;
            /* prima di ogni divisione bisogna controllare che
            il divisore sia diverso da 0,
            altrimenti l'espressione risulterà ugualmente impossibile */
            if(a==0){
                printf("non si puo' dividere un numero per 0");
                break;
            }
		}
		else{
            r = (double)a / (double)b;
            if(b==0){
                printf("non si puo' dividere un numero per 0");
                break;
            }
		}

		if (r >= 0)
		{
			r = sqrt(r);
			printf("radice quadrata del rapporto: %f\n\n", r);
		}
		else
            printf("non e' possibile calcolare la radice di un numero negativo\n\n");
	} while (r >= 0);

	return 0;
}
