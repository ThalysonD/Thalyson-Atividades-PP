#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int i, N;
    float soma, media, variancia, desvio;

    printf("Insira a quantidade de numeros desejados para media e desvio padrao: ");
    scanf("%d", &N);

    float valor[N];


    soma = 0;
    variancia = 0;

    for(i=0; i<N; i++){
        printf("informe o numero %d: ", (i+1));
        scanf("%f", &valor[i]);
        soma = soma + valor[i];
    }
    media = (float)soma / N;

    for (i=0; i<N; i++){
        variancia = variancia + pow(valor[i] - media, 2);
    }
    variancia = variancia / N;
    desvio = sqrt(variancia);

    printf("\nMedia: %g , Desvio padrao: %g\n", media, desvio);

    return 0;
}
