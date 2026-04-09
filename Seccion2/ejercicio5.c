/*
Escribe un programa en C que, introducida una serie de 10 numeros por teclado, diga
cual es el mayor, cual es el menor y cual es el valor medio
*/
#include <stdio.h>

#define ARR_SIZE 10 // Constante para tamaño del arreglo

/**
 * @brief Lee ARR_SIZE (10) números enteros desde la entrada estándar y los almacena en el arreglo proporcionado.
 * @param arreglo Puntero a un arreglo de enteros donde se almacenarán los números.
 * @return void
 * @note Asegúrate de que el arreglo tenga al menos ARR_SIZE elementos para evitar desbordamiento.
 */
void asignarNumeros(int *arreglo)
{
    for (int i=0; i<ARR_SIZE; i++){scanf("%d", arreglo+i);}
}

/**
 * @brief Imprime los elementos del arreglo separados por comas.
 * @param arreglo Puntero al arreglo de enteros a imprimir.
 * @return void
 * @note Imprime los valores sin espacios adicionales y no agrega un salto de línea al final.
 */
void imprimirArreglo(int *arreglo)
{
    for (int i=0; i<ARR_SIZE; i++){printf("%d,", *(arreglo+i));}
}

/**
 * @brief Encuentra el mayor, menor y la media de los elementos en el arreglo e imprime los resultados.
 * @param arreglo Puntero al arreglo de enteros a analizar.
 * @return void
 * @note Asume que el arreglo tiene ARR_SIZE elementos. Imprime directamente a stdout con formato específico.
 */
void buscarMayorMenorMedia(int *arreglo)
{
    unsigned int mayor, menor, sumaDeMedia;
    mayor = 0; menor = *arreglo; sumaDeMedia = 0;
    for (int i=0; i<ARR_SIZE; i++)
    {
        if (mayor<*(arreglo+i)) {mayor = *(arreglo+i);}
        if (menor>*(arreglo+i)) {menor = *(arreglo+i);}
        sumaDeMedia = sumaDeMedia + *(arreglo+i);
    }

    float promedio = (float)sumaDeMedia/ARR_SIZE;

    printf("El numero mayor es: %d\nEl numero menor es: %d\nLa media es: %.2f\n", mayor, menor, promedio);
}

int main()
{
    // Arreglo con 10 posiciones
    unsigned int arregloDeEnteros[9], contador;
    contador = 0;

    printf("Ingrese los numeros a trabajar: ");
    asignarNumeros(arregloDeEnteros);
    printf("El arreglo es el siguiente: ["); imprimirArreglo(arregloDeEnteros); printf("]\n");
    buscarMayorMenorMedia(arregloDeEnteros);

    return 0;
}