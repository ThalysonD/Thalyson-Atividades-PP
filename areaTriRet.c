#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
  printf("Programa para calcular a area de um triangulo retangulo\n\n");
  float xA, xB, yA, yB, a, b, h;
  printf("Escreva o valor de xA e yA: ");
  scanf("%f %f", &xA, &yA);
  printf("Escreva a altura de xB e yB: ");
  scanf("%f %f", &xB, &yB);

  b = xA - xB;
  h = yA - yB;

  a = (b*h)/2;
  printf("A area do triangulo e: %.2f \n", a);


  system("PAUSE");
  return 0;
}
