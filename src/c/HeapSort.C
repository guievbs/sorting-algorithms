#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int largest = i;           // Inicializa o maior como raiz
    int left = 2 * i + 1;      // Filho à esquerda
    int right = 2 * i + 2;     // Filho à direita

    // Se o filho à esquerda é maior que a raiz
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Se o filho à direita é maior que o maior até agora
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Se o maior não for a raiz
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Chama heapify na subárvore afetada
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    // Constrói o heap (reorganiza o array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extrai um elemento de cada vez do heap
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual para o final
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Chama heapify no heap reduzido
        heapify(arr, i, 0);
    }
}

// Função principal para testes
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    heap_sort(arr, n);

    printf("Array ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
