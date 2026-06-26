/*
Escriba un programa que pida al usuario 10 numeros reales positivos o negativos, y realice, por un lado la suma de todos los positivos
 y, por otro, la suma de todos los negativos mostrando al final el resultado
 */

#include <stdio.h>

int main(void) {
    double numero;
    double sumaPositivos = 0.0;
    double sumaNegativos = 0.0;

    printf("Ingrese 10 numeros reales (positivos o negativos):\n");
    for (int i = 0; i < 10; i++) {
        printf("Numero %d: ", i + 1);
        if (scanf("%lf", &numero) != 1) {
            printf("Entrada invalida. Termine el programa.\n");
            return 1;
        }

        if (numero > 0) {
            sumaPositivos += numero;
        } else if (numero < 0) {
            sumaNegativos += numero;
        }
    }

    printf("\nSuma de los positivos: %.2f\n", sumaPositivos);
    printf("Suma de los negativos: %.2f\n", sumaNegativos);

    return 0;
}