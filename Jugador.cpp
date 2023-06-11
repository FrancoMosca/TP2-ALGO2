#include "Jugador.h"

Jugador::Jugador(string nombre, char simboloDeFicha) {
    this->nombreJugador = nombre;
    this->idJugador = 0;
    this->ficha = new Ficha(simboloDeFicha);
    this->mazo = NULL;
    this->jugadas = new Lista<Casillero*>;
}

int Jugador::getIdJugador() {
    return idJugador;
}

void Jugador::setIdJugador(int idJugador) {
    Jugador::idJugador = idJugador;
}

const string &Jugador::getNombreJugador() {
    return nombreJugador;
}

void Jugador::setNombreJugador(string &nombreJugador) {
    Jugador::nombreJugador = nombreJugador;
}

Ficha *Jugador::getFicha() {
    return ficha;
}

void Jugador::setFicha(Ficha *ficha) {
    Jugador::ficha = ficha;
}

Mazo *Jugador::getMazo() const {
    return mazo;
}

void Jugador::setMazo(Mazo *mazo) {
    Jugador::mazo = mazo;
}

Lista<Casillero *> *Jugador::getJugadas() const {
    return jugadas;
}

void Jugador::setJugadas(Lista<Casillero *> *jugadas) {
    Jugador::jugadas = jugadas;
}


