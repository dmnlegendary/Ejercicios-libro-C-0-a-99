/*
Escribe en C un programa que convierta números binarios a decimales y viceversa
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

// Función para convertir binario a decimal
long long binarioADecimal(char *binario) {
    long long decimal = 0;
    int longitud = strlen(binario);

    for (int i = 0; i < longitud; i++) {
        if (binario[i] == '1') {
            decimal += (long long)pow(2, longitud - 1 - i);
        } else if (binario[i] != '0') {
            printf("Error: El número binario contiene caracteres inválidos.\n");
            return -1;
        }
    }
    return decimal;
}

// Función para convertir decimal a binario
void decimalABinario(long long decimal, char *binario) {
    if (decimal == 0) {
        strcpy(binario, "0");
        return;
    }

    int i = 0;
    while (decimal > 0) {
        binario[i++] = (decimal % 2) + '0';
        decimal /= 2;
    }
    binario[i] = '\0';

    // Invertir la cadena
    int inicio = 0;
    int fin = i - 1;
    while (inicio < fin) {
        char temp = binario[inicio];
        binario[inicio] = binario[fin];
        binario[fin] = temp;
        inicio++;
        fin--;
    }
}

int main() {
    int opcion;
    char binario[65];  // Máximo 64 bits + terminador
    long long decimal;
    char resultadoBinario[65];

    printf("Conversor Binario-Decimal\n");
    printf("1. Binario a Decimal\n");
    printf("2. Decimal a Binario\n");
    printf("Elige una opción (1 o 2): ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        printf("Introduce el número binario: ");
        scanf("%s", binario);

        long long resultado = binarioADecimal(binario);
        if (resultado != -1) {
            printf("El número binario %s en decimal es: %lld\n", binario, resultado);
        }
    } else if (opcion == 2) {
        printf("Introduce el número decimal: ");
        scanf("%lld", &decimal);

        if (decimal < 0) {
            printf("Error: Solo se admiten números decimales positivos.\n");
        } else {
            decimalABinario(decimal, resultadoBinario);
            printf("El número decimal %lld en binario es: %s\n", decimal, resultadoBinario);
        }
    } else {
        printf("Opción inválida.\n");
    }

    return 0;
}
