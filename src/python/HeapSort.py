def heapify(arr, n, i):
    largest = i         # Inicializa o maior como raiz
    left = 2 * i + 1    # Filho à esquerda
    right = 2 * i + 2   # Filho à direita

    # Se o filho à esquerda for maior que a raiz
    if left < n and arr[left] > arr[largest]:
        largest = left

    # Se o filho à direita for maior que o maior até agora
    if right < n and arr[right] > arr[largest]:
        largest = right

    # Se o maior não for a raiz
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # Troca
        heapify(arr, n, largest)  # Aplica heapify na subárvore afetada

def heap_sort(arr):
    n = len(arr)

    # Construir o heap (reorganizar o array)
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # Extrair um elemento de cada vez do heap
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # Move a raiz para o final
        heapify(arr, i, 0)  # Chama heapify no heap reduzido

# Exemplo de uso
arr = [12, 11, 13, 5, 6, 7]
print("Array original:")
print(arr)

heap_sort(arr)

print("Array ordenado:")
print(arr)
