#include "Jugador.h"

Jugador::Jugador(string nombre, char simboloDeFicha) {
    this->nombreJugador = nombre;
    this->idJugador = 0;
    this->ficha = new Ficha(simboloDeFicha);
    this->mazo = NULL;
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


Ficha *Jugador::getFicha() {
    return ficha;
}

Mazo *Jugador::getMazo() const {
    return mazo;
}

void Jugador::setMazo(Mazo *mazo) {
    Jugador::mazo = mazo;
}

int Jugador::getCantidadInsertsRestantes() {
    return cantidadInsertsRestantes;
}

void Jugador::setCantidadInsertsRestantes(int cantidadInsertsRestantes) {
    Jugador::cantidadInsertsRestantes = cantidadInsertsRestantes;
}



