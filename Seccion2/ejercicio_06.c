/*
Escribe un programa que averigue todos los numeros primos que hay entre 2 y un
numero N introducido por teclado
*/
#include <stdio.h>

#define TRUE 1
#define FALSE 0

/**
 * @brief Solicita un límite y muestra los números primos entre 2 y dicho límite.
 * @details Lee un valor entero positivo desde la entrada estándar y busca todos los
 *          números primos entre 2 y ese límite. Comprueba la primalidad de cada número
 *          probando divisores hasta la raíz cuadrada del mismo.
 * @use Llama a esta función desde el programa principal para ejecutar el cálculo.
 * @return void
 * @note La función imprime directamente los resultados en la salida estándar.
 */
void calcularPrimo() {
    unsigned int limite;
    printf("Introduce el valor limite para calcular los primos entre 2 y tu numero: ");
    scanf("%u", &limite);

    printf("Los numeros primos entre 2 y %u son:\n[", limite);

    int primero = TRUE;
    for (unsigned int i = 2; i <= limite; i++) {
        int esPrimo = TRUE;
        for (unsigned int divisor = 2; divisor * divisor <= i; divisor++) {
            if (i % divisor == 0) {
                esPrimo = FALSE;
                break;
            }
        }
        if (esPrimo) {
            if (!primero) printf(",");  // evita coma final
            printf("%u", i);
            primero = FALSE;
        }
    }
    printf("]\n");
}

int main() {
    calcularPrimo();
    return 0;
}

/*
void calcularPrimo()
{
    unsigned int limite;
    printf("Introduce el valor limite para calcular los primos entre 2 y tu numero: ");
    scanf("%u", &limite);

    printf("Los numeros primos entre 2 y %u son los siguientes:\n[", limite);
    for (unsigned int i = 2; i <= limite; i++)
    {
        int esPrimo = 1;
        for (unsigned int divisor = 2; divisor * divisor <= i; divisor++)
        {
            if (i % divisor == 0)
            {
                esPrimo = 0;
                break;
            }
        }

        if (esPrimo)
        {
            printf("%u", i);
            if (i < limite) {
                printf(",");
            }
        }
    }
    printf("]");
}

int main()
{
    calcularPrimo();
    return 0;
}
*/