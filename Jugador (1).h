/*
 * Jugador.h
 *
 *  Created on: 27/05/2023
 *      Author: algo2
 */
/*
#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "Lista.h"
#include "Carta.h"
typedef int coordenada[3];

class Jugador{
private:
	int jugador;
	Lista<Carta*>* cartasDisponibles;
	Lista<coordenada*>* posicionesSoldados;
	Lista<coordenada*>* posicionesArmamento;
public:
	Jugador(int jugador);
	~Jugador();
	void agregarCarta(Carta* carta);
	void eliminarCarta(std::string tipo);
	bool continuaJugando();
	void intercambiarPosicionSoldado(coordenada anterior,coordenada nueva);
	void eliminarSoldado(coordenada posicion);
	void intercambiarPosicionArmamento(coordenada anterior,coordenada nueva);
	void eliminarArmamento(coordenada posicion);
	Lista<Carta*>* getCartasDisponibles();
	Lista<coordenada*>*getPosicionesSoldados();
	Lista<coordenada*>*getPosicionesArmamento();
	void agregarSoldado(coordenada* posicion);
	void agregarArmamento(coordenada* posicion);
};


#endif /* JUGADOR_H_ */
*/
