#include <iostream>
using namespace std;


int main() {
  //Lineas que vienen por defecto*********
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  //**************************************

  //Se define la variable que almacena la entrada.
  int tamanio = 0;
  //Se ingresa el valor por el flujo de caracteres.
  cin >> tamanio;

  //Inicializo un contador.
  //Este contador sirve para controlar la cantidad de numerales
  //en cada paso de la escalera.
  int contador = 0;

  //Repito tantas veces como indique la entrada
  for(int i = 0; i < tamanio; i++){
    //El contador inicia en 0,
    //Agrego 1 para imprimir el primer escalón.
    contador++;

    //Por cada unidad en la Var. contador, se imprime un numeral.
    for(int j = 0; j < contador; j++){
      cout << "#";
    }

    //Se imprime un salto de línea para comenzar el siguiente escalón
    cout << endl;
  }
  
  return 0;
}