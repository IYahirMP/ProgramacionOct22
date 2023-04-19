#!/usr/bin/python3

# Esta función cubre la toma de entradas y el ordenamiento
def obtener_entradas():
    n = input()
    lista_numeros = input().split(" ")
    lista_numeros.sort()
    return lista_numeros


# Para determinar la cantidad de ocurrencias por número:

# Por cada número en la lista de números:
#   Si la lista está vacía:
#       añadirlo a nums
#       inicializar la cuenta correspondiente en lista_cuentas en 1
#   Si el número es igual al último registrado:
#       Sumar 1 a la última cuenta registrada
#   Si el número es diferente al último registrado:
#       Añadir el número a nums e inicializar la cuenta correspondiente en 1
def contarOcurrencias(lista_numeros):
    nums = list()
    lista_cuentas = list()
    for i, num in enumerate(lista_numeros):
        if len(nums) < 1:
            nums.append(num)
            lista_cuentas.append(1)
        if num == nums[-1]:
            lista_cuentas[-1] += 1
        if num != nums[-1]:
            nums.append(num)
            lista_cuentas.append(1)
    return [nums, lista_cuentas]


# Para obtener el máximo:
#   Por cada cuenta en lista_cuentas:
#     Si es el primer número:
#         Guardarlo como máximo
#     Si el número actual es mayor al máximo:
#         Conservarlo como máximo guardando el índice
#     Si el número actual es menor al máximo:
#         Descartarlo y continuar el bucle
def determinarMaximo(lista_cuentas):
    cuentaMax = -1
    for i, cuenta in enumerate(lista_cuentas):
        # Quitar este bloque no afecta
        # if i == 1:
        #  cuentaMax = i
        if cuenta > cuentaMax:
            cuentaMax = i
        # Quitar este bloque no afecta
        # if cuenta < cuentaMax:
        #  continue
    return cuentaMax


def _main() -> None:
    # Procedimiento:
    # 1. Tomar el número de entradas
    # 2. Tomar la lista de entradas
    # 3. Ordenar las entradas (de forma ascendente o descendente)
    #   Para que todos los números idénticos sean adyacentes en la lista
    # 4. Contar la cantidad de ocurrencias por número
    # 5. Determinar el máximo de la cantidad de ocurrencias
    # 6. Imprimir el resultado

    entradas = obtener_entradas()
    numeros, cuentas = contarOcurrencias(entradas)
    maximo = determinarMaximo(cuentas)
    print(numeros[maximo])


if __name__ == '__main__':
    _main()
