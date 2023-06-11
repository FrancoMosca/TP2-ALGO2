#ifndef COLA_H_
#define COLA_H_

#include "Nodo.h"

template<class T>
class Cola {

private:

    Nodo<T>* frente;

    Nodo<T>* ultimo;

    unsigned int tamanio;

public:
    /**
     * pre:
     * post: inicializa la cola vacia para su uso
     */
    Cola();

    /*
     * post: indica si la cola tiene algún elemento.
     */
    bool estaVacia();

    /*
     * pre :
     * post: devuelve el elemento en el frente de la cola.
     */
    T desacolar();

    /*
     * pre: el elemento no es vacio
     * post: agrega el elemento a la cola
     */
    void acolar (const T& elemento);

    /*
     * pre: el elemento no es vacio
     * post: agrega todos los elementos a la cola
     */
    //void acolarTodos (const Cola<T> * otraCola);

    /*
    * post: devuelve la cantidad de elementos que tiene la cola.
    */
    unsigned int contarElementos();

    /**
     * pre:
     * post: elimina la cola
     */
    virtual ~Cola();
};

template<class T> Cola<T>::Cola() {
    this->frente = NULL;
    this->ultimo = NULL;
    this->tamanio = 0;
}

template<class T> bool Cola<T>::estaVacia() {
    return (this->tamanio == 0);
}


template<class T> void Cola<T>::acolar(const T& elemento) {

    Nodo<T>* nuevo = new Nodo<T>(elemento);

    if (this->estaVacia()) {
        nuevo->cambiarSiguiente(NULL);
        this->frente = nuevo;

    } else {
        nuevo->cambiarSiguiente(this->ultimo);


    }
    this->ultimo = nuevo;
    this->tamanio++;
}
template<class T> unsigned int Cola<T>::contarElementos() {

    return this->tamanio;
}

template<class T> T Cola<T>::desacolar() {

    T  elemento;



    if (this->frente != NULL) {


        elemento = this->frente->obtenerDato();
        /*si habia un unico elemento que es el frente y el ultimo a la vez*/
        if(this->tamanio == 1)
        {
            delete this->frente;
            this->frente = NULL;
            this->ultimo = NULL;
            this->tamanio--;
            return elemento;
        }



        //recorro y actualizo cual es el elemento del frente
        Nodo<T>* ptr_auxiliar = NULL;
        Nodo<T>* nuevoFrente = this->ultimo;

        ptr_auxiliar = this->ultimo->obtenerSiguiente();
        while( ptr_auxiliar != this->frente)
        {
            ptr_auxiliar = ptr_auxiliar->obtenerSiguiente();
            nuevoFrente = nuevoFrente->obtenerSiguiente();
        }
        delete ptr_auxiliar;
        nuevoFrente->cambiarSiguiente(NULL);
        this->frente = nuevoFrente;
        this->tamanio--;
    }


    return elemento;
}


template<class T> Cola<T>::~Cola() {
    while (!this->estaVacia()) {

        Nodo<T>* aBorrar = this->ultimo;
        this->ultimo=this->ultimo->obtenerSiguiente();
        this->tamanio--;
        delete aBorrar;
    }
}

#endif /* COLA_H_ */