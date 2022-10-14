#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    //Se crea una variable para la cantidad de juguetes inicial.
    unsigned int noJuguetes = 0;
    cin >> noJuguetes;
    //Se crea un arreglo dinamico de enteros con capacidad para los juguetes.
    unsigned short int* diversion = new unsigned short int[noJuguetes];

    //Se le asigna una entrada a cada punto del arreglo.
    for (unsigned int i = 0; i < noJuguetes; i++)
        cin >> *(diversion + i);

    //Se ordena de mayor a menor el arreglo
    sort(diversion, diversion + (noJuguetes), greater<unsigned short int>());

    //Se crea una variable para el resultado
    int resultado = 0;
    //Se itera desde 0 hasta el penultimo juguete de la lista
    //ordenada de mayor a menor por diversion del juguete.
    //Y se suma al resultado.
    for (unsigned int i = 0; i < noJuguetes - 1; i++)
        resultado += diversion[i];
    
    //Se imprime el resultado.
    cout << resultado;

    //Se elimina el arreglo
    delete[] diversion;
    return 0;
}