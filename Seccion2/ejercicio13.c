/*
Codifica en C el reloj continuo cuyo algoritmo diseñamos en los ejercicios de la parte 1. El usuario introducira su hora local
a traves del teclado y, a partir de entonces, el programa incrementará esa hora cada segundo. Tendrás que investigar cómo puedes
hacer que el programa se detenga durante un segundo entre iteración e iteración
*/

#include <stdio.h>
#include <windows.h>  // Para la función Sleep

int main() {
    int horas, minutos, segundos;

    // Pedir la hora inicial al usuario
    printf("Introduce la hora inicial (HH MM SS): ");
    scanf("%d %d %d", &horas, &minutos, &segundos);

    // Validar la entrada
    if (horas < 0 || horas > 23 || minutos < 0 || minutos > 59 || segundos < 0 || segundos > 59) {
        printf("Hora inválida. Debe estar entre 00:00:00 y 23:59:59.\n");
        return 1;
    }

    // Bucle infinito para el reloj
    while (1) {
        // Mostrar la hora actual
        printf("\r%02d:%02d:%02d", horas, minutos, segundos);
        fflush(stdout);  // Forzar la salida inmediata

        // Incrementar los segundos
        segundos++;

        // Manejar el carry-over
        if (segundos == 60) {
            segundos = 0;
            minutos++;
            if (minutos == 60) {
                minutos = 0;
                horas++;
                if (horas == 24) {
                    horas = 0;
                }
            }
        }

        // Pausar durante 1 segundo
        Sleep(1000);
    }

    return 0;
}