#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T, S, X;
    T=1;
    S=0;
    printf("Informe um numero maior do que 1: \n");
    scanf("%d", &X);

    if (X <= 1){
        printf("Erro. Informe um numero maior que 1.\n");
    } else{
        while (T <= X)
        {
            S=S+T;
            T=T+1;
        }
        printf("SOMA = %d", S);
          }
    return 0;
}
