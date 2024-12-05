# Merge Sort

## 📖 Introdução

O **Merge Sort** é um algoritmo de ordenação eficiente baseado na técnica de **divisão e conquista**. Ele divide a lista original em sublistas, ordena-as recursivamente e, em seguida, combina as sublistas ordenadas. Este algoritmo é amplamente utilizado em aplicações que exigem alta eficiência e estabilidade.

---

## Funcionamento do Algoritmo

### Passo a Passo

1. **🪓 Divisão**: Divida a lista ao meio até que cada sublista tenha apenas um elemento.
2. **🤝 Conquista**: Ordene cada sublista recursivamente.
3. **🔗 Mesclagem (Merge)**: Combine as sublistas ordenadas comparando os elementos e organizando-os em ordem crescente.

**Exemplo de Divisão e Mesclagem:**

Lista original: `[38, 27, 43, 3, 9, 82, 10]`

1. **Divisão**:  
   `[38, 27, 43]` e `[3, 9, 82, 10]`  
   `[38]`, `[27, 43]` e `[3, 9]`, `[82, 10]`
2. **Mesclagem**:  
   `[27, 38, 43]` e `[3, 9, 10, 82]`  
   `[3, 9, 10, 27, 38, 43, 82]`

---

## 📊 Complexidade

- **Melhor Caso**: `O(n log n)`
- **Pior Caso**: `O(n log n)`
- **Caso Médio**: `O(n log n)`

O Merge Sort requer **espaço adicional** de `O(n)` devido à criação de sublistas para mesclagem.

---

## 💻 Implementação

### Python

A implementação em Python demonstra a simplicidade do algoritmo com recursão:

```python
def merge_sort(array):
    """
    Implementa o algoritmo Merge Sort para ordenar uma lista.
    Complexidade de tempo: O(n log n)
    """
    # Caso base: se o array tiver tamanho 1 ou 0, já está ordenado
    if len(array) <= 1:
        return array

    # Divide o array ao meio
    meio = len(array) // 2
    esquerda = array[:meio]
    direita = array[meio:]

    # Chamada recursiva para ordenar as duas metades
    esquerda = merge_sort(esquerda)
    direita = merge_sort(direita)

    # Combina as duas metades ordenadas
    return merge(esquerda, direita)


def merge(esquerda, direita):
    """
    Combina duas listas ordenadas em uma única lista ordenada.
    """
    resultado = []
    i = j = 0

    # Compara e combina os elementos das duas listas
    while i < len(esquerda) and j < len(direita):
        if esquerda[i] <= direita[j]:
            resultado.append(esquerda[i])
            i += 1
        else:
            resultado.append(direita[j])
            j += 1

    # Adiciona os elementos restantes da lista esquerda, se houver
    while i < len(esquerda):
        resultado.append(esquerda[i])
        i += 1

    # Adiciona os elementos restantes da lista direita, se houver
    while j < len(direita):
        resultado.append(direita[j])
        j += 1

    return resultado


# Exemplo de uso
if __name__ == "__main__":
    # Lista desordenada para teste
    lista = [64, 342, 25, 991, 12, 661, 22, 11, 90, 1, 6, 44, 192, 813, 810, 7, 18]
    print("Lista original:", lista)

    # Aplica o Merge Sort
    lista_ordenada = merge_sort(lista)
    print("Lista ordenada:", lista_ordenada)

```

**Explicação do Código:**

1. O array é dividido em duas metades.
2. Cada metade é ordenada recursivamente.
3. As duas metades são mescladas comparando os elementos em ordem crescente.

---

### C

A implementação em C é ideal para entender como o algoritmo funciona em nível mais baixo:

```c
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
```

**Explicação do Código:**

1. O array é dividido usando índices.
2. A função merge combina subarrays ordenados em um único array.

---

## 🛠️ Casos de Uso

- Ordenação em **sistemas críticos** que exigem alta previsibilidade.
- Ordenação de **grandes volumes de dados** devido à sua eficiência em `O(n log n)`.
- Ambientes que precisam de um algoritmo **estável**.

---

## ⚖️ Vantagens e Desvantagens

### ✅ Vantagens

- Complexidade consistente: `O(n log n)` em qualquer cenário.
- Estável: Mantém a ordem relativa de elementos iguais.
- Excelente para grandes conjuntos de dados.

### ❌ Desvantagens

- Consome mais memória devido à criação de sublistas.
- Menos eficiente para listas pequenas.

---

## 🎥 Vídeo Explicativo

![type:video](https://www.youtube.com/embed/a5LfKZp34d8?si=LkG0qozM1DC3OnU9)

[:fontawesome-brands-youtube: Link direto](https://www.youtube.com/watch?v=a5LfKZp34d8&t=1s){ .md-button }

---

## 📚 Referências

- [Wikipedia - Merge Sort](https://en.wikipedia.org/wiki/Merge_sort)
- **Livro:** _Entendendo Algoritmos_, Aditya Y. Bhargava.
- **Vídeo:** [CS50x - Lecture 3 - Algorithms](https://youtu.be/jZzyERW7h1A?t=6395)
