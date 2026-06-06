/*
Programa en C un pequeño juego que podemos bautizar como juego de memoria. Será un juego en modo texto (bastante feo, por lo tanto)
pero que nos servira para afianzar todos los conocmientos adquiridos hasta ahora.

Reglas del juego:
♦  El juego comenzara preguntando el nivel de dificultad, que puede ser fácil, medio o dificil.
♦  El ordenador elegirá al azar una serie de números. La serie consistirá al principio en un solo número.
   Luego serán dos números, luego tres, luego cuatro y así consecutivamente  hasta diez. Los numeros de la serie solo pueden ser [1,2,3]
♦  El ordenador mostrara su serie de numeros durante un tiempo en la pantalla. Ese tiempo sera tanto menor cuanto mas alto sea
   el nivel de dificultad.
♦  Despues, la serie se borrará y el jugador debe demostrar su memoria y sus reflejos repitiéndola.
♦  Si el jugador acierta en todos los números de la serie, el ordenador pasará a su siguiente serie (que tendrá un número más).
   Si el jugador falla, el juego termina.
♦  Si el jugador es capaz de repetir con exito todas las series (desde la que solo tiene un numero hasta la que tiene 10) el jugador gana
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>

// Detectamos el sistema operativo para cargar las librerías adecuadas
#ifdef _WIN32
    #include <windows.h> // Librería para Windows
    #define LIMPIAR_PANTALLA "cls"
#else
    #include <unistd.h>  // Librería para Linux / Mac
    #define LIMPIAR_PANTALLA "clear"
#endif

// Función para imprimir los datos (también usando %hu)
void imprimirArreglo(short unsigned int *arreglo, int cantidad) {
    printf("Contenido del arreglo: [ ");
    for (int i = 0; i < cantidad; i++) {
        printf("%hu ", arreglo[i]);
    }
    printf("]\n");
}

/**
 * @brief Genera una secuencia de números aleatorios para memorizar.
 *
 * Esta función llena un arreglo dinámico con valores aleatorios entre 1 y 3
 * (ambos inclusive). Cada posición del arreglo se asigna con un número nuevo
 * generado por rand().
 *
 * @param arregloDinamico Puntero al inicio del arreglo donde se guardarán
 *                        los números generados. El arreglo debe tener al menos
 *                        @p tamano elementos válidos.
 * @param tamano         Cantidad de números que se generarán y almacenarán en
 *                        el arreglo.
 *
 * @details
 * La función inicializa la semilla de la librería pseudoaleatoria con la hora
 * actual mediante srand(time(NULL)). Luego recorre el arreglo con un bucle for
 * y asigna a cada elemento un valor entre 1 y 3 usando la expresión
 * (rand() % 3) + 1.
 *
 * @note Debido a la llamada a srand() en cada invocación, si esta función se
 *       llama varias veces en el mismo segundo, la secuencia de números puede
 *       repetirse. Para un uso más robusto conviene sembrar la semilla una sola
 *       vez al iniciar el programa.
 */
void generarNumerosMemorizar(short unsigned int *arregloDinamico, short unsigned int tamano)
{
    // Semilla para aletoriedad de los numeros de la serie
    srand(time(NULL)); // numero = (rand() % (MAXIMO - MINIMO + 1)) + MINIMO;
    short unsigned int contador;
    for (contador=0; contador<tamano; contador++)
    {
        *(arregloDinamico+contador) = (rand() % 3) + 1;
    }
}

void imprimirNumerosMemorizar(short unsigned int *arregloDinamico, short unsigned int tamano)
{
    short unsigned int contador;
    puts("\nCOMENZAMOS\nMemoriza estos numeros:");
    for (contador=0; contador<tamano; contador++)
    {
        printf("%hu ", *(arregloDinamico+contador));
    }
}

/**
 * @brief Espera un tiempo determinado y elimina la información de la pantalla.
 *
 * Esta función muestra la pantalla del juego el tiempo necesario para que el
 * usuario memorice la secuencia y, una vez transcurrido ese intervalo, borra
 * el contenido de la consola.
 *
 * @param TIEMPO_ESPERAR Intervalo de espera antes de limpiar la consola.
 *                       En Windows se interpreta como milisegundos. En sistemas
 *                       POSIX (Linux/Mac) se interpreta como segundos.
 *
 * @details
 * Primero se fuerza el vaciado del búfer de salida con fflush(stdout), de modo
 * que todo el texto pendiente se muestre antes de pausar la ejecución. A
 * continuación, se llama a Sleep() en Windows o sleep() en sistemas POSIX
 * para suspender el programa durante el tiempo indicado. Por último, se ejecuta
 * el comando de limpieza de pantalla definido por la macro LIMPIAR_PANTALLA.
 *
 * @note El comportamiento de @p TIEMPO_ESPERAR depende de la plataforma. En
 *       Windows su unidad es milisegundos, mientras que en Linux/Mac es segundos.
 */
void desaparecerValores(unsigned short int TIEMPO_ESPERAR)
{
    // fflush(stdout) fuerza a la consola a mostrar el texto inmediatamente. 
    // Es muy importante ponerlo antes de pausar el programa.
    fflush(stdout); 
    // Limpiamos la pantalla despues de esperar el tiempo necesario
    // Pausamos el programa por 5 segundos
    #ifdef _WIN32
        Sleep(TIEMPO_ESPERAR); // En Windows, la función Sleep usa milisegundos (5000 ms = 5 s)
    #else
        sleep(TIEMPO_ESPERAR);    // En Linux/Mac, la función sleep usa segundos directos
    #endif

    // Limpiamos la pantalla
    system(LIMPIAR_PANTALLA);
}

/**
 * @brief Compara lo que ingresó el usuario con la secuencia generada.
 *
 * Esta función solicita al usuario los números que recuerda haber visto,
 * los almacena en un arreglo dinámico y luego compara cada valor con la
 * secuencia original que generó el programa.
 *
 * @param arregloGeneradoPorComputadora Puntero a la secuencia generada por la
 *                                      computadora.
 * @param tamano_arreglo               Número de elementos a leer y comparar.
 *
 * @return true  Si todos los números introducidos coinciden con la secuencia.
 * @return false Si al menos un número no coincide.
 *
 * @details
 * Se reserva memoria dinámica para almacenar la entrada del usuario. Luego se
 * leen los valores con scanf() y se comparan uno a uno con los valores
 * originales. Si existe una discrepancia, la función libera la memoria
 * asignada y devuelve false de inmediato. Si todos los valores coinciden,
 * libera la memoria y devuelve true.
 */
bool comprobarMemoria(short unsigned int *arregloGeneradoPorComputadora, short unsigned int tamano_arreglo)
{
    // Declaramos el arreglo en el que el usuario pondra los numeros que se acuerde del mismo tamano que el generado
    short unsigned int *arregloMemorizadoUsuario;
    arregloMemorizadoUsuario = (short unsigned int *)malloc(tamano_arreglo * sizeof(short unsigned int));
    if (arregloMemorizadoUsuario==NULL){
        printf("No se pudo reservar espacio en la memoria.\n");
        system("exit");
    }

    // Dejamos que el usuario introduzca los numeros que recuerde
    short unsigned int contador;
    for (contador=0; contador<tamano_arreglo; contador++){
        scanf("%hu", arregloMemorizadoUsuario+contador);
    }

    // Mostramos los numeros ingresados y los numeros generados
    printf("numeros introducidos son: ");
    imprimirArreglo(arregloMemorizadoUsuario, tamano_arreglo);
    imprimirArreglo(arregloGeneradoPorComputadora, tamano_arreglo);

    // Comprobamos que cada uno de los numeros sean equivalentes
    for (contador=0; contador<tamano_arreglo; contador++){
        // Si falla, se abortara y se retornara la respuesta al usuario del fracaso
        if (*(arregloMemorizadoUsuario+contador) != *(arregloGeneradoPorComputadora+contador)) 
        {
            // Liberamos la memoria antes de salir para evitar fugas (Memory Leaks)
            free(arregloMemorizadoUsuario);
            arregloMemorizadoUsuario=NULL;
            
            return false;
        }
    }

    // Liberamos memoria usada y notificamos exito en la respuesta del usuario
    free(arregloMemorizadoUsuario);
    arregloMemorizadoUsuario=NULL;
    return true;
}

/**
 * @brief Ejecuta las rondas del juego de memoria.
 *
 * Esta función administra la mecánica principal del juego: genera una
 * secuencia de números de longitud creciente, la muestra para que el usuario
 * la memorice, oculta los valores, y luego comprueba si la respuesta del
 * jugador es correcta.
 *
 * @param ajuste_dificultad Tiempo de espera empleado antes de desaparecer los
 *                          valores mostrados en pantalla. En Windows se
 *                          interpreta como milisegundos; en Linux/Mac como
 *                          segundos.
 *
 * @details
 * El juego avanza en rondas desde la primera hasta la décima. En cada ronda se
 * reserva memoria dinámica para la secuencia actual, se genera un arreglo de
 * números aleatorios de la longitud de la ronda, se imprimen para que el
 * usuario los memorice y se ocultan después de un tiempo determinado.
 * Después de limpiar la pantalla, se solicita al usuario que introduzca los
 * valores recordados y se compara su respuesta con la secuencia original.
 *
 * Si el jugador falla en cualquier ronda, el juego termina; si completa todas
 * las rondas, se muestra un mensaje de victoria.
 *
 * @note Se libera la memoria asignada para cada ronda antes de pasar a la
 * siguiente para evitar fugas de memoria.
 */
void pruebaMemoria(unsigned short int ajuste_dificultad)
{
    // Inicio de las rondas
    unsigned short int rondas = 1;

    // Aqui se hara todo el proceso de las rondas hasta llegar a 10
    while (rondas<=10)
    {
        // La cantidad de posiciones se determinará por la variable 'rondas'
        unsigned short int *sucecion_a_memorizar_de_numeros;
        bool correcto = false;
        sucecion_a_memorizar_de_numeros = (short unsigned int*)malloc(rondas * sizeof(short unsigned int));
        if (sucecion_a_memorizar_de_numeros==NULL)
        {
            printf("Error al asignar la memoria");
            system("exit");
        }

        generarNumerosMemorizar(sucecion_a_memorizar_de_numeros, rondas);
        imprimirNumerosMemorizar(sucecion_a_memorizar_de_numeros, rondas);
        desaparecerValores(ajuste_dificultad);
        printf("\n\nIngrese los numeros que aparecieron anteriormente:\n");
        correcto = comprobarMemoria(sucecion_a_memorizar_de_numeros, rondas);

        // Al finalizar la ronda liberaremos la memoria usada
        free(sucecion_a_memorizar_de_numeros);
        sucecion_a_memorizar_de_numeros=NULL;
        rondas++;

        if (correcto==false) {puts("Has fallado!"); break;} else {puts("Correcto!");}
    }

    // Si llega aquí el usuario significa que gano
    if (rondas>10) {puts("FELICIDADES!!! GANASTE!!!");}
}

/**
 * @brief Configura y da inicio al juego de memoria.
 *
 * Solicita al usuario el nivel de dificultad, valida la entrada y calcula el
 * tiempo que el juego mostrará cada secuencia antes de ocultarla. A continuación,
 * inicia la rutina de pruebas llamando a pruebaMemoria().
 *
 * @details
 * El usuario puede escoger entre tres niveles: fácil, medio o difícil. Si se
 * introduce un valor inválido, el juego selecciona el nivel fácil por defecto.
 * Luego, convierte el valor de dificultad en un intervalo de tiempo en función de
 * la plataforma: en Windows se traduce a milisegundos y en Linux/Mac a segundos.
 * Finalmente, se inicia la serie de rondas del juego con pruebaMemoria().
 */
void iniciarJuego()
{
    // Variables esenciales para ajustes del juego
    unsigned short int dificultad;

    // Solicitamos el nivel de dificultad al usuario
    printf("Ingrese la dificultad (3 facil, 2 medio y 1 dificil): ");
    scanf("%hu", &dificultad);

    // Verificamos que sea valido
    if (dificultad<1 || dificultad>3) {dificultad = 3;} // Por default será fácil

    // Prueba de impresion
    printf("La dificultad seleccionada es %hu.\nAhora comenzaran las rondas\n", dificultad);
    // Para la dificultad mas facil se dan 15 segundos, media es 10 seg y dificil son 5 seg
    #ifdef _WIN32
        dificultad = dificultad * 5000; // Para Windows se define el tiempo base en 5000ms * dificultad = ajuste_dificultad
    #else
        dificultad = dificultad * 5 // En Linux/Mac, se define el tiempo base en 5s * dificultad = ajuste_dificultad
    #endif
    pruebaMemoria(dificultad);
}

/**
 * @brief Punto de entrada del juego de memoria.
 *
 * El programa se ejecuta en un bucle que solicita al usuario si desea iniciar
 * una partida o finalizar la ejecución. Si el usuario introduce 1, se llama a
 * iniciarJuego() para comenzar la secuencia de memorizar números. Si se
 * introduce 0, el programa muestra un mensaje de despedida y finaliza.
 *
 * @return int Devuelve 0 al terminar correctamente.
 *
 * @details
 * main() gestiona la interacción básica con el usuario mediante un bucle do-while.
 * Dentro del bucle, solicita la entrada del usuario con scanf() y decide si
 * llamará a iniciarJuego() o terminará la ejecución. El bucle se repite mientras
 * la variable continuar_juego tenga el valor 1.
 */
int main()
{
    int continuar_juego;

    do
    {
        printf("Bienvenido al juego: (Ingresa 1 para comenzar o 0 para abandonar)\n");
        scanf("%d", &continuar_juego);
        (continuar_juego==1) ? iniciarJuego() : puts("Juego terminado...");
    } while (continuar_juego==1);
     
    return 0;
}

// Codigo de prueba para "desvancer" el texto
/*
int main() {
    unsigned int respuesta;

    printf("=======================================\n");
    printf("           JUEGO DE MEMORIA            \n");
    printf("=======================================\n\n");
    
    printf("Preparate... Memoriza el siguiente numero:\n\n");
    
    // Imprimimos el texto que queremos que desaparezca
    printf(" ---> 7 4 9 2 5 <--- \n");
    
    // fflush(stdout) fuerza a la consola a mostrar el texto inmediatamente. 
    // Es muy importante ponerlo antes de pausar el programa.
    fflush(stdout); 

    // Pausamos el programa por 5 segundos
    #ifdef _WIN32
        Sleep(5000); // En Windows, la función Sleep usa milisegundos (5000 ms = 5 s)
    #else
        sleep(5);    // En Linux/Mac, la función sleep usa segundos directos
    #endif

    // Limpiamos la pantalla
    system(LIMPIAR_PANTALLA);

    // El texto anterior desapareció, ahora continuamos el juego
    printf("¡Tiempo agotado!\n");
    printf("¿Cual era el numero que aparecia en pantalla?: ");
    scanf("%d", &respuesta);

    if (respuesta == 74925) {
        printf("\n¡Correcto! Tienes excelente memoria.\n");
    } else {
        printf("\nIncorrecto. El numero era 74925.\n");
    }

    return 0;
}
*/