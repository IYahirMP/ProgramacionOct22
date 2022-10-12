#!/usr/bin/python3

def _main() -> None:
    # TODO: fixme.
    entrada = leer_input()
    contadorMayusculas = 0
    for i in entrada:
        if contadorMayusculas == 10:
            break
        res = revisarLetras(i)
        if res != "E":
            print(res)
        elif res == "V" or i == "C" or i == "Y":
            contadorMayusculas = contadorMayusculas + 1

def leer_input():
    entrada = input()
    entrada = entrada.split(" ")
    return entrada

def revisarLetras(a):
    letras = {
            "A":"V",
            "E":"V",
            "I":"V",
            "O":"V",
            "U":"V",
            #Consonantes
            "B":"C",
            "C":"C",
            "D":"C",
            "F":"C",
            "G":"C",
            "H":"C",
            "J":"C",
            "K":"C",
            "L":"C",
            "M":"C",
            "N":"C",
            "P":"C",
            "Q":"C",
            "R":"C",
            "S":"C",
            "T":"C",
            "V":"C",
            "W":"C",
            "X":"C",
            "Z":"C",
            #Semivocal Y
            "Y":"S",
        }
    if a in letras:
        return letras.get(a)
    else:
        return "E"

if __name__ == "__main__":
  _main()