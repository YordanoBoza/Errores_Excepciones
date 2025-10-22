#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <limits>
using namespace std;

// Excepcion personalizada
class AlumnoNoEncontradoException : public exception {
    string mensaje;
public:
    AlumnoNoEncontradoException(const string& nombre)
        : mensaje("Error: Alumno '" + nombre + "' no encontrado.") {}
    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

// Funcion para validar la entrada de edad
int leerEdad() {
    int edad;
    while (true) {
        cout << "Ingrese la edad del alumno: ";
        if (cin >> edad && edad > 0)
            return edad;
        cout << "Error: edad invalida. Intente nuevamente.\n";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
}

// Funcion para registrar un alumno en el archivo
void registrarAlumno() {
    ofstream archivo("alumnos.txt", ios::app);
    if (!archivo) {
        throw runtime_error("No se pudo abrir el archivo para escritura.");
    }

    string nombre;
    cout << "Ingrese el nombre del alumno: ";
    cin.ignore();
    getline(cin, nombre);

    int edad = leerEdad();

    archivo << nombre << "," << edad << "\n";
    archivo.close();

    cout << "Alumno registrado correctamente.\n";
}

// Funcion para mostrar todos los alumnos
void mostrarAlumnos() {
    ifstream archivo("alumnos.txt");
    if (!archivo) {
        throw runtime_error("Archivo 'alumnos.txt' no encontrado o corrupto.");
    }

    string linea;
    cout << "\nLista de Alumnos\n";
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }
    archivo.close();
}

// Función para buscar un alumno por nombre
void buscarAlumno() {
    ifstream archivo("alumnos.txt");
    if (!archivo) {
        throw runtime_error("No se puede abrir el archivo para lectura.");
    }

    string nombreBuscado;
    cout << "Ingrese el nombre del alumno a buscar: ";
    cin.ignore();
    getline(cin, nombreBuscado);

    string nombre;
    int edad;
    bool encontrado = false;

    while (getline(archivo, nombre, ',') && archivo >> edad) {
        archivo.ignore(); 
        if (nombre == nombreBuscado) {
            cout << "Alumno encontrado: " << nombre << ", Edad: " << edad << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado)
        throw AlumnoNoEncontradoException(nombreBuscado);

    archivo.close();
}

int main() {
    int opcion;

    do {
        cout << "\nSistema de Registro de Alumnos\n";
        cout << "1. Registrar alumno\n";
        cout << "2. Mostrar alumnos\n";
        cout << "3. Buscar alumno\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";

        if (!(cin >> opcion)) {
            cout << "Error: opcion invalida. Intente nuevamente.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        try {
            switch (opcion) {
                case 1: registrarAlumno(); break;
                case 2: mostrarAlumnos(); break;
                case 3: buscarAlumno(); break;
                case 4: cout << "Saliendo del sistema...\n"; break;
                default: cout << "Opcion invalida.\n"; break;
            }
        }
        catch (const AlumnoNoEncontradoException& e) {
            cerr << e.what() << endl;
        }
        catch (const runtime_error& e) {
            cerr << "Error de archivo: " << e.what() << endl;
        }
        catch (const exception& e) {
            cerr << "Error inesperado: " << e.what() << endl;
        }

    } while (opcion != 4);

    return 0;
}
