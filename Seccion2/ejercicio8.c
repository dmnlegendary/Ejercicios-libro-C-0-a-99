/*
Escribe la version en C del juego del numero secreto. El ordenador elegira un numero al azar
entre 1 y 100. El usuario ira introduciendo numeros por teclado, y el ordenador le ira dando pistas:
"Mi numero es mayor" o "Mi numero es menor", hasta que el usuario acierte.
Entonces el ordenador le felicitara y le comunicara el numero de intentos que necesito para acertar
el numero secreto
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Inicializar la semilla para números aleatorios
    srand(time(NULL));

    // Generar número secreto entre 1 y 100
    int secreto = rand() % 100 + 1;
    int intento, contador = 0;

    printf("He pensado un número entre 1 y 100.\n");
    printf("¡Intenta adivinarlo!\n");

    do {
        printf("Introduce tu número: ");
        scanf("%d", &intento);
        contador++;

        if (intento < secreto) {
            printf("Mi número es mayor.\n");
        } else if (intento > secreto) {
            printf("Mi número es menor.\n");
        } else {
            printf("¡Correcto! El número secreto era %d.\n", secreto);
            printf("Lo lograste en %d intentos.\n", contador);
        }
    } while (intento != secreto);

    return 0;
}
