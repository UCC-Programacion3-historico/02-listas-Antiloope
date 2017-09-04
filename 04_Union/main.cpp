#include <iostream>
#include "../Lista/Lista.h"
#include "union.h"

using namespace std;

int main() {
    Lista<int> A;
    Lista<int> B;
    for (int i = 0; i < 10; i++) {
        A.insertarPrimero(i);
    }
    for (int i = 0; i < 10; i++) {
        B.insertarUltimo(i);
    }
    Lista<int> *R = unir(A,B);
    for (int i = 0; i < R->getTamanio(); i++) {
        cout << "Posicion " << i << ": " << R->getDato(i) << '\n';
    }
    return 0;
}
