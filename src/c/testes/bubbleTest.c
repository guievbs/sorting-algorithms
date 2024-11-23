#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

// Função bubbleSort implementada
void bubbleSort(int arr[], int n) {
    // Verifica se o array está vazio
    if (n == 0) {
        printf("O array está vazio e não há nada para ordenar.\n");
        return;
    }

    // Loop para percorrer toda a lista
    for (int i = 0; i < n - 1; i++) {
        // Loop para comparar pares de elementos
        for (int j = 0; j < n - 1 - i; j++) {
            // Se o elemento atual é maior que o próximo, faz a troca
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];     // Guarda o valor temporário para troca
                arr[j] = arr[j + 1];   // Coloca o próximo no lugar do atual
                arr[j + 1] = temp;     // Coloca o temporário no próximo
            }
        }
    }
}

// Função para criar um array aleatório
void generateRandomArray(int arr[], int size, int max) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % max;
    }
}

// Função para imprimir um array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função para verificar se um array está ordenado
int isSorted(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

// Função principal para execução dos casos de teste
void testBubbleSort() {
    const int MAX_SIZE = 100;
    
    // Caso de teste 1: Array vazio
    int emptyArray[MAX_SIZE];
    printf("Testando array vazio...\n");
    bubbleSort(emptyArray, MAX_SIZE);
    assert(isSorted(emptyArray, MAX_SIZE));

    // Caso de teste 2: Array ordenado
    int sortedArray[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        sortedArray[i] = i;
    }
    printf("Testando array ordenado...\n");
    bubbleSort(sortedArray, MAX_SIZE);
    assert(isSorted(sortedArray, MAX_SIZE));

    // Caso de teste 3: Array desordenado
    int unsortedArray[MAX_SIZE];
    generateRandomArray(unsortedArray, MAX_SIZE, 100);
    printf("Testando array desordenado...\n");
    bubbleSort(unsortedArray, MAX_SIZE);
    assert(isSorted(unsortedArray, MAX_SIZE));

    // Caso de teste 4: Array com elementos repetidos
    int repeatedArray[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        repeatedArray[i] = rand() % 50;
    }
    printf("Testando array com elementos repetidos...\n");
    bubbleSort(repeatedArray, MAX_SIZE);
    assert(isSorted(repeatedArray, MAX_SIZE));

    // Caso de teste 5: Array muito grande
    int largeArray[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        largeArray[i] = rand() % 2000;
    }
    printf("Testando array muito grande...\n");
    bubbleSort(largeArray, MAX_SIZE);
    assert(isSorted(largeArray, MAX_SIZE));

    // Caso de teste 6: Array nulo ou inválido
    printf("Testando array nulo ou inválido...\n");
    int invalidArray[0];
    bubbleSort(invalidArray, 0);
}

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    testBubbleSort();
    printf("Todos os casos de teste passaram.\n");
    return 0;
}