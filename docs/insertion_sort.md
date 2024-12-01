# Insertion Sort

## Introdução

O **Insertion Sort** é um algoritmo simples de ordenação que funciona de maneira semelhante à forma como muitas pessoas ordenam as cartas de um baralho. O algoritmo percorre a lista de dados da esquerda para a direita e vai inserindo cada novo elemento na posição correta, em relação aos elementos anteriores. Apesar de ser ineficiente para grandes volumes de dados, o Insertion Sort é bastante eficiente para listas pequenas ou quase ordenadas.

---

## Funcionamento do Algoritmo

### Passo a Passo

1. O algoritmo começa no segundo elemento da lista e o compara com o primeiro.
2. Se o segundo elemento for menor, ele é movido para a posição do primeiro.
3. O próximo elemento é comparado com os elementos à sua esquerda e movido para a posição correta.
4. Esse processo é repetido até que todos os elementos estejam ordenados.

**Exemplo de Insertion Sort:**

Lista original: `[5, 2, 9, 1, 5, 6]`

1. O elemento `2` é comparado com `5` e é colocado à esquerda.
   - Lista: `[2, 5, 9, 1, 5, 6]`
2. O elemento `9` é comparado com `5` e permanece na mesma posição.
   - Lista: `[2, 5, 9, 1, 5, 6]`
3. O elemento `1` é comparado com `9`, `5` e `2`, e é colocado no início.
   - Lista: `[1, 2, 5, 9, 5, 6]`
4. O elemento `5` é comparado com `9` e é inserido antes dele.
   - Lista: `[1, 2, 5, 5, 9, 6]`
5. O elemento `6` é comparado com `9` e inserido antes dele.
   - Lista final: `[1, 2, 5, 5, 6, 9]`

---

## Complexidade

- **Melhor Caso**: `O(n)` (quando a lista já está ordenada)
- **Pior Caso**: `O(n^2)` (quando a lista está em ordem inversa)
- **Caso Médio**: `O(n^2)`

A complexidade de tempo no pior e caso médio é `O(n^2)`, mas o **Insertion Sort** é bastante eficiente quando os dados estão parcialmente ordenados ou são poucos. Ele também tem a vantagem de ser **estável**, ou seja, mantém a ordem relativa de elementos iguais.

---

## Implementação

### Python

Aqui está uma implementação do **Insertion Sort** em Python:

```python
def insertion_sort(arr):
    """
    Implementa o algoritmo Insertion Sort para ordenar uma lista.
    Complexidade de tempo: O(n^2) no pior caso.
    """
    for i in range(1, len(arr)):
        chave = arr[i]
        j = i - 1

        # Move os elementos da lista para a direita, até a posição correta de "chave"
        while j >= 0 and arr[j] > chave:
            arr[j + 1] = arr[j]
            j -= 1

        # Coloca a chave na posição correta
        arr[j + 1] = chave

    return arr


# Exemplo de uso
if __name__ == "__main__":
    lista = [5, 2, 9, 1, 5, 6]
    print("Lista original:", lista)

    lista_ordenada = insertion_sort(lista)
    print("Lista ordenada:", lista_ordenada)
```

**Explicação do Código:**

1. O algoritmo começa com o segundo elemento da lista.
2. Para cada elemento, ele o compara com os anteriores e o move para a posição correta.
3. Esse processo é repetido até que toda a lista esteja ordenada.

---

### C

Aqui está a implementação do **Insertion Sort** em C:

```c
#include <stdio.h>

/**
 * Implementa o algoritmo Insertion Sort para ordenar uma lista.
 *
 * @param arr Array de inteiros a ser ordenado
 * @param n Tamanho do array
 */
void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int chave = arr[i];
        int j = i - 1;

        // Move os elementos de arr[0..i-1], que são maiores que chave, uma posição à frente
        while (j >= 0 && arr[j] > chave)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Coloca a chave na posição correta
        arr[j + 1] = chave;
    }
}

int main()
{
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Lista original: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    insertion_sort(arr, n);

    printf("Lista ordenada: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
```

**Explicação do Código:**

1. O algoritmo começa com o segundo elemento do array.
2. Para cada elemento, ele é comparado com os anteriores e movido para a posição correta.
3. Esse processo continua até a lista inteira ser ordenada.

---

## Casos de Uso

O **Insertion Sort** é particularmente útil quando:

- A lista de dados é pequena ou quase ordenada.
- A estabilidade é importante (manter a ordem relativa dos elementos iguais).
- Em sistemas com recursos limitados, pois o algoritmo tem baixo overhead.

---

## Vantagens e Desvantagens

### Vantagens

- **Simplicidade**: O algoritmo é simples de implementar e entender.
- **Eficiência para listas pequenas**: Funciona bem para listas pequenas ou quase ordenadas.
- **Estável**: Mantém a ordem relativa de elementos iguais.

### Desvantagens

- **Ineficiente para listas grandes**: Sua complexidade de tempo `O(n^2)` torna-o ineficiente para listas grandes.
- **Desempenho piora com o aumento da lista**: O tempo de execução cresce rapidamente conforme o número de elementos aumenta.

---

## 🎥 Vídeo Explicativo

![type:video](https://www.youtube.com/embed/rG08wJgfydA?si=-zA961YtO3RnZCzI)

[:fontawesome-brands-youtube: Link direto](https://www.youtube.com/watch?v=rG08wJgfydA&source_ve_path=MjM4NTE){ .md-button }

---

## Referências

- [Wikipedia - Insertion Sort](https://en.wikipedia.org/wiki/Insertion_sort)
- **Livro**: _Entendendo Algoritmos_, Aditya Y. Bhargava.
- **Vídeo**: [Algoritmos de Ordenação Insertion Sort](https://www.youtube.com/watch?v=rG08wJgfydA)
