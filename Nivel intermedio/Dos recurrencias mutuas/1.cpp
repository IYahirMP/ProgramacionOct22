#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> memF, memG;

int f(int);
int g(int);

int main(){
    int entrada = 0;
    cin >> entrada;

    cout << f(entrada);
}

int f(int n){
    if (memF.find(n) != memF.end())
        return memF[n];
    else if (n == 0){
        memF[n] = 1;
        return 1;
    }
    else if (n > 0){
        int tmp = f(n - 1) - g(n);
        memF[n] = tmp;
        return tmp;
    }
    return 0;
}

int g(int n){
    if (memG.find(n) != memG.end())
        return memG[n];
    else if (n <= 2){
        memG[n] = -2;
        return -2;
    }
    else if (n > 2){
        int tmp = f(n-2) - 1;
        memG[n] = tmp;
        return tmp;
    }
    return 0;
}