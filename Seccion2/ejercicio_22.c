/*
Las tres en raya (Version Avanzada)
Diseño mejorado con colores, posicionamiento del cursor y lectura instantánea del teclado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h> // Para cambiar colores y mover el cursor
#include <conio.h>   // Para _getch() (leer sin pulsar Enter)

// Códigos de colores para Windows
#define BLANCO 15
#define AZUL_CLARO 9
#define ROJO_CLARO 12
#define VERDE_CLARO 10
#define AMARILLO 14

// ==========================================
// FUNCIONES DE INTERFAZ GRÁFICA (UI)
// ==========================================

// Cambia el color del texto en la consola
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Mueve el cursor a una coordenada (x, y) específica en la pantalla
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// ==========================================
// LÓGICA DEL JUEGO
// ==========================================

// Imprime el tablero con colores dependiendo de la ficha
void imprimirTablero(char tablero[]) {
    system("cls"); // Limpiamos pantalla
    
    setColor(AMARILLO);
    printf("==========================================\n");
    printf("        TRES EN RAYA - EDICION DELUXE     \n");
    printf("==========================================\n\n");
    setColor(BLANCO);

    for (int i = 0; i < 9; i++) {
        // Salto de línea e interfaz de la cuadrícula
        if (i % 3 == 0 && i > 0) {
            setColor(BLANCO);
            printf("\n ---+---+---\n");
        }
        
        printf(" ");
        
        // Pintamos las fichas de colores
        if (tablero[i] == 'O') {
            setColor(AZUL_CLARO);
            printf("O");
        } else if (tablero[i] == 'X') {
            setColor(ROJO_CLARO);
            printf("X");
        } else {
            setColor(BLANCO);
            printf("%d", i + 1); // Mostramos el número de casilla si está vacía
        }
        
        setColor(BLANCO);
        if ((i + 1) % 3 != 0) printf(" |"); // Separador vertical
    }
    printf("\n\n");
}

// Revisa si hay un ganador usando ciclos (mucho más limpio que la v. básica)
bool checarGanador(char t[], char ficha) {
    // Líneas Horizontales
    for (int i = 0; i <= 6; i += 3)
        if (t[i] == ficha && t[i+1] == ficha && t[i+2] == ficha) return true;
    
    // Líneas Verticales
    for (int i = 0; i < 3; i++)
        if (t[i] == ficha && t[i+3] == ficha && t[i+6] == ficha) return true;
        
    // Diagonales
    if (t[0] == ficha && t[4] == ficha && t[8] == ficha) return true;
    if (t[2] == ficha && t[4] == ficha && t[6] == ficha) return true;

    return false;
}

int main() {
    char tablero[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int turnosJugados = 0;
    int turnoActual; 
    bool juegoTerminado = false;
    
    srand(time(NULL));
    turnoActual = rand() % 2;

    while (turnosJugados < 9 && !juegoTerminado) {
        imprimirTablero(tablero);

        if (turnoActual == 0) {
            // ================== TURNO DEL HUMANO ==================
            setColor(AZUL_CLARO);
            printf("--- TU TURNO (O) ---\n");
            setColor(BLANCO);
            printf("Presiona el numero de la casilla (1-9): ");
            
            bool movimientoValido = false;
            while (!movimientoValido) {
                // _getch() lee la tecla inmediatamente, sin esperar a que pulses Enter
                char tecla = _getch(); 
                int eleccion = tecla - '0'; // Convertimos el caracter a número entero

                if (eleccion >= 1 && eleccion <= 9) {
                    if (tablero[eleccion - 1] != 'O' && tablero[eleccion - 1] != 'X') {
                        tablero[eleccion - 1] = 'O';
                        movimientoValido = true;
                    }
                }
            }

            if (checarGanador(tablero, 'O')) {
                imprimirTablero(tablero);
                setColor(VERDE_CLARO);
                printf("\n\a¡IMPRESIONANTE! Has ganado la partida.\n");
                setColor(BLANCO);
                juegoTerminado = true;
            } else {
                turnoActual = 1;
            }

        } else {
            // ================ TURNO DE LA COMPUTADORA ================
            setColor(ROJO_CLARO);
            printf("--- TURNO DE LA COMPUTADORA (X) ---\n");
            setColor(BLANCO);
            printf("Pensando");
            
            // Efecto visual de "pensando" con puntos suspensivos
            for(int i=0; i<3; i++){
                Sleep(400); 
                printf(".");
            }
            
            bool movimientoValido = false;
            while (!movimientoValido) {
                int eleccion = rand() % 9;
                if (tablero[eleccion] != 'O' && tablero[eleccion] != 'X') {
                    tablero[eleccion] = 'X';
                    movimientoValido = true;
                }
            }

            if (checarGanador(tablero, 'X')) {
                imprimirTablero(tablero);
                setColor(ROJO_CLARO);
                printf("\n\a¡LA COMPUTADORA GANA! Has sido derrotado.\n");
                setColor(BLANCO);
                juegoTerminado = true;
            } else {
                turnoActual = 0;
            }
        }
        turnosJugados++;
    }

    if (turnosJugados == 9 && !juegoTerminado) {
        imprimirTablero(tablero);
        setColor(AMARILLO);
        printf("\n¡EMPATE! El tablero esta lleno.\n");
        setColor(BLANCO);
    }

    printf("\nPresiona cualquier tecla para salir...");
    _getch(); // Pausa final antes de cerrar
    return 0;
}