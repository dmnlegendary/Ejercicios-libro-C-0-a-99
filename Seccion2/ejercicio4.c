/*
Escribe un programa que escriba todos los numeros pares entre 1 y un numero N introducido por teclado
*/
#include <stdio.h>

int main()
{
    unsigned int limite;
    printf("Ingrese el numero maximo a contar: "); scanf("%d", &limite);

    printf("Los numeros pares entre 1 y %d son:\n[", limite);
    for (size_t i = 1; i <= limite; i++)
    {
        if (i%2==0) {printf("%d,", i);}
    }
    putchar(']');
    
    return 0;
}