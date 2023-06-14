#ifndef TP2_ALGO2_MAZO_H
#define TP2_ALGO2_MAZO_H

#include "Carta.h"
#include "Lista.h"

class Mazo {
private:
    Lista<Carta *> mazoCartas;

public:
    //Pre: la cantidad de cartas no puede ser negativa
    //Post: se cre un mazo de "cantidadCartas" cantidadCartas
    Mazo(int cantidadCartas);

    //Pre: -
    //Post: se crea un mazo de cartas vacio
    Mazo();

    //Pre: -
    //Post: agrega la carta "nuevaCarta" al mazo
    void agregarCarta(Carta *nuevaCarta);

    //Pre: -
    //Post: retorna la ultima carta agregada al mazo
    Carta *obtenerCartaSuperior();

    //Pre: -
    //Post: las posiciones de las cartas se encuentran mezcladas
    void barajarMazo();

    //Pre: -
    //Post: se libera la memoria solicitada
    void destruirMazo();

    //Pre: -
    //Post: muestra por pantalla las cartas disponibles que se pueden usar 
    void imprimirMazo();

    //Pre: debe existir una carta en la posicion "pos"
    //Post: la carta ubicada en "pos" ha sido eliminada
    void eliminarCarta(unsigned int pos);

    //Pre: -
    //Post: retorna una lista que contiene a las cartas del maso
    Lista<Carta *> &getMazoCartas();

    //Pre:-
    //Post: devuelve la cantidad de cartas totales ubicadas en el mazo
    unsigned int getCantidadCartas();

};


#endif
