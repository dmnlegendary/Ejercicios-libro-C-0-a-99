/*
El juego de Nim (simplificado). El Nim es un juego clásico de estrategía que se supone originario de Oriente.
Sus reglas, en nuestra versión ligeramente modificidada, son las siguientes:

•   Se tienen tres montones de palillos, cada uno de los cuales tiene, al principio del juego, entre 3 y 6 palillos.
    El número inicial de palillos en cada montón lo determinará el ordenador al azar y puede variar de una partida a otra, pero
    siempre habrá un mínimo de 3 y un máximo de 6.
•   El jugador humano elige un monto y quita de él 1 o 2 palillos.
•   Despues, el ordenador hace lo mismo: elige un monton y quita de el 1 o 2 palillos.
•   Los dos pasos anteriores se repiten hasta que sólo queda un palillo en total. El jugador que deba retirar
    el ultimo palillo pierde.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define CANTIDAD_MONTOS 3

// Detectamos el sistema operativo para cargar las librerías adecuadas
#ifdef _WIN32
    #include <windows.h> // Librería para Windows
    #define LIMPIAR_PANTALLA "cls"
#else
    #include <unistd.h>  // Librería para Linux / Mac
    #define LIMPIAR_PANTALLA "clear"
#endif

void generarCantidadPalillosPorMonto(short int *montosPalillos);
void mostrarCantidadPalillosPorMonto(short int *montosPalillos);
bool computadoraQuitaPalillos(short int *montosPalillos, bool *ganador);
bool jugadorQuitaPalillos(short int *montosPalillos, bool *ganador);
void comenzarJuego();

int main()
{
    srand(time(NULL));
    char continuar;

    do
    {
        puts("Bienvenido al juego del NIM, quieres jugar una ronda? (Y/N)");
        // El espacio antes de %c reemplaza al fflush(stdin) y es la forma estándar de limpiar el buffer
        scanf(" %c", &continuar); 
        
        if (continuar == 'Y' || continuar == 'y') {
            comenzarJuego();
        } else {
            puts("Hasta Luego!");
        }
    } while (continuar == 'Y' || continuar == 'y');
    
    return 0;
}

void comenzarJuego()
{
    // Generamos los 3 montones con los palillos en cada uno
    short int montones[CANTIDAD_MONTOS];
    bool usuarioGanador = false;

    generarCantidadPalillosPorMonto(montones);
    puts("Iniciemos!");

    // Comenzamos el ciclo del juego
    bool juegoTerminado = false; // Cambié el nombre para que sea más lógico: si es false, seguimos jugando.
    
    while (juegoTerminado == false)
    {
        // Mostramos los palillos en los montones
        mostrarCantidadPalillosPorMonto(montones);
        
        // Siempre comienza primero el usuario
        juegoTerminado = jugadorQuitaPalillos(montones, &usuarioGanador);

        // Validamos si el usuario terminó el juego antes de darle el turno a la computadora
        if (juegoTerminado == true) {
            break; 
        }

        // Sigue el turno de la computadora
        juegoTerminado = computadoraQuitaPalillos(montones, &usuarioGanador);
    }
    
    // Imprimimos el resultado final
    if (usuarioGanador == true)
    {
        puts("\n¡Felicidades has ganado! La computadora se llevo el ultimo palillo.\n");
    }
    else
    {
        puts("\n¡La computadora ha ganado! Te toco el ultimo palillo :(\n");
    }

    // Pausamos el programa por 5 segundos
    #ifdef _WIN32
        Sleep(5000);
    #else
        sleep(5);
    #endif

    // Limpiamos la pantalla
    system(LIMPIAR_PANTALLA);
}

void generarCantidadPalillosPorMonto(short int *montosPalillos)
{
    short int contador;
    puts("\n\nLos palillos disponibles son los siguientes:");

    for (contador = 0; contador < CANTIDAD_MONTOS; contador++)
    {
        *(montosPalillos + contador) = (rand() % (6 - 3 + 1)) + 3;
    }
}

void mostrarCantidadPalillosPorMonto(short int *montosPalillos)
{
    short int contador;
    printf("\nMontones: [ 1 ] [ 2 ] [ 3 ]\n");
    printf("Palillos: ");
    for (contador = 0; contador < CANTIDAD_MONTOS; contador++)
    {
        printf("  %hd   ", *(montosPalillos + contador));
    }
    puts("\n");
}

bool jugadorQuitaPalillos(short int *montosPalillos, bool *ganador)
{
    short int totalPalillos = montosPalillos[0] + montosPalillos[1] + montosPalillos[2];

    // Condición de derrota: Si al iniciar tu turno solo queda 1 palillo, pierdes automáticamente.
    if (totalPalillos == 1)
    {
        *ganador = false; // El usuario NO es el ganador
        return true;      // El juego termina
    }

    short int monto, cantidad;
    bool movimientoValido = false;

    printf("--- TU TURNO ---\n");
    do {
        printf("Elige un monto (1-3): ");
        scanf("%hd", &monto);
        monto--; // Restamos 1 para alinearlo con los índices del arreglo (0, 1, 2)

        // Validaciones del montón
        if (monto < 0 || monto > 2) {
            printf("[!] Monto invalido. Debe ser 1, 2 o 3.\n");
            continue;
        }
        if (montosPalillos[monto] == 0) {
            printf("[!] Ese monto ya esta vacio. Elige otro.\n");
            continue;
        }

        // Validaciones de la cantidad
        printf("¿Cuantos palillos quitas (1 o 2)?: ");
        scanf("%hd", &cantidad);

        if (cantidad != 1 && cantidad != 2) {
            printf("[!] Solo puedes quitar 1 o 2 palillos por turno.\n");
            continue;
        }
        if (cantidad > montosPalillos[monto]) {
            printf("[!] No hay suficientes palillos en ese monto.\n");
            continue;
        }
        if (totalPalillos - cantidad == 0) {
            printf("[!] Movimiento invalido: debes dejar por lo menos 1 palillo en el tablero.\n");
            continue;
        }

        // Si superó todas las validaciones, el movimiento es válido y salimos del bucle
        movimientoValido = true;

    } while (!movimientoValido);

    // Aplicamos el movimiento
    montosPalillos[monto] -= cantidad;
    return false; // El juego continúa
}

bool computadoraQuitaPalillos(short int *montosPalillos, bool *ganador)
{
    short int totalPalillos = montosPalillos[0] + montosPalillos[1] + montosPalillos[2];

    // Condición de derrota: Si al iniciar su turno solo queda 1 palillo, la PC pierde.
    if (totalPalillos == 1)
    {
        *ganador = true; // El usuario ES el ganador
        return true;     // El juego termina
    }

    short int montoSeleccionado, cantidadPalosParaQuitar;

    // 1. Elegir un montón que no esté vacío
    do {
        montoSeleccionado = rand() % 3; // Genera 0, 1 o 2 (índices correctos)
    } while (montosPalillos[montoSeleccionado] == 0);

    // 2. Elegir cantidad a quitar
    if (montosPalillos[montoSeleccionado] == 1) {
        cantidadPalosParaQuitar = 1;
    } else {
        cantidadPalosParaQuitar = (rand() % 2) + 1; // Genera 1 o 2
    }

    // 3. Regla de oro: La computadora nunca debe romper la regla de dejar el tablero en 0
    if (totalPalillos - cantidadPalosParaQuitar == 0) {
        cantidadPalosParaQuitar = 1; // Si iba a dejar 0, mejor quita solo 1 para dejarle la derrota al jugador.
    }

    // Aplicamos el movimiento
    montosPalillos[montoSeleccionado] -= cantidadPalosParaQuitar;
    printf(">> La computadora quita %hd palillo(s) del monto %hd.\n", cantidadPalosParaQuitar, montoSeleccionado + 1);
    
    return false; // El juego continúa
}