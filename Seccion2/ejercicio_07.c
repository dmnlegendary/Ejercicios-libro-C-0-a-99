/*
Escribe en C un programa que genere combinaciones aleatorias para jugar a la quiniela
(15 resultados con los valores 1,X o 2)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Dependiendo el Sistema Operativo será la biblioteca a usar para la funcion sleep()
#ifdef _WIN32
    #include <windows.h>
    #define SLEEP(ms) Sleep(ms) // el valor en ms para el retraso en ejecución ms = 1 quiere decir 1 milisegundo; mientras que 1000 es 1s
#else
    #include <unistd.h>
    #define SLEEP(ms) usleep(ms * 1000) // el valor en segundo, ms = 1 -> usleep(1 * 1000) == 1 segundo
#endif

int main() {
    // Inicializar la semilla para números aleatorios
    srand(time(NULL));

    printf("Combinaciones aleatorias para la quiniela:\n");

    for (int i = 1; i <= 15; i++) {
        int resultado = rand() % 3;  // genera 0, 1 o 2

        // Usamos operador ternario para mapear valores
        char simbolo = (resultado == 0) ? '1' : (resultado == 1) ? 'X' : '2';

        printf("Partido %2d: %c\n", i, simbolo);

        SLEEP(1000);
    }

    return 0;
}
