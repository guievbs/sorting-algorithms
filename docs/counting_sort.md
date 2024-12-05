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
    # Encontrar o maior valor no array para definir o tamanho do array auxiliar
    max_val = max(arr)

    # Criar um array auxiliar para armazenar as contagens, inicializado com 0
    count = [0] * (max_val + 1)

    # Contar a ocorrência de cada elemento no array original
    for num in arr:
        count[num] += 1

    # Modificar o array count para armazenar as posições corretas dos elementos
    for i in range(1, len(count)):
        count[i] += count[i - 1]

    # Criar um array para o resultado final ordenado
    output = [0] * len(arr)
    for num in reversed(
        arr
    ):  # Percorrer de trás para frente para garantir estabilidade
        output[count[num] - 1] = num
        count[num] -= 1

    # Copiar o array ordenado de volta para o array original
    for i in range(len(arr)):
        arr[i] = output[i]


# Exemplo de uso
arr = [4, 2, 2, 8, 3, 3, 1]
print("Array original:")
print(arr)

counting_sort(arr)

print("Array ordenado:")
print(arr)
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
#include <string.h>

void counting_sort(int arr[], int n) {
    // Encontrar o maior valor no array para definir o tamanho do array auxiliar
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Criar um array auxiliar para armazenar as contagens, inicializado com 0
    int count[max + 1];
    memset(count, 0, sizeof(count));

    // Contar a ocorrência de cada elemento no array original
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Modificar o array count para armazenar as posições corretas dos elementos
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Criar um array para o resultado final ordenado
    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copiar o array ordenado de volta para o array original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Função principal para testes
int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    counting_sort(arr, n);

    printf("Array ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
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
