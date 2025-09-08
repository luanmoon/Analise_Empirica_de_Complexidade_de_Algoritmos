#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "benchmark.h"

#define REPETICOES 5

// Medir tempo de ordenação
double medirTempoOrdenacao(void (*sort)(int*, int), int arr[], int n) {
    clock_t inicio, fim;
    double soma = 0.0;

    int* copia = (int*) malloc(n * sizeof(int));
    for (int r = 0; r < REPETICOES; r++) {
        copiarArray(arr, copia, n);
        inicio = clock();
        sort(copia, n);
        fim = clock();
        soma += ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    }
    free(copia);
    return soma / REPETICOES;
}

// Medir tempo de busca
double medirTempoBusca(int (*busca)(int*, int, int), int arr[], int n) {
    clock_t inicio, fim;
    double soma = 0.0;

    for (int r = 0; r < REPETICOES; r++) {
        int chave = arr[rand() % n];
        inicio = clock();
        busca(arr, n, chave);
        fim = clock();
        soma += ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    }
    return soma / REPETICOES;
}
