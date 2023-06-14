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

Ficha::~Ficha() {

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
    this->idJugador = 0;
    this->simboloFicha = VACIO;
}


void Ficha::setSimboloFecha(char simboloFicha) {
    Ficha::simboloFicha = simboloFicha;
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


