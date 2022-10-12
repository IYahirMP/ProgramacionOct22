#include <iostream>
#include <string>


int main() {
  int pesoSandia = 0;
  std::cin >> pesoSandia;
  int arr1[49];
  for (int i = 0; i < 49; i++)
    arr1[i] = (i + 1) * 2;
    bool valorEncontrado = 0;
  
  for(int i = 0; i < 49; i++){
    for (int j = 0; j < 49; j++){
      if (arr1[i] + arr1[j] == pesoSandia){
        std::cout << "SI";
        valorEncontrado = 1;
        break;
      }
    }
    if (valorEncontrado == 1){
      break;
    }
  }

  if (valorEncontrado == 0)
    std::cout << "NO";
}