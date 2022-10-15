#Numero de elementos del arreglo
n = int(input())

#Secuencia de numeros
secuencia = input()
secuencia = secuencia.split(" ")
secuencia = [int(x) for x in secuencia]

#Factor por el cual se ha de comprobar divisibilidad
k = int(input())

#Si num mod k = 0, se imprime el numero.
#De otra forma, se imprime "X"
for i, item in enumerate(secuencia):
    if item % k == 0:
        print(item)
    if item % k != 0:
        print("X")
    if i < n:
        print(" ")
    