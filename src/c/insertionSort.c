#include <stdio.h>

void insertionSort(int arr[], int n) {
    // Vamos começar do segundo elemento (posição 1)
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // Escolhemos um número para ordenar
        int j = i - 1;     // Posição do número à esquerda

        // Enquanto o número à esquerda for maior que o número escolhido
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Mova o número para a direita
            j--;                  // Ande uma posição para trás
        }

        // Coloca o número escolhido na posição certa
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};  // Lista de números para ordenar
    int n = sizeof(arr) / sizeof(arr[0]);  // Tamanho da lista

    printf("Lista antes de ordenar: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    // Chama a função para ordenar a lista
    insertionSort(arr, n);

    printf("Lista ordenada: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
