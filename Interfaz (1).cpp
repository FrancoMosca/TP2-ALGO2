/*
 * Interfaz.cpp
 *
 *  Created on: 07/06/2023
 *      Author: algo2
 */
#include "Interfaz.h"
#include "Ficha.h"
#include "Casillero.h"

void colorSector(int fila, int columna,RGBApixel color,BMP* ubicacion,int totalFilas, int totalColumnas){
	for(int i = 640/totalFilas*fila+1; i < 640/totalFilas*(fila+1);i++){
		for (int j = 430/totalColumnas*columna+1; j< 430/totalColumnas*(columna+1); j++){
			ubicacion->SetPixel(i,j,color);
		}
	}
}

void agregarSoldado(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas){
	RGBApixel  color;
	RGBApixel blanco;
	blanco.Blue = 255;blanco.Green = 255; blanco.Red = 255;
	color.Red =69;color.Green = 36; color.Blue = 29;
	colorSector(fila,columna,color,ubicacion,totalFilas,totalColumnas);
	int iniciox = 640/totalFilas*fila+1 + ((640/totalFilas-4)/2);
	int inicioy = 430/totalColumnas*columna+1 + ((430/totalColumnas-5)/2);
	ubicacion->SetPixel(iniciox+1,inicioy,blanco);
	ubicacion->SetPixel(iniciox+2,inicioy,blanco);
	ubicacion->SetPixel(iniciox+3,inicioy,blanco);
	ubicacion->SetPixel(iniciox,inicioy+1,blanco);
	ubicacion->SetPixel(iniciox+1,inicioy+2,blanco);
	ubicacion->SetPixel(iniciox+2,inicioy+2,blanco);
	ubicacion->SetPixel(iniciox+3,inicioy+3,blanco);
	ubicacion->SetPixel(iniciox,inicioy+4,blanco);
	ubicacion->SetPixel(iniciox+1,inicioy+4,blanco);
	ubicacion->SetPixel(iniciox+2,inicioy+4,blanco);
}

void agregarMina(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas){
	RGBApixel negro;
	negro.Blue = 0;negro.Red = 0;negro.Green = 0;
	int iniciox = 640/totalFilas*fila+1 + ((640/totalFilas-5)/2);
	int inicioy = 430/totalColumnas*columna+1 + ((430/totalColumnas-5)/2);
	for(int j = 0; j<5; j++){
		ubicacion->SetPixel(iniciox,inicioy+j,negro);
		ubicacion->SetPixel(iniciox+4,inicioy+j,negro);
	}
	ubicacion->SetPixel(iniciox+1,inicioy+1,negro);
	ubicacion->SetPixel(iniciox+2,inicioy+2,negro);
	ubicacion->SetPixel(iniciox+3,inicioy+1,negro);
}

void agregarArmamento(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas){
	RGBApixel  color;
	RGBApixel blanco;
	blanco.Red = 255;blanco.Green = 255; blanco.Blue = 255;
	color.Red =69;color.Green = 36; color.Blue = 29;
	colorSector(fila,columna,color,ubicacion,totalFilas,totalColumnas);
	int iniciox = 640/totalFilas*fila+1 + ((640/totalFilas-4)/2);
	int inicioy = 430/totalColumnas*columna+1 + ((430/totalColumnas-5)/2);
	for(int j = 0; j<5; j++){
		ubicacion->SetPixel(iniciox,inicioy+j,blanco);
	}
	for(int j = 1; j<3; j++){
		ubicacion->SetPixel(iniciox+j,inicioy,blanco);
		ubicacion->SetPixel(iniciox+j,inicioy+2,blanco);
	}
	ubicacion->SetPixel(iniciox+3,inicioy+1,blanco);
	ubicacion->SetPixel(iniciox+2,inicioy+3,blanco);
	ubicacion->SetPixel(iniciox+3,inicioy+4,blanco);
}

void agregarBarco(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas){
	RGBApixel  color;
	RGBApixel blanco;
	blanco.Red = 255;blanco.Green = 255; blanco.Blue = 255;
	color.Red =37;color.Green = 109; color.Blue = 123;
	colorSector(fila,columna,color,ubicacion,totalFilas,totalColumnas);
	int iniciox = 640/totalFilas*fila+1 + ((640/totalFilas-4)/2);
	int inicioy = 430/totalColumnas*columna+1 + ((430/totalColumnas-5)/2);
	for(int j = 0; j<5; j++){
		ubicacion->SetPixel(iniciox,inicioy+j,blanco);
	}
	for(int j = 1; j<3; j++){
		ubicacion->SetPixel(iniciox+j,inicioy,blanco);
		ubicacion->SetPixel(iniciox+j,inicioy+2,blanco);
		ubicacion->SetPixel(iniciox+j,inicioy+4,blanco);
	}
	ubicacion->SetPixel(iniciox+3,inicioy+1,blanco);
	ubicacion->SetPixel(iniciox+3,inicioy+3,blanco);
}

void agregarAvion(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas){
	RGBApixel  color;
	RGBApixel blanco;
	blanco.Red = 255;blanco.Green = 255; blanco.Blue = 255;
	color.Red =0;color.Green = 204; color.Blue = 255;
	colorSector(fila,columna,color,ubicacion,totalFilas,totalColumnas);
	int iniciox = 640/totalFilas*fila+1 + ((640/totalFilas-4)/2);
	int inicioy = 430/totalColumnas*columna+1 + ((430/totalColumnas-5)/2);
	for(int j = 0; j<5; j++){
		ubicacion->SetPixel(iniciox,inicioy+j,blanco);
	}
	for(int j = 1; j<3; j++){
		ubicacion->SetPixel(iniciox+j,inicioy,blanco);
		ubicacion->SetPixel(iniciox+j,inicioy+2,blanco);
	}
	ubicacion->SetPixel(iniciox+3,inicioy+1,blanco);
}

void crearTabla(BMP* ubicacion,int totalFilas, int totalColumnas){
	RGBApixel cuadrilla;
	cuadrilla.Blue = 25;
	for (int i =640/totalFilas;i<640;i+= 640/totalFilas){
		for (int j = 0; j<429; j ++)
			ubicacion->SetPixel((int)i,(int)j,cuadrilla);
	}
	for (int j =430/totalColumnas;j<430;j+= 430/totalColumnas){
		for (int i = 0; i<640; i ++)
			ubicacion->SetPixel((int)i,(int)j,cuadrilla);
	}
}

void mostrarCapa(Tablero tablero, int altura, BMP* ubicacion,int jugador){
	int totalFilas = tablero.getFila();
	int totalColumnas = tablero.getColumna();
	int tamano = tablero.getProfundidad();
	if (altura > tablero.getProfundidad()){
		throw "la altura no es valida";
	}
	RGBApixel  agua,tierra,aire,vacio;
	agua.Red =37; agua.Green = 109; agua.Blue = 123;
	tierra.Red =69; tierra.Green = 36; tierra.Blue = 29;
	aire.Red =0; aire.Green = 204; aire.Blue = 255;
	vacio.Red =0; vacio.Green = 0; vacio.Blue = 0;
	ubicacion->SetSize(640,430);
	ubicacion->SetBitDepth(8);
	crearTabla(ubicacion,totalFilas,totalColumnas);
	if(altura < 5){
		for (int i = 0; i < totalFilas; i++){
			for (int j = 0; j < totalColumnas; j++){
				elemento_t elemento = tablero.obtenerCasillero(i,j,altura)->getFicha()->getElementoFicha2();
				int jugadores = tablero.obtenerCasillero(i,j,altura)->getFicha()->getJugador();
				if (elemento == SOLDADO) {
					if(jugadores != jugador || jugadores!= 0){
						colorSector(i,j,tierra,ubicacion,totalFilas,totalColumnas);
					}else{
					agregarSoldado(i,j,ubicacion,totalFilas,totalColumnas);
					}
				} else if (elemento == MINA){
					if(jugadores != jugador || jugadores!= 0){
						colorSector(i,j,tierra,ubicacion,totalFilas,totalColumnas);
					}else{
					agregarMina(i,j,ubicacion,totalFilas,totalColumnas);
					}
				} else if (elemento == ARMAMENTO){
					if(jugadores != jugador || jugadores!= 0){
						colorSector(i,j,tierra,ubicacion,totalFilas,totalColumnas);
					}else{
					agregarArmamento(i,j,ubicacion,totalFilas,totalColumnas);
					}
				}else if (elemento == BARCO){
					if(jugadores != jugador || jugadores!= 0){
						colorSector(i,j,agua,ubicacion,totalFilas,totalColumnas);
					}else{
					agregarBarco(i,j,ubicacion,totalFilas,totalColumnas);
					}
				}else if (elemento == AGUA) {
					colorSector(i,j,agua,ubicacion,totalFilas,totalColumnas);
				} else if (elemento == TIERRA) {
					colorSector(i,j,tierra,ubicacion,totalFilas,totalColumnas);
				} else if (elemento == VACIO) {
					colorSector(i,j,vacio,ubicacion,totalFilas,totalColumnas);
				}
			}
		}
	}else{
		for (int i = 0; i < totalFilas; i++){
			for (int j = 0; j < totalColumnas; j++){
				colorSector(i,j,aire,ubicacion,totalFilas,totalColumnas);
				for (int k = 5; k < tamano; k++){
					elemento_t elemento = tablero.obtenerCasillero(i,j,k)->getFicha()->getElementoFicha2();
					int jugadores = tablero.obtenerCasillero(i,j,k)->getFicha()->getJugador();
					if (elemento == AVION){
						if(jugadores != jugador || jugadores!= 0){
							colorSector(i,j,aire,ubicacion,totalFilas,totalColumnas);
						}else{
						agregarAvion(i,j,ubicacion,totalFilas,totalColumnas);
						}
					}
				}
			}
		}
	}
}

void mostrarTablero(Tablero tablero, int jugador){
	int tamano = tablero.getProfundidad();
	BMP capa_1;
	mostrarCapa(tablero, 0, &capa_1,jugador);
	capa_1.WriteToFile("primerNivel");
	if (tamano>1){
		BMP capa_2;
		mostrarCapa(tablero, 1, &capa_2,jugador);
		capa_2.WriteToFile("segundoNivel");
	}
	if (tamano>2){
		BMP capa_3;
		mostrarCapa(tablero, 2, &capa_3,jugador);
		capa_3.WriteToFile("tercerNivel");
	}
	if (tamano>3){
		BMP capa_4;
		mostrarCapa(tablero, 3, &capa_4,jugador);
		capa_4.WriteToFile("cuartoNivel");
	}
	if (tamano>4){
		BMP capa_5;
		mostrarCapa(tablero, 4, &capa_5,jugador);
		capa_5.WriteToFile("quintoNivel");
	}
	if(tamano>5){
	BMP capa_cielo;
	mostrarCapa(tablero, 6, &capa_cielo,jugador);
	capa_cielo.WriteToFile("cielo");
	}
}


