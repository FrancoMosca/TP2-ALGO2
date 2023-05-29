/*
 * Soldado.h
 *
 *  Created on: 05/05/2023
 *      Author: algo2
 */

#ifndef SOLDADO_H_
#define SOLDADO_H_
#include <string>

class Soldado{
private:
	int posicion [3];
	std::string jugador;
	std::string tipo;
public:
	Soldado(int* posicion, std::string jugador, std::string tipo);
	~Soldado();
	int* getPosicion();
	std::string getJugador();
	std::string getTipo();
};



#endif /* SOLDADO_H_ */
