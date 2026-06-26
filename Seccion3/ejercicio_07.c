/*
Realiza otra version del ejercicio anterior, pero piensa ahora en algun metodo de ordenamiento de vectores,
que no utilize un vector auxiliar, sino que el vector se ordene sobre si mismo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANO 1000 

int main() {
    int vector[TAMANO];
    int actual; // Guardará el número que estamos intentando acomodar
    int j;

    // Inicializamos la semilla
    srand(time(NULL));

    // Llenamos el vector
    for (int i = 0; i < TAMANO; i++) {
        vector[i] = rand() % 30001; 
    }

    printf("====================================================\n");
    printf("        ORDENAMIENTO POR INSERCION (IN-SITU)        \n");
    printf("====================================================\n\n");

    printf("Muestra ANTES de ordenar (primeros 10):\n[ ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", vector[i]);
    }
    printf("]\n\n");

    // ==========================================
    // ALGORITMO DE INSERCIÓN
    // ==========================================
    printf("Ordenando el vector...\n\n");
    
    // Empezamos desde la posición 1 (asumimos que la posición 0 ya está "ordenada")
    for (int i = 1; i < TAMANO; i++) {
        actual = vector[i]; // Tomamos la carta (número) que vamos a evaluar
        j = i - 1;          // Apuntamos al número que está justo a la izquierda

        // Mientras no lleguemos al inicio (j >= 0) Y el número de la izquierda sea mayor...
        while (j >= 0 && vector[j] > actual) {
            vector[j + 1] = vector[j]; // ...recorremos ese número grande un espacio a la derecha
            j--;                       // Retrocedemos para comparar con el siguiente a la izquierda
        }
        
        // Cuando encontramos un número más pequeño (o llegamos al inicio), 
        // insertamos nuestro número en ese hueco vacío.
        vector[j + 1] = actual;
    }

    // ==========================================
    // COMPROBACIÓN DE RESULTADOS
    // ==========================================
    printf("Muestra DESPUES de ordenar (primeros 10 menores):\n[ ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", vector[i]);
    }
    printf("]\n\n");

    printf("Muestra DESPUES de ordenar (ultimos 10 mayores):\n[ ");
    for (int i = TAMANO - 10; i < TAMANO; i++) {
        printf("%d ", vector[i]);
    }
    printf("]\n");

    return 0;
}