#include <stdio.h>

// Função para fazer a organização
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Função para mostrar o array
void printArray(int arr[], int size) {
    if (arr == NULL || size == 0) {
        printf("Erro: Array invalido ou vazio\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// Função main
int main() {
    
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array Original: ");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("Array Ordenado: ");
    printArray(arr, n);

    return 0;
}
