#include <stdio.h>

// Função para ordenar um array usando o algoritmo Insertion Sort
void insertionSort(int arr[], int n) {
    // Começa do segundo elemento, pois assumimos que o primeiro já está "ordenado"
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // Número atual a ser inserido na parte ordenada do array
        int j = i - 1;     // Índice do último elemento da parte ordenada

        // Move elementos da parte ordenada que são maiores que 'key' para uma posição à frente
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Move o elemento para a direita
            j--;                  // Avança para o próximo elemento à esquerda
        }

        // Insere o 'key' na posição correta
        arr[j + 1] = key;

        // Exibe o estado do array após cada iteração
        printf("Iteração %d: ", i);
        for (int k = 0; k < n; k++) printf("%d ", arr[k]);
        printf("\n");
    }
}

int main() {
    // Array de exemplo para teste
    int arr[] = {12, 11, 13, 5, 6};

    // Calcula o tamanho do array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Exibe o array antes da ordenação
    printf("Lista antes de ordenar: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    // Chama a função de ordenação
    insertionSort(arr, n);

    // Exibe o array após a ordenação
    printf("Lista ordenada: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
