/*
Escribe en C el programa que convierte cualquier tipo de unidad de medida de información
(por ejemplo, bytes en Kbytes, Mbytes en bits, etc.).
El programa preguntará una cantidad númerica, una unidad de origen y una unidad de destino.
Hará la conversión de la unidad de origen a la de destino
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

// Definir las unidades y sus factores de conversión a bytes
#define NUM_UNIDADES 8

typedef struct {
    char nombre[10];
    double factor;  // Factor de conversión a bytes
} Unidad;

Unidad unidades[NUM_UNIDADES] = {
    {"bits", 1.0/8.0},      // 1 bit = 0.125 bytes
    {"bytes", 1.0},         // 1 byte = 1 byte
    {"KB", 1024.0},         // 1 KB = 1024 bytes
    {"MB", 1024.0*1024.0},  // 1 MB = 1024*1024 bytes
    {"GB", 1024.0*1024.0*1024.0},  // 1 GB = 1024^3 bytes
    {"TB", 1024.0*1024.0*1024.0*1024.0},  // 1 TB = 1024^4 bytes
    {"PB", 1024.0*1024.0*1024.0*1024.0*1024.0},  // 1 PB = 1024^5 bytes
    {"EB", 1024.0*1024.0*1024.0*1024.0*1024.0*1024.0}  // 1 EB = 1024^6 bytes
};

int buscarUnidad(char *unidad) {
    for (int i = 0; i < NUM_UNIDADES; i++) {
        if (strcmp(unidades[i].nombre, unidad) == 0) {
            return i;
        }
    }
    return -1;  // No encontrada
}

int main() {
    double cantidad;
    char unidadOrigen[10], unidadDestino[10];
    int indiceOrigen, indiceDestino;

    // Mostrar unidades disponibles
    printf("Unidades disponibles: bits, bytes, KB, MB, GB, TB, PB, EB\n\n");

    // Pedir cantidad
    printf("Introduce la cantidad: ");
    scanf("%lf", &cantidad);

    // Pedir unidad de origen
    printf("Introduce la unidad de origen: ");
    scanf("%s", unidadOrigen);

    // Pedir unidad de destino
    printf("Introduce la unidad de destino: ");
    scanf("%s", unidadDestino);

    // Buscar índices de las unidades
    indiceOrigen = buscarUnidad(unidadOrigen);
    indiceDestino = buscarUnidad(unidadDestino);

    if (indiceOrigen == -1 || indiceDestino == -1) {
        printf("Error: Unidad no reconocida.\n");
        return 1;
    }

    // Convertir a bytes primero
    double enBytes = cantidad * unidades[indiceOrigen].factor;

    // Convertir a la unidad destino
    double resultado = enBytes / unidades[indiceDestino].factor;

    // Mostrar resultado
    printf("%.2f %s = %.2f %s\n", cantidad, unidadOrigen, resultado, unidadDestino);

    return 0;
}