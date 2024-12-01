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
    if len(array) <= 1:
        return array

    meio = len(array) // 2
    esquerda = array[:meio]
    direita = array[meio:]

    esquerda = merge_sort(esquerda)
    direita = merge_sort(direita)

    return merge(esquerda, direita)


def merge(esquerda, direita):
    resultado = []
    i = j = 0

    while i < len(esquerda) and j < len(direita):
        if esquerda[i] <= direita[j]:
            resultado.append(esquerda[i])
            i += 1
        else:
            resultado.append(direita[j])
            j += 1

    resultado.extend(esquerda[i:])
    resultado.extend(direita[j:])
    return resultado


# Exemplo de uso
if __name__ == "__main__":
    lista = [64, 342, 25, 991, 12, 661, 22, 11, 90, 1, 6, 44, 192, 813]
    print("Lista original:", lista)
    print("Lista ordenada:", merge_sort(lista))
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

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Lista antes da ordenação: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    merge_sort(arr, 0, n - 1);

    printf("Lista após a ordenação: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

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
