/*
Implementa en C el programa que convierte numeros de hasta 5 cifras a su denominacion en letra. Por ejemplo, si se introduce el numero
1980, la salida del programa debe ser "mil novecientos ochenta"
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define NUM_STRINGS 20
#define LONG_STRING 15

void obtenerValorEscrito(int numero)
{
    // Podemos observar 2 formas de aproximarnos al resultado: una es descomponiendo el valor por sumas entre digitos || leer caracter por caracter
    // Caso 1: Sea 1984 entonces 1000 + 900 + 80 + 4 -> mil novecientos ochenta cuatro
    // Caso 2: Sea 15374 entonces "15374", leemos de izq a der considerando el tamaño del string [4]->[0]=1, [1]=5, [2]=3, [3]=7, [4]=4 -> quince mil trescientos setenta y cuatro
    // Usaremos el caso 1
    char diccionarioDeNumeros[NUM_STRINGS][LONG_STRING] = {
        "cero", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve",
        "diez", "once", "doce", "trece", "catorce", "quince", "dieciseis", "diecisiete", "dieciocho", "diecinueve"
    };
    
    char decenas[10][LONG_STRING] = {
        "", "", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"
    };
    
    char centenas[10][LONG_STRING] = {
        "", "ciento", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos"
    };
    
    // Descomponer el número
    int unidades = numero % 10;
    int decena = (numero / 10) % 10;
    int centena = (numero / 100) % 10;
    int milesDecena = (numero / 1000) % 10;
    int milesUnidad = (numero / 10000) % 10;
    
    if (numero == 0) {
        printf("%s\n", diccionarioDeNumeros[0]);
        return;
    }
    
    // Procesar decenas de mil y unidades de mil
    int milesCompletos = milesUnidad * 10 + milesDecena;
    
    if (milesCompletos >= 10 && milesCompletos <= 19) {
        // Números entre 10.000 y 19.999 (diez mil a diecinueve mil)
        printf("%s mil", diccionarioDeNumeros[milesCompletos]);
        printf(" ");
    } else if (milesUnidad > 0) {
        // Números entre 20.000 y 99.999
        printf("%s", diccionarioDeNumeros[milesUnidad]);
        if (milesDecena > 0) {
            printf(" %s", decenas[milesDecena]);
        }
        printf(" mil");
        printf(" ");
    } else if (milesDecena > 0) {
        // Números entre 1.000 y 9.999
        printf("%s mil", diccionarioDeNumeros[milesDecena]);
        printf(" ");
    }
    
    // Procesar centenas
    if (centena > 0) {
        if (centena == 1 && decena == 0 && unidades == 0) {
            printf("cien");
        } else {
            printf("%s", centenas[centena]);
        }
        if (decena > 0 || unidades > 0) printf(" ");
    }
    
    // Procesar decenas y unidades
    int dosDigitos = decena * 10 + unidades;
    
    if (dosDigitos >= 10 && dosDigitos <= 19) {
        printf("%s", diccionarioDeNumeros[dosDigitos]);
    } else {
        if (decena > 0) {
            printf("%s", decenas[decena]);
            if (unidades > 0) printf(" y ");
        }
        if (unidades > 0 || (decena == 0 && centena == 0 && milesUnidad == 0 && milesDecena == 0)) {
            printf("%s", diccionarioDeNumeros[unidades]);
        }
    }
    printf("\n");
}

bool menuControl(int *numeroParaConvertir)
{
    unsigned int opcion;
    /*
    Opcion 0: Ingresar numero
    Opcion 1: Interpretar numero
    Opcion 2: Salir
    */
   printf("Opcion 0: Ingresar numero\nOpcion 1: Interpretar numero\nOpcion 2: Salir\nIngrese la opcion que desea realizar: ");
   scanf("%d", &opcion);

   if (opcion==0)
   {
        scanf("%d", numeroParaConvertir);
        // Expresion para garantizar que el numero se mantenga en el rango
        *numeroParaConvertir = (*numeroParaConvertir>=0 && *numeroParaConvertir<100000) ? *numeroParaConvertir : 0;
        return true;
   }
   else if (opcion==1)
   {
        obtenerValorEscrito(*numeroParaConvertir);
   }
   else if (opcion==2) {return false;}
   else {puts("Ingrese una opcion disponible"); return true;}
}

int main()
{
    bool revision = false;
    int numeroParaConvertir = 0;
    do
    {
        revision = menuControl(&numeroParaConvertir);
        puts("\n\n");
    } while (revision);
    
    
    return 0;
}