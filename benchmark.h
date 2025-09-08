#ifndef BENCHMARK_H
#define BENCHMARK_H

#include "algorithms.h"
#include <time.h>

// Funções de benchmark
double medirTempoOrdenacao(void (*sort)(int*, int), int arr[], int n);
double medirTempoBusca(int (*busca)(int*, int, int), int arr[], int n);

#endif
