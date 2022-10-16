#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, unsigned long int> recurrencia0;

unsigned long int recurrencia(int n, int k){
  string vals = "n" + to_string(n) + "k" + to_string(k);
  if (recurrencia0.find(vals) != recurrencia0.end())
    return recurrencia0[vals];
  if (n == 0)
    return k;
  if (n > 0){
    unsigned long int resultado = recurrencia(n - 1, k) + 2 * recurrencia(n - k, 1 - k);
    recurrencia0[vals] = resultado;
    return resultado;
  }
  return 0;
}


int main() {
  int n = 0;
  cin >> n;
  cout << recurrencia(n, 0) << endl;
  return 0;
}