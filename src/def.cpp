#include "header.h"
// Función para agregar estudiante (CREATE)
void agregarEstudiante() {
    Estudiante e;
    cout << "Nombre (sin espacios): ";
    cin >> e.nombre;
    cout << "Carnet: ";
    cin >> e.carnet;
    cout << "Edad: ";
    cin >> e.edad;

    ofstream archivo("estudiantes.txt", ios::app);
    if (archivo.is_open()) {
        archivo << e.nombre << " " << e.carnet << " " << e.edad << endl;
        archivo.close();
        cout << "Estudiante agregado correctamente.\n";
    } else {
        cout << "Error al abrir el archivo.\n";
    }
}

// Función para mostrar estudiantes (READ)
void mostrarEstudiantes() {
    ifstream archivo("estudiantes.txt");
    Estudiante e;

    if (archivo.is_open()) {
        cout << "\n--- Lista de Estudiantes ---\n";
        while (archivo >> e.nombre >> e.carnet >> e.edad) {
            cout << "Nombre: " << e.nombre 
                 << ", Carnet: " << e.carnet
                 << ", Edad: " << e.edad << endl;
        }
        archivo.close();
    } else {
        cout << "Error al abrir el archivo.\n";
    }
}

// -----------------------------

// 👇 TU TAREA: Completa esta función (UPDATE)
void modificarEstudiante() {
    // Debes permitir actualizar nombre, carnet y/o edad
    // de un estudiante identificado por su carnet.
    // Puedes usar o no manejo de archivos.
    // Si lo implementas con archivos correctamente, obtendrás **2 puntos extra**.
    ifstream archivo("estudiantes.txt"); //Se abre el archivo para tener un backup de los datos
    ofstream temp("temp.txt"); //Este archivo es el que se modificara
    Estudiante e; //Iniciamos la estructura estudiantes
    string buscado; //Variable para almacenar el carnet a bucar
    bool modificado = false;

    cout << "Ingrese carnet a modificar: ";
    cin >> buscado;

    if (archivo.is_open() && temp.is_open()) { //Se valida si los archivos se encuentran abiertos
        while (archivo >> e.nombre >> e.carnet >> e.edad) {//Bucle que recorre todos los datos
            if (e.carnet == buscado) {//Condicional para validar el carnet coincida con uno de los almacenado
                //Bloque que modifica el nombre, id y edad 
                cout<<"Ingrese el nuevo nombre "; cin>>e.nombre;
                cout<<"Ingrese el nuevo id "; cin>>e.carnet;
                cout<<"Ingrese la nueva edad "; cin>>e.edad;      
            }
             //Esta linea impide que se borren los registros anteriores y guarda los registros modificados
            temp<<e.nombre<<" "<<e.carnet<<" "<<e.edad<<endl;
        }
        //Se cierran los archivos para no tener problemas
        archivo.close();
        temp.close();
        remove("estudiantes.txt"); //Eliminamos el backup
        rename("temp.txt", "estudiantes.txt");//Renombramos nuestro archivo temporal para dejarlo como el principal

        if (modificado)
            cout << "Estudiante modificado correctamente.\n";//Mensaje que muestra que se ha modificado con exito
        else
            cout << "Carnet no encontrado.\n";//Mensaje que muestra que el carnet no ha sido encontrado
    } else {
        cout << "Error abriendo los archivos.\n";//Mensaje que muestra un error al abrir los archivos
    }
    
    
}
// -----------------------------

// Función para eliminar estudiante (DELETE)
void eliminarEstudiante() {
    ifstream archivo("estudiantes.txt");
    ofstream temp("temp.txt");
    Estudiante e;
    string buscado;
    bool eliminado = false;

    cout << "Ingrese carnet a eliminar: ";
    cin >> buscado;

    if (archivo.is_open() && temp.is_open()) {
        while (archivo >> e.nombre >> e.carnet >> e.edad) {
            if (e.carnet == buscado) {
                eliminado = true;               // No se copia: se “borra”
            } else {
                temp << e.nombre << " " << e.carnet << " " << e.edad << endl;
            }
        }
        archivo.close();
        temp.close();
        remove("estudiantes.txt");
        rename("temp.txt", "estudiantes.txt");

        if (eliminado)
            cout << "Estudiante eliminado correctamente.\n";
        else
            cout << "Carnet no encontrado.\n";
    } else {
        cout << "Error abriendo los archivos.\n";
    }
}
