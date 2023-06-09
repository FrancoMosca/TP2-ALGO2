/*
 * ficha.h
 *
 *  Created on: 05/05/2023
 *      Author: algo2
 */

#ifndef FICHA_H_
#define FICHA_H_


typedef enum {
    SOLDADO,
	ARMAMENTO,
    MINA,
    BARCO,
    AVION,
    VACIO,
    TIERRA,
    AGUA,
    AIRE,
} elemento_t;

class Ficha {
private:
    char elementoF;
    bool estaBloqueada;
    int turnosRestantesParaDesbloqueo;
    elemento_t elemento;
    int jugador;
    int posicion [3];
public:
    Ficha(elemento_t elementoFicha,int jugador,int posicion[3]);
    Ficha(elemento_t elementoFicha,int posicion[3]);
    char getElementoFicha();
    elemento_t getElementoFicha2();
	~Ficha();
	int getJugador();
	bool getBloqueada();
	void aumentarContador();
	void bloquear(int turnos);
	void cambiarElemento(elemento_t nuevoElemento);
	void getPosicion(int(*posicion)[3]);
};


#endif /* FICHA_H_ */
