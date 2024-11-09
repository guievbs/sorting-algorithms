def merge_sort(array):
    """
    Implementa o algoritmo Merge Sort para ordenar uma lista.
    Complexidade de tempo: O(n log n)
    """
    # Caso base: se o array tiver tamanho 1 ou 0, já está ordenado
    if len(array) <= 1:
        return array

    # Divide o array ao meio
    meio = len(array) // 2
    esquerda = array[:meio]
    direita = array[meio:]

    # Chamada recursiva para ordenar as duas metades
    esquerda = merge_sort(esquerda)
    direita = merge_sort(direita)

    # Combina as duas metades ordenadas
    return merge(esquerda, direita)


def merge(esquerda, direita):
    """
    Combina duas listas ordenadas em uma única lista ordenada.
    """
    resultado = []
    i = j = 0

    # Compara e combina os elementos das duas listas
    while i < len(esquerda) and j < len(direita):
        if esquerda[i] <= direita[j]:
            resultado.append(esquerda[i])
            i += 1
        else:
            resultado.append(direita[j])
            j += 1

    # Adiciona os elementos restantes da lista esquerda, se houver
    while i < len(esquerda):
        resultado.append(esquerda[i])
        i += 1

    # Adiciona os elementos restantes da lista direita, se houver
    while j < len(direita):
        resultado.append(direita[j])
        j += 1

    return resultado


# Exemplo de uso
if __name__ == "__main__":
    # Lista desordenada para teste
    lista = [64, 342, 25, 991, 12, 661, 22, 11, 90, 1, 6, 44, 192, 813, 810, 7, 18]
    print("Lista original:", lista)

    # Aplica o Merge Sort
    lista_ordenada = merge_sort(lista)
    print("Lista ordenada:", lista_ordenada)
