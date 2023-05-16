#ifndef TABLERO_H
#define TABLERO_H

#include "Casillero.h"
#include "Lista.h"
#include "string"

class Tablero {
private:
    int fila;
    int columna;
    int profundidad;
    Lista<Lista<Lista<Casillero*>*>*>* casilleros;

public:
    Tablero(int fila, int columna, int profundidad);
    virtual ~Tablero();
    Casillero * obtenerCasillero(int fila, int columna, int profundidad);
};


#endif
