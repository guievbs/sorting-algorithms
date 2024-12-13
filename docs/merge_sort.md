# Merge Sort

## 📖 Introdução

O **Merge Sort** é um algoritmo de ordenação eficiente que utiliza a técnica de **divisão e conquista**. Criado por **[John von Neumann](https://pt.wikipedia.org/wiki/John_von_Neumann)** em **1945**, este algoritmo se destaca pela sua eficiência e estabilidade, sendo amplamente utilizado em aplicações que exigem alta performance na ordenação de dados.

###### Curiosidade sobre o Neumnn: "As festas em casa de von Neumann eram frequentes, famosas, e longas."

---

## Motivação do Uso e Desenvolvimento

O Merge Sort foi desenvolvido para resolver problemas de ordenação em grandes volumes de dados, onde a eficiência é crucial. Sua abordagem divide o problema em partes menores, permitindo que cada parte seja resolvida independentemente antes de serem combinadas. Essa característica torna o Merge Sort especialmente útil em ambientes onde a estabilidade da ordenação é necessária, como na ordenação de registros com múltiplos campos.

---

## Funcionamento do Algoritmo

### Passo a Passo

1. **🪓 Divisão**: A lista é dividida ao meio até que cada sublista tenha apenas um elemento.
2. **🤝 Conquista**: Cada sublista é ordenada recursivamente.
3. **🔗 Mesclagem (Merge)**: As sublistas ordenadas são combinadas, comparando os elementos e organizando-os em ordem crescente.

**Exemplo de Divisão e Mesclagem:**

Lista original: `[38, 27, 43, 3, 9, 82, 10]`

- **Divisão**:  
  `[38, 27, 43]` e `[3, 9, 82, 10]`  
  ``, `[27, 43]`e`[3, 9]`, `[82, 10]`

- **Mesclagem**:  
  `[27, 38, 43]` e `[3, 9, 10, 82]`  
  Resultado final: `[3, 9, 10, 27, 38, 43, 82]`

---

## 📊 Complexidade

s

- **Melhor Caso**: O(n \log n)
- **Pior Caso**: O(n \log n)
- **Caso Médio**: O(n \log n)

O Merge Sort requer **espaço adicional** de _O(n)_ devido à criação de sublistas para a mesclagem.

---

## 💻 Implementação

### Python

```python
def merge_sort(array):
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

    while i < len(esquerda):
        resultado.append(esquerda[i])
        i += 1

    while j < len(direita):
        resultado.append(direita[j])
        j += 1

    return resultado
```

### C

```c
#include <stdio.h>
#include <stdlib.h>

void mergeSort(int arr[], int inicio, int fim);
void merge(int arr[], int inicio, int meio, int fim);

void mergeSort(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio + 1, fim);
        merge(arr, inicio, meio, fim);
    }
}

void merge(int arr[], int inicio, int meio, int fim) {
    int i = inicio;
    int j = meio + 1;
    int k = inicio;

    int *temp = malloc((fim - inicio + 1) * sizeof(int));

    while (i <= meio && j <= fim) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= meio) {
        temp[k++] = arr[i++];
    }

    while (j <= fim) {
        temp[k++] = arr[j++];
    }

    for (i = inicio; i <= fim; i++) {
        arr[i] = temp[i];
    }

    free(temp);
}
```

---

## 🛠️ Casos de Uso

- Ordenação em sistemas críticos que exigem alta previsibilidade.
- Ordenação de grandes volumes de dados devido à sua eficiência em _O(n \log n)_.
- Ambientes que precisam de um algoritmo estável.

---

## ⚖️ Vantagens e Desvantagens

### ✅ Vantagens

- Complexidade consistente: _O(n \log n)_ em qualquer cenário.
- Estável: Mantém a ordem relativa de elementos iguais.
- Excelente para grandes conjuntos de dados.

### ❌ Desvantagens

- Consome mais memória devido à criação de sublistas.
- Menos eficiente para listas pequenas.

---

## 📝 Curiosidades

- O Merge Sort é frequentemente utilizado em linguagens como Lisp devido à sua eficiência na manipulação de listas encadeadas.
- É o algoritmo base para o TimSort utilizado no Python e Java.

---

## Gráfico Comparativo com Outros Algoritmos

| Algoritmo      | Melhor Caso | Pior Caso  | Caso Médio  |
| -------------- | ----------- | ---------- | ----------- |
| Merge Sort     | O(n \log n) | (n \log n) | (n \log n)  |
| Quick Sort     | O(n \log n) | O(n²)      | O(n \log n) |
| Bubble Sort    | O(n)        | O(n²)      | O(n²)       |
| Insertion Sort | O(n)        | O(n²)      | O(n²)       |

---

## Elementos Repetidos no Merge sort

O Merge Sort é um algoritmo de ordenação que se comporta de maneira eficiente e estável, mesmo em listas que contêm elementos repetidos.

- O algoritmo divide a lista em sublistas até que cada sublista contenha apenas um elemento. Isso significa que, se houver elementos repetidos, cada um deles será tratado como uma entidade separada durante a divisão. Durante a fase de mesclagem, os elementos das sublistas são comparados. Se dois elementos iguais forem encontrados (por exemplo, duas instâncias do número 5), o algoritmo os manterá na mesma ordem em que foram encontrados nas sublistas originais.
- Isso ocorre porque, ao mesclar, o Merge Sort sempre pega o primeiro elemento disponível de cada sublista. Se ambos os elementos forem iguais, o elemento da sublista à esquerda será escolhido primeiro, preservando sua posição relativa. Após todas as mesclagens, os elementos duplicados aparecerão lado a lado na lista ordenada final. Por exemplo, ao ordenar a lista [4, 2, 5, 5, 1], o resultado será [1, 2, 4, 5, 5], onde os dois 5 permanecem na mesma ordem relativa.

---

## Importância dos Algoritmos de Ordenação

Os algoritmos de ordenação são fundamentais na ciência da computação porque:

- Facilitam a busca eficiente de dados.
- Melhoram a performance de outros algoritmos que dependem da ordenação.
- São essenciais em aplicações práticas como bancos de dados e sistemas operacionais.

---

## Programação Competitiva

A programação competitiva envolve resolver problemas complexos sob restrições de tempo. O conhecimento sobre algoritmos como o Merge Sort é crucial para otimizar soluções e garantir desempenho eficiente.

---

## Quiz Interativo

1. Qual é a complexidade do Merge Sort no pior caso?

2. O Merge Sort é um algoritmo:

3. Em qual ano John von Neumann desenvolveu o Merge Sort?

---

## Recursos Gráficos na Web

Para visualizar o funcionamento do Merge Sort e comparar com outros algoritmos:

- [Visualgo](https://visualgo.net/en/sorting)
- [HackerEarth](https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/visualize/)

---

## Dicas para Programar no LeetCode

1. **Entenda bem o problema** antes de começar a codificar.
2. **Estude soluções existentes** e analise diferentes abordagens.
3. **Teste seu código com casos extremos** para garantir robustez.
4. Pratique regularmente para aprimorar suas habilidades em algoritmos.

---

## 🎥 Vídeo Explicativo

![type:video](https://www.youtube.com/embed/nV_WE8SEuGE?si=mmKkww2e7E-QSfPS)

---

## Referências

Esses detalhes adicionais enriquecem a documentação do Merge Sort e ajudam a compreender melhor sua importância na ciência da computação.

Citação:

1. [Wikipedia](https://en.wikipedia.org/wiki/Merge_Sort)
2. [Stackoverflow](https://stackoverflow.com/questions/73733319/comparison-using-merge-sort)
3. [Visualgo](https://visualgo.net/en/sorting)
4. [Geeks For Geeks](https://www.geeksforgeeks.org/merge-sort/)
5. [Geeks For Geeks](https://www.geeksforgeeks.org/time-and-space-complexity-analysis-of-merge-sort/)
6. [Code Mentor](https://www.codementor.io/@satycool16/a-step-by-step-guide-to-mastering-leetcode-problems-2dp8hqogsg)
7. [Developer Nvidia](https://developer.nvidia.com/blog/merge-sort-explained-a-data-scientists-algorithm-guide/)
8. [Github](https://github.com/tusharmakkar08/Sorting_Graphs)
9. [HSM - Stack Exchange](https://hsm.stackexchange.com/questions/12549/how-did-von-neumann-come-up-with-his-merge-sort-algorithm)
