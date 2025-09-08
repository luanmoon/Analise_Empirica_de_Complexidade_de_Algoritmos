#ifndef ALGORITHMS_H
#define ALGORITHMS_H

// Ordenação
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);

// Busca
int buscaSequencial(int arr[], int n, int chave);
int buscaBinaria(int arr[], int n, int chave);

// Auxiliares
void preencherAleatorio(int arr[], int n);
void copiarArray(int origem[], int destino[], int n);

#endif
