# Quick Sort

## Introdução

O **Quick Sort** é um algoritmo de ordenação eficiente baseado na técnica de **divisão e conquista**. Ele divide a lista em duas partes, usando um **pivô** para ordenar os elementos em relação a ele. Esse processo é repetido recursivamente nas sublistas, resultando em uma ordenação eficiente. O Quick Sort é amplamente utilizado devido à sua rapidez em médias e grandes listas de dados.

---

## Funcionamento do Algoritmo

### Passo a Passo

1. **Escolha do Pivô**: Escolha um elemento da lista como pivô. Esse pivô pode ser escolhido de várias maneiras (por exemplo, o primeiro, o último ou o elemento do meio).
2. **Particionamento**: Organize os elementos de modo que todos os elementos menores que o pivô fiquem à esquerda e todos os maiores fiquem à direita.
3. **Recursão**: Aplique o Quick Sort recursivamente nas sublistas à esquerda e à direita do pivô até que a lista esteja completamente ordenada.

**Exemplo de Quick Sort:**

Lista original: `[10, 7, 8, 9, 1, 5]`

1. Escolha o pivô (por exemplo, o último elemento, `5`).
2. Particione a lista em relação ao pivô:
   - Lista após particionamento: `[1, 5, 8, 9, 7, 10]`
   - O pivô (`5`) está na posição correta.
3. Recursivamente, aplique o Quick Sort nas sublistas à esquerda (`[1]`) e à direita (`[8, 9, 7, 10]`).

---

## Complexidade

- **Melhor Caso**: `O(n log n)`
- **Pior Caso**: `O(n²)` (quando o pivô é mal escolhido)
- **Caso Médio**: `O(n log n)`

A complexidade de tempo do Quick Sort pode ser `O(n log n)` no melhor e caso médio, mas no pior caso, pode atingir `O(n²)`. Isso ocorre quando o pivô é constantemente escolhido de forma ineficiente.

---

## Implementação

### Python

Aqui está a implementação do **Quick Sort** em Python:

```python
def partition(arr: list[int], low: int, high: int) -> int:
    """
    Particiona o array e retorna o índice do ponto de divisão.

    Parameters:
        arr (list[int]): Array de inteiros a ser particionado
        low (int): Índice inicial da sublista
        high (int): Índice final da sublista

    Returns:
        int: Índice do ponto de divisão
    """
    pivot = arr[high]

    point = low - 1

    for i in range(low, high):
        if arr[i] < pivot:
            point += 1
            arr[i], arr[point] = arr[point], arr[i]

    arr[point + 1], arr[high] = arr[high], arr[point + 1]
    return point + 1

def quick_sort(arr: list, low: int, high: int) -> None:
    """
    Ordena o array utilizando o algoritmo Quick Sort.

    Parameters:
        arr (list): Array de inteiros a ser ordenado
        low (int): Índice inicial da sublista
        high (int): Índice final da sublista
    """
    if low < high:
        point = partition(arr, low, high)  # Ponto de divisão

        quick_sort(arr, low, point - 1)  # Ordena a parte esquerda do ponto de divisão
        quick_sort(arr, point + 1, high)  # Ordena a parte direita do ponto de divisão

# Faz com que o algoritmo seja executado diretamente
if __name__ == "__main__":
    arr = [12, 11, 13, 5, 6]
    
    print("Lista antes de ordenar:", arr)
    
    quick_sort(arr, 0, len(arr) - 1)
    
    print("Lista ordenada:", arr)

```

**Explicação do Código:**

1. A função `quick_sort` recebe uma lista e retorna a lista ordenada.
2. O pivô é escolhido como o último elemento da lista.
3. A lista é particionada em três partes: elementos menores que o pivô, o próprio pivô e elementos maiores que o pivô.
4. O Quick Sort é aplicado recursivamente nas sublistas à esquerda e à direita do pivô.

---

### C

Aqui está a implementação do **Quick Sort** em C:

```c
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

```

**Explicação do Código:**

1. A função `swap` troca os valores de dois elementos no array.
2. A função `partition` organiza os elementos em torno de um pivô e retorna a posição final do pivô.
3. A função `quick_sort` aplica o algoritmo recursivamente nas sublistas à esquerda e à direita do pivô.

---

## Casos de Uso

O **Quick Sort** é útil quando:

- Precisamos de um algoritmo rápido para listas grandes, especialmente quando a média de elementos é bem distribuída.
- O algoritmo é ideal para **ambientes de sistemas embarcados** ou **algoritmos de processamento de dados em tempo real**, onde o desempenho é crucial.

---

## Vantagens e Desvantagens

### Vantagens

- **Eficiência**: Tem uma complexidade média de tempo de `O(n log n)`, que é muito eficiente para grandes listas.
- **In-place**: Não exige espaço adicional significativo além do necessário para armazenar a lista.
- **Flexibilidade**: Pode ser adaptado para diferentes escolhas de pivô (primeiro, último, aleatório, etc.).

### Desvantagens

- **Pior caso**: Se o pivô for mal escolhido, o Quick Sort pode ter uma complexidade de `O(n²)` no pior caso.
- **Não é estável**: O Quick Sort não preserva a ordem relativa de elementos iguais.
- **Uso de memória**: A recursão pode levar a um consumo significativo de memória, especialmente para listas muito grandes.

---

## 🎥 Vídeo Explicativo

![type:video](https://www.youtube.com/embed/nV_WE8SEuGE?si=mmKkww2e7E-QSfPS)

[:fontawesome-brands-youtube: Link direto](https://www.youtube.com/watch?v=nV_WE8SEuGE){ .md-button }

---

## Referências

- [Wikipedia - Quick Sort](https://en.wikipedia.org/wiki/Quicksort)
- **Livro**: _Entendendo Algoritmos_, Aditya Y. Bhargava.
- **Vídeo**: [Quicksort: Implementação e Explicação](https://www.youtube.com/watch?v=nV_WE8SEuGE)
