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
    if arr is None: # Verifica se a lista é nula
        print("Entrada inválida: lista é nula.")
        raise TypeError("Entrada inválida: lista é nula.")

    if not arr: # Verifica se a lista está vazia
        print("A lista está vazia e não há nada para ordenar.")
        return None
    
    n = len(arr) # Tamanho da lista

    # Loop principal que percorre toda a lista
    for i in range(n - 1):
        # Um segundo loop que compara cada par de elementos
        for j in range(n - 1 - i):
            # Se o elemento atual é maior que o próximo, troca de posição
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]  # Troca de posição

# Exemplo para testar o algoritmo
arr = []  # Teste com lista vazia
print("Lista antes de ordenar:", arr)
bubble_sort(arr)
print("Lista depois de ordenar:", arr)

# Outro exemplo com lista preenchida
arr = [64, 34, 25, 12, 22, 11, 90]
print("\nLista antes de ordenar:", arr)
bubble_sort(arr)
print("Lista depois de ordenar:", arr)

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

void bubbleSort(int arr[], int n) {
    // Verifica se o array está vazio
    if (n == 0) {
        printf("O array está vazio e não há nada para ordenar.\n");
        return;
    }

    // Loop para percorrer toda a lista
    for (int i = 0; i < n - 1; i++) {
        // Loop para comparar pares de elementos
        for (int j = 0; j < n - 1 - i; j++) {
            // Se o elemento atual é maior que o próximo, faz a troca
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];     // Guarda o valor temporário para troca
                arr[j] = arr[j + 1];   // Coloca o próximo no lugar do atual
                arr[j + 1] = temp;     // Coloca o temporário no próximo
            }
        }
    }
}

int main() {
    int arr1[] = {};  // Array vazio
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    printf("Array antes de ordenar (vazio): ");
    for (int i = 0; i < n1; i++) printf("%d ", arr1[i]);
    printf("\n");

    bubbleSort(arr1, n1);  // Teste com array vazio

    printf("Array depois de ordenar (vazio): ");
    for (int i = 0; i < n1; i++) printf("%d ", arr1[i]);
    printf("\n");

    // Outro exemplo com array preenchido
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("\nArray antes de ordenar: ");
    for (int i = 0; i < n2; i++) printf("%d ", arr2[i]);
    printf("\n");

    bubbleSort(arr2, n2);  // Teste com array preenchido

    printf("Array depois de ordenar: ");
    for (int i = 0; i < n2; i++) printf("%d ", arr2[i]);
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
