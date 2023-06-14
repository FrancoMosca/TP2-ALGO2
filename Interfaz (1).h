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

//Pre: -
//Post: dentro de la imagen "ubicacion" se pinta de "color" la celda representada por la posicion "fila" x "columna" de un tablero cuyas dimensiones son "totalfilas" x "totalColumnas" 
void colorSector(int fila, int columna,RGBApixel color,BMP* ubicacion,int totalFilas, int totalColumnas);
//Pre: - 
//Post: dentro de la imagen "ubicacion" se colorea de tal forma que se distinga una S en la celda representada por la posicion "fila" x "columna" de un tablero cuyas dimensiones son "totalfilas" x "totalColumnas" 
void agregarSoldado(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas);
//Pre: -
//Post: dentro de la imagen "ubicacion" se colorea de tal forma que se distinga una M en la celda representada por la posicion "fila" x "columna" de un tablero cuyas dimensiones son "totalfilas" x "totalColumnas" 
void agregarMina(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas);
//Pre: -
//Post: dentro de la imagen "ubicacion" se colorea de tal forma que se distinga una B en la celda representada por la posicion "fila" x "columna" de un tablero cuyas dimensiones son "totalfilas" x "totalColumnas" 
void agregarBarco(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas);
//Pre: -
//Post: dentro de la imagen "ubicacion" se colorea de tal forma que se distinga una A en la celda representada por la posicion "fila" x "columna" de un tablero cuyas dimensiones son "totalfilas" x "totalColumnas" 
void agregarAvion(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas);
//Pre: -
//Post: se colorea la imagen "ubicacion" buscando que se grafique un tablero cuyas dimensiones sean "totalfilas" x "totalColumnas" 
void crearTabla(BMP* ubicacion,int totalFilas, int totalColumnas);
//Pre: recibe como parametro el tablero que se busca representar junto con la ubicacion donse se representara , el nivel de profudidad que se quiere repesentar y el jugador al que se lo quiere mostrar
//Post: se colorea la imagen "ubicacion" de tal forma que sean visibles las fichas ubicadas en el nievel "altura" de profundidad que estan asociadas al jugador "jugador"
void mostrarCapa(Tablero* tablero, int altura, BMP* ubicacion, int jugador);
//Pre: recibe como parametro el tablero que se busca representar  y el jugador al que se lo quiere mostrar
//Post: se crean 6 imagenes en formato .BNP donde cada una de ellas representara un nivel de profundidad diferente
void mostrarTablero(Tablero* tablero, int jugador);
#endif /* INTERFAZ_H_ */
