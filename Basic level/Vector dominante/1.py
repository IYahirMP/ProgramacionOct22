#Tamaño del arreglo
n = int(input())

#Secuencia 1
arr1 = input()
arr1 = arr1.split(" ")
arr1 = [int(x) for x in arr1]

#Secuencia 2
arr2 = input()
arr2 = arr2.split(" ")
arr2 = [int(x) for x in arr2]

#Condición
arr1EsMayor = True

#Si se detecta que alguno de los números
#en la secuencia 1 es menor a su correspondiente
#de la secuencia 2, la condición es Falsa
#y se termina el procedimiento.
for i, elem in enumerate(arr1):
    if (arr1[i] <= arr2[i]):
        arr1EsMayor = False
        break

print(int(arr1EsMayor))
