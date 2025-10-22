#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

int main() {
    vector<int> lista = {23, 27, 39, 48, 49};
    int indice;

    cout << "Elementos -> ";
    for (int i = 0; i < lista.size(); i++) {
        cout << lista[i] << " ";
    }
    cout << endl;

    cout << "indice a buscar -> ";
    cin >> indice;

    try {
        if (indice < 0 || indice >= lista.size()) {
            throw out_of_range("No esta en el rango");
        }
        cout << "Se encontro en la posiscion -> " << indice << ": " << lista[indice] << endl;
    }
    catch (const out_of_range &e) {
        cout << "Ocurrio un error " << e.what() << endl;
        cout << "Pruebe denuevo" << endl;
    }

    cout << "Termino" << endl;
    return 0;
}
