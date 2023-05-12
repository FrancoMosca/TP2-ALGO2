/*
 * Tablero.h
 *
 *  Created on: 4 may 2023
 *      Author: rinco
 */

#ifndef TABLERO_H_
#define TABLERO_H_

#include "Lista.h"
#include "Casillero.h"

class Tablero {

private:

	int fila;
	int columna;
	int profundidad;

	Lista<Lista<Lista<Casillero*>*>*>* casilleros;


public:
	Tablero();

	Tablero(int fila, int columna, int profundidad);




	virtual ~Tablero();







};






#endif /* TABLERO_H_ */
