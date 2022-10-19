#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

unordered_map<int, long int> memF;

long int f(int n){
    if (memF.find(n) != memF.end())
        return memF[n];
    
    int ab = abs(n);

    if (ab == 25){
        memF[n] = 1;
        return 1;
    }
    if (ab != 25 && n < 0){
        long int tmp = f(n-1) + f(1-n);
        memF[n] = tmp;
        return tmp;
    }
    if (ab != 25 && n == 0){
        long int tmp = f(-1) + f(1);
        memF[n] = tmp;
        return tmp;
    }
    if (ab != 25 && n > 0){
        long int tmp = f(n+1) + f(n * -1);
        memF[n] = tmp;
        return tmp;
    }

    return 0;
}

int main(){
    int entrada = 0;
    cin >> entrada;

    cout << f(entrada);
}