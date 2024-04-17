#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Empleado {
    string nombre;
    string apellido;
    int edad;
    double salario;
};

void buscarEmpleado(const string& nombreCompleto, ifstream& archivo) {
    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        Empleado empleado;
        getline(ss, empleado.nombre, ',');
        getline(ss, empleado.apellido, ',');
        ss >> empleado.edad;
        ss.ignore(); 
        ss >> empleado.salario;
        
        if (nombreCompleto == empleado.nombre + " " + empleado.apellido) {
            cout << "Información del empleado:" << endl;
            cout << "Nombre: " << empleado.nombre << endl;
            cout << "Apellido: " << empleado.apellido << endl;
            cout << "Edad: " << empleado.edad << endl;
            cout << "Salario: " << empleado.salario << endl;
            return;
        }
    }
    cout << "Empleado no encontrado en el archivo." << endl;
}

int main() {
    ifstream archivo("empleados.txt");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    string nombreCompleto;
    while (true) {
        cout << "Ingrese el nombre completo del empleado (o 'salir' para terminar): ";
        getline(cin, nombreCompleto);

        if (nombreCompleto == "salir") {
            cout << "Saliendo del programa..." << endl;
            break;
        }

        buscarEmpleado(nombreCompleto, archivo);
        archivo.clear(); 
        archivo.seekg(0); 
    }

    archivo.close();
    return 0;
}
