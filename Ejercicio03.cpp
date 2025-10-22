#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

int main() {
    string nombreArchivo;
    cout << "archivo -> ";
    cin >> nombreArchivo;

    ifstream archivo(nombreArchivo);

    try {
        if (!archivo.is_open()) {
            throw runtime_error("El archivono se puede abrir");
        }

        cout <<"archivo ->" << endl;
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }

        archivo.close();
    }
    catch (const runtime_error &e) {
        cout << "Error detectado " << e.what() << endl;
        cout << "Continua" << endl;
    }

    cout << "Termino" << endl;
    return 0;
}
