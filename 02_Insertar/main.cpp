#include <iostream>
#include "../Lista/Lista.h"

using namespace std;

int main() {
    Lista<float> lis;

    int o;
    cout << "Generador de lista de elementos no enteros." << '\n';
    while(1) {
        do {
            cout << "Desea agregarlo: \n  1)Al final\n  2)Al principio\n  3)Al medio\n  4)Salir y mostrar" << '\n';
            cin >> o;
        }while(o>4 || o<0);
        if (o==4) {
            for (int i = 0; i < lis.getTamanio(); i++) {
                cout << "Elemento numero " << i << ": " << lis.getDato(i) << '\n';
            }
            return 0;
        }
        float a;
        cout << "Ingrese un elemento no entero: ";
        cin >> a;
        switch (o) {
          case 1:
            lis.insertarUltimo(a);
            break;
          case 2:
            lis.insertarPrimero(a);
            break;
          case 3:
            if (lis.esVacia()) {
                lis.insertarPrimero(a);
            }
            else {
                lis.insertar(lis.getTamanio()/2,a);
            }
            break;
        }
    }
    return 0;
}
