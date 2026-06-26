/*
Escribe un programa que defina un vector de 1000 numeros enteros y lo inicialize con valores aleatorios entre 0 y 30000.
Posteriormente, el programa debe ordenar los elementos del vector de menor a mayor, de manera que el que ocupe la posicion 0 sea
el menor de todos y así sucesivamente hasta llegar al elemento mas grande. Puedes usar un arreglo auxiliar
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Usamos una constante para el tamaño, así es más fácil de modificar en el futuro
#define TAMANO 1000 

int main() {
    int vector[TAMANO];
    int auxiliar; // Variable temporal para hacer los intercambios

    // 1. Inicializamos la semilla para que los números sean diferentes cada vez
    srand(time(NULL));

    // 2. Llenamos el vector con números aleatorios entre 0 y 30000
    for (int i = 0; i < TAMANO; i++) {
        vector[i] = rand() % 30001; 
    }

    printf("====================================================\n");
    printf("              ORDENAMIENTO DE VECTOR                \n");
    printf("====================================================\n\n");

    // Imprimimos una muestra ANTES de ordenar para comprobar
    printf("Muestra de los primeros 10 numeros DESORDENADOS:\n[ ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", vector[i]);
    }
    printf("]\n\n");

    // 3. Algoritmo de Ordenamiento de Burbuja (Bubble Sort)
    printf("Ordenando 1000 elementos... por favor espera...\n\n");
    
    for (int i = 0; i < TAMANO - 1; i++) {
        for (int j = 0; j < TAMANO - i - 1; j++) {
            
            // Si el número actual es mayor que el de la derecha, los intercambiamos
            if (vector[j] > vector[j + 1]) {
                auxiliar = vector[j];          // Guardamos el actual en la variable segura
                vector[j] = vector[j + 1];     // Pasamos el menor a la izquierda
                vector[j + 1] = auxiliar;      // Pasamos el mayor a la derecha
            }
        }
    }

    // 4. Comprobación del resultado
    printf("Muestra de los primeros 10 numeros ORDENADOS (Los menores):\n[ ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", vector[i]);
    }
    printf("]\n\n");

    printf("Muestra de los ultimos 10 numeros ORDENADOS (Los mayores):\n[ ");
    for (int i = TAMANO - 10; i < TAMANO; i++) {
        printf("%d ", vector[i]);
    }
    printf("]\n");

    return 0;
}