#include <iostream>
#include <string>
#include <stdexcept> 
using namespace std;

int main() {
    string entrada;
    int numero;
    bool valido = false; 

    while (!valido) {
        try {
            cout << "Ingrese un número: ";
            cin >> entrada;

            //Convierte el texto a entero
            numero = stoi(entrada);

            valido = true;
            cout << "El número ingresado es: " << numero << endl;
        }
        catch (invalid_argument &e) {
            cout << "Debe ingresar un número válido.\n";
        }
    }

    cout << "Se ingreso número correcto" << endl;
    return 0;
}