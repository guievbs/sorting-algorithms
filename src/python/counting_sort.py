def counting_sort(arr):
    # Encontrar o maior valor no array para definir o tamanho do array auxiliar
    max_val = max(arr)

    # Criar um array auxiliar para armazenar as contagens, inicializado com 0
    count = [0] * (max_val + 1)

    # Contar a ocorrência de cada elemento no array original
    for num in arr:
        count[num] += 1

    # Modificar o array count para armazenar as posições corretas dos elementos
    for i in range(1, len(count)):
        count[i] += count[i - 1]

    # Criar um array para o resultado final ordenado
    output = [0] * len(arr)
    for num in reversed(
        arr
    ):  # Percorrer de trás para frente para garantir estabilidade
        output[count[num] - 1] = num
        count[num] -= 1

    # Copiar o array ordenado de volta para o array original
    for i in range(len(arr)):
        arr[i] = output[i]


# Exemplo de uso
arr = [4, 2, 2, 8, 3, 3, 1]
print("Array original:")
print(arr)

counting_sort(arr)

print("Array ordenado:")
print(arr)
