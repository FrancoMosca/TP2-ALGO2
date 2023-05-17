#include "Casillero.h"

Casillero::Casillero(elemento_t elemento) {
    this->ficha = new Ficha(elemento);
    this->estadoCasillero = false;
}

Ficha *Casillero::getFicha() {
    return ficha;
}
