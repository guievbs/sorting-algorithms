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
    largest = i         # Inicializa o maior como raiz
    left = 2 * i + 1    # Filho à esquerda
    right = 2 * i + 2   # Filho à direita

    # Se o filho à esquerda for maior que a raiz
    if left < n and arr[left] > arr[largest]:
        largest = left

    # Se o filho à direita for maior que o maior até agora
    if right < n and arr[right] > arr[largest]:
        largest = right

    # Se o maior não for a raiz
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # Troca
        heapify(arr, n, largest)  # Aplica heapify na subárvore afetada

def heap_sort(arr):
    n = len(arr)

    # Construir o heap (reorganizar o array)
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # Extrair um elemento de cada vez do heap
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # Move a raiz para o final
        heapify(arr, i, 0)  # Chama heapify no heap reduzido

# Exemplo de uso
arr = [12, 11, 13, 5, 6, 7]
print("Array original:")
print(arr)

heap_sort(arr)

print("Array ordenado:")
print(arr)

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
