#include <stdio.h>

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

int main() {
    int arr1[] = {};  // Array vazio
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    printf("Array antes de ordenar (vazio): ");
    for (int i = 0; i < n1; i++) printf("%d ", arr1[i]);
    printf("\n");

    bubbleSort(arr1, n1);  // Teste com array vazio

    printf("Array depois de ordenar (vazio): ");
    for (int i = 0; i < n1; i++) printf("%d ", arr1[i]);
    printf("\n");

    // Outro exemplo com array preenchido
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("\nArray antes de ordenar: ");
    for (int i = 0; i < n2; i++) printf("%d ", arr2[i]);
    printf("\n");

    bubbleSort(arr2, n2);  // Teste com array preenchido

    printf("Array depois de ordenar: ");
    for (int i = 0; i < n2; i++) printf("%d ", arr2[i]);
    printf("\n");

    return 0;
}
