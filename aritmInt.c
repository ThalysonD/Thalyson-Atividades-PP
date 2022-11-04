#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;

    printf("Digite dois numeros inteiros: \n");
    scanf("%d", &a);
    scanf("%d", &b);

    int soma = a + b;
    printf("%d + %d = %d\n", a, b, soma);

    int sub = a - b;
    printf("%d - %d = %d\n", a, b, sub);

    int mult = a * b;
    printf("%d * %d = %d\n", a, b, mult);

    int div = a / b;
    printf("%d / %d = %d\n", a, b, div);

    int resto = a % b;
    printf("%d %% %d = %d\n", a, b, resto);

    return 0;
}
