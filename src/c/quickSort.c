#include <stdio.h>

/**
 * Troca os valores de duas variáveis entre sí.
 *
 * @param a Primeira variável
 * @param b Segunda variável
 */
void swap(int *a, int *b)
{
    // Guarda o valor de a em c
    int c = *a;

    // Coloca o valor de b em a
    *a = *b;

    // Coloca o valor de c(a) em b
    *b = c;
}

/**
 * Particiona o array e retorna o índice do ponto de divisão.
 *
 * @param arr Array de inteiros a ser particionado
 * @param low Índice inicial da sublista
 * @param high Índice final da sublista
 * @return Índice do ponto de divisão
 */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Elemento pivô

    // Percorre o array para organizar elementos em relação ao pivô
    int point = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            point++;                    // Incrementa o índice do ponto de divisão
            swap(&arr[point], &arr[j]); // Troca os elementos
        }
    }

    // Coloca o pivô em sua posição correta no array
    swap(&arr[point + 1], &arr[high]);
    return point + 1; // Retorna o índice do ponto de divisão
}

/**
 * Ordena uma lista de inteiros usando o algoritmo Quick Sort.
 *
 * @param arr Array de inteiros a ser ordenado
 * @param low Índice inicial da sublista
 * @param high Índice final da sublista
 */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Particiona o array e obtém o ponto de divisão
        int pt = partition(arr, low, high);

        // Recursivamente ordena a parte esquerda do ponto de divisão
        quickSort(arr, low, pt - 1);

        // Recursivamente ordena a parte direita do ponto de divisão
        quickSort(arr, pt + 1, high);
    }
}

int main()
{
    // Conjunto de casos de teste
    int test_cases[][5] = {
        {12, 11, 13, 5, 6},
        {3, 1, 4, 1, 5},
        {10, 9, 8, 7, 6},
        {1, 2, 3, 4, 5},
        {5, 3, 8, 6, 2}
    };

    // Calcula o número de casos de teste
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    // Itera sobre cada caso de teste
    for (int i = 0; i < num_cases; i++)
    {
        int *arr = test_cases[i];
        int n = sizeof(test_cases[i]) / sizeof(test_cases[i][0]);

        // Exibe a lista antes da ordenação
        printf("Lista antes de ordenar: ");
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[j]);
        }
        printf("\n");

        // Aplica o Quick Sort na lista
        quickSort(arr, 0, n - 1);

        // Exibe a lista após a ordenação
        printf("Lista depois de ordenar: ");
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[j]);
        }
        printf("\n\n");
    }
}
