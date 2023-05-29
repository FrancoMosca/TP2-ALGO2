#include "Mina.h"

Mina::Mina(int posicion[3],std::string jugador){
	for (int i = 0; i < 3; i++){
	this->posicion[i] = posicion[i];
	}
	this->jugador = jugador;
	this->activa = false;
	this->contador = 0;
	this->turnos = 0;
}

Mina::~Mina(){
}

int* Mina::getPosicion(){
	return this->posicion;
}

std::string Mina::getJugador(){
	return this->jugador;
}

bool Mina::getActiva(){
	return this->activa;
}

bool Mina::aumentarContador(){
	this->contador += 1;
	return (this->contador == this->turnos);
}

void Mina::activarMina(int turnos){
	this->activa = true;
	this->turnos = turnos;
}
