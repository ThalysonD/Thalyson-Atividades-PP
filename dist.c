#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double xA, yA, xB, yB, difx, dify, resultado=0;

    scanf("%lf %lf", &xA, &yA);
    scanf("%lf %lf", &xB, &yB);

    difx = xA - xB;
    dify = yA - yB;

    resultado = sqrt(pow(difx, 2) + pow(dify, 2));

    printf("%.2lf", resultado);

    return 0;
}
