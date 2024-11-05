def bubble_sort(arr):
    # Verifica se a lista está vazia
    if not arr:
        print("A lista está vazia e não há nada para ordenar.")
        return
    
    n = len(arr)  # Tamanho da lista

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
