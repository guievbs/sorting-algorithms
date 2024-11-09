#include <stdio.h>
#include <stdlib.h>

// Protótipos das funções
void mergeSort(int arr[], int inicio, int fim);
void merge(int arr[], int inicio, int meio, int fim);
void imprimirArray(int arr[], int tamanho);

// Função principal do Merge Sort
void mergeSort(int arr[], int inicio, int fim) {
    // Verifica se há mais de um elemento para ordenar
    if (inicio < fim) {
        // Encontra o ponto médio do array
        int meio = inicio + (fim - inicio) / 2;
        
        // Chamadas recursivas para ordenar as duas metades
        mergeSort(arr, inicio, meio);     // Ordena primeira metade
        mergeSort(arr, meio + 1, fim);    // Ordena segunda metade
        
        // Combina as duas metades ordenadas
        merge(arr, inicio, meio, fim);
    }
}

// Função para combinar duas partes ordenadas
void merge(int arr[], int inicio, int meio, int fim) {
    int i, j, k;
    
    // Calcula o tamanho dos subarrays
    int tamanho_esquerda = meio - inicio + 1;
    int tamanho_direita = fim - meio;
    
    // Cria arrays temporários para armazenar as duas metades
    int *esquerda = (int*)malloc(tamanho_esquerda * sizeof(int));
    int *direita = (int*)malloc(tamanho_direita * sizeof(int));
    
    // Verifica se a alocação de memória foi bem sucedida
    if (esquerda == NULL || direita == NULL) {
        printf("Erro na alocação de memória!\n");
        return;
    }
    
    // Copia os dados para os arrays temporários
    for (i = 0; i < tamanho_esquerda; i++)
        esquerda[i] = arr[inicio + i];
    for (j = 0; j < tamanho_direita; j++)
        direita[j] = arr[meio + 1 + j];
    
    // Inicializa os índices dos subarrays e do array principal
    i = 0;      // Índice inicial do primeiro subarray
    j = 0;      // Índice inicial do segundo subarray
    k = inicio; // Índice inicial do array mesclado
    
    // Mescla os arrays temporários de volta ao array principal
    while (i < tamanho_esquerda && j < tamanho_direita) {
        if (esquerda[i] <= direita[j]) {
            arr[k] = esquerda[i];
            i++;
        } else {
            arr[k] = direita[j];
            j++;
        }
        k++;
    }
    
    // Copia os elementos restantes da esquerda, se houver
    while (i < tamanho_esquerda) {
        arr[k] = esquerda[i];
        i++;
        k++;
    }
    
    // Copia os elementos restantes da direita, se houver
    while (j < tamanho_direita) {
        arr[k] = direita[j];
        j++;
        k++;
    }
    
    // Libera a memória alocada
    free(esquerda);
    free(direita);
}

// Função auxiliar para imprimir o array
void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função principal para demonstração
int main() {
    // Array de exemplo
    int arr[] = {64, 342, 25, 991, 12, 661, 22, 11, 90, 1, 6, 44, 192, 813, 810, 7, 18};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array original: ");
    imprimirArray(arr, tamanho);
    
    // Chama o Merge Sort
    mergeSort(arr, 0, tamanho - 1);
    
    printf("Array ordenado: ");
    imprimirArray(arr, tamanho);
    
    return 0;
}