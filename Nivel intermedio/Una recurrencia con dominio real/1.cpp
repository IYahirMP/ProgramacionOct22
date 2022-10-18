#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

unordered_map<float, unsigned long int> memoria;

bool esEntero(float x){
    return x == (int)x;
}

unsigned long int recurrencia(float x){
    if (memoria.find(x) != memoria.end())
        return memoria[x];
    if (x <= 2){
        memoria[x] = 1;
        return memoria[x];
    }
    if (x > 2 && !esEntero(x)){
        unsigned long int tmp = recurrencia(floor(x)) + 2;
        memoria[x] = tmp;
        return memoria[x];
    } 
    if (x > 2 && esEntero(x) && (int)x % 2 == 0){
        unsigned long int tmp = recurrencia(x - 1) + recurrencia(x - 2);
        memoria[x] = tmp;
        return memoria[x];
    }
    if (x > 2 && esEntero(x) && (int)x % 2 != 0){
        unsigned long int tmp = recurrencia(x - 1) + recurrencia(x/2.0) + 1;
        memoria[x] = tmp;
        return memoria[x];
    }

    return 0;
}

int main(){
    float entrada;
    cin >> entrada;

    cout << recurrencia(entrada);
}