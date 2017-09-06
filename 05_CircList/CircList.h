#ifndef CIRCLIST_H
#define CIRCLIST_H

#include <iostream>

template <class T>
class nodo {
private:
    T dato;
    nodo* siguiente;
public:
    nodo(){
        siguiente = NULL;
    }
    nodo(T d, nodo* s){
        dato = d;
        siguiente = s;
    }
    T getDato(){
        return dato;
    }
    void setDato(T d) {
        dato = d;
    }
    nodo *getSiguiente(){
        return siguiente;
    }
    void setSiguiente(nodo *n) {
        siguiente = n;
    }
};

template <class T>
class CircList {
private:
    nodo<T> *puntero;
public:
    CircList();
    CircList(const CircList<T> &li);
    ~CircList();

    bool esVacia();
    int getTamanio();
    void insertar(T dato);
    void avanzar();
    T getDato();
    void vaciar();
    void remover();
    void reemplazar(T dato);
};

template <class T>
CircList<T>::CircList() {
    puntero = NULL;
}

template <class T>
CircList<T>::CircList(const CircList<T> &li) {

}

template <class T>
CircList<T>::~CircList() {
    vaciar();
}

template <class T>
bool CircList<T>::esVacia() {
    return puntero == NULL;
}

template <class T>
int CircList<T>::getTamanio() {
    int cont = 1;
    nodo<T> *aux = puntero;

    if (NULL == puntero) {
        return 0;
    }
    while (aux->getSiguiente() != puntero) {
        cont++;
        aux = aux->getSiguiente();
    }
    return cont;
}

template <class T>
void CircList<T>::insertar(T dato) {
    if (puntero == NULL) {
        puntero = new nodo<T>(dato,puntero);
        return;
    }
    nodo<T> *aux = new nodo<T>(dato, puntero->getSiguiente());
    puntero->setSiguiente(aux);
    puntero = puntero->getSiguiente();
}

template <class T>
T CircList<T>::getDato() {
    if (puntero == NULL) {
          throw 1;
    }
    return puntero->getDato();
}

template <class T>
void CircList<T>::vaciar() {
    while (!esVacia()) {
        remover();
    }
}

template <class T>
void CircList<T>::avanzar() {
    if (puntero != NULL) {
        puntero = puntero->getSiguiente();
    }
    //Si es NULL no hace nada
}

template <class T>
void CircList<T>::remover(){
    nodo<T> *aux = puntero;

    if (puntero == NULL)
        return;

    while (aux->getSiguiente() != puntero) {
        aux = aux->getSiguinete();
    }
    if (aux == puntero) {
        delete puntero;
        puntero = NULL;
        return;
    }
    aux->setSiguiente(puntero->getSiguiente());
    delete puntero;
    puntero = aux->getSiguiente();
}

template <class T>
void CircList<T>::reemplazar(T dato){
    if (puntero == NULL) {
        throw 1;
    }
    puntero->setDato(dato);
}

#endif //CIRCLIST_H
