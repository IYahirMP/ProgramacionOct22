#Se establece la precision
from decimal import *
getcontext().prec = 7

#Se introducen X, Y y Z.
xyz = input()
xyz = xyz.split(" ")
xyz = [Decimal(x) for x in xyz]

#Se acomodan en variables individuales por comodidad.
x = xyz[0]
y = xyz[1]
z = xyz[2]
del xyz

#Se definen expresiones para el numerador
factor1Numerador = (2*x + y)/z
factor2Numerador = (pow(y,3) - z)
numerador = factor1Numerador * factor2Numerador

#Se definen expresiones para el denominador
denominador1 = (x + 2*y + 3*z)/(z - 2*y -3*x)
denominador2 = pow(x,2)
denominador3 = pow(z,2)
denominador = denominador1 + denominador2 + denominador3

print(numerador / denominador, end="")