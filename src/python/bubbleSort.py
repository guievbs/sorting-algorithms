def bubble_sort(arr):
    """
    Ordena uma lista de elementos usando o algoritmo Bubble Sort.
    Args:
        arr (list): A lista de elementos a ser ordenada.
    """
    # Verifica se a entrada é nula (None)
    if arr is None:
        print("Entrada inválida: lista é nula.")
        raise TypeError("Entrada inválida: lista é nula.")  # Lança um erro para entradas nulas

    # Verifica se a lista está vazia
    if not arr:
        print("A lista está vazia e não há nada para ordenar.")
        return None  # Não faz nada se a lista estiver vazia
    
    # Obtém o tamanho da lista
    n = len(arr)

    # Loop principal: controla o número de passagens necessárias
    for i in range(n - 1):
        # Loop interno: compara elementos adjacentes
        for j in range(n - 1 - i):
            # Se o elemento atual for maior que o próximo, realiza a troca
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]  # Troca usando desempacotamento

        # Exibe o estado da lista após cada passagem
        print(f"Iteração {i + 1}: {arr}")

# Teste com uma lista vazia
arr = []  # Lista vazia
print("Lista antes de ordenar:", arr)
bubble_sort(arr)
print("Lista depois de ordenar:", arr)

# Teste com uma lista preenchida
arr = [64, 34, 25, 12, 22, 11, 90]  # Lista de exemplo
print("\nLista antes de ordenar:", arr)
bubble_sort(arr)
print("Lista depois de ordenar:", arr)
