# Heap Sort

## Introdução

O **Heap Sort** é um algoritmo de ordenação eficiente baseado na estrutura de dados **heap**, que é uma árvore binária completa. O algoritmo utiliza o conceito de **heap máximo** ou **heap mínimo**, que permite extrair o maior (ou menor) elemento de forma eficiente. Ao combinar as operações de construção do heap e extração do máximo, o Heap Sort ordena os elementos de maneira eficiente.

---

## Funcionamento do Algoritmo

### Passo a Passo

1. **Construção do Heap**: Construa um heap máximo a partir da lista de dados. Isso é feito a partir do meio da lista para garantir que as propriedades do heap sejam mantidas.
2. **Extração do Máximo**: O maior elemento (a raiz do heap) é extraído e colocado no final da lista. Em seguida, o heap é reorganizado para manter suas propriedades.
3. **Repetição**: O passo 2 é repetido até que todos os elementos sejam extraídos e a lista esteja ordenada.

**Exemplo de Heap Sort:**

Lista original: `[4, 10, 3, 5, 1]`

1. Construa um **heap máximo**:
   - Heap máximo: `[10, 5, 3, 4, 1]`
2. Extraia o máximo (10) e coloque no final:
   - Lista: `[1, 5, 3, 4, 10]`
   - Heap máximo após reorganização: `[5, 4, 3, 1]`
3. Extraia o máximo (5) e coloque no final:
   - Lista: `[1, 4, 3, 5, 10]`
   - Heap máximo após reorganização: `[4, 1, 3]`
4. Repita os passos até que a lista esteja completamente ordenada:
   - Lista final: `[1, 3, 4, 5, 10]`

---

## Complexidade

- **Melhor Caso**: `O(n log n)`
- **Pior Caso**: `O(n log n)`
- **Caso Médio**: `O(n log n)`

A complexidade do Heap Sort é `O(n log n)` no melhor, pior e caso médio. Isso torna o algoritmo eficiente, especialmente para grandes listas, embora ele não seja estável.

---

## Implementação

### Python

Aqui está uma implementação do **Heap Sort** em Python:

```python
def heapify(arr, n, i):
    """
    Converte um subárvore em um heap máximo.
    """
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    # Verifica se o filho à esquerda é maior que o pai
    if left < n and arr[left] > arr[largest]:
        largest = left

    # Verifica se o filho à direita é maior que o maior até agora
    if right < n and arr[right] > arr[largest]:
        largest = right

    # Se o maior não for o elemento atual, troca e chama heapify novamente
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # Troca
        heapify(arr, n, largest)


def heap_sort(arr):
    """
    Implementa o algoritmo Heap Sort para ordenar uma lista.
    Complexidade de tempo: O(n log n)
    """
    n = len(arr)

    # Construção do heap máximo
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # Extração dos elementos um a um
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # Troca o maior com o último elemento
        heapify(arr, i, 0)  # Reorganiza o heap

    return arr


# Exemplo de uso
if __name__ == "__main__":
    lista = [4, 10, 3, 5, 1]
    print("Lista original:", lista)

    lista_ordenada = heap_sort(lista)
    print("Lista ordenada:", lista_ordenada)
```

**Explicação do Código:**

1. A função `heapify` é responsável por garantir que a propriedade do heap máximo seja mantida em cada subárvore.
2. O algoritmo começa construindo um heap máximo a partir da lista.
3. Em seguida, ele extrai o maior elemento (a raiz) e coloca-o no final da lista.
4. O processo é repetido até que a lista esteja completamente ordenada.

---

### C

Aqui está a implementação do **Heap Sort** em C:

```c
#include <stdio.h>

/**
 * Função auxiliar para manter a propriedade do heap máximo.
 *
 * @param arr Array de inteiros a ser ordenado
 * @param n Tamanho do array
 * @param i Índice do nó a ser reorganizado
 */
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Verifica se o filho à esquerda é maior que o pai
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Verifica se o filho à direita é maior que o maior até agora
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Se o maior não for o elemento atual, troca e chama heapify novamente
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

/**
 * Implementa o algoritmo Heap Sort para ordenar uma lista.
 *
 * @param arr Array de inteiros a ser ordenado
 * @param n Tamanho do array
 */
void heap_sort(int arr[], int n)
{
    // Construção do heap máximo
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extração dos elementos do heap
    for (int i = n - 1; i > 0; i--)
    {
        // Troca o maior com o último elemento
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Reorganiza o heap
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Lista original: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    heap_sort(arr, n);

    printf("Lista ordenada: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
```

**Explicação do Código:**

1. A função `heapify` mantém a propriedade do heap máximo em uma subárvore.
2. A função `heap_sort` constrói o heap máximo e, em seguida, extrai os elementos um a um, reorganizando o heap a cada extração.

---

## Casos de Uso

O **Heap Sort** é útil quando:

- Precisamos de um algoritmo de ordenação eficiente e **sem uso de espaço adicional**.
- Trabalhamos com grandes volumes de dados onde a complexidade `O(n log n)` é vantajosa.
- A estrutura de dados do **heap** já está sendo utilizada em outras operações, como na implementação de filas de prioridade.

---

## Vantagens e Desvantagens

### Vantagens

- **Eficiência**: Tem uma complexidade de tempo `O(n log n)` no melhor, pior e caso médio.
- **Não exige espaço adicional significativo**: Ao contrário do Merge Sort, o Heap Sort não requer espaço adicional além do necessário para armazenar a lista.
- **Versatilidade**: Funciona bem em diversos cenários e é eficiente para grandes listas de dados.

### Desvantagens

- **Não é estável**: O Heap Sort não preserva a ordem relativa de elementos iguais.
- **Desempenho constante**: Embora eficiente, o Heap Sort tende a ser mais lento que algoritmos como Quick Sort, dependendo da implementação e dos dados.

---

## 🎥 Vídeo Explicativo

![type:video](https://www.youtube.com/embed/mgUiY8CVDhU?si=EWbgqtwWuH802yC7)

[:fontawesome-brands-youtube: Link direto](https://www.youtube.com/watch?v=mgUiY8CVDhU&source_ve_path=MjM4NTE){ .md-button }

---

## Referências

- [Wikipedia - Heap Sort](https://en.wikipedia.org/wiki/Heap_sort)
- **Livro**: _Entendendo Algoritmos_, Aditya Y. Bhargava.
- **Vídeo**: [Heap sort visualization](https://www.youtube.com/watch?v=mgUiY8CVDhU)
