#include "Casillero.h"

Casillero::Casillero(terreno_t terreno, char simboloFicha) {
    this->ficha = new Ficha(simboloFicha);
    this->estadoCasillero = false;
    this->terreno = terreno;
}

Ficha *Casillero::getFicha() {
    return this->ficha;
}

bool Casillero::estaCasilleroVacio() {
    if (this->ficha->getElementoFicha() == '-') {
        return true;
    }
    return false;
}
