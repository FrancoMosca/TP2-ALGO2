#include "Ficha.h"

Ficha::Ficha(char simboloFicha) {
    this->elementoF = simboloFicha;
    this->estaBloqueada = false;
    this->turnosRestantesParaDesbloqueo = 0;
}

Ficha::Ficha(elemento_t elementoFicha, int jugador) {
    this->estaBloqueada = false;
    this->turnosRestantesParaDesbloqueo = 0;
    this->elemento = elementoFicha;
    this->jugador = jugador;
    /*
    if (elementoFicha == SOLDADO) {
        this->elementoF = (jugador+48);
    } else if (elementoFicha == MINA){
        this->elementoF = 'M';
    } else if (elementoFicha == ARMAMENTO){
        this->elementoF = 'R';
    }else if (elementoFicha == BARCO){
        this->elementoF = 'B';
    }else if (elementoFicha == AVION){
        this->elementoF = 'P';
    }
*/
}

char Ficha::getElementoFicha() {
    return this->elementoF;
}

elemento_t Ficha::getElementoFicha2() {
    return this->elemento;
}

Ficha::~Ficha() {

}

int Ficha::getJugador() {
    return this->jugador;
}

bool Ficha::getBloqueada() {
    return this->estaBloqueada;
}

bool Ficha::aumentarContador() {
    this->turnosRestantesParaDesbloqueo -= 1;
    if (this->turnosRestantesParaDesbloqueo == 0) {
        this->estaBloqueada = false;
    }
    return this->estaBloqueada;
}

void Ficha::bloquear(int turnos) {
    this->estaBloqueada = true;
    this->jugador = 0;
    this->turnosRestantesParaDesbloqueo = turnos;
}

void Ficha::cambiarElemento(elemento_t nuevoElemento) {
    this->elemento = nuevoElemento;
    if (nuevoElemento == SOLDADO) {
        this->elementoF = (jugador + 48);
    } else if (nuevoElemento == MINA) {
        this->elementoF = 'M';
    } else if (nuevoElemento == ARMAMENTO) {
        this->elementoF = 'R';
    } else if (nuevoElemento == BARCO) {
        this->elementoF = 'B';
    } else if (nuevoElemento == AVION) {
        this->elementoF = 'P';
    }
}

char Ficha::getElementoF() const {
    return elementoF;
}

void Ficha::setElementoF(char elementoF) {
    Ficha::elementoF = elementoF;
}

elemento_t Ficha::getElemento() const {
    return elemento;
}

void Ficha::setElemento(elemento_t elemento) {
    Ficha::elemento = elemento;
}

int Ficha::getVidas() const {
    return vidas;
}

void Ficha::setVidas(int vidas) {
    Ficha::vidas = vidas;
}
