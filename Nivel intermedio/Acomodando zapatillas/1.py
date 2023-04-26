# 1. Introducir el número N de zapatillas
# 2. Introducir los N identificadores de zapatillas en una línea
# 3. Ordenar los N identificadores de zapatilas
# 4. Por cada zapatilla en el arreglo de identificadores:
#   4.1 Si es la primera zapatilla:
#       4.1.1 Agregar la zapatilla a la lista de zapatillas encontradas.
#       4.1.2 Inicializar una cuenta para esta zapatilla
#       4.1.3 Continuar el bucle
#   4.2 Si la zapatilla es igual a la última encontrada:
#       4.2.1 Sumar 1 a la cantidad de zapatillas encontradas para esa zapatilla.
#       4.2.2 Continuar el bucle
#   4.3 Si la zapatilla es diferente a la última encontrada:
#       4.3.1 Agregar la zapatilla a la lista de zapatillas encontradas.
#       4.3.2 Inicializar una cuenta para esta zapatilla.
# 5. Por cada contador de zapatillas encontradas:
#   5.1 Si el contador es impar:
#       5.1.1 Restar uno al contador de zapatillas. En consecuencia, este ahora es par.
#       5.1.2 Agregar el identificador de la zapatilla a la lista de zapatillas a tirar.
#       5.1.3 Continuar el bucle
#   5.2 Si el contador es par:
#       5.2.1 Continuar el bucle
# 6. Imprimir los identificadores de las zapatillas a tirar
# 7. Contar las zapatillas que se pueden tirar e imprimir el resultado.
# 8. COntar las zapatillas que Ayla no va a tirar e imprimir el resultado.

def obtenerZapatillas():
    N = input()
    zapatillas = input().split(" ")
    zapatillas = [int(x) for x in zapatillas]
    zapatillas.sort()
    return zapatillas


def contarZapatillas():
    zapatillasEncontradas = list()
    cuentaZapatillas = list()
    for i, zapatilla in enumerate(zapatillas):
        if i == 0:
            zapatillasEncontradas.append(zapatilla)
            cuentaZapatillas.append(1)
            continue
        if (zapatilla == zapatillasEncontradas[-1]):
            cuentaZapatillas[-1] += 1
            continue
        if (zapatilla != zapatillasEncontradas[-1]):
            zapatillasEncontradas.append(zapatilla)
            cuentaZapatillas.append(1)
    return [zapatillasEncontradas, cuentaZapatillas]


def tirarZapatillas(zapatillasEncontradas, cuentaZapatillas):
    zapatillasATirar = list()
    for i, cuentaZapatilla in enumerate(cuentaZapatillas):
        if cuentaZapatilla % 2 == 1:
            cuentaZapatillas[i] -= 1
            zapatillasATirar.append(zapatillasEncontradas[i])
            continue
        # Se puede prescindir de estas dos lineas sin problemas
        if cuentaZapatilla % 2 == 0:
            continue
    return zapatillasATirar


def imprimirZapatillasATirar(zapatillasATirar):
    if len(zapatillasATirar) != 0:
        zapatillasATirar = [str(x) for x in zapatillasATirar]
        tmp = " ".join(zapatillasATirar)
        print(tmp)
    else:
        print(":D")


def imprimirZapatillasAConservar(cuentaZapatillas):
    sumaZapatillas = 0
    for cuenta in cuentaZapatillas:
        sumaZapatillas += cuenta
    print(sumaZapatillas)


zapatillas = obtenerZapatillas()
zapatillasEncontradas, cuentaZapatillas = contarZapatillas()
zapatillasATirar = tirarZapatillas(zapatillasEncontradas, cuentaZapatillas)

imprimirZapatillasATirar(zapatillasATirar)
print(len(zapatillasATirar))
imprimirZapatillasAConservar(cuentaZapatillas)
