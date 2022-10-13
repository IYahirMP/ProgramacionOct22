#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int noJuguetes;
    vector<unsigned short int> diversion;

    cin >> noJuguetes;
    for (int i = 0; i < noJuguetes; i++){
        int tmp;
        cin >> tmp;
        diversion.push_back(tmp);
    }

    sort(diversion.begin(), diversion.end(), greater<int>());
    noJuguetes = 0;
    for (int i = 0; i < diversion.size() - 1; i++)
        noJuguetes += diversion[i];
    cout << noJuguetes;
}