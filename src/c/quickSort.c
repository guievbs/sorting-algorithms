#include <stdio.h>

// Troca os valores de duas variáveis entre sí
void swap(int *a, int *b) {
    // Guarda o valor de a em c
    int c = *a;

    // Coloca o valor de b em a
    *a = *b;

    // Coloca o valor de c(a) em b
    *b = c;
}

// Particiona a lista e retorna o ponto de divisão
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pivo

    int point = low - 1;    // Ponto de divisão

    // Loop para percorrer toda a lista
    for (int j = low; j <= high; j++) {
        if (arr[j] < pivot) {
            point++;

            // Troca os valores
            swap(&arr[point], &arr[j]);
        }
    }

    // Troca o pivo com o ponto de divisão
    swap(&arr[point + 1], &arr[high]);
    return point + 1;    // Ponto de divisão
}

// Ordena uma lista de inteiros com o algoritmo Quick Sort.
int quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pt = partition(arr, low, high);  // Ponto de divisão

        // Recursão
        quickSort(arr, low, pt - 1);         // Ordena a parte esquerda
        quickSort(arr, pt + 1, high);        // Ordena a parte direita
    }
}

int main() {

    int arr[] = {12, 11, 13, 5, 6};  // Lista de números para ordenar
    int n = sizeof(arr) / sizeof(arr[0]);  // Tamanho da lista
    
    printf("Lista antes de ordenar: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    // Chama a função para ordenar a lista
    quickSort(arr, 0, n - 1);

    printf("Lista ordenada: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
