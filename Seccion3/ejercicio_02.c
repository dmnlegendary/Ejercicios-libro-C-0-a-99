/*
Define dos vectores de 100 numeros enteros, uno llamado pares y otro impares.
Inicializa el primero con los primeros 100 numeros pares positivos (pares[0] = 2, pares[1] = 4 ... y sucesivamente)
Inicializa el segundo con los primeros 100 impares positivos
*/

#include <stdio.h>
#include <stdlib.h>

void inicializarPares(int *arr)
{
    int contador;
    int conteo = 2;

    for (contador=0; contador<100; contador++)
    {
        *(arr+contador) = 2*(contador+1);
        conteo += 2;
    }
}

void inicializarImpares(int *arr)
{
    int contador;

    for (contador=0; contador<100; contador++)
    {
        *(arr+contador) = (contador*2)+1;
    }
}

void mostrarArreglo(int *arr)
{
    // Se muestra arreglo de 100 posiciones
    for (size_t i = 0; i < 100; i++)
    {
        printf("Posicion %d: %d\n", i+1, *(arr+i));
    }
    
}

int main()
{
    // Creamos los arreglos estaticos
    int pares[100], impares[100];

    // Inicializamos los valores respectivos para cada uno
    inicializarPares(pares);
    inicializarImpares(impares);

    // Mostramos los resultados
    mostrarArreglo(pares);
    mostrarArreglo(impares);

    return 0;
}