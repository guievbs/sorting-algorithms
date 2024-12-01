# Counting Sort

## Introdução

O **Counting Sort** é um algoritmo de ordenação não comparativo, o que significa que ele não compara diretamente os elementos da lista para ordená-los. Ele funciona contando a ocorrência de cada elemento e utilizando essas contagens para calcular a posição de cada item na lista ordenada. Este algoritmo é eficiente quando os números a serem ordenados estão em um intervalo pequeno e é especialmente útil quando os valores dos elementos são inteiros não negativos.

---

## Funcionamento do Algoritmo

### Passo a Passo

1. **Contagem das Ocorrências**: O algoritmo conta quantas vezes cada valor ocorre na lista de entrada.
2. **Cálculo das Posições**: Com base na contagem de cada valor, ele calcula as posições acumuladas dos elementos.
3. **Construção do Resultado**: Usando as contagens acumuladas, o algoritmo coloca os elementos nas suas posições corretas na lista ordenada.

**Exemplo de Counting Sort:**

Lista original: `[4, 2, 2, 8, 3, 3, 1, 5]`

1. Contagem das ocorrências:

   - `0: 0`, `1: 1`, `2: 2`, `3: 2`, `4: 1`, `5: 1`, `6: 0`, `7: 0`, `8: 1`

2. Cálculo das posições acumuladas:

   - `0: 0`, `1: 1`, `2: 3`, `3: 5`, `4: 6`, `5: 7`, `6: 7`, `7: 7`, `8: 8`

3. Construção da lista ordenada:
   - A partir das contagens acumuladas, os elementos são colocados nas suas respectivas posições: `[1, 2, 2, 3, 3, 4, 5, 8]`

---

## Complexidade

- **Melhor Caso**: `O(n + k)` onde `n` é o número de elementos e `k` é o valor máximo na lista.
- **Pior Caso**: `O(n + k)`
- **Caso Médio**: `O(n + k)`

Onde:

- `n` é o número de elementos na lista de entrada.
- `k` é o valor máximo presente na lista (ou o intervalo dos valores).

O Counting Sort é muito eficiente quando `k` é pequeno em relação a `n`, mas não é adequado para listas com uma grande variação de valores.

---

## Implementação

### Python

Aqui está uma implementação do **Counting Sort** em Python:

```python
def counting_sort(arr):
    """
    Implementa o algoritmo Counting Sort para ordenar uma lista.
    Complexidade de tempo: O(n + k), onde n é o número de elementos e k é o valor máximo.
    """
    # Se a lista estiver vazia, retorna imediatamente
    if not arr:
        return arr

    # Encontra o maior valor na lista
    max_val = max(arr)

    # Cria a lista de contagem com o tamanho do maior valor + 1
    count = [0] * (max_val + 1)

    # Conta a ocorrência de cada elemento
    for num in arr:
        count[num] += 1

    # Reconstrói a lista ordenada
    sorted_arr = []
    for num, freq in enumerate(count):
        sorted_arr.extend([num] * freq)

    return sorted_arr


# Exemplo de uso
if __name__ == "__main__":
    lista = [4, 2, 2, 8, 3, 3, 1, 5]
    print("Lista original:", lista)

    lista_ordenada = counting_sort(lista)
    print("Lista ordenada:", lista_ordenada)
```

**Explicação do Código:**

1. O algoritmo encontra o valor máximo na lista de entrada.
2. Cria um array de contagem onde cada índice corresponde a um valor na lista de entrada.
3. A lista ordenada é construída a partir das contagens acumuladas, colocando os elementos nas suas posições corretas.

---

### C

Aqui está a implementação do **Counting Sort** em C:

```c
#include <stdio.h>
#include <stdlib.h>

/**
 * Implementa o algoritmo Counting Sort em C para ordenar uma lista.
 *
 * @param arr Array de inteiros a ser ordenado
 * @param n Tamanho do array
 */
void counting_sort(int arr[], int n)
{
    // Encontra o maior valor na lista
    int max_val = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max_val)
            max_val = arr[i];
    }

    // Cria a lista de contagem com o tamanho do maior valor + 1
    int *count = (int *)calloc(max_val + 1, sizeof(int));

    // Conta as ocorrências de cada elemento
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    // Reconstrói a lista ordenada
    int idx = 0;
    for (int i = 0; i <= max_val; i++)
    {
        while (count[i] > 0)
        {
            arr[idx++] = i;
            count[i]--;
        }
    }

    free(count); // Libera a memória alocada
}

int main()
{
    int arr[] = {4, 2, 2, 8, 3, 3, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Lista original: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    counting_sort(arr, n);

    printf("Lista ordenada: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
```

**Explicação do Código:**

1. O maior valor na lista é encontrado para determinar o tamanho do array de contagem.
2. O algoritmo cria uma lista de contagem e conta quantas vezes cada valor ocorre.
3. Reconstrói a lista ordenada com base nas contagens.

---

## Casos de Uso

O **Counting Sort** é eficaz quando:

- O intervalo dos valores (ou seja, a diferença entre o maior e o menor valor) é pequeno.
- É necessário ordenar inteiros ou números não negativos.
- A estabilidade da ordenação é importante (o algoritmo mantém a ordem relativa dos elementos com o mesmo valor).

---

## Vantagens e Desvantagens

### Vantagens

- **Eficiência em intervalos pequenos**: O algoritmo é extremamente rápido quando o valor máximo (`k`) é pequeno em relação ao número de elementos (`n`).
- **Não comparativo**: Não faz comparações diretas entre elementos, o que pode ser vantajoso em certos contextos.

### Desvantagens

- **Espaço adicional**: O algoritmo requer um array de contagem adicional, o que pode consumir muita memória se o intervalo de valores for muito grande.
- **Não aplicável a todos os tipos de dados**: Funciona apenas com números inteiros não negativos.

---

## 🎥 Vídeo Explicativo

![type:video](https://www.youtube.com/embed/3bm7NgKJpj4?si=jgPd_3X7lW8Pp0l-)

[:fontawesome-brands-youtube: Link direto](https://www.youtube.com/watch?v=3bm7NgKJpj4){ .md-button }

---

## Referências

- [Wikipedia - Counting Sort](https://en.wikipedia.org/wiki/Counting_sort)
- **Livro**: _Entendendo Algoritmos_, Aditya Y. Bhargava.
- **Vídeo**: [UFCG: Counting Sort](https://www.youtube.com/watch?v=3bm7NgKJpj4)
