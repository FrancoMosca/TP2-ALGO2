#ifndef TP2_ALGO2_MAZO_H
#define TP2_ALGO2_MAZO_H

#include "Carta.h"
#include "Lista.h"

class Mazo
{
private:
    Lista<Carta*> mazoCartas;

public:

    Mazo(int cantidadCartas);
    Mazo();
    void agregarCarta(Carta * nuevaCarta);
    Carta *obtenerCartaSuperior();
    void barajarMazo();
    void destruirMazo();
    void imprimirMazo();
    void eliminarCarta(unsigned int pos);
    Lista<Carta*>&getMazoCartas();
    unsigned int getCantidadCartas();

};


#endif
