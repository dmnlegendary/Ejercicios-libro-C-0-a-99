/*
Elabora un programa que imprima una tabla de código ASCII similar a la que puedes encontrar en cientos de paginas web
*/

#include <stdio.h>

/**
 * @brief Imprime una tabla completa de códigos ASCII del 0 al 255
 * 
 * @description
 * Esta función genera e imprime una tabla que relaciona los valores numéricos
 * (0-255) con sus correspondientes caracteres ASCII. Cada línea de la salida
 * muestra el valor decimal y su representación en carácter ASCII.
 * 
 * @param void
 * 
 * @return void
 * No retorna ningún valor. La función solo produce salida en pantalla mediante printf().
 * 
 * @details
 * - Rango de caracteres: 0 a 255 (tabla ASCII completa)
 * - Formato de salida: "El valor X representa a Y"
 * - Los primeros 32 caracteres son caracteres especiales no imprimibles
 * - Caracteres imprimibles comienzan desde el código 32 (espacio)
 * 
 * @note
 * Algunos caracteres especiales pueden no ser visibles en la salida,
 * como caracteres de control (0-31) y el carácter DEL (127).
 * 
 * @example
 * @code
 * showASCII();
 * // Salida:
 * // El valor 0 representa a (no visible)
 * // El valor 32 representa a (espacio)
 * // El valor 65 representa a A
 * // El valor 97 representa a a
 * @endcode
 */
void showASCII()
{
    // Itera sobre todos los valores ASCII (0-255)
    for (size_t sequence = 0; sequence < 256; sequence++)
    {
        // Imprime el valor numérico y su correspondiente carácter ASCII
        printf("El valor %d representa a %c\n", sequence, sequence);
    }
}

int main()
{
    showASCII();
    return 0;
}