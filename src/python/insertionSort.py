def insertion_sort(arr):
    """
    Ordena uma lista de números usando o algoritmo Insertion Sort.
    Args:
        arr (list): A lista de números a ser ordenada.
    """
    # Percorre cada elemento da lista, começando do segundo
    for i in range(1, len(arr)):
        key = arr[i]  # Seleciona o elemento atual para ordenar
        j = i - 1     # Índice do elemento à esquerda da "key"

        # Exibe o estado inicial da iteração
        print(f"Iteração {i}:")
        print(f"  Elemento selecionado: {key}")
        print(f"  Sublista ordenada antes da inserção: {arr[:i]}")

        # Move os elementos maiores que "key" uma posição à direita
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]  # Move o elemento para a direita
            print(f"  {arr[j]} é maior que {key}, movendo para a direita.")
            j -= 1               # Passa para o próximo elemento à esquerda

        # Coloca a "key" na posição correta
        arr[j + 1] = key
        print(f"  Colocando {key} na posição {j + 1}.")
        print(f"  Estado atual da lista: {arr}")
        print()  # Linha em branco para separar as iterações

# Exemplo para testar o algoritmo
arr = [12, 11, 13, 5, 6]  # Lista inicial para teste
print("Lista antes de ordenar:", arr)
insertion_sort(arr)
print("Lista ordenada:", arr)
