#include<stdio.h>

int main(){
  int n, i, primeirovalor;
  int soma = 0;

  printf("Insira o numero de sequencia de hailstone: ");
  scanf("%d", &n);

  primeirovalor = n;

  while(n > 1){
    if(n%2 == 0)
      n = n / 2;
    else
      n = (3 * n)+ 1;
  soma += n;
    i++;
  }
  printf("%d", soma + primeirovalor);
}
