/*
Escribe un programa que genere al azar una combinacion para jugar a la loteria primitiva asegurandote de que ningun numero se repite.
Pista: puedes utilizar un vector de 6 numeros enteros, asignando a cada posicion un numero entero aleatorio entre 1 y 49, y comprobando
que el numero asignado no es igual a ninguno de los asignados anteriormente
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Se hara todo el codigo en la funcion main, lo cual esta mal pero para acabar el programa rapido se hara de esta forma XD
    // Semilla para aletoriedad de los numeros de la serie
    srand(time(NULL)); // numero = (rand() % (MAXIMO - MINIMO + 1)) + MINIMO;
    short unsigned loteria[6];

    for (short unsigned contador=0; contador<6; contador++)
    {
        loteria[contador] = (rand() % (49 - 1 + 1)) + 1;
    }

    printf("Los numeros generados son: ");
    for (short unsigned contador=0; contador<6; contador++)
    {
        printf("%hu, ", loteria[contador]);
    }

    return 0;
}