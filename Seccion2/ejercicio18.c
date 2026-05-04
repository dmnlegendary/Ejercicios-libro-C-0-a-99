/*
Escribe un programa para jugar a los dados con el ordenador. Las reglas del juego son las siguientes:
- El jugador humano dispondra de una cantidad inicial de dinero que introducirá por teclado.
- El jugador apostara una cantidad de dinero (siempre igual o menor del que le queda)
- Despues, se tirarán tres dados (lo cual se puede simular con la función rand())
- Si en los tres dados sale la misma cantidad, el dinero apostado por el jugador:
    - Se multiplica por 5 si en los dados ha salido un 6.
    - Se multiplica por 3 si sale cualquier otra cantidad.
- Si en dos dados de los tres sale la misma cantidad, el dinero apostado se multiplica por 2
- En cualquier otro caso, el dinero apostado se pierde.
- El proceso se repite hasta que el jugador se queda sin dinero o hasta que decide dejar de jugar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float saldo = 0.0;
    float apuesta;
    int dado1, dado2, dado3;
    int jugar = 1;

    // Inicializamos la semilla para los números aleatorios
    srand(time(NULL));

    printf("====================================================\n");
    printf("             BIENVENIDO AL JUEGO DE DADOS           \n");
    printf("====================================================\n");

    // 1. Pedir la cantidad inicial de dinero
    do {
        printf("Ingresa tu cantidad de dinero inicial: $");
        scanf("%f", &saldo);
        if (saldo <= 0) {
            printf("  [!] Debes ingresar una cantidad mayor a 0 para poder jugar.\n");
        }
    } while (saldo <= 0);

    while (jugar == 1 && saldo > 0) {
        printf("\n----------------------------------------------------\n");
        printf("Tu saldo actual es: $%.2f\n", saldo);

        // 2. Pedir la cantidad a apostar
        do {
            printf("Ingresa la cantidad a apostar (0 para salir): $");
            scanf("%f", &apuesta);
            
            if (apuesta > saldo) {
                printf("  [!] Fondos insuficientes. Solo tienes $%.2f\n", saldo);
            } else if (apuesta < 0) {
                printf("  [!] La apuesta no puede ser negativa.\n");
            }
        } while (apuesta > saldo || apuesta < 0);

        // Si apuesta 0, decide abandonar
        if (apuesta == 0) {
            printf("\nHas decidido retirarte a tiempo. ¡Te llevas $%.2f!\n", saldo);
            break;
        }

        // 3. Tirar los tres dados
        dado1 = (rand() % 6) + 1;
        dado2 = (rand() % 6) + 1;
        dado3 = (rand() % 6) + 1;

        printf("\nLanzando los dados...\n");
        printf("  Dado 1: [%d]\n", dado1);
        printf("  Dado 2: [%d]\n", dado2);
        printf("  Dado 3: [%d]\n", dado3);

        // 4. Evaluar las reglas del juego
        if (dado1 == dado2 && dado2 == dado3) {
            // Caso: Los tres dados son iguales
            if (dado1 == 6) {
                printf("¡TRIPLE 6! Tu apuesta se multiplica por 5.\n");
                saldo += (apuesta * 5) - apuesta; 
            } else {
                printf("¡TRES IGUALES! Tu apuesta se multiplica por 3.\n");
                saldo += (apuesta * 3) - apuesta;
            }
        } 
        else if (dado1 == dado2 || dado1 == dado3 || dado2 == dado3) {
            // Caso: Dos dados son iguales
            printf("¡DOS IGUALES! Tu apuesta se multiplica por 2.\n");
            saldo += (apuesta * 2) - apuesta;
        } 
        else {
            // Caso: Todos son distintos
            printf("Todos los dados son distintos. Pierdes lo apostado.\n");
            saldo -= apuesta;
        }

        // 5. Verificar si se quedó sin dinero
        if (saldo <= 0) {
            printf("\nTe has quedado sin dinero. ¡Fin del juego!\n");
            break;
        }

        // Preguntar si desea continuar
        do {
            printf("\n¿Quieres seguir jugando? (1 = Si, 0 = No): ");
            scanf("%d", &jugar);
        } while (jugar != 0 && jugar != 1);
    }

    printf("\n====================================================\n");
    printf("Juego terminado. Saldo final: $%.2f\n", saldo);
    printf("====================================================\n");

    return 0;
}