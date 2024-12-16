# Counting Sort

## 📖 Introdução

O **Counting Sort** é um algoritmo de ordenação baseado na contagem da frequência de elementos. Em vez de comparar elementos diretamente, ele cria um array auxiliar para armazenar a frequência de cada valor e, a partir dessas informações, gera a lista ordenada. Foi proposto por **Harold H. Seward** em **1954** e é considerado um dos algoritmos mais rápidos quando aplicado a dados com um intervalo limitado.

###### Curiosidade sobre o Counting Sort: "É frequentemente usado em ambientes onde os dados são pequenos e inteiros, como a ordenação de notas escolares ou distribuições numéricas com pequenos intervalos."

---

## Motivação do Uso e Desenvolvimento

O Counting Sort foi desenvolvido para ser eficiente em cenários onde a faixa de valores dos elementos a serem ordenados é limitada, especialmente quando a diferença entre o valor máximo e o valor mínimo não é muito grande. Sua principal vantagem é o desempenho em tempo linear **O(n + k)**, onde `n` é o número de elementos a ser ordenados e `k` é o intervalo de valores, o que o torna mais eficiente do que algoritmos de comparação em determinadas situações.

---

## Funcionamento do Algoritmo

### Passo a Passo

1. **📝 Contagem das Frequências**: Um array de contagem é criado, onde cada índice representará um valor possível na lista de entrada e armazenará o número de ocorrências desse valor.
2. **🔢 Cálculo da Posição**: Com base no array de contagem, o algoritmo determina a posição final de cada elemento na lista ordenada.
3. **📍 Construção da Lista Ordenada**: Utilizando as informações do array de contagem, a lista original é reconstituída de forma ordenada.

**Exemplo de Contagem e Ordenação:**

Lista original: `[4, 2, 2, 8, 3, 3, 1]`

- **Contagem de Frequências**:

  ```
  Frequências: [0, 1, 2, 2, 1, 0, 0, 0, 1]
  ```

  Onde o índice representa os números e o valor armazena a frequência.

- **Reconstrução da Lista Ordenada**:  
  Resultado final: `[1, 2, 2, 3, 3, 4, 8]`

---

## 📊 Complexidade

- **Melhor Caso**: O(n + k)
- **Pior Caso**: O(n + k)
- **Caso Médio**: O(n + k)

Embora a complexidade de tempo seja linear **O(n + k)**, ela depende fortemente de `k`, o intervalo dos elementos. Em situações onde `k` é muito maior que `n`, o Counting Sort pode ser ineficiente devido ao uso de memória adicional.

---

## 💻 Implementação

### Python

```python
def counting_sort(arr):
    # Encontrar o valor máximo na lista
    max_val = max(arr)
    min_val = min(arr)

    # Tamanho do intervalo de valores
    range_of_elements = max_val - min_val + 1

    # Criando um array de contagem com base no intervalo
    count = [0] * range_of_elements
    output = [0] * len(arr)

    # Contar a ocorrência de cada valor
    for num in arr:
        count[num - min_val] += 1

    # Alterar o array de contagem para armazenar a posição correta de cada número
    for i in range(1, len(count)):
        count[i] += count[i - 1]

    # Construir o array ordenado
    for num in reversed(arr):
        output[count[num - min_val] - 1] = num
        count[num - min_val] -= 1

    return output
```

### C

```c
#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n);

void countingSort(int arr[], int n) {
    int max_val = arr[0];
    int min_val = arr[0];

    // Encontrar o valor máximo e mínimo
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    // Tamanho do intervalo
    int range = max_val - min_val + 1;
    int *count = (int *)calloc(range, sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));

    // Contagem da frequência dos elementos
    for (int i = 0; i < n; i++) {
        count[arr[i] - min_val]++;
    }

    // Atualizar o array de contagem
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Construir o array ordenado
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - min_val] - 1] = arr[i];
        count[arr[i] - min_val]--;
    }

    // Copiar os elementos ordenados de volta para o array original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(count);
    free(output);
}
```

---

## 🛠️ Casos de Uso

- **Distribuições numéricas com um intervalo limitado**: O Counting Sort é altamente eficiente para ordenar números inteiros em intervalos pequenos.
- **Problemas de ordenação com dados discretos**: Quando o intervalo de dados conhecidos é pequeno, como ordenar notas de alunos, idades, ou classificações.

---

## ⚖️ Vantagens e Desvantagens

### ✅ Vantagens

- **Tempo Linear**: A principal vantagem é sua complexidade de tempo de O(n + k), tornando-o muito rápido para intervalos pequenos.
- **Estabilidade**: Pode ser implementado de forma estável, o que significa que a ordem relativa dos elementos iguais será mantida.
- **In-place**: Quando o intervalo de dados é restrito, o algoritmo usa pouca memória adicional.

### ❌ Desvantagens

- **Ineficiente para grandes intervalos**: Se `k`, o intervalo dos valores, for muito grande em relação a `n`, o algoritmo pode consumir grande quantidade de memória e tempo.
- **Requer conhecimento prévio do intervalo de valores**: O algoritmo exige que o intervalo dos dados seja conhecido e bem limitado.

---

## 📝 Curiosidades

- O Counting Sort é frequentemente utilizado em **sistemas de ordenação paralela** devido à sua capacidade de dividir o trabalho de contagem de frequência entre várias unidades.
- Ele é particularmente útil quando a distribuição dos dados é bastante desigual e o intervalo de valores é relativamente pequeno.

---

## Gráfico Comparativo com Outros Algoritmos

| Algoritmo     | Melhor Caso | Pior Caso  | Caso Médio |
| ------------- | ----------- | ---------- | ---------- |
| Counting Sort | O(n + k)    | O(n + k)   | O(n + k)   |
| Merge Sort    | O(n log n)  | O(n log n) | O(n log n) |
| Quick Sort    | O(n log n)  | O(n²)      | O(n log n) |
| Heap Sort     | O(n log n)  | O(n log n) | O(n log n) |

---

## Elementos Repetidos no Counting Sort

O **Counting Sort** mantém a estabilidade, o que significa que ele preserva a ordem original dos elementos duplicados. Como ele processa cada elemento de forma ordenada a partir do seu índice, ele sempre coloca as instâncias iguais em suas posições apropriadas sem reordená-las. Assim, se tivermos a lista `[4, 2, 2, 8, 3, 3, 1]`, a saída será `[1, 2, 2, 3, 3, 4, 8]`, com as duas instâncias do `2` e `3` mantendo sua ordem original.

---

## Importância dos Algoritmos de Ordenação

Os algoritmos de ordenação como o Counting Sort são essenciais para muitos sistemas computacionais que dependem de listagens ou distribuições, tais como algoritmos de análise de dados, classificação em bases de dados, e sistemas de recomendação.

---

## Programação Competitiva

Na programação competitiva, algoritmos como o Counting Sort podem ser muito úteis para resolver problemas envolvendo a contagem e distribuição de elementos de maneira eficiente. Além disso, seu uso pode melhorar drasticamente o desempenho em problemas com dados numéricos limitados.

---

## Quiz Interativo

1. Em qual situação o Counting Sort é mais eficiente?

2. O Counting Sort é considerado um algoritmo:

3. Qual é a principal desvantagem do Counting Sort?

---

## Recursos Gráficos na Web

- [Visualgo](https://visualgo.net/en/sorting)
- [GeeksForGeeks](https://www.geeksforgeeks.org/counting-sort/)

---

## Dicas para Programar no LeetCode

1. **Esteja ciente dos limites de intervalo**: O Counting Sort é ótimo quando o intervalo é pequeno. Se você suspeitar que o intervalo é grande, considere usar outros algoritmos.
2. **Aproveite as versões estáveis**: A estabilidade do Counting Sort pode ser útil para problemas onde a ordem relativa dos elementos iguais importa.
3. **Pratique sua implementação em ambientes sem muitos recursos** para testar seu desempenho.

---

## 🎥 Vídeo Explicativo

## [:fontawesome-brands-youtube: Link do vídeo](https://drive.google.com/file/d/1TjtVGY_DBz_H0U17XokO4fUZY1g3CvnT/view?usp=sharing){ .md-button }

---

## Referências

Esses detalhes adicionais enriquecem a documentação do Counting Sort e ajudam a compreender melhor sua importância na ciência da computação.

Citação:

1. [Counting Sort - Desenvolvendo Software](http://desenvolvendosoftware.com.br/algoritmos/ordenacao/counting-sort.html)
2. [CountingSort-Algorithm - GitHub](https://github.com/thales-assis/CountingSort-Algorithm)
3. [Complexidade Assintótica - Algoritmos de Ordenação (PDF)](https://edisciplinas.usp.br/pluginfile.php/2167878/mod_resource/content/1/ACH2002-Aula18-OrdenacaoTempoLinear.pdf)
4. [Counting sort – Wikipédia](https://pt.wikipedia.org/wiki/Counting_sort)
5. [Ordenação Linear: Counting sort - João Arthur](https://joaoarthurbm.github.io/eda/posts/ordenacao-linear/)
6. [Algoritmos de Ordenação: Análise e Comparação - DevMedia](https://www.devmedia.com.br/algoritmos-de-ordenacao-analise-e-comparacao/28261)
7. [Métodos de Ordenação: Quick, Radix, Counting, Bucket (Sort) - UFG (PDF)](https://ww2.inf.ufg.br/~hebert/disc/aed1/AED1_05_ordenacao2.pdf)
8. [Apresentação sobre Ordenação por Contagem - CIn UFPE (PPT)](https://www.cin.ufpe.br/~joa/menu_options/school/cursos/pea/Projetos/ApresentacaoNataliaBreno.ppt)
