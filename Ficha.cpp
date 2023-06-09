/*
 * ficha.cpp
 *
 *  Created on: 05/05/2023
 *      Author: algo2
 */

#include "Ficha.h"

Ficha::Ficha(elemento_t elementoFicha,int posicion [3]) {
    this->estaBloqueada = false;
    this->turnosRestantesParaDesbloqueo = 0;
    this->elemento = elementoFicha;
    this->jugador = 0;
    if (elementoFicha == AGUA) {
        this->elementoF = 'A';
    } else if (elementoFicha == TIERRA) {
        this->elementoF = 'T';
    } else if (elementoFicha == AIRE) {
        this->elementoF = 'Q';
    }
    for (int i = 0;i<3;i++){
    	this->posicion[i]=posicion[i];
    }
}

Ficha::Ficha(elemento_t elementoFicha,int jugador,int posicion[3]){
    this->estaBloqueada = false;
    this->turnosRestantesParaDesbloqueo = 0;
    this->elemento = elementoFicha;
    this->jugador = jugador;
    if (elementoFicha == SOLDADO) {
    	this->elementoF = (jugador+48);
    } else if (elementoFicha == MINA){
    	this->elementoF = 'M';
    } else if (elementoFicha == ARMAMENTO){
    	this->elementoF = 'R';
    }else if (elementoFicha == BARCO){
    	this->elementoF = 'B';
    }else if (elementoFicha == AVION){
    	this->elementoF = 'P';
    }
    for (int i = 0;i<3;i++){
    	this->posicion[i]=posicion[i];
    }
}

char Ficha::getElementoFicha() {
    return this->elementoF;
}
elemento_t Ficha::getElementoFicha2(){
	return this->elemento;
}

Ficha::~Ficha(){

}

int Ficha::getJugador(){
	return this->jugador;
}

bool Ficha::getBloqueada(){
	return this->estaBloqueada;
}

void Ficha::aumentarContador(){
	this->turnosRestantesParaDesbloqueo -= 1;
	if (this->turnosRestantesParaDesbloqueo == 0){
		this->estaBloqueada = false;
		if(this->posicion[2]<= 2){
			this->elementoF = 'A';
			this->elemento = AGUA;
		} else if(this->posicion[2]<=5){
			this->elementoF = 'T';
			this->elemento = TIERRA;
		}
	}
}

void Ficha::bloquear(int turnos){
	this->estaBloqueada = true;
	this->cambiarElemento(VACIO);
	this->jugador = 0;
	this->turnosRestantesParaDesbloqueo = turnos;
}
void Ficha :: cambiarElemento(elemento_t nuevoElemento){
		this->elemento = nuevoElemento;
		if (nuevoElemento == SOLDADO) {
	    	this->elementoF = (jugador+48);
	    } else if (nuevoElemento == MINA){
	    	this->elementoF = 'M';
	    } else if (nuevoElemento == ARMAMENTO){
	    	this->elementoF = 'R';
	    }else if (nuevoElemento == BARCO){
	    	this->elementoF = 'B';
	    }else if (nuevoElemento == AVION){
	    	this->elementoF = 'P';
	    }else if (nuevoElemento == AGUA) {
	        this->elementoF = 'A';
	    } else if (nuevoElemento == TIERRA) {
	        this->elementoF = 'T';
	    } else if (nuevoElemento == AIRE) {
	        this->elementoF = 'Q';
	    }
}

void Ficha::getPosicion(int(*posicion)[3]){
	for (int i=0;i<3;i++){
		(*posicion)[i]= this->posicion[i];
	}
}
