#include "Tablero.h"

using namespace std;

Tablero::Tablero(int fila, int columna, int profundidad) {
    this->fila = fila;
    this->columna = columna;
    this->profundidad = profundidad;
    Lista<Lista<Lista<Casillero*>*>*>* filas = new Lista<Lista<Lista<Casillero*>*>*>;
    for(int i=0; i < this->fila; i++){
        Lista<Lista<Casillero*>*>* columnas = new Lista<Lista<Casillero*>*>;
        for(int j=0; j < this->columna; j++){
            Lista<Casillero*>* profundidad = new Lista<Casillero*>;
            for(int k=0; this->profundidad; k++){
                Casillero * casillero = new Casillero();
                profundidad->add(casillero);
            }
            columnas->add(profundidad);
        }
        filas->add(columnas);
    }
    this->casilleros = filas;
}

Tablero::~Tablero() {
    Lista<Lista<Lista<Casillero*>*>*>* filas = this->casilleros;
    while (filas->avanzarCursor()) {
        Lista<Lista<Casillero*>*>* columnas = this->casilleros->getCursor();
        while (columnas->avanzarCursor()){
            Lista<Casillero*>* profundidad = columnas->getCursor();
            while (profundidad->avanzarCursor()) {
                delete profundidad->getCursor();
            }
            delete columnas->getCursor();
        }
        delete filas->getCursor();
    }
}

Casillero *Tablero::obtenerCasillero(int fila, int columna, int profundidad) {
    if((fila <= 0) || (columna <= 0) || (profundidad <= 0) ||
        (fila > this->fila) || (columna > this->columna) ||(profundidad > this->profundidad)){
        string coordenadasInvalidas = "Coordenadas de casilleros invalidas";
        throw coordenadasInvalidas;
    }
    return this->casilleros->get(fila)->get(columna)->get(profundidad);
}
