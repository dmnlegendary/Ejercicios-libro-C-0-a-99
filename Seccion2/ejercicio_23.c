/*
Escribe un programa en C que pida un numero entero por teclado y lo descomponga en factores primos.

Recuerda que la descomposicion en factores primos de un numero N cualquiera se hace del siguiente modo:
•   Se toma el numero N y se busca el numero primo mas pequeño que lo divide de forma exacta.
•   Supongamos que N/2 es una division exacta (es decir, 2 es el primo mas pequeno que divide a N).
    Entonces 2 es un factor primo de N.
•   El proceso continua con N/2, buscando el primo mas pequeño que divide a N/2. Puede que sea 2, 3 o5, etc.
•   El proceso termina cuando nos queda 1.
*/

#include <stdio.h>

int main() {
    int numero;
    int divisor = 2; // Siempre comenzamos buscando desde el primer número primo: el 2

    printf("==========================================\n");
    printf("     DESCOMPOSICION EN FACTORES PRIMOS    \n");
    printf("==========================================\n\n");

    // 1. Pedimos el número al usuario
    printf("Ingresa un numero entero mayor que 1: ");
    scanf("%d", &numero);

    // Validamos que el número sea válido para la descomposición
    if (numero <= 1) {
        printf("\n[!] El numero debe ser mayor que 1 para descomponerse en factores primos.\n");
        return 1; // Salimos del programa con un código de error
    }

    printf("\nLa descomposicion de %d es: ", numero);

    // 2. Aplicamos el algoritmo de división sucesiva
    while (numero > 1) {
        // Comprobamos si el divisor actual divide exactamente al número (residuo 0)
        if (numero % divisor == 0) {
            printf("%d", divisor);
            
            // Dividimos el número para continuar el proceso con el cociente
            numero = numero / divisor; 
            
            // Un pequeño detalle estético: imprimir el símbolo de multiplicación si aún quedan factores
            if (numero > 1) {
                printf(" * ");
            }
        } 
        else {
            // Si la división no es exacta, pasamos al siguiente número posible
            divisor++; 
        }
    }

    printf("\n\n");

    return 0;
}