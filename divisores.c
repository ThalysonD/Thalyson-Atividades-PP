#include <stdio.h>
#include <stdio.h>

int Divisor(int a, int b)
{
    if (b % a == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int numero;
    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    printf("Divisores de %d: ", numero);

    for (int i = 1; i <= numero; i++)
    {
        if (Divisor(i, numero))
        {
            printf("%d ", i);
        }
    }

}
