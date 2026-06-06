/*
Codifica en C el problema de la devolucion de monedas de la maquina expendedora. El programa
preguntara una cantidad de euros y luego calculara que monedas deberia devolver la maquina para
completar esa cantidad. Por ejemplo, si la cantidad es 1.45 euros, la respuesta del programa
debe ser: una moneda de 1 euro, dos de 20 centimos y una de 5 centimos.
*/
#include <stdio.h>

/**
 * @brief Calcula la forma óptima de devolver una cantidad en monedas.
 * @param cantidadCentimos Cantidad de dinero en céntimos que debe devolverse.
 * @return void
 * @details Utiliza las monedas disponibles de mayor a menor valor para minimizar el
 *          número de monedas devueltas. Imprime el número de monedas de cada valor.
 * @note Convierte la cantidad a céntimos antes de llamar a esta función para evitar
 *       errores de precisión con valores en euros.
 */
void devolverMonedas(int cantidadCentimos) {
    int monedas[] = {200, 100, 50, 20, 10, 5, 2, 1}; // valores en céntimos
    int nMonedas = sizeof(monedas) / sizeof(monedas[0]);

    printf("La máquina devuelve:\n");
    for (int i = 0; i < nMonedas; i++) {
        int num = cantidadCentimos / monedas[i];
        if (num > 0) {
            printf("%d moneda(s) de %.2f euros\n", num, monedas[i] / 100.0);
            cantidadCentimos %= monedas[i];
        }
    }
}

int main() {
    float cantidad;
    printf("Introduce la cantidad en euros: ");
    scanf("%f", &cantidad);

    // Convertimos a céntimos para trabajar con enteros
    int cantidadCentimos = (int)(cantidad * 100 + 0.5);

    devolverMonedas(cantidadCentimos);

    return 0;
}
