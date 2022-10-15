#include <iostream>
#include <cmath>

using namespace std;

int recurrencia(int n, int k){
  if (n == 0)
    return k;
  if (n > 0)
    return recurrencia(n - 1, k) + 2 * recurrencia(n - k, 1 - k);
  return 0;
}


int main() {
  int n = 0;
  cin >> n;
  cout << recurrencia(n, 0);
  return 0;
}