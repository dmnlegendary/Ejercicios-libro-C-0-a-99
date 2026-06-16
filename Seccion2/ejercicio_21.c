/*
Las tres en raya (Version Básica)

Vamos a hacer una version del popular juego de las Tres en Raya para jugar contra el ordenador.

El juego se desarrolla en un tablero de 3x3 casillas en el que los jugadores van disponiendo de sus fichas tratando
de formar una linea vertical, horizontal o diagonal. La idea es programarlo sin utilizar arrays, que son unas estructuras de datos
que se trabajan mas adelante. Por ahora solamente usaremos variables simples. Paradojicamente, empeñarnos en usar
variables simples introduce una mayor dificultad en el programa.

Las fichas del jugador humano tendrán forma de Circulos (O) mientras que las del ordenador forma de aspa (X).

Al principio, el tablero esta en blanco. Comenzara jugando uno de los dos jugadores elegio aleatoriamente. El jugador que
comienza colocará una ficha en el tablero. Despues, sera el turno del otro jugador. El proceso se repite hasta que uno de los dos
consigue colocar 3 fichas formando una linea o hasta que ya no es posible colocar mas fichas (situacion de 'tablas')
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Funciones auxiliares que reciben las 9 variables para poder evaluarlas
void imprimirTablero(char c1, char c2, char c3, char c4, char c5, char c6, char c7, char c8, char c9);
bool checarGanador(char ficha, char c1, char c2, char c3, char c4, char c5, char c6, char c7, char c8, char c9);

int main() {
    // Las 9 casillas representadas por variables individuales (Espacio en blanco al inicio)
    char c1 = ' ', c2 = ' ', c3 = ' ', c4 = ' ', c5 = ' ', c6 = ' ', c7 = ' ', c8 = ' ', c9 = ' ';
    
    int turnosJugados = 0;
    int turnoActual; // 0 = Humano (O), 1 = Computadora (X)
    bool juegoTerminado = false;
    
    srand(time(NULL));
    turnoActual = rand() % 2; // Decidimos aleatoriamente quién empieza

    printf("==========================================\n");
    printf("         TRES EN RAYA (TIC-TAC-TOE)       \n");
    printf("==========================================\n");
    printf("Tu juegas con 'O' y la computadora con 'X'.\n");
    printf("Las casillas se enumeran del 1 al 9, de izquierda a derecha y de arriba a abajo.\n\n");

    if (turnoActual == 0) {
        printf("¡La suerte ha hablado! Empiezas TU.\n");
    } else {
        printf("¡La suerte ha hablado! Empieza la COMPUTADORA.\n");
    }

    // Bucle principal del juego (Máximo 9 turnos en total)
    while (turnosJugados < 9 && !juegoTerminado) {
        imprimirTablero(c1, c2, c3, c4, c5, c6, c7, c8, c9);

        int eleccion;
        bool movimientoValido = false;

        if (turnoActual == 0) {
            // ==========================================
            // TURNO DEL HUMANO
            // ==========================================
            printf("--- TU TURNO ---\n");
            do {
                printf("Elige una casilla libre (1-9): ");
                scanf("%d", &eleccion);

                // Validamos que la casilla seleccionada esté libre usando variables simples
                if (eleccion == 1 && c1 == ' ') { c1 = 'O'; movimientoValido = true; }
                else if (eleccion == 2 && c2 == ' ') { c2 = 'O'; movimientoValido = true; }
                else if (eleccion == 3 && c3 == ' ') { c3 = 'O'; movimientoValido = true; }
                else if (eleccion == 4 && c4 == ' ') { c4 = 'O'; movimientoValido = true; }
                else if (eleccion == 5 && c5 == ' ') { c5 = 'O'; movimientoValido = true; }
                else if (eleccion == 6 && c6 == ' ') { c6 = 'O'; movimientoValido = true; }
                else if (eleccion == 7 && c7 == ' ') { c7 = 'O'; movimientoValido = true; }
                else if (eleccion == 8 && c8 == ' ') { c8 = 'O'; movimientoValido = true; }
                else if (eleccion == 9 && c9 == ' ') { c9 = 'O'; movimientoValido = true; }
                else {
                    printf("[!] Casilla ocupada o invalida. Intenta de nuevo.\n");
                }
            } while (!movimientoValido);

            // Verificamos si el humano ganó con este movimiento
            if (checarGanador('O', c1, c2, c3, c4, c5, c6, c7, c8, c9)) {
                imprimirTablero(c1, c2, c3, c4, c5, c6, c7, c8, c9);
                printf("\n¡FELICIDADES! Has formado una linea y le ganaste a la computadora.\n");
                juegoTerminado = true;
            } else {
                turnoActual = 1; // Pasamos el turno a la PC
            }

        } else {
            // ==========================================
            // TURNO DE LA COMPUTADORA
            // ==========================================
            printf("--- TURNO DE LA COMPUTADORA ---\n");
            printf("La computadora esta pensando...\n");
            
            do {
                // Elige un número al azar del 1 al 9
                eleccion = (rand() % 9) + 1;

                if (eleccion == 1 && c1 == ' ') { c1 = 'X'; movimientoValido = true; }
                else if (eleccion == 2 && c2 == ' ') { c2 = 'X'; movimientoValido = true; }
                else if (eleccion == 3 && c3 == ' ') { c3 = 'X'; movimientoValido = true; }
                else if (eleccion == 4 && c4 == ' ') { c4 = 'X'; movimientoValido = true; }
                else if (eleccion == 5 && c5 == ' ') { c5 = 'X'; movimientoValido = true; }
                else if (eleccion == 6 && c6 == ' ') { c6 = 'X'; movimientoValido = true; }
                else if (eleccion == 7 && c7 == ' ') { c7 = 'X'; movimientoValido = true; }
                else if (eleccion == 8 && c8 == ' ') { c8 = 'X'; movimientoValido = true; }
                else if (eleccion == 9 && c9 == ' ') { c9 = 'X'; movimientoValido = true; }
            } while (!movimientoValido);

            printf("La computadora coloco su ficha en la casilla %d.\n", eleccion);

            // Verificamos si la computadora ganó con este movimiento
            if (checarGanador('X', c1, c2, c3, c4, c5, c6, c7, c8, c9)) {
                imprimirTablero(c1, c2, c3, c4, c5, c6, c7, c8, c9);
                printf("\n¡LA COMPUTADORA GANA! Mas suerte para la proxima.\n");
                juegoTerminado = true;
            } else {
                turnoActual = 0; // Pasamos el turno al humano
            }
        }

        turnosJugados++; // Aumentamos el contador global de turnos
    }

    // Si pasaron 9 turnos y nadie ganó, es un empate ("tablas")
    if (turnosJugados == 9 && !juegoTerminado) {
        imprimirTablero(c1, c2, c3, c4, c5, c6, c7, c8, c9);
        printf("\n¡EMPATE! Se han llenado todas las casillas.\n");
    }

    return 0;
}

// ==========================================
// FUNCIONES AUXILIARES
// ==========================================

// Imprime la cuadrícula clásica pasando las 9 variables
void imprimirTablero(char c1, char c2, char c3, char c4, char c5, char c6, char c7, char c8, char c9) {
    printf("\n");
    printf("  %c | %c | %c \n", c1, c2, c3);
    printf(" ---+---+---\n");
    printf("  %c | %c | %c \n", c4, c5, c6);
    printf(" ---+---+---\n");
    printf("  %c | %c | %c \n", c7, c8, c9);
    printf("\n");
}

// Revisa todas las combinaciones posibles de victoria de forma manual
bool checarGanador(char ficha, char c1, char c2, char c3, char c4, char c5, char c6, char c7, char c8, char c9) {
    // 3 Combinaciones Horizontales
    if (c1 == ficha && c2 == ficha && c3 == ficha) return true;
    if (c4 == ficha && c5 == ficha && c6 == ficha) return true;
    if (c7 == ficha && c8 == ficha && c9 == ficha) return true;
    
    // 3 Combinaciones Verticales
    if (c1 == ficha && c4 == ficha && c7 == ficha) return true;
    if (c2 == ficha && c5 == ficha && c8 == ficha) return true;
    if (c3 == ficha && c6 == ficha && c9 == ficha) return true;
    
    // 2 Combinaciones Diagonales
    if (c1 == ficha && c5 == ficha && c9 == ficha) return true;
    if (c3 == ficha && c5 == ficha && c7 == ficha) return true;

    return false; // Si no cumplió ninguna, no hay ganador aún
}