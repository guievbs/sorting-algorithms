# Bubble Sort

## 📖 Introdução

O **Bubble Sort** é um algoritmo de ordenação simples, mas ineficiente, que trabalha repetidamente trocando elementos adjacentes que estão fora de ordem. Ele continua até que a lista esteja completamente ordenada. Embora seja fácil de entender e implementar, o Bubble Sort tem uma performance inferior em listas grandes, sendo utilizado principalmente para fins didáticos.

---

## Funcionamento do Algoritmo

### Passo a Passo

1. **Comparação e Troca**: O algoritmo percorre a lista várias vezes. Em cada passagem, ele compara elementos adjacentes e os troca se estiverem fora de ordem.
2. **Repetição**: O processo é repetido para o restante da lista, diminuindo gradualmente a quantidade de comparações feitas a cada iteração.
3. **Finalização**: Quando não são feitas mais trocas, o algoritmo termina, indicando que a lista está ordenada.

**Exemplo de Bubble Sort:**

Lista original: `[5, 3, 8, 4, 2]`

1. Primeira passagem:

   - Compara `5` e `3` → troca → `[3, 5, 8, 4, 2]`
   - Compara `5` e `8` → sem troca → `[3, 5, 8, 4, 2]`
   - Compara `8` e `4` → troca → `[3, 5, 4, 8, 2]`
   - Compara `8` e `2` → troca → `[3, 5, 4, 2, 8]`

2. Segunda passagem:

   - Compara `3` e `5` → sem troca → `[3, 5, 4, 2, 8]`
   - Compara `5` e `4` → troca → `[3, 4, 5, 2, 8]`
   - Compara `5` e `2` → troca → `[3, 4, 2, 5, 8]`

3. Terceira passagem:

   - Compara `3` e `4` → sem troca → `[3, 4, 2, 5, 8]`
   - Compara `4` e `2` → troca → `[3, 2, 4, 5, 8]`

4. Quarta passagem:
   - Compara `3` e `2` → troca → `[2, 3, 4, 5, 8]`

Agora a lista está ordenada: `[2, 3, 4, 5, 8]`

---

## 📊 Complexidade

- **Melhor Caso**: `O(n)` - Quando a lista já está ordenada.
- **Pior Caso**: `O(n^2)` - Quando a lista está ordenada de forma inversa.
- **Caso Médio**: `O(n^2)` - A complexidade geralmente é quadrática.

O Bubble Sort é um algoritmo de ordenação que tem uma complexidade de tempo ruim para listas grandes, sendo impraticável para grandes volumes de dados.

---

## 💻 Implementação

### Python

Aqui está uma implementação do **Bubble Sort** em Python:

```python
def bubble_sort(arr):
    """
    Implementa o algoritmo Bubble Sort para ordenar uma lista.
    Complexidade de tempo: O(n^2)
    """
    n = len(arr)
    # Percorre a lista
    for i in range(n):
        # A cada iteração, a maior parte da lista já está ordenada
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]  # Troca os elementos
    return arr


# Exemplo de uso
if __name__ == "__main__":
    lista = [64, 342, 25, 991, 12, 661, 22, 11, 90, 1, 6, 44, 192, 813]
    print("Lista original:", lista)

    lista_ordenada = bubble_sort(lista)
    print("Lista ordenada:", lista_ordenada)
```

**Explicação do Código:**

1. O algoritmo percorre toda a lista repetidamente.
2. A cada passagem, ele compara os elementos adjacentes e os troca, movendo os maiores para o final da lista.
3. O processo é repetido até que a lista esteja ordenada.

---

### C

Aqui está a implementação do **Bubble Sort** em C:

```c
#include <stdio.h>

/**
 * Implementa o algoritmo Bubble Sort em C para ordenar uma lista.
 *
 * @param arr Array de inteiros a ser ordenado
 * @param n Tamanho do array
 */
void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        // Percorre a lista e compara elementos adjacentes
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                // Troca os elementos
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {64, 342, 25, 991, 12, 661, 22, 11, 90, 1, 6, 44, 192, 813};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Lista original: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    bubble_sort(arr, n);

    printf("Lista ordenada: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
```

**Explicação do Código:**

1. O array é percorrido várias vezes.
2. Cada passagem compara elementos adjacentes e os troca, colocando os maiores no final da lista.
3. O algoritmo repete o processo até que a lista esteja ordenada.

---

## 🛠️ Casos de Uso

O **Bubble Sort** é geralmente usado em:

- **Ambientes de aprendizado**: Devido à sua simplicidade, é um bom ponto de partida para quem está aprendendo sobre algoritmos de ordenação.
- **Listas pequenas**: Embora ineficiente para grandes listas, pode ser útil para listas pequenas onde a simplicidade é mais importante que a eficiência.

---

## ⚖️ Vantagens e Desvantagens

### ✅ Vantagens

- **Simplicidade**: O Bubble Sort é fácil de entender e implementar.
- **In-place**: Não exige espaço extra significativo, além do necessário para armazenar os dados.

### ❌ Desvantagens

- **Ineficiente**: Sua complexidade de tempo `O(n^2)` o torna muito lento para listas grandes.
- **Performance ruim em casos gerais**: Comparado a outros algoritmos, o Bubble Sort é significativamente mais lento.

---

## 🎥 Vídeo Explicativo

![type:video](https://www.youtube.com/embed/8RkZoBZNNgI?si=lbZPfh023MqmhpQF)

[:fontawesome-brands-youtube: Link direto](https://www.youtube.com/watch?v=8RkZoBZNNgI){ .md-button }

---

## Referências

- [Wikipedia - Bubble Sort](https://en.wikipedia.org/wiki/Bubble_sort)
- **Livro**: _Entendendo Algoritmos_, Aditya Y. Bhargava.
- **Vídeo**: [O que é e COMO FUNCIONA o BubbleSort](https://www.youtube.com/watch?v=8RkZoBZNNgI)
