/*
Escribe un programa en C en el que se defina un vector de 100 numeros enteros. Inicializa todos los elementos del
array al valor '-1'
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    short arreglo[100];
    unsigned short contador;

    // Generamos el valor desde contador[0] hasta contador[99] ya que contador[100]==\0 como fin o termino del arreglo
    for (contador=0; contador<100; contador++)
    {
        arreglo[contador] = -1;
    }

    // Imprimimos los valores del arreglo
    for (contador=0; contador<100; contador++)
    {
        printf("Posicion %hu: %hd\n", contador+1, arreglo[contador]);
    }

    return 0;
}