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
def quick_sort(arr):
    """
    Implementa o algoritmo Quick Sort para ordenar uma lista.
    Complexidade de tempo: O(n log n) no melhor caso, O(n²) no pior caso
    """
    if len(arr) <= 1:
        return arr

    # Escolhe o pivô (último elemento da lista)
    pivô = arr[-1]
    esquerda = []
    direita = []
    meio = []

    # Particiona os elementos em relação ao pivô
    for num in arr:
        if num < pivô:
            esquerda.append(num)
        elif num > pivô:
            direita.append(num)
        else:
            meio.append(num)

    # Recursivamente aplica o Quick Sort nas sublistas
    return quick_sort(esquerda) + meio + quick_sort(direita)


# Exemplo de uso
if __name__ == "__main__":
    lista = [10, 7, 8, 9, 1, 5]
    print("Lista original:", lista)

    lista_ordenada = quick_sort(lista)
    print("Lista ordenada:", lista_ordenada)
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
 * Função para realizar a troca de dois elementos no array.
 *
 * @param a Ponteiro para o primeiro elemento
 * @param b Ponteiro para o segundo elemento
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Função de particionamento do array em torno de um pivô.
 *
 * @param arr Array de inteiros a ser particionado
 * @param low Índice inicial da lista
 * @param high Índice final da lista
 * @return O índice do pivô após a partição
 */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Pivô é o último elemento
    int i = low - 1; // Índice do menor elemento

    // Organiza os elementos em relação ao pivô
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]); // Coloca o pivô em sua posição final
    return i + 1;
}

/**
 * Função recursiva para aplicar o Quick Sort.
 *
 * @param arr Array de inteiros a ser ordenado
 * @param low Índice inicial da lista
 * @param high Índice final da lista
 */
void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Particiona o array e obtém o índice do pivô
        int pi = partition(arr, low, high);

        // Recursivamente ordena as duas sublistas
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Lista original: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    quick_sort(arr, 0, n - 1);

    printf("Lista ordenada: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
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
