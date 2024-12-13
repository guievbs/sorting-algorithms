# Insertion Sort

## ✨ Introdução

O **Insertion Sort** é um algoritmo simples e eficiente para ordenar listas pequenas. Ele funciona de maneira semelhante à organização de cartas de um baralho: você seleciona uma carta de cada vez e a posiciona no local correto entre as outras.

---

## Motivção do Uso e Desenvolvimento

O Insertion Sort é muito útil em situações onde a simplicidade da implementação é crucial e os conjuntos de dados são pequenos ou quase ordenados. Sua abordagem intuitiva faz com que seja uma escolha popular para ensino de algoritmos de ordenação.

---

## Funcionamento do Algoritmo

### Passo a Passo

1. **Selecionar um elemento**: Comece com o segundo elemento da lista (o primeiro é considerado já ordenado).
2. **Comparar**: Compare este elemento com os elementos anteriores da lista.
3. **Reordenar**: Insira o elemento na posição correta na sublista ordenada.
4. **Repetir**: Repita para todos os elementos até que a lista esteja completamente ordenada.

**Exemplo de Funcionamento:**

Lista original: `[5, 3, 8, 6]`

- **Passo 1:** Selecionar `3`, comparar com `5` e inserir antes: `[3, 5, 8, 6]`
- **Passo 2:** Selecionar `8`, nenhuma alteração necessária: `[3, 5, 8, 6]`
- **Passo 3:** Selecionar `6`, inserir entre `5` e `8`: `[3, 5, 6, 8]`
- **Fim:** Lista ordenada.

Na primeira iteração, `3` é comparado a `5` porque é menor e, portanto, é deslocado para a primeira posição. Posteriormente, “6” encontra seu lugar entre `5` e `8`, demonstrando como o algoritmo refina progressivamente a ordem.

---

## 📊 Complexidade

- **Melhor Caso:** _O(n)_ – quando a lista já está ordenada.
- **Pior Caso:** _O(n²)_ – quando a lista está em ordem decrescente.
- **Caso Médio:** _O(n²)_.

O Insertion Sort tem a vantagem de ser um algoritmo _in-place_, ou seja, não requer memória adicional significativa.

---

## 💻 Implementação

### Python

```python
def insertion_sort(array):
    for i in range(1, len(array)):
        key = array[i]
        j = i - 1
        while j >= 0 and array[j] > key:
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = key
    return array
```

### C

```c
#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
```

---

## 🛠️ Casos de Uso

- Conjuntos de dados pequenos.
- Dados quase ordenados.
- Situações educacionais para ensino de algoritmos de ordenação.

---

## ⚖️ Vantagens e Desvantagens

### ✅ Vantagens

- Simples e intuitivo de implementar.
- Excelente desempenho para listas pequenas.
- Estável, mantendo a ordem relativa de elementos iguais.

### ❌ Desvantagens

- Ineficiente para listas grandes.
- Complexidade $$O(n^2)$$ em muitos cenários.

---

## Curiosidades

- O Insertion Sort é um dos algoritmos mais intuitivos e pode ser implementado à mão sem dificuldade.
- Seu conceito está relacionado ao método que humanos frequentemente usam para ordenar cartas.

---

## Gráfico Comparativo com Outros Algoritmos

| Algoritmo      | Melhor Caso | Pior Caso   | Caso Médio  |
| -------------- | ----------- | ----------- | ----------- |
| Insertion Sort | O(n)        | O(n²)       | O(n²)       |
| Bubble Sort    | O(n)        | O(n²)       | O(n²)       |
| Quick Sort     | O(n \log n) | O(n²)       | O(n \log n) |
| Merge Sort     | O(n \log n) | O(n \log n) | O(n \log n) |

---

### Como o Insertion Sort lida com elementos repetidos

O Insertion Sort é um algoritmo **estável**, ou seja, ele preserva a ordem relativa dos elementos iguais, tornando-o ideal para situações onde essa característica é importante.

---

## Importância dos Algoritmos de Ordenação

Os algoritmos de ordenação são essenciais na computação para:

- Otimizar buscas e análises de dados.
- Organizar informações para processamento.
- Facilitar operações em bancos de dados.

---

## Programção Competitiva

Embora o Insertion Sort seja pouco usado em competições devido à sua ineficiência em dados grandes, ele é uma opção inicial simples para prototipação e aprendizado.

---

## Quiz Interativo

1. Qual é a complexidade do Insertion Sort no melhor caso?

2. O Insertion Sort é um algoritmo:

3. Para quais conjuntos de dados o Insertion Sort é mais eficiente?

---

## Recursos Gráficos na Web

- [Visualgo](https://visualgo.net/en/sorting)
- [GeeksforGeeks](https://www.geeksforgeeks.org/insertion-sort/)

---

## Dicas para Programar no LeetCode

1. **Entenda o problema**: avalie quando usar Insertion Sort em desafios.
2. **Explore variações**, como a ordenação em ordem decrescente.
3. **Analise cenários adequados**, priorizando listas pequenas ou quase ordenadas.

---

## 🎥 Vídeo Explicativo

![type:video](https://www.youtube.com/embed/nV_WE8SEuGE?si=mmKkww2e7E-QSfPS)

---

## Referências

Esses detalhes adicionais enriquecem a documentação do Insertion Sort e ajudam a compreender melhor sua importância na ciência da computação.

Citação:

1. [João Arthur - Insertion Sort](https://joaoarthurbm.github.io/eda/posts/insertion-sort/)
2. [Como Programar - Desvendando o Algoritmo de Ordenação Insertion Sort](https://comoprogramar.com.br/desvendando-o-algoritmo-de-ordenacao-insertion-sort-como-funciona-e-por-que-e-importante/)
3. [Blog Cyberini - Insertion Sort](https://www.blogcyberini.com/2018/06/insertion-sort.html)
4. [Paulo R. Lisboa de Almeida - Aula 9 - Insertion Sort (PDF)](https://prlalmeida.com.br/algII-2022-01/Aula9.pdf)
5. [Akira - O Algoritmo Insertion Sort](https://akiradev.netlify.app/posts/algoritmo-insertion-sort/)
6. [Wikipedia - Insertion sort](https://pt.wikipedia.org/wiki/Insertion_sort)
7. [Paulo R. Lisboa de Almeida - Aula 8 - Insertion Sort - Análise (PDF)](https://prlalmeida.com.br/algII-2022-01/Aula10.pdf)
8. [UFG - Métodos de Ordenação: Selection, Insertion, Bubble, Merge (Sort) (PDF)](https://ww2.inf.ufg.br/~hebert/disc/aed1/AED1_04_ordenacao1.pdf)
