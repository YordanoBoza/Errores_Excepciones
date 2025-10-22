#include <iostream>
#include <stdexcept> // para runtime_error
using namespace std;

int main() {
    double num1, num2;

    cout << "Ingrese el primer numero: ";
    cin >> num1;
    cout << "Ingrese el segundo numero: ";
    cin >> num2;

    try {
        if (cin.fail()) {
            throw invalid_argument("Error: Entrada invalida, se esperaba un numero.");
        }

        if (num2 == 0) {
            throw runtime_error("Error: No se puede dividir por cero.");
        }

        double resultado = num1 / num2;
        cout << "El resultado de la division es: " << resultado << endl;
    }
    catch (const invalid_argument& e) {  
        cout << e.what() << endl;
    }
    catch (const runtime_error& e) {     
        cout << e.what() << endl;
    }
    catch (...) { 
        cout << "Ocurrio un error inesperado." << endl;
    }

    cout << "Programa finalizado. Gracias por usar el sistema." << endl;

    return 0;
}
