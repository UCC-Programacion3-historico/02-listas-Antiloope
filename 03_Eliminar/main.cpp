#include <iostream>
#include "../Lista/Lista.h"
#include <windows.h>

using namespace std;

int main() {
    int o;
    Lista<int> lis;
    system("cls");

    while (1) {
        do {
            cout << "Quiere agregar un elemento a la lista o proceder a borrarlos?" << '\n';
            cout << "  1)Agregar numero\n  2)Eliminar numero \n  3)Salir\n" ;
            cin >> o;
            system("cls");
        } while(o>3 || o<0);
        if (o == 3) { //Salir
            return 0;
        }
        if (o == 1) { //Insertar
            cout << "Lista actual:" << '\n';
            for (int i = 0; i < lis.getTamanio(); i++) {
                cout << "Posicion " << i << ": " << lis.getDato(i) << '\n';
            }
            cout << "\nIngrese el numero para agregar a la lista: ";
            cin >> o;
            system("cls");
            lis.insertarUltimo(o);
        }
        if (o == 2) {
            cout << "Lista actual:" << '\n';
            for (int i = 0; i < lis.getTamanio(); i++) {
                cout << "Posicion " << i << ": " << lis.getDato(i) << '\n';
            }
            cout << "Ingrese el numero de posicion del elemento que desea eliminar, o -1 para salir:" << '\n';
            cin >> o;
            system("cls");
            if (o<0) {
                cout << "Lista final" << '\n';
                for (int i = 0; i < lis.getTamanio(); i++) {
                    cout << "Posicion " << i << ": " << lis.getDato(i) << '\n';
                }
                return 0;
            }
            if (lis.getTamanio()<=o) {
                cout << "No se puede eliminar un elemento que no existe :P" << '\n';
                system("pause>nul");
                system("cls");
            }
            else {
                lis.remover(o);
            }
        }
    }
    return 0;
}
