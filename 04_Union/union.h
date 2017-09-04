#include "../Lista/Lista.h"

#ifndef UNION_H
#define UNION_H

template<class T>
void agregar(Lista<T> *lis,Lista<T> *lisA,int tam);

template<class T>
Lista<T> *unir(Lista<T> &lisA, Lista<T> &lisB) {
    Lista<T> *lis = new Lista<T>;
    agregar(lis,&lisB,lisB.getTamanio());
    agregar(lis,&lisA,lisA.getTamanio());
    return lis;
}

template<class T>
void agregar(Lista<T> *res,Lista<T> *lis,int tam){
    //Base
    if (tam == 0){
        return;
    }
    res->insertarPrimero(lis->getDato(tam-1));
    //Recursion
    agregar(res,lis,tam-1);
}


#endif //UNION_H
