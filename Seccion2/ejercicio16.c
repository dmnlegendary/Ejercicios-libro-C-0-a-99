/*
Realiza en C el programa para calcular la edad de una persona. El programa pedirá la fecha de nacimiento del usuario y
la fecha actual, y calculará la edad en días, teniendo en cuenta los años bisiestos
*/

#include <stdio.h>

// Función para determinar si un año es bisiesto
int esBisiesto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

// Función para calcular los días transcurridos desde el 1 de enero hasta la fecha dada
int diasHastaFecha(int dia, int mes, int ano) {
    int diasMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dias = 0;

    // Sumar días de meses completos
    for (int i = 0; i < mes - 1; i++) {
        dias += diasMes[i];
    }

    // Agregar días del mes actual
    dias += dia;

    // Si es febrero y año bisiesto, agregar 1 día extra
    if (mes > 2 && esBisiesto(ano)) {
        dias += 1;
    }

    return dias;
}

// Función para calcular días bisiestos entre dos años
int diasBisiestosEntre(int anoInicio, int anoFin) {
    int contador = 0;
    for (int ano = anoInicio; ano < anoFin; ano++) {
        if (esBisiesto(ano)) {
            contador++;
        }
    }
    return contador;
}

int main() {
    int diaNac, mesNac, anoNac;
    int diaActual, mesActual, anoActual;

    // Pedir fecha de nacimiento
    printf("Introduce tu fecha de nacimiento (DD MM AAAA): ");
    scanf("%d %d %d", &diaNac, &mesNac, &anoNac);

    // Pedir fecha actual
    printf("Introduce la fecha actual (DD MM AAAA): ");
    scanf("%d %d %d", &diaActual, &mesActual, &anoActual);

    // Validar fechas (básica)
    if (anoNac > anoActual || (anoNac == anoActual && mesNac > mesActual) ||
        (anoNac == anoActual && mesNac == mesActual && diaNac > diaActual)) {
        printf("Error: La fecha de nacimiento no puede ser posterior a la fecha actual.\n");
        return 1;
    }

    // Calcular días
    int diasNacimiento = diasHastaFecha(diaNac, mesNac, anoNac);
    int diasActual = diasHastaFecha(diaActual, mesActual, anoActual);

    int diasBisiestos = diasBisiestosEntre(anoNac, anoActual);

    int edadEnDias = (anoActual - anoNac) * 365 + diasBisiestos + diasActual - diasNacimiento;

    printf("Tu edad es de %d días.\n", edadEnDias);

    return 0;
}