#include <iostream>
#include <stdexcept>  
using namespace std;

//Definición de la excepción 
class EdadInvalidaException : public exception {
public:
    const char* what() const noexcept override {
        return "Edad fuera de rango";
    }
};

int main() {
    int edad;

    try {
        cout << "Ingrese su edad: ";
        cin >> edad;

        //Valida el rango de edad
        if (edad < 0 || edad > 120) {
            throw EdadInvalidaException();  //Lanza la excepción 
        }

        cout << "Edad: " << edad << " años" << endl;
    }
    catch (const EdadInvalidaException& e) {
        cout << "Excepción capturada: " << e.what() << endl;
    }

    cout << "Fin del programa" << endl;
    return 0;
}