/*
Escribe un programa que cree un vector de gran tamano (de miles de elementos), inicializandolo con numeros al azar.
Luego, ordena el vector con cada uno de los metedos de ordenacion que hemos visto (bubble sort, selection sort and quicksort)
contabilizando el tiempo que emplea cada uno (utiliza para eso la funcion time()). Muestra en pantalla el resultado de las
mediciones y observa las notables diferencias entre ellos. Realiza una busqueda secuencial y otra binaria sobre el vector ordenado,
contabilizando el numero de iteraciones empleado por cada uno y observa si hay diferencias mesurables entre ellas
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>

void ejecutarPrograma();

void fill_array(unsigned int *a, size_t n);
void copy_array(unsigned int *dst, const unsigned int *src, size_t n);
void bubble_sort(unsigned int *a, size_t n);
void selection_sort(unsigned int *a, size_t n);
int cmp_uint(const void *a, const void *b);
size_t sequential_search(const unsigned int *a, size_t n, unsigned int target, size_t *iterations);
size_t binary_search(const unsigned int *a, size_t n, unsigned int target, size_t *iterations);

int main(){
    srand(time(NULL));
    ejecutarPrograma();

    return 0;
}

void ejecutarPrograma(){
    size_t n = (size_t)(rand() % (60000 - 10000 + 1) + 10000);
    unsigned int *base = malloc(n * sizeof(unsigned int));
    if(!base){
        perror("malloc");
        return;
    }

    fill_array(base, n);

    printf("El tamano del arreglo es: %zu\n", n);

    unsigned int *a1 = malloc(n * sizeof(unsigned int));
    unsigned int *a2 = malloc(n * sizeof(unsigned int));
    unsigned int *a3 = malloc(n * sizeof(unsigned int));
    if(!a1 || !a2 || !a3){
        perror("malloc");
        free(base); free(a1); free(a2); free(a3);
        return;
    }

    copy_array(a1, base, n);
    copy_array(a2, base, n);
    copy_array(a3, base, n);

    clock_t start, end;
    double t_bubble = -1.0, t_selection = -1.0, t_qsort = -1.0;

    // Bubble sort (puede ser lento para tamaños muy grandes)
    start = clock();
    bubble_sort(a1, n);
    end = clock();
    t_bubble = (double)(end - start) / CLOCKS_PER_SEC;

    // Selection sort
    start = clock();
    selection_sort(a2, n);
    end = clock();
    t_selection = (double)(end - start) / CLOCKS_PER_SEC;

    // Quicksort usando qsort de la biblioteca
    start = clock();
    qsort(a3, n, sizeof(unsigned int), cmp_uint);
    end = clock();
    t_qsort = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Tiempos (s): bubble=%.3f selection=%.3f qsort=%.3f\n", t_bubble, t_selection, t_qsort);

    // Seleccionamos un valor existente para las búsquedas
    unsigned int target = base[rand() % n];
    size_t iter_seq = 0, iter_bin = 0;
    size_t idx_seq = sequential_search(a3, n, target, &iter_seq);
    size_t idx_bin = binary_search(a3, n, target, &iter_bin);

    if(idx_seq < n) printf("Busqueda secuencial: encontrado en pos %zu en %zu iteraciones\n", idx_seq, iter_seq);
    else printf("Busqueda secuencial: no encontrado (iter=%zu)\n", iter_seq);

    if(idx_bin < n) printf("Busqueda binaria: encontrado en pos %zu en %zu iteraciones\n", idx_bin, iter_bin);
    else printf("Busqueda binaria: no encontrado (iter=%zu)\n", iter_bin);

    free(base);
    free(a1); free(a2); free(a3);
}

void fill_array(unsigned int *a, size_t n){
    for(size_t i=0;i<n;i++){
        a[i] = (unsigned int)rand();
    }
}

void copy_array(unsigned int *dst, const unsigned int *src, size_t n){
    for(size_t i=0;i<n;i++) dst[i]=src[i];
}

void bubble_sort(unsigned int *a, size_t n){
    for(size_t i=0;i+1<n;i++){
        bool swapped = false;
        for(size_t j=0;j+1<n-i;j++){
            if(a[j] > a[j+1]){
                unsigned int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

void selection_sort(unsigned int *a, size_t n){
    for(size_t i=0;i+1<n;i++){
        size_t min_i = i;
        for(size_t j=i+1;j<n;j++){
            if(a[j] < a[min_i]) min_i = j;
        }
        if(min_i != i){
            unsigned int tmp = a[i];
            a[i] = a[min_i];
            a[min_i] = tmp;
        }
    }
}

int cmp_uint(const void *a, const void *b){
    unsigned int ua = *(const unsigned int*)a;
    unsigned int ub = *(const unsigned int*)b;
    if(ua < ub) return -1;
    if(ua > ub) return 1;
    return 0;
}

size_t sequential_search(const unsigned int *a, size_t n, unsigned int target, size_t *iterations){
    *iterations = 0;
    for(size_t i=0;i<n;i++){
        (*iterations)++;
        if(a[i] == target) return i;
    }
    return n;
}

size_t binary_search(const unsigned int *a, size_t n, unsigned int target, size_t *iterations){
    *iterations = 0;
    size_t left = 0, right = (n==0?0:n-1);
    while(left <= right && left < n){
        (*iterations)++;
        size_t mid = left + (right - left) / 2;
        if(a[mid] == target) return mid;
        if(a[mid] < target) left = mid + 1;
        else {
            if(mid == 0) break;
            right = mid - 1;
        }
    }
    return n;
}