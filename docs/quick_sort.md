# Quick Sort

## 🕯️ Introdução

O **Quick Sort** é um algoritmo de ordenação eficiente e popular, baseado no princípio de **divisão e conquista**. Desenvolvido por **Tony Hoare** em **1960**, este algoritmo é amplamente utilizado devido à sua simplicidade e excelente desempenho em grandes volumes de dados.

**Curiosidade:** Tony Hoare também é conhecido pela "Hipótese do Buraco de Memória" e pela famosa "Null Pointer Exception", que ele chamou de seu "maior erro".

---

## Motivação

O Quick Sort foi criado para resolver problemas de ordenação em situações onde o desempenho e a flexibilidade são cruciais. Sua principal força está em dividir o problema em subproblemas menores, utilizando um elemento chamado **pivô** para realizar essa separação.

Essa abordagem adaptável torna o Quick Sort ideal para aplicações que lidam com dados dispostos de formas variadas.

---

## Funcionamento do Algoritmo

### Passo a Passo

1. **Seleção do Pivô**: Escolhe-se um elemento da lista como pivô (geralmente o último elemento ou um escolhido aleatoriamente).
2. **Particionamento**: Elementos menores que o pivô são movidos para a esquerda, enquanto os maiores vão para a direita.
3. **Chamada Recursiva**: O processo é repetido recursivamente nas sublistas esquerda e direita até que a lista esteja completamente ordenada.

**Exemplo de Funcionamento:**

Lista original: `[10, 7, 8, 9, 1, 5]`

- Escolhe-se o pivô: `5`
- Particiona-se: `[1] | 5 | [10, 7, 8, 9]`
- Recursão à esquerda e à direita até obter `[1, 5, 7, 8, 9, 10]`.

---

## 📊 Complexidade

- **Melhor Caso**: O(n \log n) – quando o pivô divide a lista em metades iguais.
- **Pior Caso**: O(n²) – ocorre quando o pivô é sempre o maior ou menor elemento.
- **Caso Médio**: O(n \log n) – comportamento mais comum.

O Quick Sort exige **memória adicional mínima**, pois realiza a ordenação no local (**in-place sorting**).

---

## 💻 Implementação

### Em Python

```python
def quick_sort(array):
    if len(array) <= 1:
        return array

    pivô = array[-1]  # Escolhe o último elemento como pivô
    menores = [x for x in array[:-1] if x <= pivô]
    maiores = [x for x in array[:-1] if x > pivô]

    return quick_sort(menores) + [pivô] + quick_sort(maiores)
```

### Em C

```c
#include <stdio.h>

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Escolhe o último elemento como pivô
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}
```

---

## 🔧 Casos de Uso

- Aplicativos onde a velocidade de ordenação é crucial.
- Cenários com pouca memória disponível, pois o Quick Sort utiliza pouco espaço adicional.
- Situações onde a estabilidade da ordenação não é necessária.

---

## ⚖️ Vantagens e Desvantagens

- Altamente eficiente em grandes conjuntos de dados.
- Requer pouca memória adicional.
- Geralmente mais rápido que outros algoritmos de ordenação.

### ❌ Desvantagens

- Desempenho pode ser prejudicado em listas já ordenadas ou quase ordenadas.
- Não preserva a estabilidade entre elementos iguais.

---

## 📝 Curiosidades

- O Quick Sort é utilizado em bibliotecas padrão de linguagens como C++ e Python devido à sua eficiência.
- Linguagens modernas implementam variações do Quick Sort, como o **Dual-Pivot Quick Sort**.

---

## Comparativo com Outros Algoritmos

| Algoritmo      | Melhor Caso | Pior Caso   | Caso Médio  |
| -------------- | ----------- | ----------- | ----------- |
| Quick Sort     | O(n \log n) | O(n²)       | O(n \log n) |
| Merge Sort     | O(n \log n) | O(n \log n) | O(n \log n) |
| Bubble Sort    | O(n)        | O(n²)       | O(n²)       |
| Insertion Sort | O(n)        | O(n²)       | O(n²)       |

---

## Elementos Repetidos no Merge sort

Em listas com elementos repetidos, o Quick Sort pode alterar a ordem relativa desses elementos, já que não é estável. Contudo, ele agrupa todas as ocorrências do mesmo valor de forma eficiente.

---

## 🔍 Importância dos Algoritmos de Ordenação

Os algoritmos de ordenação são essenciais para:

- Facilitar buscas eficientes em dados.
- Auxiliar em operações como fusão de bases de dados.
- Melhorar o desempenho em aplicações complexas, como inteligência artificial.

---

## 🎯 Quick Sort na Programação Competitiva

No contexto da programação competitiva, o Quick Sort é amplamente utilizado por sua velocidade e simplicidade de implementação. Porém, é fundamental:

- Selecionar o pivô de forma criteriosa (por exemplo, de forma aleatória) para evitar o pior caso.
- Conhecer bem as limitações e adaptações do algoritmo para diferentes problemas.

---

## Quiz Interativo

1. Qual é a complexidade do Quick Sort no melhor caso?

2. O Quick Sort é um algoritmo:

3. Em qual ano foi desenvolvido o Quick Sort?

---

## 🌐 Recursos Gráficos na Web

- [Visualgo](https://visualgo.net/en/sorting)
- [HackerEarth](https://www.hackerearth.com/practice/algorithms/sorting/quick-sort/visualize/)

---

## 🏅 Dicas para o LeetCode

1. **Compreenda bem o problema** antes de começar a codificar.
2. **Pratique diferentes variações** do Quick Sort (pivô fixo, aleatório, etc.).
3. **Teste casos extremos** para assegurar eficiência.
4. **Pratique regularmente** para aprimorar suas habilidades.

---

## 🎥 Vídeo Explicativo

![type:video](https://www.youtube.com/embed/nV_WE8SEuGE?si=mmKkww2e7E-QSfPS)

---

## Referências

Esses detalhes adicionais enriquecem a documentação do Quick Sort e ajudam a compreender melhor sua importância na ciência da computação.

Citação:

1. [Wikipedia - Quick Sort](https://en.wikipedia.org/wiki/Quicksort)
2. **Livro**: _Entendendo Algoritmos_, Aditya Y. Bhargava.
3. **Vídeo**: [Quicksort: Implementação e Explicação](https://www.youtube.com/watch?v=nV_WE8SEuGE)
4. [DEV Community](https://dev.to/dormin/ordenacao-rapida-quick-sort-171f)
5. [Blog Cyberini](https://www.blogcyberini.com/2018/08/quicksort-analise-e-implementacoes.html)
6. [Khan Academy](https://pt.khanacademy.org/computing/computer-science/algorithms/quick-sort/a/overview-of-quicksort) -
