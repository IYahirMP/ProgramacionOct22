#include <iostream>
#include <queue>
#include <string>

using namespace std;

int detectarOperacion(string &operacion);
void procesarAlumno(string &operacion, queue<string> &cola);
void procesarTrabajador(string &operacion, queue<string> &cola);
void atender(queue<string> &alumnos, queue<string> &trabajadores);

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    // TODO: fixme.
    // Inicializo una cola donde se almacenan las operaciones a hacer en orden
    queue<string> operaciones;

    // Esto es para fines de depuracion
    int noOperaciones = -1;

    // Entrada del numero de operaciones a realizar.
    cin >> noOperaciones;

    // Con fines de depuracion
    if (noOperaciones == -1)
    {
        cout << "Error en la entrada numerica";
    }

    // El cin deja un \n en el flujo de entrada. Se resuelve con esto.
    cin.ignore();

    // Segun el numero de operaciones:
    //       1. Leer una operacion
    //       2. Insertar la operacion en la cola de operaciones
    string operacion;
    for (int i = 0; i < noOperaciones; i++)
    {
        getline(cin, operacion);
        operaciones.push(operacion);
    }

    // Se declara una cola para alumnos y trabajadores que van llegando.
    queue<string> alumnos;
    queue<string> trabajadores;

    // Se obtiene el tamaño de la cola de operaciones.
    int ops = operaciones.size();

    // Segun el tamaño de la cola de operaciones:
    //       1. Leer el frente de la cola
    //       2. Eliminar el frente de la cola.
    //       3. Interpretar el tipo de operacion a que se refiere
    //       4. Según el tipo de operación:
    //           a) Marcar error (Con fines de depuracion)
    //           b) Ingresar un alumno a la cola
    //           c) Ingresar un trabajador a la cola
    //           d) Atender segun prioridad
    for (int i = 0; i < ops; i++)
    {
        operacion = operaciones.front();
        operaciones.pop();
        int op = detectarOperacion(operacion);
        switch (op)
        {
        case -1:
            cout << "error";
            break;
        case 0:
            procesarAlumno(operacion, alumnos);
            break;
        case 1:
            procesarTrabajador(operacion, trabajadores);
            break;
        case 2:
            atender(alumnos, trabajadores);
        }
    }

    return 0;
}

int detectarOperacion(string &operacion)
{
    // Se revisa si la operacion se trata de un alumno:
    string sub = "ALUMNO";
    size_t pos = operacion.find(sub);

    if (pos != string::npos)
    {
        return 0;
    }

    // No se trata de un alumno.
    // Se revisa si la operacion se trata de un trabajador
    sub = "TRABAJADOR";
    pos = operacion.find(sub);
    if (pos != string::npos)
    {
        return 1;
    }

    // No se trata de un trabajador.
    // Se revisa si la operacion se trata de atender.
    sub = "ATIENDE";
    if (sub.compare(operacion) == 0)
    {
        return 2;
    }

    // Fallaron las demas pruebas, suelta un valor para error.
    return -1;
}

void procesarAlumno(string &operacion, queue<string> &cola)
{
    // Se introduce en la cola de alumnos el nombre
    // encontrado en la operacion.
    cola.push(operacion.substr(13, operacion.size() - 13));
}

void procesarTrabajador(string &operacion, queue<string> &cola)
{
    // Se introduce en la cola de trabajadores el nombre
    // encontrado en la operacion.
    cola.push(operacion.substr(17, operacion.size() - 17));
}

void atender(queue<string> &alumnos, queue<string> &trabajadores)
{
    // Si aun hay trabajadores en la cola, se les da prioridad al atender
    // Luego se eliminan de la cola.
    if (trabajadores.size() != 0)
    {
        cout << trabajadores.front() << endl;
        trabajadores.pop();
    }
    // No habiendo trabajadores, se atiende a los alumnos y se eliminan de la cola.
    else if (alumnos.size() != 0)
    {
        cout << alumnos.front() << endl;
        alumnos.pop();
    }
}