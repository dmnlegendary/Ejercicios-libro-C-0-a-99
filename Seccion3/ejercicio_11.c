/*
Escriba un programa que defina un vector de 10 enteros y lo rellene con numeros crecientes al azar entre 1 y 100.
Es decir, los numeros seran elegidos aleatoriamente pero siempre tienen que ser mayores que los anteriores:
El numero que ocupe la posicion 1 debe ser mayor que el de la posicion 0, el de la posicion 2 mayor que la 1, asi sucesivamente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANO 10

int main() {
    int vector[TAMANO];
    int minimo, maximo;

    // Inicializamos la semilla
    srand(time(NULL));

    printf("====================================================\n");
    printf("        VECTOR DE NUMEROS ALEATORIOS CRECIENTES     \n");
    printf("====================================================\n\n");

    // ==========================================
    // GENERACIÓN PROTEGIDA
    // ==========================================
    for (int i = 0; i < TAMANO; i++) {
        
        // 1. Definir el límite inferior
        if (i == 0) {
            minimo = 1; // El primer número puede ser desde 1
        } else {
            minimo = vector[i - 1] + 1; // Los siguientes deben ser estrictamente mayores al anterior
        }
        
        // 2. Definir el límite superior dinámico
        // Si estamos en la posición 0, faltan 9 números por generar.
        // Por lo tanto, el número máximo permitido aquí es 100 - 9 = 91.
        maximo = 100 - (TAMANO - 1 - i); 
        
        // 3. Generar el número aleatorio dentro de nuestro rango seguro
        vector[i] = minimo + (rand() % (maximo - minimo + 1));
    }

    // ==========================================
    // RESULTADO
    // ==========================================
    printf("Los %d numeros generados son:\n[ ", TAMANO);
    for (int i = 0; i < TAMANO; i++) {
        printf("%d ", vector[i]);
    }
    printf("]\n\n");

    return 0;
}