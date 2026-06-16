/*
Escribe un programa en C que pida dos numeros enteros por teclado y calcule el minimo comun multiplo de ambos numeros
*/

#include <stdio.h>

// Función para calcular el Máximo Común Divisor (MCD) usando el Algoritmo de Euclides
int calcularMCD(int a, int b) {
    int residuo;
    while (b != 0) {
        residuo = a % b;
        a = b;
        b = residuo;
    }
    return a;
}

int main() {
    int num1, num2;
    int mcm;

    printf("==========================================\n");
    printf("        MINIMO COMUN MULTIPLO (MCM)       \n");
    printf("==========================================\n\n");

    // 1. Pedir los números al usuario
    printf("Ingresa el primer numero entero: ");
    scanf("%d", &num1);
    
    printf("Ingresa el segundo numero entero: ");
    scanf("%d", &num2);

    // 2. Validación de seguridad (El MCM con 0 siempre es 0)
    if (num1 == 0 || num2 == 0) {
        printf("\nEl Minimo Comun Multiplo es: 0\n");
        return 0;
    }

    // Convertimos los números a positivos (valor absoluto) para que las matemáticas no fallen
    int a = (num1 > 0) ? num1 : -num1;
    int b = (num2 > 0) ? num2 : -num2;

    // 3. Aplicar la fórmula matemática
    mcm = (a * b) / calcularMCD(a, b);

    // 4. Mostrar el resultado
    printf("\nEl Minimo Comun Multiplo de %d y %d es: %d\n\n", num1, num2, mcm);

    return 0;
}