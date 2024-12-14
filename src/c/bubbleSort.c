#include <stdio.h>

// Função para realizar a ordenação do array usando o algoritmo Bubble Sort,
// exibindo passo a passo o estado do array após cada operação.
void bubbleSort(int arr[], int n) {
    // Verifica se o array está vazio
    if (n == 0) {
        printf("O array está vazio e não há nada para ordenar.\n");
        return;
    }

    // Exibe o estado inicial do array
    printf("Array inicial: ");
    for (int k = 0; k < n; k++) printf("%d ", arr[k]);
    printf("\n\n");

    // Loop principal: controla o número de passagens pelo array
    for (int i = 0; i < n - 1; i++) {
        printf("Passo %d:\n", i + 1);

        // Variável para rastrear se houve trocas durante a passagem
        int trocou = 0;

        // Loop secundário: realiza as comparações e trocas entre elementos adjacentes
        for (int j = 0; j < n - 1 - i; j++) {
            printf("  Comparando %d e %d", arr[j], arr[j + 1]);

            // Se o elemento atual é maior que o próximo, realiza a troca
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];     // Armazena o valor do elemento atual em uma variável temporária
                arr[j] = arr[j + 1];  // Move o próximo elemento para a posição atual
                arr[j + 1] = temp;    // Coloca o valor armazenado na próxima posição
                trocou = 1;           // Marca que uma troca foi realizada
                printf(" => Troca realizada");
            }
            printf("\n");
        }

        // Mostra o estado do array após cada passagem
        printf("  Estado atual do array: ");
        for (int k = 0; k < n; k++) printf("%d ", arr[k]);
        printf("\n");

        // Se nenhuma troca foi feita, o array já está ordenado
        if (!trocou) {
            printf("  Nenhuma troca realizada, array já está ordenado.\n");
            break; // Encerra o loop principal mais cedo
        }
        printf("\n");
    }

    // Exibe o estado final do array após a ordenação
    printf("\nArray final ordenado: ");
    for (int k = 0; k < n; k++) printf("%d ", arr[k]);
    printf("\n");
}

int main() {
    // Array de exemplo para teste
    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    // Calcula o tamanho do array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Chama a função de ordenação passo a passo
    bubbleSort(arr, n);

    return 0;
}
