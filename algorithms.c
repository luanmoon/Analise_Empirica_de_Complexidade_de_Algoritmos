#include <stdio.h>
#include <stdlib.h>
#include "algorithms.h"

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// Busca Sequencial
int buscaSequencial(int arr[], int n, int chave) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == chave)
            return i;
    }
    return -1;
}

// Busca Binária
int buscaBinaria(int arr[], int n, int chave) {
    int inicio = 0, fim = n-1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (arr[meio] == chave) return meio;
        if (arr[meio] < chave) inicio = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

// Preencher vetor aleatório
void preencherAleatorio(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (n*10);
    }
}

// Copiar array
void copiarArray(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}
