#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main(){
    //Se crea una variable para la cantidad de juguetes inicial.
    int noJuguetes;
    //Se crea un vector para los pesos.
    vector<char> diversion;

    //Se ingresa el numero de juguetes iniciales.
    cin >> noJuguetes;

    //Se coloca un valor de diversion (peso) a cada juguete.
    int tmp;
    for (int i = 0; i < noJuguetes; i++){
        cin >> tmp;
        diversion.push_back(tmp);
    }

    //Se ordena el arreglo de forma descendente
    sort(diversion.begin(), diversion.end(), greater<int>());

    //Se inicializa un acumulador
    int resultado = 0;

    //Se itera sobre el vector, acumulando en el resultado
    //Los primeros diversion.size() - 1 valores de peso.
    for (int i = 0; i < diversion.size() - 1; i++)
        resultado += diversion[i];
    
    //Se imprime el resultado
    cout << resultado;
}