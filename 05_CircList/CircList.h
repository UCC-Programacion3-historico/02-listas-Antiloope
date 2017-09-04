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
    void insertarAntes(T dato);
    void insertarDespues(T dato);
    T getDato(int pos);
    void vaciar();

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

}

template <class T>
bool CircList<T>::esVacia() {

}

template <class T>
int CircList<T>::getTamanio() {

}

template <class T>
void CircList<T>::insertarAntes(T dato) {

}

template <class T>
void CircList<T>::insertarDespues(T dato) {

}

template <class T>
T CircList<T>::getDato(int pos) {

}

template <class T>
void CircList<T>::vaciar() {

}

#endif //CIRCLIST_H
