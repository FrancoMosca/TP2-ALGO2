#ifndef CASILLERO_H
#define CASILLERO_H

#include "Ficha.h"
#include "string"

typedef enum {
    TIERRA,
    AGUA,
    AIRE,
} terreno_t;

class Casillero {
private:
    Ficha * ficha;
    bool estadoCasillero;
    terreno_t terreno;

public:
    Casillero(terreno_t terreno, char simboloFicha);
    Ficha * getFicha();
    bool estaCasilleroVacio();
};

#endif
