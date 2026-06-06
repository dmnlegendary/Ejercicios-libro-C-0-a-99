/*
Escribe un programa que permita jugar a la ruleta con el ordenador. Supondremos que la ruleta tiene 20 numeros rojos y 20 negros. 
El jugador, que tendra una suma de dinero inicial, apostará una cantidad (siempre menor que el dinero que le quede) a un número y un color. 
La ruleta, que puedes simular con las funciones de la familia rand(), la manejara el ordenador y comunicara al jugador el resultado. 
Si acierta, multiplicara por 10 el dinero apostado, si falla, lo perderá. 
El proceso se repetirá hasta que el jugador decida abandonar el juego, o bien se quede sin dinero.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float saldo = 1000.0; // El jugador comienza con 1000 de dinero
    float apuesta;
    int numero_apostado, color_apostado;
    int numero_ganador, color_ganador;
    int jugar = 1;

    // Inicializamos la semilla para generar números aleatorios
    srand(time(NULL));

    printf("====================================================\n");
    printf("              BIENVENIDO A LA RULETA                \n");
    printf("====================================================\n");
    printf("La ruleta tiene 20 numeros rojos (1-20) y 20 negros (1-20).\n\n");

    while (jugar == 1 && saldo > 0) {
        printf("----------------------------------------------------\n");
        printf("Tu saldo actual es: $%.2f\n", saldo);

        // 1. Pedir la cantidad a apostar
        do {
            printf("Ingresa la cantidad a apostar (0 para salir): $");
            scanf("%f", &apuesta);
            
            if (apuesta > saldo) {
                printf("  [!] Fondos insuficientes. Tu saldo es $%.2f\n", saldo);
            } else if (apuesta < 0) {
                printf("  [!] La apuesta no puede ser negativa.\n");
            }
        } while (apuesta > saldo || apuesta < 0);

        // Opción para abandonar el juego ingresando 0
        if (apuesta == 0) {
            printf("\nHas decidido retirarte. ¡Te llevas $%.2f!\n", saldo);
            break;
        }

        // 2. Pedir el color
        do {
            printf("Elige el color a apostar (1 = Rojo, 2 = Negro): ");
            scanf("%d", &color_apostado);
            if (color_apostado != 1 && color_apostado != 2) {
                printf("  [!] Opcion invalida. Elige 1 o 2.\n");
            }
        } while (color_apostado != 1 && color_apostado != 2);

        // 3. Pedir el número
        do {
            printf("Elige el numero (del 1 al 20): ");
            scanf("%d", &numero_apostado);
            if (numero_apostado < 1 || numero_apostado > 20) {
                printf("  [!] Opcion invalida. El numero debe estar entre 1 y 20.\n");
            }
        } while (numero_apostado < 1 || numero_apostado > 20);

        // 4. Girar la ruleta (Generar resultados aleatorios)
        numero_ganador = (rand() % 20) + 1; // Genera un número del 1 al 20
        color_ganador = (rand() % 2) + 1;   // Genera un número del 1 al 2 (1=Rojo, 2=Negro)

        printf("\n>>> La ruleta gira y la bola cae en... %s %d <<<\n",
               (color_ganador == 1) ? "ROJO" : "NEGRO", numero_ganador);

        // 5. Comprobar resultados y actualizar saldo
        if (numero_ganador == numero_apostado && color_ganador == color_apostado) {
            // Multiplica la apuesta por 10 (Gana 9 veces su apuesta en beneficio neto)
            float ganancia = apuesta * 10;
            saldo += (ganancia - apuesta); 
            printf("¡FELICIDADES! Has acertado ambos. Ganas $%.2f\n", ganancia);
        } else {
            // Pierde la apuesta
            saldo -= apuesta;
            printf("Lo siento, has fallado. Pierdes $%.2f\n", apuesta);
        }

        // 6. Verificar si se quedó sin dinero o si quiere continuar
        if (saldo <= 0) {
            printf("\nBancarrota. Te has quedado sin dinero. ¡Fin del juego!\n");
            break;
        }

        do {
            printf("\n¿Quieres seguir jugando? (1 = Si, 0 = No): ");
            scanf("%d", &jugar);
        } while (jugar != 0 && jugar != 1);
    }

    printf("\n====================================================\n");
    printf("Gracias por jugar. Saldo final en tu cartera: $%.2f\n", saldo);
    printf("====================================================\n");

    return 0;
}