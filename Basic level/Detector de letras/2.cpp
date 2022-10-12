#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

unordered_map<char, char> hashTable;

char identificarLetra(char input){
  if (hashTable.find(input) != hashTable.end()){
    return hashTable[input];
  }
  else{
    return 'E';
  }

}

vector<char> separarLetras(std::string input){
  vector<char> letras;
  for (char i : input){
    if ( i != ' '){
      letras.push_back(i);
    }
  }
  return letras;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  // TODO: fixme.
  hashTable['A'] = 'V';
  hashTable['E'] = 'V';
  hashTable['I'] = 'V';
  hashTable['O'] = 'V';
  hashTable['U'] = 'V';
  hashTable['B'] = 'C';
  hashTable['C'] = 'C';
  hashTable['D'] = 'C';
  hashTable['F'] = 'C';
  hashTable['G'] = 'C';
  hashTable['H'] = 'C';
  hashTable['J'] = 'C';
  hashTable['K'] = 'C';
  hashTable['L'] = 'C';
  hashTable['M'] = 'C';
  hashTable['N'] = 'C';
  hashTable['P'] = 'C';
  hashTable['Q'] = 'C';
  hashTable['R'] = 'C';
  hashTable['S'] = 'C';
  hashTable['T'] = 'C';
  hashTable['V'] = 'C';
  hashTable['W'] = 'C';
  hashTable['X'] = 'C';
  hashTable['Y'] = 'S';
  hashTable['Z'] = 'C';
  
  string input;
  getline(cin, input);

  vector<char> caracteres = separarLetras(input);
  int letrasContadas = 0;

  for (char i : caracteres){
    if (identificarLetra(i) == 'V'){
      cout << "V ";
      letrasContadas++;
    }
    if (identificarLetra(i) == 'S'){
      cout << "S ";
      letrasContadas++;
    }
    if (identificarLetra(i) == 'C'){
      cout << "C ";
      letrasContadas++;
    }
  }
  return 0;
}