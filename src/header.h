#include <iostream>
#include <fstream>
using namespace std;

struct Estudiante {
    string nombre;
    string carnet;
    int edad;
};

void agregarEstudiante();
void mostrarEstudiantes();
void modificarEstudiante();
void eliminarEstudiante();
