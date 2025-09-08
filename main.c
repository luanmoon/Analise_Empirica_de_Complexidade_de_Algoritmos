#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "algorithms.h"
#include "benchmark.h"

#define MAX_N 20000
#define STEP 2000
#define NUM_FUNCS 4
#define MAX_TESTS ((MAX_N - 1000)/STEP + 1)

// Funções teóricas
double f_n(int n) { return (double)n; }
double f_log(int n) { return (n > 0) ? log2(n) : 0.0; }
double f_nlogn(int n) { return (n > 0) ? n * log2(n) : 0.0; }
double f_n2(int n) { return (double)n * n; }

// Estrutura de função teórica
typedef struct {
    const char *nome;
    double (*func)(int);
} FuncaoTeorica;

// Normalizar para mesma escala
void normalizar(double *teorico, double *real, int m) {
    double maxReal = real[0], maxTheo = teorico[0];
    for (int i = 1; i < m; i++) {
        if (real[i] > maxReal) maxReal = real[i];
        if (teorico[i] > maxTheo) maxTheo = teorico[i];
    }
    double fator = maxReal / maxTheo;
    for (int i = 0; i < m; i++) {
        teorico[i] *= fator;
    }
}

// Calcular erro médio quadrático
double calcularErro(double *real, double *teorico, int m) {
    double soma = 0.0;
    for (int i = 0; i < m; i++) {
        double diff = real[i] - teorico[i];
        soma += diff * diff;
    }
    return soma / m;
}

// Encontrar melhor ajuste
const char* melhorAjuste(double *real, int *nVals, int m) {
    FuncaoTeorica funcs[NUM_FUNCS] = {
        {"O(n)", f_n},
        {"O(log n)", f_log},
        {"O(n log n)", f_nlogn},
        {"O(n^2)", f_n2}
    };

    double menorErro = 1e18;
    const char* melhor = "";

    for (int k = 0; k < NUM_FUNCS; k++) {
        double teorico[MAX_TESTS];
        for (int i = 0; i < m; i++) {
            teorico[i] = funcs[k].func(nVals[i]);
        }
        normalizar(teorico, real, m);
        double erro = calcularErro(real, teorico, m);
        if (erro < menorErro) {
            menorErro = erro;
            melhor = funcs[k].nome;
        }
    }
    return melhor;
}

int main() {
    srand(time(NULL));
    FILE* f = fopen("resultados.csv", "w");
    if (!f) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    fprintf(f, "n,bubbleSort,insertionSort,buscaSeq,buscaBin\n");

    // Armazenar tempos
    int nVals[MAX_TESTS];
    double bubble[MAX_TESTS], insert[MAX_TESTS], seq[MAX_TESTS], bin[MAX_TESTS];
    int m = 0;

    for (int n = 1000; n <= MAX_N; n += STEP) {
        int* arr = (int*) malloc(n * sizeof(int));
        preencherAleatorio(arr, n);

        double tBubble = medirTempoOrdenacao(bubbleSort, arr, n);
        double tInsert = medirTempoOrdenacao(insertionSort, arr, n);

        insertionSort(arr, n); // necessário para busca binária
        double tSeq = medirTempoBusca(buscaSequencial, arr, n);
        double tBin = medirTempoBusca(buscaBinaria, arr, n);

        nVals[m] = n;
        bubble[m] = tBubble;
        insert[m] = tInsert;
        seq[m] = tSeq;
        bin[m] = tBin;
        m++;

        fprintf(f, "%d,%.6f,%.6f,%.6f,%.6f\n",
                n, tBubble, tInsert, tSeq, tBin);

        free(arr);
    }
    fclose(f);

    // Indicar melhor ajuste para cada algoritmo
    printf("\n=== Melhor ajuste teórico ===\n");
    printf("Bubble Sort: %s\n", melhorAjuste(bubble, nVals, m));
    printf("Insertion Sort: %s\n", melhorAjuste(insert, nVals, m));
    printf("Busca Sequencial: %s\n", melhorAjuste(seq, nVals, m));
    printf("Busca Binária: %s\n", melhorAjuste(bin, nVals, m));

    printf("\nResultados salvos em resultados.csv\n");
    return 0;
}
