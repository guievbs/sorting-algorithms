# Heap Sort

## 📖 Introdução

O **Heap Sort** é um algoritmo de ordenação baseado na estrutura de dados chamada **heap**, que pode ser **max heap** ou **min heap**. Ele utiliza a técnica de **seleção e ajuste** para ordenar os elementos. Desenvolvido por **J. W. J. Williams** em 1964, o Heap Sort é eficiente e possui uma complexidade de tempo de **O(n log n)** em todos os casos, o que o torna um dos algoritmos de ordenação eficientes.

###### Curiosidade sobre o Heap: "O heap, sendo uma estrutura de árvore binária, garante uma inserção e remoção de elementos de maneira eficiente, especialmente em problemas que envolvem otimização como agendamento e filas de prioridade."

---

## Motivação do Uso e Desenvolvimento

O Heap Sort foi desenvolvido para resolver problemas de ordenação em que a eficiência e o uso eficiente da memória são cruciais. Ao contrário de algoritmos como o Merge Sort, que exigem espaço adicional, o Heap Sort é um algoritmo **in-place** e não precisa de memória extra. Ele é frequentemente utilizado quando o espaço de memória é limitado ou quando é necessário um algoritmo eficiente em termos de complexidade de tempo.

---

## Funcionamento do Algoritmo

### Passo a Passo

1. **🛠️ Construção do Heap**: A estrutura de heap é construída a partir do array original. No caso do Max Heap, a maior chave estará na raiz da árvore, e as chaves dos nós filhos serão menores que a chave do nó pai.
2. **🏗️ Remoção e Ajuste**: O elemento na raiz (máximo ou mínimo) é removido e colocado na posição final do array. Em seguida, o heap é ajustado para manter a propriedade de heap.
3. **🔄 Repetição**: O passo de remoção e ajuste é repetido até que o heap tenha sido completamente ordenado.

**Exemplo de Construção de um Heap:**

Lista original: `[4, 10, 3, 5, 1]`

- **Construção do Max Heap**: `[10, 5, 3, 4, 1]`
- **Remoção da raiz (10) e ajuste**: A raiz é colocada no final e o heap é ajustado para `[5, 4, 3, 1]`.
- **Repetição do processo** até que a lista esteja ordenada: `[1, 3, 4, 5, 10]`

---

## 📊 Complexidade

- **Melhor Caso**: O(n log n)
- **Pior Caso**: O(n log n)
- **Caso Médio**: O(n log n)

Embora a complexidade seja **O(n log n)**, o Heap Sort tem a vantagem de ser um algoritmo **in-place**, ou seja, não necessita de espaço extra significativo, exceto para a pilha de chamadas recursivas.

---

## 💻 Implementação

### Python

```python
def heapify(arr, n, i):
    largest = i  # Inicializa o maior como raiz
    left = 2 * i + 1  # Esquerdo = 2*i + 1
    right = 2 * i + 2  # Direito = 2*i + 2

    # Se o filho da esquerda for maior que a raiz
    if left < n and arr[left] > arr[largest]:
        largest = left

    # Se o filho da direita for maior que o maior até agora
    if right < n and arr[right] > arr[largest]:
        largest = right

    # Se o maior não for a raiz
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # Troca
        heapify(arr, n, largest)

def heap_sort(arr):
    n = len(arr)

    # Construir o heap (reorganizar o array)
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # Um por um, remover os elementos do heap
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # Troca
        heapify(arr, i, 0)

    return arr
```

### C

```c
#include <stdio.h>

void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}
```

---

## 🛠️ Casos de Uso

- **Algoritmos de otimização** que exigem a ordenação de elementos de forma eficiente.
- **Filas de prioridade**, especialmente quando é necessário inserir e remover elementos frequentemente.
- **Problemas de seleção** em que o objetivo é encontrar o k-ésimo maior ou menor elemento rapidamente.

---

## ⚖️ Vantagens e Desvantagens

### ✅ Vantagens

- **Eficiência**: Complexidade de O(n log n) em todos os cenários.
- **In-place**: Não requer memória adicional significativa.
- **Versátil**: Pode ser usado para problemas de fila de prioridade e seleção de elementos.

### ❌ Desvantagens

- **Não estável**: Não mantém a ordem relativa de elementos iguais.
- **Mais lento que o Merge Sort** em muitos cenários, especialmente com dados parcialmente ordenados.

---

## 📝 Curiosidades

- O Heap Sort é fundamental em muitas implementações de **filas de prioridade**, sendo utilizado, por exemplo, nos algoritmos de **Dijkstra** para encontrar o caminho mais curto.
- É um dos algoritmos que prova a relação entre a manipulação de heaps e a eficiência em otimizar problemas complexos.

---

## Gráfico Comparativo com Outros Algoritmos

| Algoritmo      | Melhor Caso | Pior Caso  | Caso Médio |
| -------------- | ----------- | ---------- | ---------- |
| Heap Sort      | O(n log n)  | O(n log n) | O(n log n) |
| Merge Sort     | O(n log n)  | O(n log n) | O(n log n) |
| Quick Sort     | O(n log n)  | O(n²)      | O(n log n) |
| Insertion Sort | O(n)        | O(n²)      | O(n²)      |

---

## Elementos Repetidos no Heap Sort

Embora o Heap Sort seja **não estável**, ele ainda garante que todos os elementos serão corretamente ordenados, incluindo elementos duplicados. Quando os elementos iguais são encontrados, eles são colocados de acordo com a sua posição no heap durante o processo de seleção e ajuste. No entanto, a ordem relativa entre elementos iguais pode ser alterada.

---

## Importância dos Algoritmos de Ordenação

Algoritmos como o Heap Sort são essenciais em aplicações que exigem otimização, como jogos, sistemas de distribuição de tarefas e sistemas de banco de dados. Sua eficácia em espaços de memória limitados é crucial quando se trata de sistemas em tempo real.

---

## Programação Competitiva

Dominar o Heap Sort é uma habilidade fundamental na programação competitiva. Ele é frequentemente usado em problemas que exigem uma manipulação eficiente de filas de prioridade ou a solução de problemas de otimização, como o problema de seleção de k-ésimos maiores/menores elementos.

---

## Quiz Interativo

1. Qual é a principal vantagem do Heap Sort em comparação com o Merge Sort?

2. O Heap Sort é considerado um algoritmo:

3. Qual é a complexidade do Heap Sort no pior caso?

---

## Recursos Gráficos na Web

- [Visualgo](https://visualgo.net/en/sorting)
- [GeeksForGeeks](https://www.geeksforgeeks.org/heap-sort/)

---

## Dicas para Programar no LeetCode

1. **Estude as estruturas de dados** como o heap, já que elas frequentemente aparecem em problemas do LeetCode.
2. **Pratique manipulação de filas de prioridade** utilizando heap sort.
3. **Teste seu código** com entradas de diferentes tamanhos e padrões para garantir eficiência.

---

## 🎥 Vídeo Explicativo

## [:fontawesome-brands-youtube: Link do vídeo](https://drive.google.com/file/d/1TjtVGY_DBz_H0U17XokO4fUZY1g3CvnT/view?usp=sharing){ .md-button }

---

## Referências

Esses detalhes adicionais enriquecem a documentação do Heap Sort e ajudam a compreender melhor sua importância na ciência da computação.

1. [Heapsort - Wikipédia](https://pt.wikipedia.org/wiki/Heapsort)
2. [Aula 16 - HeapSort (PDF)](https://edisciplinas.usp.br/pluginfile.php/2129286/mod_resource/content/1/ACH2002-Aula16-HeapSort.pdf)
3. [Algoritmo do Heapsort - GitHub](https://github.com/Vnicius/ed-heapsort)
4. [09-heapSort.pdf - EACH-Usp](http://www.each.usp.br/digiampietri/SIN5013/09-heapSort.pdf)
5. [Análise de algoritmos - Heapsort (PDF)](http://www.din.uem.br/~fuber/PAA/notas-de-aula/pdfs/06-heapsort.pdf)
6. [HeapSort - Delano M. Beder (PDF)](http://www.each.usp.br/digiampietri/SIN5013/09-heapSort.pdf)
7. [Heapsort - Artigo de Prof. Flávio Rogério Uber (PDF)](http://www.din.uem.br/~fuber/PAA/notas-de-aula/pdfs/06-heapsort.pdf)
8. [HeapSort em Java - Exemplo de implementação](https://pt.wikipedia.org/wiki/Heapsort#Implementa%C3%A7%C3%A3o_em_Java)
