#!/usr/bin/python3

def _main() -> None:
    #Se introduce la cadena
    a = input()
    #Se separan las entradas
    inputs = a.split(" ")

    #Se crean dos variables por comodidad
    a = int(inputs[0])
    b = int(inputs[1])

    #Desarrollo de las condiciones
    if (a+b == 5):
        b = b + 3
        print (2*a + b)
    else:
        a = a -1
        if (7*a + b) % 2 == 0:
            print(a - b)
        else:
            print(a*b)

if __name__ == '__main__':
  _main()