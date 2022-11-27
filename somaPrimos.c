#include <stdio.h>
#include <stdlib.h>

int ehprimo(int x){
    int i, divisores = 0;

    for (i = 1; i <= x; i++){
        if(x % i == 0)
           divisores ++;
    }
    if (divisores == 2)
        return 1;
    else
        return 0;
}
int primeirovalor, segundovalor, soma, n;

int main (){
    printf("Digite o valor menor: ");
    scanf("%d", &primeirovalor);
    printf("Digite o valor maior: ");
    scanf("%d", &segundovalor);
    int i;

    for(i = primeirovalor; i <= segundovalor; i++){
        if(ehprimo(i) == 1)
    soma += i;
      n++;
    }
    printf("%d", soma);
    return 0;
}
