#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float peso, altura, IMC;

    printf("Informe seu peso e altura: ");
    scanf("%f", &peso);
    scanf("%f", &altura);

    altura = pow(altura,2);
    IMC = peso / altura;

    {
    if (IMC <=16){
        printf("O valor eh %.2f (Perigo de vida)\n", IMC);
    }
    if (IMC > 16 && IMC <= 17){
        printf("O valor eh %.2f (Abaixo do peso)\n", IMC);
    }
    if (IMC > 17 && IMC <= 18.5){
        printf("O valor eh %.2f (Abaixo do peso)\n", IMC);
    }
    if (IMC > 18.5 && IMC <= 25){
        printf("O valor eh %.2f (Peso Normal)\n", IMC);
    }
    if (IMC > 25 && IMC <= 30){
        printf("O valor eh %.2f (Acima do Peso)\n", IMC);
    }
    if (IMC > 30 && IMC <= 35){
        printf("O valor eh %.2f (Obesidade Grau I)\n", IMC);
    }
    if (IMC > 35 && IMC <= 40){
        printf("O valor eh %.2f (Obesidade Grau II)\n", IMC);
    }
    if (IMC > 40){
        printf("O valor eh %.2f (Obesidade Grau III)\n", IMC);
    }
    }

    return 0;
}
