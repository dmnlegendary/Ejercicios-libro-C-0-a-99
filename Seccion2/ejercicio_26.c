/*
Escribe un programa en C que muestre una pelota moviendose por la pantalla y rebotando por los bordes
La pelota se puede simular con el carácter 'O', escribiendolo en diferentes celdas de la pantalla cada vez.

(Para este ejercicio necesitara la libreria conio (windows) o ncurses (linux o MacOS) dependiendo tu OS)

Se realizara en tres fases sucesivas, (podemos incluso integrarla como un menu para seleccionar cual queremos ejecutar)

Fase 1: la pelota se mueve y rebota por la pantalla, pero va dejando un rastro de Oes

Fase 2: La pelota se meuve por la pantalla sin dejar rastro, el resultado debe dejar la sensacion de movimiento sin parpadeos

Fase 3: La pelote se mueve por la pantalla dejando una estela de cuatro o cinco Oes a su paso
*/

/*
Animación de una pelota rebotando en 3 fases.
Uso exclusivo para Windows (<windows.h> y <conio.h>)
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>

// Límites de la pantalla (ajustados para una consola estándar)
#define ANCHO 78
#define ALTO 24

// ==========================================
// FUNCIONES DE CONTROL DE CONSOLA
// ==========================================

// Mueve el cursor a una posición (x, y) específica
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Oculta el cursor de texto parpadeante para que la animación sea limpia
void ocultarCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE; // FALSE oculta el cursor
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

// ==========================================
// FASES DEL JUEGO
// ==========================================

void fase1_Rastro() {
    system("cls");
    int x = 10, y = 10;
    int dx = 1, dy = 1; // Dirección de la pelota (1 = derecha/abajo, -1 = izquierda/arriba)

    gotoxy(0, 0);
    printf("FASE 1: Rastro permanente. Presiona cualquier tecla para salir...");

    while (!_kbhit()) { // Mientras no se presione ninguna tecla
        // Dibujamos la pelota
        gotoxy(x, y);
        printf("O");

        // FÍSICA DE REBOTE
        if (x + dx >= ANCHO || x + dx <= 1) dx = -dx; // Rebote horizontal
        if (y + dy >= ALTO  || y + dy <= 1) dy = -dy; // Rebote vertical

        // Movemos la pelota
        x += dx;
        y += dy;

        Sleep(30); // Controla la velocidad de la pelota
    }
    _getch(); // Limpiamos el buffer de la tecla presionada
}

void fase2_MovimientoLimpio() {
    system("cls");
    int x = 40, y = 12;
    int dx = 1, dy = -1; 

    gotoxy(0, 0);
    printf("FASE 2: Movimiento limpio. Presiona cualquier tecla para salir...");

    while (!_kbhit()) {
        // 1. Borramos la pelota en su posición actual (Anti-Parpadeo)
        gotoxy(x, y);
        printf(" ");

        // 2. Calculamos el rebote
        if (x + dx >= ANCHO || x + dx <= 1) dx = -dx;
        if (y + dy >= ALTO  || y + dy <= 1) dy = -dy;

        // 3. Actualizamos coordenadas
        x += dx;
        y += dy;

        // 4. Dibujamos la pelota en la nueva posición
        gotoxy(x, y);
        printf("O");

        Sleep(30);
    }
    _getch();
}

void fase3_Estela() {
    system("cls");
    int x = 20, y = 5;
    int dx = 1, dy = 1;
    
    // Búfer para guardar las últimas 5 posiciones
    int estelaX[5] = {x, x, x, x, x};
    int estelaY[5] = {y, y, y, y, y};
    int indice = 0;

    gotoxy(0, 0);
    printf("FASE 3: Estela de 5 posiciones. Presiona cualquier tecla para salir...");

    while (!_kbhit()) {
        // 1. Borramos el rastro MÁS ANTIGUO (el que está a punto de ser reemplazado)
        gotoxy(estelaX[indice], estelaY[indice]);
        printf(" ");

        // 2. Calculamos el rebote
        if (x + dx >= ANCHO || x + dx <= 1) dx = -dx;
        if (y + dy >= ALTO  || y + dy <= 1) dy = -dy;

        x += dx;
        y += dy;

        // 3. Guardamos la nueva posición en el búfer sobreescribiendo la antigua
        estelaX[indice] = x;
        estelaY[indice] = y;

        // 4. Dibujamos la cabeza de la pelota
        gotoxy(x, y);
        printf("O");
        
        // Efecto extra: Dibujamos el resto de la estela un poco más pequeña
        // (Esto es opcional, pero le da un toque visual excelente)
        for (int i = 0; i < 5; i++) {
            if (i != indice) { // Si no es la cabeza actual
                gotoxy(estelaX[i], estelaY[i]);
                printf("o");
            }
        }

        // Movemos el índice del búfer (0, 1, 2, 3, 4, 0, 1...)
        indice = (indice + 1) % 5;

        Sleep(40);
    }
    _getch();
}

// ==========================================
// FUNCIÓN PRINCIPAL
// ==========================================

int main() {
    ocultarCursor(); // Hacemos que la pantalla luzca profesional desde el inicio
    char opcion;

    do {
        system("cls");
        printf("==========================================\n");
        printf("            SIMULADOR DE REBOTES          \n");
        printf("==========================================\n");
        printf("1. Fase 1: Dejar rastro (Pintar todo)\n");
        printf("2. Fase 2: Movimiento limpio (Sin parpadeo)\n");
        printf("3. Fase 3: Estela corta (Bufer Circular)\n");
        printf("0. Salir del programa\n");
        printf("==========================================\n");
        printf("Selecciona una opcion: ");
        
        opcion = _getch(); // Lee sin presionar Enter

        switch (opcion) {
            case '1': fase1_Rastro(); break;
            case '2': fase2_MovimientoLimpio(); break;
            case '3': fase3_Estela(); break;
            case '0': 
                system("cls");
                printf("¡Hasta luego!\n"); 
                break;
            default: break;
        }

    } while (opcion != '0');

    return 0;
}