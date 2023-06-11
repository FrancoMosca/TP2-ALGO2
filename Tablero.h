#ifndef TABLERO_H
#define TABLERO_H

#include "Casillero.h"
#include "Lista.h"
#include "string"

static const char SIMBOLO_FICHA_VACIO = '-';

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
    bool existeLaCasilla(int fila, int columna, int profundidad);
    int getFila();
    void setFila(int fila);
    int getColumna();
    void setColumna(int columna);
    int getProfundidad();
    void setProfundidad(int profundidad);
    void setCasilla(size_t fila, size_t columna, size_t profundidad, char simboloFicha);
    int obtenerCantidadDePosiciones();
};


#endif
