#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, fat = 1;

    printf("Escreva um valor para calcular o fatorial: \n");
    scanf("%d", &n);

    for(i=n; i>1; i--){
        fat = fat*i;
    }
    printf("Fatorial de %d e' %d", n, fat);
    return 0;
}
