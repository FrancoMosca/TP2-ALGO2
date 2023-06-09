/*
 * Jugador.cpp
 *
 *  Created on: 27/05/2023
 *      Author: algo2
 */
/*
#include "Jugador.h"

Jugador::Jugador(int jugador){
	this->jugador = jugador;
	this->cartasDisponibles = new Lista<Carta*>;
	this->posicionesSoldados = new Lista<coordenada*>;
	this->posicionesArmamento = new Lista<coordenada*>;
}

Jugador::~Jugador(){
	//this->cartasDisponibles->~Lista();
	//this->posicionesArmamento->~Lista();
	//this->posicionesSoldados->~Lista();
}

void Jugador::agregarCarta(Carta* carta){
	unsigned int cantidad = this->cartasDisponibles->contarElementos();
	if (cantidad >= 7){
		throw "tiene maximo permitido de cartas acumuladas";
	}
	else{
		this->cartasDisponibles->add(carta);
	}
}

void Jugador :: eliminarCarta(std::string tipo){
	unsigned int cantidad = this->cartasDisponibles->contarElementos();
	for(int i= 1;i<cantidad;i++){
		if(this->cartasDisponibles->get(i)->obtenerTipoCartaAleatorio() == tipo){
			this->cartasDisponibles->remover(i);
			i = cantidad;
		}
	}
}

bool Jugador :: continuaJugando(){
	return (!this->posicionesSoldados->vacia());
}

void Jugador :: intercambiarPosicionSoldado(coordenada anterior,coordenada nueva){
	unsigned int cantidad = this->posicionesSoldados->contarElementos();
	for (unsigned int i = 1; i<cantidad;i++){
		coordenada* ubicacion = this->posicionesSoldados->get(i);
		if((*ubicacion)[0]==anterior[0]&&(*ubicacion)[1]==anterior[1]&&(*ubicacion)[2]==anterior[2]){
			this->posicionesSoldados->remover(i);
			(*ubicacion)[0]= nueva[0];
			(*ubicacion)[1]= nueva[1];
			(*ubicacion)[2]= nueva[2];
			i = cantidad;
		}
	}
}

void Jugador::eliminarSoldado(coordenada posicion){
	unsigned int cantidad = this->posicionesSoldados->contarElementos();
	for (unsigned int i = 1; i<cantidad;i++){
		coordenada* ubicacion = this->posicionesSoldados->get(i);
		if((*ubicacion)[0]==posicion[0]&&(*ubicacion)[1]==posicion[1]&&(*ubicacion)[2]==posicion[2]){
			this->posicionesSoldados->remover(i);
			i = cantidad;
		}
	}
}

void Jugador :: intercambiarPosicionArmamento(coordenada anterior,coordenada nueva){
	unsigned int cantidad = this->posicionesArmamento->contarElementos();
	for (unsigned int i = 1; i<cantidad;i++){
		coordenada* ubicacion = this->posicionesArmamento->get(i);
		if((*ubicacion)[0]==anterior[0]&&(*ubicacion)[1]==anterior[1]&&(*ubicacion)[2]==anterior[2]){
			this->posicionesArmamento->remover(i);
			(*ubicacion)[0]= nueva[0];
			(*ubicacion)[1]= nueva[1];
			(*ubicacion)[2]= nueva[2];
			i = cantidad;
		}
	}
}


void Jugador::eliminarArmamento(coordenada posicion){
	unsigned int cantidad = this->posicionesArmamento->contarElementos();
	for (unsigned int i = 1; i<cantidad;i++){
		coordenada* ubicacion = this->posicionesArmamento->get(i);
		if((*ubicacion)[0]==posicion[0]&&(*ubicacion)[1]==posicion[1]&&(*ubicacion)[2]==posicion[2]){
			this->posicionesArmamento->remover(i);
			i = cantidad;
		}
	}
}

Lista<Carta*>* Jugador :: getCartasDisponibles(){
	return this->cartasDisponibles;
}

Lista<coordenada*>* Jugador::getPosicionesSoldados(){
	return this->posicionesArmamento;
}

Lista<coordenada*>* Jugador :: getPosicionesSoldados(){
	return this->posicionesSoldados;
}

void Jugador::agregarSoldado(coordenada* posicion){
	this->posicionesSoldados->add(posicion);
}
void Jugador::agregarArmamento(coordenada* posicion){
	this->posicionesArmamento->add(posicion)
}
*/
