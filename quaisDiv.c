#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, ref;

    printf("Com quantos numeros deseja trabalhar?\n");
    scanf("%d", &n);

    int vet[n];

    for (i = 0; i < n; i++){
        printf("Escreva um valor: \n");
        scanf("%d", &vet[i]);
    }

    printf("Insira o valor referencia:\n");
      scanf("%d", &ref);

    for (i = 0; i < n; i++){
            if (ref % vet[i] == 0){
                printf("%d# ", vet[i]);
            }
            else{
                printf("%d ", vet[i]);
            }
    }



    return 0;
}
