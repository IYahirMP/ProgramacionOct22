#Numero de enteros
N = int(input())

#Conjunto de enteros
n = input()
n = n.split(" ")
n = [int(x) for x in n]

#Par/Impar
p = int(input())

#Para imprimir numeros pares
if (p == 0):
  for i, elem in enumerate(n):
    if elem % 2 == 0:
      print(elem)
    if i < N:
      print(" ")
    else:
      break
elif (p == 1): #Para imprimir numeros pares
  for i, elem in enumerate(n):
    if elem % 2 != 0:
      print( elem )
    if i < N:
      print(" ")
    else:
      break