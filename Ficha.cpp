#include "Ficha.h"

Ficha::Ficha(elemento_t elementoFicha) {
    this->estaBloqueada = false;
    this->turnosRestantesParaDesbloqueo = 0;
    this->elemento = elementoFicha;
    if (elementoFicha == AGUA) {
        this->elementoF = 'A';
    } else if (elementoFicha == TIERRA) {
        this->elementoF = 'T';
    } else if (elementoFicha == AIRE) {
        this->elementoF = 'Q';
    }
}

char Ficha::getElementoFicha() {
    return this->elementoF;
}
