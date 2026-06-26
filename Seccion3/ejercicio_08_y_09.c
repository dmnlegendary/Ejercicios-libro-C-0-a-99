/*
Escribe un programa que defina un vector de 1000 numeros enteros e inicializalo con numeros aleatorios
entre 0 y 30000. Una vez generado el vector, aplicale algun metodo de ordenacion de los vistos en el ejercicio anterior.
Despues de que el vector haya sido ordenado, el usuario debe introducir un numero entre 0 y 30000, y el programa debe buscar ese numero
en el vector, comunicando al usuario la posicion que ocupa(si lo encuenta) o un mensaje de error(si no lo encuentra)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define TAMANO 1000

int main() {
    int vector[TAMANO];
    int numero_buscado;
    
    // Inicializamos la semilla
    srand(time(NULL));

    // 1. Llenamos el vector con números aleatorios entre 0 y 30000
    for (int i = 0; i < TAMANO; i++) {
        vector[i] = rand() % 30001;
    }

    printf("====================================================\n");
    printf("         ORDENAMIENTO Y BUSQUEDA BINARIA            \n");
    printf("====================================================\n\n");
    
    printf("Generando y ordenando 1000 numeros... ");

    // 2. Ordenamiento por Inserción (In-Situ)
    int actual, j;
    for (int i = 1; i < TAMANO; i++) {
        actual = vector[i];
        j = i - 1;

        while (j >= 0 && vector[j] > actual) {
            vector[j + 1] = vector[j];
            j--;
        }
        vector[j + 1] = actual;
    }
    printf("¡Listo!\n\n");

    // 3. Pedir el número al usuario
    printf("Ingresa el numero que deseas buscar (0 - 30000): ");
    scanf("%d", &numero_buscado);

    // ==========================================
    // ALGORITMO DE BÚSQUEDA BINARIA
    // ==========================================
    int izquierda = 0;
    int derecha = TAMANO - 1;
    int medio;
    bool encontrado = false;
    int posicion = -1;

    while (izquierda <= derecha) {
        // Calculamos el punto medio exacto
        medio = izquierda + (derecha - izquierda) / 2; 

        // Caso 1: ¡Lo encontramos en el medio!
        if (vector[medio] == numero_buscado) {
            encontrado = true;
            posicion = medio;
            break; // Salimos del bucle
        }
        
        // Caso 2: El número buscado es MAYOR que el del medio
        if (vector[medio] < numero_buscado) {
            izquierda = medio + 1; // Descartamos la mitad izquierda
        } 
        // Caso 3: El número buscado es MENOR que el del medio
        else {
            derecha = medio - 1; // Descartamos la mitad derecha
        }
    }

    // ==========================================
    // RESULTADO DE LA BÚSQUEDA
    // ==========================================
    if (encontrado) {
        printf("\n¡EXITO! El numero %d ha sido encontrado en la posicion: %d\n", numero_buscado, posicion);
        
        // Comprobación visual opcional para que veas que sí está ahí
        printf("Comprobacion -> vector[%d] = %d\n", posicion, vector[posicion]);
    } else {
        printf("\n[!] ERROR 404: El numero %d no se genero en este vector.\n", numero_buscado);
    }

    return 0;
}