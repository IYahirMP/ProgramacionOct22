from math import ceil

#Tamaño del tache
n = int(input())

#Por cada fila, por cada espacio:
for fila in range(0, n):
    for espacio in range(0, n):
        #Si está en el medio, imprime # y sale del bucle
        if (espacio == ceil(n/2) - 1 and fila == ceil(n/2) - 1):
            print("@", end="")
            break
        #Si el numero del espacio de escritura coincide con la fila
        #Se imprime @. Si se pasa de la mitad, sale del bucleo.
        #Si no pasa de la mitad, continua el bucle.
        #Imprime la diagonal principal
        elif (espacio == fila):
            print("@", end="")
            if (espacio > ceil(n/2) - 1):
                break
            else:
                continue
        #Actua de forma similar al anterior,
        #pero en el sentido contrario.
        #Imprime la diagonal secundaria
        elif (espacio == n - fila - 1):
            print("@", end="")
            if (espacio < ceil(n/2) - 1):
                continue
            else:
                break
        #Si no se imprime una @, se imprime un espacio.
        else:
            print(" ", end="")
            continue
    #Si se llegó al final de la figura, se sale del bucle
    if (fila == n - 1):
        break
    #De otra forma, se cambia de linea.
    print("")