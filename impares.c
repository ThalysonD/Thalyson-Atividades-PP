#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, menor, maior, soma = 0;

    printf("Escreva o menor e maior valor para informar os impares: ");
    scanf("%d %d", &menor, &maior);

    for (i = menor; i <= maior ; i++)
        if (i % 2 == 1)
             printf("%d\n", i);
    return 0;
}
