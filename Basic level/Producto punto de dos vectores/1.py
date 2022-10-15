#Numero de componentes de ambos vectores
n = int(input())

#Vector 1
vec1 = input()
vec1 = vec1.split(" ")
vec1 = [int(x) for x in vec1]

#Vector 2
vec2 = input()
vec2 = vec2.split(" ")
vec2 = [int(x) for x in vec2]

#Se inicializa un acumulador
productoPunto = 0

#Se suman los productos de las componentes de los vectores al acumulador
for i, componente in enumerate(vec1):
    productoPunto = productoPunto + vec1[i]*vec2[i]

print(productoPunto)