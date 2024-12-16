# Bubble Sort

## 🫧 Introdução

O **Bubble Sort** é um algoritmo de ordenação simples, mas didático, amplamente utilizado para ensinar os fundamentos de algoritmos de ordenação. Apesar de sua performance inferior a outros algoritmos mais modernos, ele é importante por ilustrar conceitos básicos como comparção e troca de elementos.

###### Curiosidade: O nome "Bubble" (bolha) vem da ideia de que os elementos maiores "flutuam" para o topo da lista, como bolhas na água.

---

## Motivação do Uso e Desenvolvimento

O Bubble Sort foi desenvolvido como um algoritmo simples para ordenação, com a vantagem de ter uma implementação intuitiva e clara. Apesar de não ser eficiente para conjuntos de dados grandes, ele é frequentemente usado em aplicações didáticas e em casos onde a simplicidade da implementação é mais importante que a eficiência.

---

## Funcionamento do Algoritmo

### Passo a Passo

1. **Comparar pares consecutivos**: Percorra a lista e compare cada par de elementos adjacentes.
2. **Trocar se necessário**: Caso o elemento atual seja maior que o seguinte, troque-os de posição.
3. **Repetir**: Repita o processo até que nenhum elemento precise mais ser trocado, indicando que a lista está ordenada.

**Exemplo de Funcionamento:**

Lista original: `[5, 3, 8, 6]`

- **Passo 1**: Compare o primeiro par `(5, 3)` e, como `5 > 3`, realizamos a troca. A lista torna-se `[3, 5, 8, 6]`.
- **Passo 2**: Compare o próximo par `(5, 8)`. Como `5 < 8`, nenhuma troca é feita.
- **Passo 3**: Compare o último par `(8, 6)` e, como `8 > 6`, realizamos a troca. A lista torna-se `[3, 5, 6, 8]`.
- **Passo 4**: Na segunda varredura, nenhuma troca é necessária, indicando que a lista já está ordenada. Resultado final: `[3, 5, 6, 8]`.

---

## 📊 Complexidade

- **Melhor Caso**: O(n) – quando a lista já está ordenada.
- **Pior Caso**: O(n²) – quando a lista está completamente desordenada.
- **Caso Médio**: O(n²).

O Bubble Sort não utiliza memória adicional significativa, pois é implementado _in-place_.

---

## 💻 Implementação

### Python

```python
def bubble_sort(array):
    n = len(array)
    for i in range(n):
        trocou = False
        for j in range(n - i - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]
                trocou = True
        if not trocou:
            break
    return array
```

### C

```c
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int trocou;
    for (int i = 0; i < n - 1; i++) {
        trocou = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                trocou = 1;
            }
        }
        if (!trocou)
            break;
    }
}
```

---

## 🔧 Casos de Uso

- Aplicativos onde a simplicidade é mais importante que a eficiência.
- Cenários educacionais para ensinar algoritmos de ordenação.
- Pequenos conjuntos de dados que precisam ser ordenados rapidamente sem dependência de bibliotecas externas.

---

## ⚖️ Vantagens e Desvantagens

### ✅ Vantagens

- Simples de entender e implementar.
- Pode ser otimizado para interromper quando a lista está ordenada (melhor caso).
- Não requer memória adicional.

### ❌ Desvantagens

- Ineficiente para grandes conjuntos de dados.
- Alto número de comparações e trocas.

---

## Curiosidades

- Apesar de sua ineficiência, o Bubble Sort ainda é usado em situações muito específicas, como microcontroladores simples.
- Ele é frequentemente o primeiro algoritmo de ordenação que programadores aprendem.

---

## Gráfico Comparativo com Outros Algoritmos

| Algoritmo      | Melhor Caso | Pior Caso   | Caso Médio  |
| -------------- | ----------- | ----------- | ----------- |
| Bubble Sort    | O(n)        | O(n²)       | O(n²)       |
| Quick Sort     | O(n \log n) | O(n²)       | O(n \log n) |
| Merge Sort     | O(n \log n) | O(n \log n) | O(n \log n) |
| Insertion Sort | O(n)        | O(n²)       | O(n²)       |

---

### Como o Bubble Sort se comporta em listas com elementos repetidos

O Bubble Sort é **estável**, o que significa que ele preserva a ordem relativa de elementos iguais na lista final.

---

## Importância dos Algoritmos de Ordenação

Os algoritmos de ordenação são fundamentais na computação por:

- Melhorar a eficiência de buscas.
- Organizar dados para análise posterior.
- Facilitar outras operações algoritmicas, como junções e filtros em bases de dados.

---

## Programação Competitiva

Na programação competitiva, o Bubble Sort não é amplamente utilizado devido à sua lentidão. Contudo, é frequentemente usado como um ponto de partida para entender outros algoritmos de ordenação mais eficientes.

---

## Quiz Interativo

1. Qual é a complexidade do Bubble Sort no melhor caso?
2. O Bubble Sort é um algoritmo:
3. Em que cenário o Bubble Sort é ideal?

---

## Recursos Gráficos na Web

- [Visualgo](https://visualgo.net/en/sorting)
- [GeeksforGeeks](https://www.geeksforgeeks.org/bubble-sort/)

---

## Dicas para Programar no LeetCode

1. **Entenda bem o problema** antes de implementar a solução.
2. **Experimente otimizações simples**, como parar a iteração cedo quando a lista já estiver ordenada.
3. **Compreenda bem as limitações** do algoritmo para evitar aplicá-lo em casos inadequados.

---

## 🎥 Vídeo Explicativo

## [:fontawesome-brands-youtube: Link do vídeo](https://drive.google.com/file/d/1UG4JikH2-MuZ5XG_0jU7C6aupzuaraG3/view?usp=sharing){ .md-button }

---

## Referências

Esses detalhes adicionais enriquecem a documentação do Bubble Sort e ajudam a compreender melhor sua importância na ciência da computação.

Citação:

1. [Trybe Blog - Bubble Sort](https://blog.trybe.com.br/algoritmo-bubble-sort/)
2. [Embarcados - Bubble Sort](https://www.embarcados.com.br/bubble-sort/)
3. [Prof. Desiqqueira - Bubble Sort](https://profdesiqqueira.com/bubble-sort/)
4. [ElemarJR - Bubble Sort](https://elemarrjr.com/bubble-sort/)
5. [IFRN - Bubble Sort](https://www.ifrn.edu.br/ensino/tecnologia/bubble-sort)
6. [FreeCodeCamp - Algoritmos de Ordenação](https://www.freecodecamp.org/news/sorting-algorithms-explained/)
7. [Wikipedia - Bubble Sort](https://pt.wikipedia.org/wiki/Bubble_sort)
8. [UFG - Métodos de Ordenação](https://www.ufg.br/arquivos/ordenacao.pdf)
