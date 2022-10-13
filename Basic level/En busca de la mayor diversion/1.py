noJuguetes = int(input())
diversion = list()
for i in range(0, noJuguetes):
    diversion.append(input())
diversion = [int(x) for x in diversion]

resultados = list()
for i, juguete in enumerate(diversion):
    resultados.append(0)
    for j, peso in enumerate(diversion):
        if (j != i):
            resultados[i] += peso
            
resultados.sort(reverse = True)
print(resultados[0])