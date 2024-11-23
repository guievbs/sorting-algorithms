import random
from typing import List

def bubble_sort(arr: List[int]) -> None:
    if arr is None: # Verifica se a lista é nula
        print("Entrada inválida: lista é nula.")
        raise TypeError("Entrada inválida: lista é nula.")

    if not arr: # Verifica se a lista está vazia
        print("A lista está vazia e não há nada para ordenar.")
        return None
    
    n = len(arr) # Tamanho da lista

    # Loop principal que percorre toda a lista
    for i in range(n - 1):
        # Um segundo loop que compara cada par de elementos
        for j in range(n - 1 - i):
            # Se o elemento atual é maior que o próximo, troca de posição
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]  # Troca de posição

def generate_random_list(size: int, max_value: int) -> List[int]:
    return [random.randint(0, max_value) for _ in range(size)]

def print_list(arr: List[int]) -> None:
    print("Lista:", arr)

def test_bubble_sort() -> None:
    print("Testando bubble sort...")
    # Caso de teste 1: Lista vazia
    empty_list = []
    print("Caso de teste 1: lista vazia")
    assert bubble_sort(empty_list) == None
    print_list(empty_list)

    # Caso de teste 2: Lista ordenada
    sorted_list = list(range(10))
    print("Caso de teste 2: lista ordenada")
    bubble_sort(sorted_list)
    assert sorted_list == sorted_list
    print_list(sorted_list)

    # Caso de teste 3: Lista desordenada
    unsorted_list = generate_random_list(100, 1000)
    print("Caso de teste 3: lista desordenada")
    original_unsorted = unsorted_list.copy()
    bubble_sort(unsorted_list)
    assert unsorted_list == sorted(original_unsorted)
    print_list(unsorted_list)

    # Caso de teste 4: Lista com elementos repetidos
    repeated_list = [random.randint(0, 50) for _ in range(50)]
    print("Caso de teste 4: lista com elementos repetidos")
    bubble_sort(repeated_list)
    assert all(repeated_list[i] <= repeated_list[i+1] for i in range(len(repeated_list)-1))
    print_list(repeated_list)

    # Caso de teste 5: Lista muito grande
    large_list = generate_random_list(10000, 100000)
    print("Caso de teste 5: lista muito grande")
    original_large = large_list.copy()
    bubble_sort(large_list)
    assert large_list == sorted(original_large)
    print_list(large_list[:5])  # Imprime apenas os primeiros elementos para evitar saída excessiva

    # Caso de teste 6: Lista nula ou inválida
    print("Caso de teste 6: lista nula ou inválida")
    try:
        bubble_sort(None)
        
        # Antigo ponto de parada do algoritmo,
        # pois não lançava exceção com entrada invalida
        assert False, "Deveria ter lançado uma exceção"
    except TypeError as e:
        print(f"Erro esperado: {e}")
    print("Todos os casos de teste foram executados com sucesso!")

if __name__ == "__main__":
    test_bubble_sort()
