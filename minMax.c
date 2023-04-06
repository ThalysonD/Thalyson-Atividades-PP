#include <stdio.h>

int main() {
    int n, menor, maior, i;

    printf("Digite a quantidade de elementos: ");
    scanf("%d", &n);

    int numeros[n];

    for (i = 0; i < n; i++) {
        printf("Digite o %do elemento: ", i+1);
        scanf("%d", &numeros[i]);

        if (i == 0) {
            menor = numeros[i];
            maior = numeros[i];
        } else {
            if (numeros[i] < menor) {
                menor = numeros[i];
            }
            if (numeros[i] > maior) {
                maior = numeros[i];
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
        if (numeros[i] == menor) {
            printf("< ");
        }
        if (numeros[i] == maior) {
            printf("> ");
        }
    }

    printf("\n");

    return 0;
}
