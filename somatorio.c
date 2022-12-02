#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    float soma;

    printf("Quantos numeros voce deseja informar? ");
    scanf("%d", &n);

    float vet[n];

    for(i = 0; i < n; i++){
        printf("Informe um numero para somar: ");
        scanf("%f", &vet[i]);
        soma = soma + vet[i];
    }

    for (i = 0; i < n; i++){
        printf("%g ", vet[i]);
        if(i < n-1){
            printf("+ ");
        }
    }
    printf(" = %g", soma);
    return 0;
}
