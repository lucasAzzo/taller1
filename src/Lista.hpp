#include "Lista.h"

template <typename T>
Lista<T>::Lista() {
    primero = NULL;
}

// Inicializa una lista vacía y luego utiliza operator= para no duplicar el
// código de la copia de una lista.
template <typename T>
Lista<T>::Lista(const Lista<T>& l) : Lista() { *this = l; } 

template <typename T>
Lista<T>::~Lista() {
    Nodo* p = primero;
    while(p != NULL){
        Nodo* q = p->siguiente;
        q = p->siguiente;
        delete p;
        p = q;
    }

}

template <typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& l) {
    Lista() = l;
}

template <typename T>
void Lista<T>::agregarAdelante(const T& elem) {
    Nodo *n = new Nodo;
    n->valor = elem;
    n->siguiente = primero;
    primero = n;
}

template <typename T>
void Lista<T>::agregarAtras(const T& elem) {
    Nodo* n= new Nodo;
    n->valor = elem;
    n->siguiente = NULL;
    if(primero == NULL){
        primero = n;
    } else {
        Nodo* p = primero;
        while(p->siguiente != NULL){
            p = p->siguiente;
        }
        p->siguiente = n;
    }
}

template <typename T>
int Lista<T>::longitud() const {
   Nodo* p = primero;
   int n=0;
   while(p != NULL){
       n++;
       p = p->siguiente;
   }
   return n;
}

template <typename T>
const T& Lista<T>::iesimo(Nat i) const {
    Nodo* p = primero;
    for (int j = 0; j < i; ++j) {
        p = p->siguiente;
    }
    return p->valor;
}

template <typename T>
void Lista<T>::eliminar(Nat i) {
    Nodo* p = primero;
    for (int j = 0; j < i; ++j) {
        p = p->siguiente;
    }
    if(p->siguiente == NULL){
        delete p;
    } else{
        Nodo* q = p;
        q = p->siguiente;
        delete p;
    }
}

template <typename T>
T& Lista<T>::iesimo(Nat i) {
    Nodo* p = primero;
    for (int j = 0; j < i; ++j) {
        p = p->siguiente;
    }
    return p->valor;
}

template <typename T>
void Lista<T>::mostrar(std::ostream& o) {
	o<<"[";
    for (int i = 0; i < this->longitud(); ++i) {
        o<< this->iesimo(i) << "i";
    }
    o << "]";
}
