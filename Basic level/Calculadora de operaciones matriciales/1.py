def inicializarMatriz():
    dim = input()
    dim = dim.split(" ")
    dim = [int(x) for x in dim]

    matr = list()
    for i in range(0, dim[0]):
        row = input()
        row = row.split(" ")
        row = [int(x) for x in row]
        matr.append(row)
    
    return matr

def matrizACadena(A):
    rows = len(A)
    if (rows == 1):
        A[0] = [str(x) for x in A[0]]
        return " ".join(A[0])
    
    cols = len(A[0])
    
    for i in range(0, rows):
        A[i] = [str(x) for x in A[i]]
        A[i] = " ".join(A[i])
    A = "\n".join(A)
    return A      
    
def sonDeMismasDimensiones(A,B):
    mismasFilas = len(A) == len(B)
    mismasColumnas = len(A[0]) == len(B[0])
    if (mismasFilas and mismasColumnas):
        return True
    else:
        return False

def resta(A,B):
    if (sonDeMismasDimensiones(A,B)):
        resultado = list()
        rows = len(A)
        cols = len(A[0])
        for i in range(0, rows):
            resultado.append(list())
            for j in range(0, cols):
                resultado[i].append(A[i][j] - B[i][j])        
        
        return resultado
    else:
        return [None]
    
def suma(A,B):
    if (sonDeMismasDimensiones(A,B)):
        resultado = list()
        rows = len(A)
        cols = len(A[0])
        for i in range(0, rows):
            resultado.append(list())
            for j in range(0, cols):
                resultado[i].append(A[i][j] + B[i][j])        
        
        return resultado
    else:
        return [None]
    
def compatibleBajoMultiplicacion(A,B):
    return len(A[0]) == len(B)

def transpuesta(A):
    rows = len(A)
    cols = len(A[0])
    transpuesta = list()
    
    rowsTrans = cols
    colsTrans = rows
    
    for i in range(0, rowsTrans):
        transpuesta.append(list())
        for j in range(0, colsTrans):
            transpuesta[i].append(A[j][i])
    return transpuesta
    
#La entrada son dos vectores de n componentes.
#Se presupone que no hay errores ni chequeos
def multiplicarVector(A,B):
    vectorResultado = list()
    for index, i in enumerate(A):
            vectorResultado.append(A[index] * B[index])
    return vectorResultado

def multiplicacion(A,B):
    if (compatibleBajoMultiplicacion(A,B) == True):
        resultado = list()
        #Por comodidad, se transpone B
        bTrans = transpuesta(B)
        
        for i, renglon in enumerate(A):
            resultado.append(list())
            for j, columna in enumerate(bTrans):
                productoPunto = multiplicarVector(renglon, columna)
                val = 0
                for k in productoPunto:
                    val = val + k
                resultado[i].append(val)
        
        return resultado
    else:
        return [None]

def realizarOperaciones(operaciones, A, B):
    for i in operaciones:
        if (i == "SALIR"):
            break
        if (i == "RESTA"):
            tmp = (resta(A,B))
            if tmp != [None]:
                print(matrizACadena(tmp))
            else:
                print("X")
            continue
        if (i == "SUMA"):
            tmp = (suma(A,B))
            if tmp != [None]:
                print(matrizACadena(tmp))
            else:
                print("X")
            continue
        if (i == "MULTIPLICACION"):
            tmp = (multiplicacion(A,B))
            if tmp != [None]:
                print(matrizACadena(tmp))
            else:
                print("X")
            continue
        if (i == "TRASPUESTA"):
            print(matrizACadena(transpuesta(A)))
            continue

matrizA = inicializarMatriz()
matrizB = inicializarMatriz()
operaciones = input()
operaciones = operaciones.split(" ")
realizarOperaciones(operaciones, matrizA, matrizB)
    