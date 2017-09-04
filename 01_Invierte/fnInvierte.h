#include "../Lista/Lista.h"
#ifndef FNINVIERTE_H
#define FNINVIERTE_H

template <class T>
void fnInvierte (Lista<T> *lis);
//Invierte es una funcion recursiva que cambia el orden de lis y lo guarda en inv
template <class T>
void invierte(Lista<T> *lis,Lista<T> inv);
//Copia es una funcion recursiva que copia la lista inv a lis.
template <class T>
void copia(Lista<T> *lis,Lista<T> inv);

template <class T>
void fnInvierte (Lista<T> *lis){
    if (lis->esVacia()) {
        return;
    }

    Lista<T> *inversa = new Lista<T>;

    invierte(lis,inversa);
    copia(lis,inversa);
}

template <class T>
void invierte(Lista<T> *lis,Lista<T> *inv){
    //Base
    if (lis->esVacia()) {
        return;
    }
    inv->insertarPrimero(lis->getDato(0));
    lis->remover(0);
    //Recursion
    invierte(lis,inv);
}

template <class T>
void copia(Lista<T> *lis,Lista<T> *inv){
    //Base
    if (inv->esVacia()){
        return;
    }
    lis->insertarUltimo(inv->getDato(0));
    inv->remover(0);
    //Recursion
    copia(lis,inv);
}

#endif //FNINVIERTE_H
