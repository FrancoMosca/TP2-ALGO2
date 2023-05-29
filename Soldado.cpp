/*
 * Soldado.cpp
 *
 *  Created on: 05/05/2023
 *      Author: algo2
 */
#include "Soldado.h"
Soldado::Soldado(int* posicion, std::string jugador, std::string tipo){
	for (int i=0; i<3; i++){
		this->posicion[i] = posicion[i];
		this->jugador = jugador;
		this->tipo = tipo;
	}
}

Soldado::~Soldado(){

}

int* Soldado::getPosicion(){
	return this->posicion;
}
std::string Soldado::getJugador(){
	return this->jugador;
}
std::string Soldado::getTipo(){
	return this->tipo;
}


