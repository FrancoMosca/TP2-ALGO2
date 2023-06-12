#include "Tablero.h"

using namespace std;

Tablero::Tablero(int fila, int columna, int profundidad) {
    this->fila = fila;
    this->columna = columna;
    this->profundidad = profundidad;
    Lista<Lista<Lista<Casillero*>*>*>* filas = new Lista<Lista<Lista<Casillero*>*>*>;
    for(int i = 0; i < this->fila; i++){
        Lista<Lista<Casillero*>*>* columnas = new Lista<Lista<Casillero*>*>;
        for(int j = 0; j < this->columna; j++){
            Lista<Casillero*>* profundidad = new Lista<Casillero*>;
            for(int k = 0; k < this->profundidad; k++){
                Casillero * casillero;
                if (k <= 2) {
                    casillero = new Casillero(AGUA, VACIO);
                } else if (k <= 5) {
                    casillero = new Casillero(TIERRA, VACIO);
                } else {
                    casillero = new Casillero(AIRE, VACIO);
                }
                profundidad->agregar(casillero);
            }
            columnas->agregar(profundidad);
        }
        filas->agregar(columnas);
    }
    this->casilleros = filas;
}

Tablero::~Tablero() {
    Lista<Lista<Lista<Casillero*>*>*>* filas = this->casilleros;
    while (filas->avanzarCursor()) {
        Lista<Lista<Casillero*>*>* columnas = this->casilleros->obtenerCursor();
        while (columnas->avanzarCursor()){
            Lista<Casillero*>* profundidad = columnas->obtenerCursor();
            while (profundidad->avanzarCursor()) {
                delete profundidad->obtenerCursor();
            }
            delete columnas->obtenerCursor();
        }
        delete filas->obtenerCursor();
    }
}

Casillero *Tablero::obtenerCasillero(int fila, int columna, int profundidad) {
    if((fila <= 0) || (columna <= 0) || (profundidad <= 0) ||
        (fila > this->fila) || (columna > this->columna) ||(profundidad > this->profundidad)){
        string coordenadasInvalidas = "Coordenadas de casilleros invalidas";
        throw coordenadasInvalidas;
    }
    return this->casilleros->obtener(fila)->obtener(columna)->obtener(profundidad);
}

int Tablero::getFila() {
    return fila;
}

void Tablero::setFila(int fila) {
    Tablero::fila = fila;
}

int Tablero::getColumna() {
    return columna;
}

void Tablero::setColumna(int columna) {
    Tablero::columna = columna;
}

int Tablero::getProfundidad() {
    return profundidad;
}

void Tablero::setProfundidad(int profundidad) {
    Tablero::profundidad = profundidad;
}

bool Tablero::existeLaCasilla(int fila, int columna, int profundidad) {
    if(this->fila < fila || this->columna < columna || this->profundidad < profundidad || fila < 1 || columna < 1 || profundidad < 1){
        return false;
    }
    return true;
}

void Tablero::setCasilla(size_t fila, size_t columna, size_t profundidad, char simboloFicha, int idJugador) {
    Ficha *ficha = this->casilleros->obtener(fila)->obtener(columna)->obtener(profundidad)->getFicha();
    ficha->setSimboloFecha(simboloFicha);
    ficha->setIdJugador(idJugador);
}

void Tablero::setCasillaMina(size_t fila, size_t columna, size_t profundidad, char simboloFicha) {
    Ficha *ficha = this->casilleros->obtener(fila)->obtener(columna)->obtener(profundidad)->getFicha();
    ficha->setSimboloFecha(simboloFicha);
    ficha->setIdJugador(666666);
    ficha->bloquear(5);
}

int Tablero::obtenerCantidadDePosiciones() {
    return (this->fila * this->columna * this->profundidad);
}
