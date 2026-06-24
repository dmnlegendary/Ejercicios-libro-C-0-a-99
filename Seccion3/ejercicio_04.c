/*
Escribe un programa que pida al usuario 10 numeros enteros y calcule el valor medio de todos ellos, mostrando luego en pantalla
los numeros que estan por encima de la media y los que estan por debajo de ella
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <time.h>

void ingresarNumeros(short unsigned *arreglo);
short unsigned obtener_medio(short unsigned *arreglo);
void describirArreglo(short unsigned *arreglo, short unsigned media);
void cicloPrincipal();

// Implementacion de quicksort solo para apantallar XD
void swap(unsigned short *a, unsigned short *b) {
    unsigned short temp = *a;
    *a = *b;
    *b = temp;
}

int partition(unsigned short arr[], int low, int high) {
    unsigned short pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(unsigned short arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main(){
    cicloPrincipal();

    return 0;
}

void cicloPrincipal(){
    short unsigned numerosIngresados[10];

    puts("Ingrese los numeros que quiera:");
    // Aqui le pedimos los numeros al usuario
    ingresarNumeros(numerosIngresados);

    // Aqui obtenemos el valor medio
    short unsigned valor_medio = obtener_medio(numerosIngresados);

    // Aqui imprimimos la informacion solicitada
    describirArreglo(numerosIngresados, valor_medio);
}

void ingresarNumeros(short unsigned *arreglo){
    int contador;

    for (contador = 0; contador<10; contador++){
        scanf("%hu", arreglo+contador);
    }
}

short unsigned obtener_medio(short unsigned *arreglo){
    unsigned int suma = 0;

    for (int contador = 0; contador < 10; contador++){
        suma += arreglo[contador];
    }

    return (short unsigned)(suma / 10);
}

void describirArreglo(short unsigned *arreglo, short unsigned media){
    quicksort(arreglo, 0, 9);

    printf("\nValor medio: %hu\n", media);
    printf("Arreglo ordenado: ");
    for (int i = 0; i < 10; i++){
        printf("%hu ", arreglo[i]);
    }
    printf("\n");

    printf("Numeros por debajo de la media: ");
    for (int i = 0; i < 10; i++){
        if (arreglo[i] < media){
            printf("%hu ", arreglo[i]);
        }
    }
    printf("\n");

    printf("Numeros iguales a la media: ");
    for (int i = 0; i < 10; i++){
        if (arreglo[i] == media){
            printf("%hu ", arreglo[i]);
        }
    }
    printf("\n");

    printf("Numeros por encima de la media: ");
    for (int i = 0; i < 10; i++){
        if (arreglo[i] > media){
            printf("%hu ", arreglo[i]);
        }
    }
    printf("\n");
}