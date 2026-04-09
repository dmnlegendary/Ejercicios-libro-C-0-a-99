/*
Escribe un programa en C que pida dos números por teclado y diga cual es el mayor y cual es el menor
*/

#include <stdio.h>

/**
 * @brief Compara dos números enteros y determina cuál es mayor, menor o si son iguales.
 * 
 * Esta función toma dos enteros como parámetros, los compara y imprime el resultado
 * en la consola. Es útil para ejercicios básicos de comparación en C.
 * 
 * @param num1 Primer número a comparar.
 * @param num2 Segundo número a comparar.
 * 
 * @return void (imprime directamente el resultado).
 * 
 * @note Los números deben ser enteros válidos. No maneja errores de entrada.
 * @see scanf() para leer entrada del usuario.
 */
void compararMayorMenor(int *num1, int *num2){
    if (*num1>*num2) {printf("%d es mayor que %d", *num1, *num2);}
    else if (*num1<*num2) {printf("%d es mayor que %d", *num2, *num1);}
    else {printf("Ambos numeros son iguales.\n");}
}

int main()
{
    static signed int primerNumero, segundoNumero; //Declara dos variables enteras estáticas para almacenar los números a comparar
    // Al ser estaticas quiere decir que siempre quedaran reservadas en memoria mientras este activo el programa, en este caso es una MALA PRACTICA
    printf("Ingresa dos numeros para comparar cual es mayor y menor.\nDe ser el caso, iguales:    ");

    // Se usara scanf para leer los numeros de tipo entero
    scanf("%d%d", &primerNumero, &segundoNumero);
    compararMayorMenor(&primerNumero, &segundoNumero);

    return 1;
}