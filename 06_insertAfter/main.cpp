#include <iostream>
#include "../Lista/Lista.h"

using namespace std;

int main() {
    Lista<int> lis;

    for (int i = 0; i < 10; i++) {
        lis.insertarPrimero(i);
    }
    lis.insertar(3,1);
    lis.insertar(7,1);
    lis.insertar(9,1);

    for (int i = 0; i < lis.getTamanio(); i++) {
        cout << "Posicion " << i << ": " << lis.getDato(i) << '\n';
    }

    lis.insertAfter2(1,1,45);
    
    cout << "\n\n";
    for (int i = 0; i < lis.getTamanio(); i++) {
        cout << "Posicion " << i << ": " << lis.getDato(i) << '\n';
    }
    return 0;
}
