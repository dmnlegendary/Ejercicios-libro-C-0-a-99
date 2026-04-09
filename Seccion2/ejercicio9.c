/*
Escribe en C el programa del calculo del salario de un trabajador. Una funcion salario() debe
calcular el dinero que ha cobrar un trabajador a la semana, pasandole como parametros el numero
de horas semanales que ha trabajado y el precio que se le paga por cada hora. Si ha trabajado
mas de 40 horas, el salario de cada hora adicional es 1.5 veces el de las horas convencionales.

Programa tambien una funcion main() que haga uso de la funcion salario(), para comprobrar
si su comportamiento es el esperado
*/
#include <stdio.h>

/**
 * @brief Calcula el salario semanal de un trabajador.
 * @param horas Número total de horas trabajadas en la semana.
 * @param precioHora Precio pagado por hora de trabajo.
 * @return Salario total a pagar en la semana.
 * @details Si el trabajador ha trabajado más de 40 horas, las horas adicionales se pagan a
 *          1.5 veces el precio de la hora normal.
 */
float salario(int horas, float precioHora) {
    float total;
    if (horas <= 40) {
        total = horas * precioHora;
    } else {
        int horasExtra = horas - 40;
        total = (40 * precioHora) + (horasExtra * precioHora * 1.5);
    }
    return total;
}

int main() {
    int horas;
    float precioHora;

    printf("Introduce el número de horas trabajadas en la semana: ");
    scanf("%d", &horas);

    printf("Introduce el precio por hora: ");
    scanf("%f", &precioHora);

    float pago = salario(horas, precioHora);

    printf("El salario semanal es: %.2f\n", pago);

    return 0;
}
