#include "Carta.h"
#include <cstdlib>
#include <ctime>
#include <iostream>


Carta::Carta() {
    this->habilidadCarta = CARTA_SIN_EFECTO;
}

Carta::Carta(habilidadCarta_t efecto) {
    this->habilidadCarta = efecto;
}

habilidadCarta_t Carta::generarEfectoAleatorio() {

    int efectoRandom = (rand() % 6) + 1;
    return (habilidadCarta_t) efectoRandom;
}

void Carta::setHabilidad(habilidadCarta_t efecto) {
    this->habilidadCarta = efecto;
}

habilidadCarta_t Carta::getHabilidad() {
    return this->habilidadCarta;
}

Carta::~Carta() {

}

void Carta::imprimirHabilidadCarta() {
    switch (this->habilidadCarta) {
        case 0:
            std::cout << "CARTA SINEFECTO " << std::endl;
            break;
        case 1:
            std::cout << "CARTA PERDER TURNO " << std::endl;
            break;

        case 2:
            std::cout << "CARTA BLOQUEAR FICHA " << std::endl;
            break;

        case 3:
            std::cout << "CARTA ANULAR CASILLERO " << std::endl;
            break;

        case 4:
            std::cout << "CARTA VOLVER JUGADA " << std::endl;
            break;

        case 5:
            std::cout << "CARTA ELIMINAR CARTA" << std::endl;
            break;

        case 6:
            std::cout << "CARTA ROBAR  " << std::endl;
            break;
        default:
            break;
    }
}

void Carta::obtenerRango() {

}

void Carta::detectarMinas(Tablero *tablero) {
}

void Carta::dispararMisil() {
}

void Carta::ataqueQuimico() {

}

void Carta::desarmarSoldados() {

}

void Carta::ataqueMultiple() {

}

void Carta::aumentarResistencia(Tablero *tablero) {

}


