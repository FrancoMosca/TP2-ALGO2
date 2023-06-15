#include "Mazo.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Mazo::Mazo(int cantidadCartas) {
    for (int i = 0; i < cantidadCartas; i++) {
        this->mazoCartas.agregar(new Carta());
    }
}

unsigned int Mazo::getCantidadCartas() {
    return this->mazoCartas.contarElementos();
}

Mazo::Mazo() {

}

void Mazo::agregarCarta(Carta *nuevaCarta) {
    this->mazoCartas.agregar(nuevaCarta);

}

Carta *Mazo::obtenerCartaSuperior() {
    // se deuelve la ultima carta agregada al mazo es decir la superior
    Carta *cartaSuperior = this->mazoCartas.obtener(this->mazoCartas.contarElementos());
    this->mazoCartas.remover(this->mazoCartas.contarElementos());
    return cartaSuperior;

}


void Mazo::destruirMazo() {
    this->mazoCartas.iniciarCursor();
    while (this->mazoCartas.avanzarCursor()) {
        delete this->mazoCartas.obtenerCursor();
    }
}

void Mazo::barajarMazo() {
    srand(static_cast<unsigned int>(std::time(NULL)));
    this->mazoCartas.iniciarCursor();
    while (this->mazoCartas.avanzarCursor()) {
        this->mazoCartas.obtenerCursor()->setHabilidad(this->mazoCartas.obtenerCursor()->generarEfectoAleatorio());
    }

}

void Mazo::imprimirMazo() {
    int i = 1;
    this->mazoCartas.iniciarCursor();
    std::cout << "----------------SU MAZO DE CARTAS------------------" << std::endl;
    while (this->mazoCartas.avanzarCursor()) {
        std::cout << "CARTA NUMERO " << i++ << ": ";
        this->mazoCartas.obtenerCursor()->imprimirHabilidadCarta();
    }
}

Lista<Carta *> &Mazo::getMazoCartas() {
    return this->mazoCartas;
}

void Mazo::eliminarCarta(unsigned int pos) {
    this->mazoCartas.remover(pos);
}


