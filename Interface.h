#ifndef INTERFACE_H_
#define INTERFACE_H_
#include "EasyBMP.h"
#include "Tablero.h"

//Pre: recibe un caracter "inicial" que repesenta el color que se quiere pintar y un entero que representa la oscuridad del color (1 o 2)
//Post: retorna un tipo de dato RGBApixel que representa un color
RGBApixel crearColor(char inicial, int numero);

//Pre: -
//Post: genera la imagen de un soldado
void agregarSoldado(int fila, int columna,BMP* ubicacion,int totalFilas, int totalColumnas);

//Pre: -
//Post: genera la imagen de una mina
void agregarMina(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas);

//Pre: -
//Post: genera la imagen de un barco
void agregarBarco(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas);

//Pre: -
//Post: genera la imagen de un casillero inactivo
void colorSector(int fila, int columna,BMP* ubicacion,int totalFilas, int totalColumnas);

//Pre: -
//Post: genera la imagen de un avion
void agregarAvion(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas);

//Pre: -
//Post: genera la imagen de un casillero de tierra
void agregarTierra(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas);

//Pre: -
//Post: genera la imagen de un casillero de agua
void agregarAgua(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas);

//Pre: -
//Post: genera la imagen de un casillero de cielo
void agregarCielo(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas);

//Pre: -
//Post: se genera la imagen para el tablero en la profundidad "altura"
void mostrarCapa(Tablero *tablero, int altura, BMP* ubicacion, int jugador);

//Pre: -
//Post: se genera una imagen por piso del tablero
void mostrarTablero(Tablero* tablero, int jugador);

#endif /* INTERFACE_H_ */
