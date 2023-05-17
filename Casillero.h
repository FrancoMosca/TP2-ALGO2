#ifndef CASILLERO_H
#define CASILLERO_H

#include "Ficha.h"


class Casillero {
private:
    Ficha * ficha;
    bool estadoCasillero;

public:
    Casillero(elemento_t elementoCasillero);

    Ficha * getFicha();


};

#endif
