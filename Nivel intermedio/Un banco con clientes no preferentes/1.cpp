#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

/**
 * En el banco hay dos filas:
 *  La fila 1 atiende a los clientes con una política FIFO (First In, First Out), propia de una cola
 *  La fila 2 atiende a los clientes con una política LIFO (Last In, First Out), propia de una pila
 * Se tiene una bitácora donde se registra cuándo entran los clientes y en qué fila, y cuándo se atiende.
 * E 1 juan significa que entra Juan a la fila 1.
 * A 1 significa que se atiende en la fila 1.
 *
 * El algoritmo que usaré es el siguiente:
 *
 * Algoritmo principal:
 * 1. n <- número de entradas de la bitácora
 * 2. Por cada entrada en la bitácora:
 *      2.1 Leer una operación
 *      2.2 Determinar el tipo de operación
 *      2.3 Si se refiere a encolar un cliente:
 *          2.3.1 agregar el cliente a la cola correcta.
 *          2.3.2 continuar el bucle
 *      2.4 Si se refiere a atender una fila:
 *          2.4.1 Atender la fila correcta
 *          2.4.2 continuar el bucle
 *
 * Agregar el cliente a la cola:
 * 1. Identificar la fila
 * 2. Identificar el cliente
 * 3. Si la fila es la fila 1:
 *      3.1 Agregar el nombre del cliente a la fila 1
 * 4. Si la fila es la fila 2:
 *      4.2 Agregar el nombre del cliente a la fila 2
 *
 * Atender una fila:
 * 1. Identificar la fila.
 * 2. Si es la fila 1:
 *      2.1 Imprimir el nombre del primer cliente ingresado en la fila
 *      2.2 Eliminar al primer cliente ingresado en la fila
 *      2.3 Ir al paso 4.
 * 3. Si es la fila 2:
 *      3.1 Imprimir el nombre del último cliente ingresado en la fila
 *      3.2 Eliminar al último cliente ingresado de la fila
 */

int leerNoEntradas();
string leerOperacion();
int determinarTipoOperacion(string &);
void encolarCliente(queue<string> &fila1, stack<string> &fila2, string &operacion);
void atenderFila(queue<string> &fila1, stack<string> &fila2, string &operacion);

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    // TODO: fixme.

    int n = leerNoEntradas();

    string operacion = "";
    int tipoOperacion = -1; // El -1 es un valor de control para identificar errores
    queue<string> fila1;    // La fila 1 se representa con una cola por su política FIFO
    stack<string> fila2;    // La fila 2 se representa con una pila por su política LIFO
    for (int i = 0; i < n; i++)
    {
        operacion = leerOperacion();
        // determinarTipoOperacion retorna 0 si es para encolar, 1 si es para atender.
        tipoOperacion = determinarTipoOperacion(operacion);
        if (tipoOperacion == 0)
            encolarCliente(fila1, fila2, operacion);
        if (tipoOperacion == 1)
            atenderFila(fila1, fila2, operacion);
    }

    return 0;
}

int leerNoEntradas()
{
    int n = 0;
    cin >> n;
    cin.ignore(); // el .ignore es para eliminar el \n sobrante del cin.
    return n;
}

string leerOperacion()
{
    string op = "";
    getline(cin, op);
    return op;
}

int determinarTipoOperacion(string &operacion)
{
    char op = operacion[0];
    if (op == 'E')
        return 0;
    if (op == 'A')
        return 1;
    else
        return -1; // Valor de control para identificar errores
}

void encolarCliente(queue<string> &fila1, stack<string> &fila2, string &operacion)
{
    char fila = operacion[2];
    string cliente = operacion.substr(4, operacion.size() - 4);
    if (fila == '1')
    {
        fila1.push(cliente);
        return;
    }
    if (fila == '2')
    {
        fila2.push(cliente);
        return;
    }
    // Esto solo ocurre si la operación no entra en alguna clasificación
    cerr << "Error al encolar un cliente";
}

void atenderFila(queue<string> &fila1, stack<string> &fila2, string &operacion)
{
    char fila = operacion[2];
    if (fila == '1')
    {
        cout << fila1.front() << endl;
        fila1.pop();
        return;
    }
    if (fila == '2')
    {
        cout << fila2.top() << endl;
        fila2.pop();
        return;
    }
    // Esto solo ocurre si la operación no entra en alguna clasificación
    cerr << "Error al atender fila";
}