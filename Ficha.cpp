#include "Ficha.h"

Ficha::Ficha(char simboloFicha) {
    this->simboloFicha = simboloFicha;
    this->estaBloqueada = false;
    this->turnosRestantesParaDesbloqueo = 0;
    this->idJugador = 999999; // Ficha con idJugador especial, ya que fue creada sin un idJugador REAL
}

Ficha::Ficha(char simboloFicha, int idJugador) {
    this->simboloFicha = simboloFicha;
    this->estaBloqueada = false;
    this->turnosRestantesParaDesbloqueo = 0;
    this->idJugador = idJugador;
}


char Ficha::getElementoFicha() {
    return this->simboloFicha;
}

elemento_t Ficha::getElementoFicha2() {
    return this->elemento;
}

Ficha::~Ficha() {

}

int Ficha::getJugador() {
    return this->idJugador;
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
    this->turnosRestantesParaDesbloqueo = turnos;
}

void Ficha::cambiarElemento(elemento_t nuevoElemento) {
    this->elemento = nuevoElemento;
    if (nuevoElemento == SOLDADO) {
        this->simboloFicha = (idJugador + 48);
    } else if (nuevoElemento == MINA) {
        this->simboloFicha = 'M';
    } else if (nuevoElemento == ARMAMENTO) {
        this->simboloFicha = 'R';
    } else if (nuevoElemento == BARCO) {
        this->simboloFicha = 'B';
    } else if (nuevoElemento == AVION) {
        this->simboloFicha = 'P';
    }
}

char Ficha::getElementoF() const {
    return simboloFicha;
}

void Ficha::setSimboloFecha(char simboloFicha) {
    Ficha::simboloFicha = simboloFicha;
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

int Ficha::getIdJugador() const {
    return idJugador;
}

void Ficha::setIdJugador(int idJugador) {
    Ficha::idJugador = idJugador;
}


