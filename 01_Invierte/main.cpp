#include <iostream>
#include "../Lista/Lista.h"
#include "fnInvierte.h"

using namespace std;

int main() {
    Lista<int> lis;
    int a;
    do {
        cout << "Ingrese un elemento a la lista. Si no quiere agregar mas ingrese -1" << '\n';
        cin >> a;
        if (a>=0) {
            lis.insertarUltimo(a);
        }
    } while(a>=0);

    cout << "La lista tiene " << lis.getTamanio() << " elementos" << '\n';

    for (int i = 0; i < lis.getTamanio(); i++) {
        cout << "Elemento numero " << i << ": " << lis.getDato(i) << '\n';
    }

    fnInvierte(&lis);

    cout << "Ahora la lista esta al reves" << '\n';
    for (int i = 0; i < lis.getTamanio(); i++) {
        cout << "Elemento numero " << i << ": " << lis.getDato(i) << '\n';
    }

    return 0;
}
