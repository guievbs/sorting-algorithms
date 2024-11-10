def partition(arr: list, low: int, high: int) -> int:
    pivot = arr[high]  # Pivo
    
    point = low - 1  # Ponto de divisão
    
    # Loop para percorrer toda a lista
    for i in range(low, high):
        if arr[i] < pivot:
            point += 1
            
            # Troca os elementos
            arr[i], arr[point] = arr[point], arr[i]

    # Troca o pivo com o ponto de divisão
    arr[point + 1], arr[high] = arr[high], arr[point + 1]
    return point + 1

def quick_sort(arr: list, low: int, high: int) -> None:
    if low < high:
        point = partition(arr, low, high)  # Ponto de divisão
        
        quick_sort(arr, low, point - 1)
        quick_sort(arr, point + 1, high)

# Faz com que o algoritmo seja executado diretamente
if __name__ == "__main__":
    arr = [12, 11, 13, 5, 6]
    
    print("Lista antes de ordenar:", arr)
    
    quick_sort(arr, 0, len(arr) - 1)
    
    print("Lista ordenada:", arr)
