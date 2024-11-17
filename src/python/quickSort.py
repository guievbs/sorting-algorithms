def partition(arr: list[int], low: int, high: int) -> int:
    """
    Particiona o array e retorna o índice do ponto de divisão.

    Parameters:
        arr (list[int]): Array de inteiros a ser particionado
        low (int): Índice inicial da sublista
        high (int): Índice final da sublista

    Returns:
        int: Índice do ponto de divisão
    """
    pivot = arr[high]

    point = low - 1

    for i in range(low, high):
        if arr[i] < pivot:
            point += 1
            arr[i], arr[point] = arr[point], arr[i]

    arr[point + 1], arr[high] = arr[high], arr[point + 1]
    return point + 1

def quick_sort(arr: list, low: int, high: int) -> None:
    """
    Ordena o array utilizando o algoritmo Quick Sort.

    Parameters:
        arr (list): Array de inteiros a ser ordenado
        low (int): Índice inicial da sublista
        high (int): Índice final da sublista
    """
    if low < high:
        point = partition(arr, low, high)  # Ponto de divisão

        quick_sort(arr, low, point - 1)  # Ordena a parte esquerda do ponto de divisão
        quick_sort(arr, point + 1, high)  # Ordena a parte direita do ponto de divisão

# Faz com que o algoritmo seja executado diretamente
if __name__ == "__main__":
    arr = [12, 11, 13, 5, 6]
    
    print("Lista antes de ordenar:", arr)
    
    quick_sort(arr, 0, len(arr) - 1)
    
    print("Lista ordenada:", arr)
