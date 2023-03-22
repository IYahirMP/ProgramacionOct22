#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

// En este problema ocurren varias cosas:
// 1. El asistente coloca un número sobre el escritorio del telefonista
// 2. El telefonista toma el número, lo mueve de su lugar, y toma la llamada.
// 3. Mientras el telefonista llama, por cada minuto que pasa, el asistente coloca un nuevo número.
// 4. El asistente anota el teléfono que acaba de pasarle a la telefonista en una agenda.
// 5. Cuando el telefonista termina de llamar, anota el tiempo que tomó y toma el número que sigue en la pila de números.
// Al finalizar, se tienen dos notas:
//      La del recepcionista, que contiene el orden en que se colocaron los papeles con numeros en la mesa
//      La del telefonista, que contiene el orden en que se tomaron las llamadas.

// Algoritmo:
// 1. Leer el número de llamadas.
// 2. Leer las duraciones de las llamadas a la cola DURACIONES
// 3. Según el número de llamadas:
//       3.1 Leer el número al que se llamó
//       3.2 Almacenar el número en la cola NUMEROS
// 4. Inicializar la pila LLAMADAS.
// 5. Por cada numero (en la cola DURACIONES):
//       5.1 Si se trata de la primera llamada:
//              5.1.1 Añado el siguiente número a la pila (se lo paso al telefonista) y lo elimino de la cola
//       5.2 El telefonista realiza una llamada (se elimina una llamada de la pila)
//       5.3 Reviso el tiempo que tarda el telefonista en llamar (Se elimina una duracion de la cola Duraciones)
//       5.4 Por cada minuto tardado:
//              5.4.1 Añadir el siguiente número (de NUMEROS) a la pila (LLAMADAS)
//              5.4.2 Eliminar el número de la cola NUMEROS.

int leerNoLlamadas();
queue<int> leerDuraciones(int noLlamadas);
queue<string> leerNumeros(int noLlamadas);
void anexarNumero(queue<string> &numero, stack<string> &llamadas);
void realizarLlamada(stack<string> &llamadas);
int revisarTiempo(queue<int> &duraciones);

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // TODO: fixme.
    int noLlamadas = leerNoLlamadas();
    // Cola DURACIONES, análoga a la lista que anota el telefonista
    // con las duraciones de sus llamadas.
    queue<int> duraciones = leerDuraciones(noLlamadas);
    // Cola NUMEROS, análoga a la forma en que llegan los números al asistente.
    queue<string> numeros = leerNumeros(noLlamadas);

    // Pila LLAMADAS, que representa la pila de notas con números en la mesa
    // del telefonista.
    stack<string> llamadas;

    // Por cada numero
    for (int i = 0; i < noLlamadas; i++)
    {
        // Si es la primera llamada
        if (i == 0)
            anexarNumero(numeros, llamadas);
        realizarLlamada(llamadas);
        int minutosTardados = revisarTiempo(duraciones);
        for (int i = 0; i < minutosTardados; i++)
            anexarNumero(numeros, llamadas);
    }

    return 0;
}

int leerNoLlamadas()
{
    int noLlamadas = 0;
    cin >> noLlamadas;
    // Esto es porque leerDuraciones usa getLine()
    // y cin deja un "\n" en el flujo de entrada.
    cin.ignore();
    return noLlamadas;
}

queue<int> leerDuraciones(int noLlamadas)
{
    queue<int> duraciones;
    string duracion;

    // Caso extremo: Solo 1 llamada
    if (noLlamadas == 1)
    {
        getline(cin, duracion, '\n');
        duraciones.push(stoi(duracion));
        return duraciones;
    }

    // Caso común: Más de una llamada
    for (int i = 0; i < noLlamadas - 1; i++)
    {
        getline(cin, duracion, ' ');
        duraciones.push(stoi(duracion));
    }
    getline(cin, duracion, '\n');
    duraciones.push(stoi(duracion));
    return duraciones;
}

queue<string> leerNumeros(int noLlamadas)
{
    string numero;
    queue<string> numeros;
    for (int i = 0; i < noLlamadas; i++)
    {
        cin >> numero;
        numeros.push(numero);
    }
    return numeros;
}

void anexarNumero(queue<string> &numero, stack<string> &llamadas)
{
    if (numero.empty() != true)
    {
        llamadas.push(numero.front());
        numero.pop();
    }
};

void realizarLlamada(stack<string> &llamadas)
{
    cout << llamadas.top() << endl;
    llamadas.pop();
}

int revisarTiempo(queue<int> &duraciones)
{
    if (duraciones.empty() != true)
    {
        int duracion = duraciones.front();
        duraciones.pop();
        return duracion;
    }
    return 0;
}