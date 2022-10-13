#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    //Almacena las 4 entradas en formato de texto.
    vector<string> entrada = {"","","",""};

    //Almacenan 2 entradas (como numero) cada uno.
    vector<int> hueso1, hueso2;

    //Se toma un número hasta el primer espacio
    getline(cin, entrada[0], ' ');
    //Se toma el primer número hasta el primer salto de línea
    getline(cin, entrada[1], '\n');
    //Otra vez, para la siguiente línea.
    getline(cin, entrada[2], ' ');
    getline(cin, entrada[3], '\n');
    
    //Se convierten e insertan los datos en los vectores de enteros.
    for (int i = 0; i < 2; i++){
        hueso1.push_back(stoi(entrada[i]));
        hueso2.push_back(stoi(entrada[i + 2]));
    }
    
    //Se prefiere un hueso SI Y SOLO SI es más grande y de mejor olor que el otro.
    //Si solo tiene mejor olor O solo tiene mejor tamaño, el perro se confunde.
    bool prefiereHueso2 = hueso1[0] < hueso2[0] && hueso1[1] < hueso2[1];
    bool prefiereHueso1 = hueso1[0] > hueso2[0] && hueso1[1] > hueso2[1];
    
    if (prefiereHueso1)
        cout << "Hueso 1";
    else if (prefiereHueso2)
        cout << "Hueso 2";
    else
        cout << "Perrito confundido :(";
    return 0;
}