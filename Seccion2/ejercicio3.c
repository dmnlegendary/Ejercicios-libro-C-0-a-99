/*
Escribe un programa que determine si un año es bisiesto
*/
#include <stdio.h>
#include <stdbool.h> // Permite usar tipo de dato booleano

int main()
{
    unsigned int year;
    printf("Ingrese el año a calcular:  ");
    scanf("%d", &year); //leemos por teclado

    bool esBisiesto = (year%4 == 0) && ( (year%100 != 0) || (year%400 == 0) );
    printf("El año %d ", year);
    printf(esBisiesto ? "Es bisiesto\n" : "No es bisiesto\n");
    
    return 0;
}