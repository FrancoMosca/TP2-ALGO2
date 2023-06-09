/*
 * Interfaz.h
 *
 *  Created on: 07/06/2023
 *      Author: algo2
 */

#ifndef INTERFAZ_H_
#define INTERFAZ_H_
#include "EasyBMP.h"
#include "Tablero.h"

void colorSector(int fila, int columna,RGBApixel color,BMP* ubicacion,int totalFilas, int totalColumnas);

void agregarSoldado(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas);

void agregarMina(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas);

void agregarArmamento(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas);

void agregarBarco(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas);

void agregarAvion(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas);

void crearTabla(BMP* ubicacion,int totalFilas, int totalColumnas);

void mostrarCapa(Tablero tablero, int altura, BMP* ubicacion, int jugador);

void mostrarTablero(Tablero tablero, int jugador);
#endif /* INTERFAZ_H_ */
