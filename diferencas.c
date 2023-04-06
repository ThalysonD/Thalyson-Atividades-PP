#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    float *A, *B, min, max;

    printf("Digite a quantidade de elementos: ");
    scanf("%d", &n);

    A = (float *) malloc(n * sizeof(float));
    B = (float *) malloc((n-1) * sizeof(float));

    printf("Digite os %d elementos de A:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &A[i]);
    }

    for (i = 0; i < n-1; i++) {
        B[i] = A[i+1] - A[i];
    }

    min = B[0];
    max = B[0];

    for (i = 0; i < n-1; i++) {
        if (B[i] < min) {
            min = B[i];
        }
        if (B[i] > max) {
            max = B[i];
        }
    }

    printf("As diferenças entre os elementos adjacentes de A são:\n");
    for (i = 0; i < n-1; i++) {
        printf("%.2f ", B[i]);
    }

    printf("\nO mínimo das diferenças é: %.2f\n", min);
    printf("O máximo das diferenças é: %.2f\n", max);

    free(A);
    free(B);

    return 0;
}
