#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n ,j = 0, k = 1 , t;

	printf("Informe a quantidade de termos:  ");
	scanf("%i", &n);

	printf("SERIE DE FIBONACCI \n  ");


	for (i = 1; i <= n; ++i) {
		printf("%i, ", j);;

		t = j + k;
		j = k;
		k = t;

		}
    return 0;
}
