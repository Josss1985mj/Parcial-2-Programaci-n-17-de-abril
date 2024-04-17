#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Empleado {
private:
    string nombre;
    string apellido;
    int edad;
    double salario;

public:
    // Constructor
    Empleado(string nombre, string apellido, int edad, double salario) 
        : nombre(nombre), apellido(apellido), edad(edad), salario(salario) {}

    // Métodos para establecer y obtener los valores de los atributos
    void establecerNombre(string nombre) { this->nombre = nombre; }
    void establecerApellido(string apellido) { this->apellido = apellido; }
    void establecerEdad(int edad) { this->edad = edad; }
    void establecerSalario(double salario) { this->salario = salario; }

    string obtenerNombre() const { return nombre; }
    string obtenerApellido() const { return apellido; }
    int obtenerEdad() const { return edad; }
    double obtenerSalario() const { return salario; }
};

int main() {
    // Abrir el archivo para escribir
    ofstream archivo("empleados.txt");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    // Solicitar al usuario los datos de los empleados
    while (true) {
        string nombre, apellido;
        int edad;
        double salario;

        cout << "Ingrese el nombre del empleado (o 'fin' para terminar): ";
        cin >> nombre;
        if (nombre == "fin")
            break;

        cout << "Ingrese el apellido del empleado: ";
        cin >> apellido;

        cout << "Ingrese la edad del empleado: ";
        cin >> edad;

        cout << "Ingrese el salario del empleado: ";
        cin >> salario;

        // Crear un objeto Empleado con los datos proporcionados
        Empleado empleado(nombre, apellido, edad, salario);

        // Escribir los datos del empleado en el archivo
        archivo << empleado.obtenerNombre() << "," << empleado.obtenerApellido() << "," 
                << empleado.obtenerEdad() << "," << empleado.obtenerSalario() << endl;
    }

    // Cerrar el archivo
    archivo.close();

    // Mostrar mensaje de éxito
    cout << "Los datos de los empleados se han guardado correctamente en empleados.txt." << endl;

    return 0;
}
