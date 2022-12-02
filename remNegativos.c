#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, teve_positivo = 0;

    printf("Quantos numeros voce deseja digitar? ");
    scanf("%d", &N);

    int vet[N];

    for(i=0; i<N; i++){
        printf("Digite um numero: ");
        scanf("%d", &vet[i]);
    }

    for(i=0; i<N; i++){
        if (vet[i] > 0){
            printf("%d", vet[i]);
            teve_positivo = 1;
        }
        if ((i < N-1) && (vet[i] > 0)){
            printf(" , ");
        }
        }

        if (teve_positivo == 0){
            printf("Vazio!");
        }


    return 0;
}
