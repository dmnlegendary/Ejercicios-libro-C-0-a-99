/*
Juego de Automovilismo en Terminal
El jugador controla la 'H' con las teclas 'A' (Izquierda) y 'D' (Derecha).
El objetivo es sobrevivir el mayor tiempo posible sin chocar contra los muros '|'.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h> // Para la función Sleep()
#include <conio.h>   // Para _kbhit() y _getch() (lectura de teclado en tiempo real)

int main() {
    int vidas = 3;
    int ancho_carretera = 20;
    int borde_izquierdo = 15; // Posición inicial del muro izquierdo
    int posicion_H = borde_izquierdo + (ancho_carretera / 2); // El coche empieza en el centro
    
    time_t tiempo_inicio, tiempo_fin;
    double segundos_sobrevividos;

    // Inicializamos la semilla de aleatoriedad
    srand(time(NULL));

    printf("====================================================\n");
    printf("                CARRERA MORTAL EN C                 \n");
    printf("====================================================\n");
    printf("Instrucciones:\n");
    printf("- Usa 'A' para moverte a la IZQUIERDA.\n");
    printf("- Usa 'D' para moverte a la DERECHA.\n");
    printf("- Evita chocar contra los muros '|'.\n");
    printf("- Tienes 3 vidas. ¡Sobrevive lo mas que puedas!\n\n");
    printf("Presiona cualquier tecla para arrancar el motor...\n");
    
    _getch(); // Esperamos a que el jugador esté listo
    
    // Guardamos el momento exacto en el que empieza el juego
    tiempo_inicio = time(NULL);

    // ==========================================
    // BUCLE PRINCIPAL DEL JUEGO
    // ==========================================
    while (vidas > 0) {
        
        // 1. LEER LA ENTRADA DEL JUGADOR (Sin pausar el juego)
        if (_kbhit()) { // Si se ha presionado una tecla...
            char tecla = _getch();
            if (tecla == 'a' || tecla == 'A') {
                posicion_H--; // Mover a la izquierda
            } else if (tecla == 'd' || tecla == 'D') {
                posicion_H++; // Mover a la derecha
            }
        }

        // 2. GENERAR LAS CURVAS DE LA CARRETERA
        // Generamos un cambio aleatorio: -1 (izquierda), 0 (recto), o 1 (derecha)
        int curva = (rand() % 3) - 1;
        borde_izquierdo += curva;

        // Evitamos que la carretera se salga por completo de la pantalla
        if (borde_izquierdo < 2) borde_izquierdo = 2;
        if (borde_izquierdo > 40) borde_izquierdo = 40;

        // 3. COMPROBAR COLISIONES
        bool choque = false;
        if (posicion_H <= borde_izquierdo || posicion_H >= borde_izquierdo + ancho_carretera) {
            choque = true;
            vidas--;
        }

        // 4. DIBUJAR LA PISTA EN ESTA FRACCIÓN DE SEGUNDO
        for (int i = 0; i < 70; i++) {
            if (i == borde_izquierdo || i == borde_izquierdo + ancho_carretera) {
                printf("|"); // Dibujar muros
            } 
            else if (i == posicion_H) {
                if (choque) {
                    printf("*"); // Si chocó, dibujamos una explosión
                } else {
                    printf("H"); // Si está bien, dibujamos el coche
                }
            } 
            else {
                printf(" "); // Asfalto o fuera de la carretera
            }
        }
        printf("\n"); // Salto de línea para dar la ilusión de avance

        // 5. MANEJAR LAS CONSECUENCIAS DEL CHOQUE
        if (choque) {
            printf("\n[!] ¡CRASH! Te has chocado. Vidas restantes: %d\n\n", vidas);
            Sleep(1500); // Pausamos 1.5 segundos para que el jugador se recupere
            
            // Re-centramos el coche para que no vuelva a chocar inmediatamente
            posicion_H = borde_izquierdo + (ancho_carretera / 2);
            
            // Limpiamos el buffer del teclado por si el jugador presionó teclas por pánico
            while (_kbhit()) _getch(); 
        }

        // 6. CONTROLAR LA VELOCIDAD DEL JUEGO
        Sleep(50); // Pausamos 50 milisegundos (20 cuadros por segundo)
    }

    // ==========================================
    // FIN DEL JUEGO
    // ==========================================
    
    // Registramos el tiempo en el que perdió su última vida
    tiempo_fin = time(NULL);
    segundos_sobrevividos = difftime(tiempo_fin, tiempo_inicio);

    printf("\n====================================================\n");
    printf("                    FIN DEL JUEGO                   \n");
    printf("====================================================\n");
    printf("Te has quedado sin vidas.\n");
    printf("Tiempo aguantando en la carretera: %.0f segundos.\n", segundos_sobrevividos);
    printf("====================================================\n");

    return 0;
}