/*
 * Tablero.cpp
 *
 *  Created on: 4 may 2023
 *      Author: rinco
 */

#include "Tablero.h"





Tablero::Tablero(int fila, int columna, int profundidad){ // @suppress("Class members should be properly initialized")

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







Tablero::Tablero() {
	// TODO Auto-generated constructor stub

}

Tablero::~Tablero() {
	// TODO Auto-generated destructor stub
}

