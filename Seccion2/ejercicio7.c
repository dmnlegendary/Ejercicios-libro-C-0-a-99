/*
Escribe en C un programa que genere combinaciones aleatorias para jugar a la quiniela
(15 resultados con los valores 1,X o 2)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  // necesario para sleep()

int main() {
    // Inicializar la semilla para números aleatorios
    srand(time(NULL));

    printf("Combinaciones aleatorias para la quiniela:\n");

    for (int i = 1; i <= 15; i++) {
        int resultado = rand() % 3;  // genera 0, 1 o 2

        // Usamos operador ternario para mapear valores
        char simbolo = (resultado == 0) ? '1' : (resultado == 1) ? 'X' : '2';

        printf("Partido %2d: %c\n", i, simbolo);

        sleep(1);
    }

    return 0;
}
