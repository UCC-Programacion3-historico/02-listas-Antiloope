#ifndef LISTA_H
#define LISTA_H

#include <iostream>
/**
 * Clase que implementa una Lista Enlasada generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */

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
class Lista {
private:
    nodo<T> *inicio;
public:
    Lista();

    Lista(const Lista<T> &li);

    ~Lista();

    bool esVacia();

    int getTamanio();

    void insertar(int pos, T dato);

    void insertarPrimero(T dato);

    void insertarUltimo(T dato);

    void remover(int pos);

    T getDato(int pos);

    void reemplazar(int pos, T dato);

    void vaciar();
};


/**
 * Constructor de la clase Lista
 * @tparam T
 */
template<class T>
Lista<T>::Lista() {
    inicio = NULL;
}


/**
 * Constructor por copia de la clase Lista
 * @tparam T
 * @param li
 */
template<class T>
Lista<T>::Lista(const Lista<T> &li) {
    inicio = new nodo<T>;

    nodo<T> *tmp = li.inicio;
    nodo<T> *aux = inicio;
    nodo<T> *aux2;

    while (tmp != NULL) {
        aux->dato = tmp->dato;
        aux2 = new nodo<T>;
        aux->siguiente = &aux2;
        tmp = tmp->siguiente;
        aux = aux->siguiente;
    }
}


/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los nodos
 * utilizados en la lista
 * @tparam T
 */
template<class T>
Lista<T>::~Lista() {
    this->vaciar();
}


/**
 * Metodo para saber si la lista esta vacia
 * @tparam T
 * @return true si la lista esta vacia, sino false
 */
template<class T>
bool Lista<T>::esVacia() {
    return inicio == NULL;
}


/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 */
template<class T>
int Lista<T>::getTamanio() {
    int cont = 0;
    nodo<T> *aux = inicio;

    while (aux !=NULL) {
        cont++;
        aux = aux->getSiguiente();
    }
    return cont;
}


/**
 * Inserta un nodo con el dato en la posicion pos
 * @tparam T
 * @param pos lugar donde será insertado el dato
 * @param dato  dato a insertar
 */
template<class T>
void Lista<T>::insertar(int pos, T dato) {
    int cont = 0;
    nodo<T> *aux = inicio;
    if (pos == 0) {
        nodo<T> *nodoAux = new nodo<T>(dato,inicio);
        inicio = nodoAux;
        return;
    }
    while (aux!=NULL && cont < pos-1) {
        aux = aux->getSiguiente();
        cont++;
    }
    if (cont==pos-1) {
        nodo<T> *nodoAux = new nodo<T>(dato,aux->getSiguiente());
        aux->setSiguiente(nodoAux);
    }
    else {
        if(aux==NULL) {
            throw 7;
        }
    }
}


/**
 * Inserta un nodo con el dato en la primera posicion
 * @tparam T
 * @param dato dato a insertar
 */
template<class T>
void Lista<T>::insertarPrimero(T dato) {
    nodo<T> *nodoAux = new nodo<T>(dato,inicio);
    inicio = nodoAux;
}


/**
 * Inserta un nodo con el dato en la ultima posicion
 * @tparam T
 * @param dato dato a insertar
 */
template<class T>
void Lista<T>::insertarUltimo(T dato) {
    nodo<T> *aux = inicio;
    if (inicio == NULL) {
        nodo<T> *nodoAux = new nodo<T>(dato,NULL);
        inicio = nodoAux;
    }
    else {
        while (aux->getSiguiente() != NULL) {
            aux = aux->getSiguiente();
        }
        nodo<T> *nodoAux = new nodo<T>(dato,NULL);
        aux->setSiguiente(nodoAux);
    }
}


/**
 * Elimina el nodo en la posicion 'pos' de la lista enlasada
 * @tparam T
 * @param pos posicion del nodo a eliminar
 */
template<class T>
void Lista<T>::remover(int pos) {
    int cont = 0;
    nodo<T> *aux = inicio;
    nodo<T> *tmp;
    if (pos == 0) {
        inicio = inicio->getSiguiente();
        delete aux;
        return;
    }
    while (aux!=NULL && cont < pos-1) {
        aux = aux->getSiguiente();
        cont++;
    }
    if (cont==pos-1) {
        tmp = aux->getSiguiente();
        aux->setSiguiente(tmp->getSiguiente());
        delete tmp;
    }
    else {
        if(aux==NULL) {
            throw 7;
        }
    }
}


/**
 * Obtener el dato del nodo en la posicion pos
 * @tparam T
 * @param pos posicion del dato
 * @return dato almacenado en el nodo
 */
template<class T>
T Lista<T>::getDato(int pos) {
    int cont = 0;
    nodo<T> *aux = inicio;

    while (aux!=NULL && cont < pos) {
        aux = aux->getSiguiente();
        cont++;
    }
    if (cont == pos) {
        return aux->getDato();
    }
    else{
        if (aux==NULL) {
            throw 7;
        }
    }
}


/**
 * Reemplaza el dato almacenado en un nodo por este otro
 * @tparam T
 * @param pos posicion donde se desea reemplazar
 * @param dato nuevo dato a almacenar
 */
template<class T>
void Lista<T>::reemplazar(int pos, T dato) {
    int cont = 0;
    nodo<T> *aux = inicio;
    if (pos == 0) {
        nodo<T> *nodoAux = new nodo<T>(dato,aux->getSiguiente());
        inicio = nodoAux;
        delete aux;
        return;
    }
    while (aux!=NULL && cont < pos-1) {
        aux = aux->getSiguiente();
        cont++;
    }
    if (cont==pos-1) {
        nodo<T> *nodoAux = new nodo<T>(dato,aux->getSiguiente());
        nodo<T> *tmp = aux->getSiguiente();
        aux->setSiguiente(nodoAux);
        nodoAux->setSiguiente(tmp->getSiguiente());
        delete tmp;
    }
    else{
        if (aux==NULL) {
            throw 7;
        }
    }
}


/**
 * Función que vacia la lista enlazada
 * @tparam T
 */
template<class T>
void Lista<T>::vaciar() {
    nodo<T> *aux = inicio;
    nodo<T> *tmp = inicio;

    while (aux != NULL) {
        tmp = aux;
        aux = aux->getSiguiente();
        delete tmp;
    }
    inicio = NULL;
}


#endif //LISTA_H
