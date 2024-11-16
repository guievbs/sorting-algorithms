#include <stdio.h>
#include <string.h>

void counting_sort(int arr[], int n) {
    // Encontrar o maior valor no array para definir o tamanho do array auxiliar
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Criar um array auxiliar para armazenar as contagens, inicializado com 0
    int count[max + 1];
    memset(count, 0, sizeof(count));

    // Contar a ocorrência de cada elemento no array original
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Modificar o array count para armazenar as posições corretas dos elementos
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Criar um array para o resultado final ordenado
    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copiar o array ordenado de volta para o array original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Função principal para testes
int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    counting_sort(arr, n);

    printf("Array ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
