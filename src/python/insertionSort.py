def insertion_sort(arr):
    # Percorre cada elemento da lista, começando do segundo
    for i in range(1, len(arr)):
        key = arr[i]  # Seleciona o número que vamos ordenar
        j = i - 1  # Posição do elemento à esquerda da "key"

        # Enquanto o número da esquerda for maior que a "key"
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]  # Mova esse número para a direita
            j -= 1  # Volte uma posição para comparar o próximo

        # Coloca a "key" na posição correta
        arr[j + 1] = key

# Exemplo para testar o algoritmo
arr = [12, 11, 13, 5, 6]
print("Lista antes de ordenar:", arr)
insertion_sort(arr)
print("Lista ordenada:", arr)
