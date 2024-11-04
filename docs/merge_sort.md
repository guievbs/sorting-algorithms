# Algoritmo de Ordenação: Merge Sort

## Índice

1. [Introdução](#introdução)
2. [Funcionamento do Algoritmo](#funcionamento-do-algoritmo)
3. [Complexidade](#complexidade)
4. [Implementação](#implementação)
   - [Python](https://github.com/guievbs/sorting-algorithms/tree/main/src/python)
   - [C](https://github.com/guievbs/sorting-algorithms/tree/main/src/c)
5. [Casos de Uso](#casos-de-uso)
6. [Vantagens e Desvantagens](#vantagens-e-desvantagens)
7. [Referências](#referências)

---

## Introdução

O **Merge Sort** é um algoritmo de ordenação eficiente que utiliza a técnica de **divisão e conquista**. É particularmente útil para grandes conjuntos de dados devido à sua complexidade logarítmica, sendo também estável, ou seja, mantém a ordem relativa dos elementos iguais. Em sistemas críticos e ambientes que exigem alta eficiência, o Merge Sort é frequentemente preferido por sua previsibilidade e consistência em tempo de execução.

---

## Funcionamento do Algoritmo

### Descrição

O algoritmo funciona dividindo a lista a ser ordenada em sublistas cada vez menores, até que cada sublista contenha apenas um elemento, que por definição está ordenado. Em seguida, ele realiza a fase de **mesclagem** das sublistas de maneira ordenada para reconstruir a lista original, agora totalmente ordenada.

### Passo a Passo

1. **Divisão**: Se a lista tiver mais de um elemento, ela é dividida ao meio, criando duas sublistas.
2. **Conquista**: As duas sublistas são ordenadas recursivamente utilizando o próprio Merge Sort.
3. **Combinação (Merge)**: As sublistas ordenadas são combinadas em uma única lista ordenada, comparando os elementos das duas listas e inserindo o menor deles na lista resultante.

Esse processo se repete recursivamente até que toda a lista original esteja ordenada.

---

## Complexidade

A análise de complexidade do Merge Sort considera as operações de divisão e mesclagem dos elementos:

- **Melhor Caso**: `O(n log n)` - Todos os elementos são processados de maneira previsível.
- **Pior Caso**: `O(n log n)` - O Merge Sort sempre executa a mesma quantidade de operações, independentemente da organização dos dados.
- **Caso Médio**: `O(n log n)` - A complexidade permanece constante em qualquer cenário, tornando-o altamente eficiente e previsível.

O Merge Sort requer um espaço adicional de `O(n)` para realizar as operações de mesclagem, o que pode ser um fator limitante em aplicações com grandes volumes de dados.

---

## Implementação

Abaixo, temos links para as implementações em diferentes linguagens:

- **Python**: [Implementação em Python](https://github.com/guievbs/sorting-algorithms/tree/main/src/python)
- **C**: [Implementação em C](https://github.com/guievbs/sorting-algorithms/tree/main/src/c)

Esses códigos demonstram como o Merge Sort é implementado de forma recursiva, mantendo sua estrutura clara e modular.

---

## Casos de Uso

O Merge Sort é amplamente utilizado em cenários onde é necessário um algoritmo de ordenação estável e eficiente:

1. **Sistemas de gerenciamento de bancos de dados**: Ideal para ordenar grandes conjuntos de dados de forma eficiente e previsível.
2. **Algoritmos de ordenação interna**: Serve como base para algoritmos mais complexos e técnicas de otimização de dados.
3. **Bibliotecas de programação**: Muitas bibliotecas padrão incluem o Merge Sort para realizar operações de ordenação de alta performance, especialmente para grandes volumes de dados.

---

## Vantagens e Desvantagens

### Vantagens

- **Eficiência garantida**: O Merge Sort sempre apresenta complexidade `O(n log n)`.
- **Estabilidade**: Mantém a ordem dos elementos iguais, o que pode ser importante em determinados contextos.
- **Aplicável a grandes conjuntos de dados**: É especialmente eficaz para ordenar listas de tamanho considerável.

### Desvantagens

- **Requer memória adicional**: A mesclagem de sublistas exige espaço extra, o que pode ser problemático em sistemas com limitações de memória.
- **Não é o mais rápido para listas pequenas**: Para listas menores, o Merge Sort pode ser menos eficiente em comparação a outros algoritmos, como o Insertion Sort.

---

## Referências

- [Wikipedia - Merge Sort](https://en.wikipedia.org/wiki/Merge_sort)
- **Livro**: *Entendendo Algoritmos*, Aditya Y. Bhargava, capítulo 4 - Quick Sort, Página 84.
- **Vídeo**: "CS50x 2024 - Lecture 3 - Algorithms", disponível no [Youtube](https://youtu.be/jZzyERW7h1A?t=6395), conteúdo em inglês.
