#!/usr/bin/python3

def _main() -> None:
    #Lee primera linea.
    entrada = input()
    #Separa las entradas de la primera linea
    hueso1 = entrada.split(" ")
    
    #Lee segunda linea
    entrada = input()
    #Separa las entradas de la segunda linea
    hueso2A = entrada.split(" ")

    #Se prefiere el hueso 2 SI Y SOLO SI es mejor que el hueso 1 tanto en tamaño como en olor.
    prefiereHueso2 = int(hueso1[0]) < int(hueso2A[0]) and int(hueso1[1]) < int(hueso2A[1])
    #Se prefiere el hueso 1 SI Y SOLO SI es mejor que el hueso 2 en ambas cosas.
    prefiereHueso1 = int(hueso1[0]) > int(hueso2A[0]) and int(hueso1[1]) > int(hueso2A[1])

    #Se elige el hueso.
    if prefiereHueso1:
        print ("Hueso 1")
    elif prefiereHueso2:
        print("Hueso 2")
    else:
        print("Perrito confundido :(")
if __name__ == '__main__':
  _main()