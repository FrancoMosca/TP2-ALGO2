#include "Interface.h"

#include "Ficha.h"
#include "Casillero.h"
#include "Interface.h"

using namespace std;
RGBApixel crearColor(char inicial, int numero){
	RGBApixel colorFinal;
	if (inicial == 't'){
		if(numero == 1){
			colorFinal.Red = 198 ; colorFinal.Green = 153 ; colorFinal.Blue = 85;
		}else{
			colorFinal.Red = 103 ; colorFinal.Green = 75 ; colorFinal.Blue = 35;
		}
	}
	if (inicial == 'c'){
		colorFinal.Red = 153 ; colorFinal.Green = 217 ; colorFinal.Blue = 234;
	}
	if (inicial == 'a'){
		if(numero == 1){
			colorFinal.Red = 63 ; colorFinal.Green = 72 ; colorFinal.Blue = 204;
		}else{
			colorFinal.Red = 4 ; colorFinal.Green = 18 ; colorFinal.Blue = 142;
		}
	}
	if (inicial == 'v'){
		if(numero == 1){
			colorFinal.Red = 27 ; colorFinal.Green = 139 ; colorFinal.Blue = 61;
		}else{
			colorFinal.Red = 15 ; colorFinal.Green = 77 ; colorFinal.Blue = 33;
		}
	}
	if (inicial == 'b'){
		colorFinal.Red = 255 ; colorFinal.Green = 255 ; colorFinal.Blue = 255;
	}
	if (inicial == 'r'){
		colorFinal.Red = 237 ; colorFinal.Green = 28 ; colorFinal.Blue = 36;
	}
	if (inicial == 'n'){
		colorFinal.Red = 0 ; colorFinal.Green = 0 ; colorFinal.Blue = 0;
	}
	if (inicial == 'p'){
		colorFinal.Red = 249 ; colorFinal.Green = 200 ; colorFinal.Blue = 134;
	}
	return colorFinal;
}

//imagenes para las entidades del tablero (ocupan un espacio de 15 x 15 pixeles)
void agregarSoldado(int fila, int columna,BMP* ubicacion,int totalFilas, int totalColumnas){
	int columnaI = totalColumnas*15 - 15*(totalColumnas-columna+1) ;
	int columnaF = columnaI + 15 ;
	int filaI = totalFilas*15 - 15*(totalFilas-fila+1) ;
	int filaF = filaI + 15 ;
	for(int i = columnaI; i < columnaF; i++){
		for(int j= filaI; j < filaF; j++){
			ubicacion->SetPixel(i,j,crearColor('t',1));
		}
	}
	for(int i = columnaI; i < columnaF; i++){
		ubicacion->SetPixel(i,filaI,crearColor('n',1));
		ubicacion->SetPixel(i,filaF - 1,crearColor('n',1));
	}
	for(int j= filaI; j < filaF; j++){
		ubicacion->SetPixel(columnaI,j,crearColor('n',1));
		ubicacion->SetPixel(columnaF-1,j,crearColor('n',1));
	}
	for(int i = columnaI+5; i < columnaI+10; i++){
			ubicacion->SetPixel(i,filaI+3,crearColor('n',1));
	}
	for(int i = columnaI+2; i < columnaI+13; i++){
			ubicacion->SetPixel(i,filaI+7,crearColor('n',1));
	}
	for(int i = columnaI+6; i < columnaI+9; i++){
			ubicacion->SetPixel(i,filaI+12,crearColor('n',1));
	}
	for(int i = filaI+4; i < filaI+11; i++){
			ubicacion->SetPixel(columnaI+4,i,crearColor('n',1));
			ubicacion->SetPixel(columnaI+10,i,crearColor('n',1));
	}
	for(int i = columnaI+5; i < columnaI+10; i++){
		for(int j = filaI+8; j < filaI+12; j++){
			ubicacion->SetPixel(i,j,crearColor('p',1));
		}
	}
	ubicacion->SetPixel(columnaI+3,filaI+6,crearColor('n',1));
	ubicacion->SetPixel(columnaI+5,filaI+11,crearColor('n',1));
	ubicacion->SetPixel(columnaI+11,filaI+6,crearColor('n',1));
	ubicacion->SetPixel(columnaI+9,filaI+11,crearColor('n',1));
	ubicacion->SetPixel(columnaI+6,filaI+9,crearColor('n',1));
	ubicacion->SetPixel(columnaI+8,filaI+9,crearColor('n',1));
	for(int i = filaI+4; i < filaI+7; i=i+2){
		for(int j = columnaI+5; j < columnaI+10; j=j+2){
			ubicacion->SetPixel(j,i,crearColor('v',1));
		}
	}
	for(int i = filaI+4; i < filaI+7; i++){
		ubicacion->SetPixel(columnaI+6,i,crearColor('v',2));
		ubicacion->SetPixel(columnaI+8,i,crearColor('v',2));
	}
	for(int i = columnaI+5; i < columnaI+10; i++){
			ubicacion->SetPixel(i,filaI+5,crearColor('v',2));
	}
	ubicacion->SetPixel(columnaI+4,filaI+6,crearColor('v',2));
	ubicacion->SetPixel(columnaI+10,filaI+6,crearColor('v',2));
}

void agregarMina(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas){
	int columnaI = totalColumnas*15 - 15*(totalColumnas-columna+1) ;
	int columnaF = columnaI + 15 ;
	int filaI = totalFilas*15 - 15*(totalFilas-fila+1) ;
	int filaF = filaI + 15 ;
	for(int i = columnaI; i < columnaF; i++){
		for(int j= filaI; j < filaF; j++){
			ubicacion->SetPixel(i,j,crearColor('t',1));
		}
	}
	for(int i = columnaI; i < columnaF; i++){
		ubicacion->SetPixel(i,filaI,crearColor('n',1));
		ubicacion->SetPixel(i,filaF - 1,crearColor('n',1));
	}
	for(int j= filaI; j < filaF; j++){
		ubicacion->SetPixel(columnaI,j,crearColor('n',1));
		ubicacion->SetPixel(columnaF-1,j,crearColor('n',1));
	}
	for(int i = filaI+7; i < filaI+10; i++){
		for(int j = columnaI+3; j < columnaI+12; j++){
			ubicacion->SetPixel(j,i,crearColor('n',1));
		}
	}
	for(int j = columnaI+5; j < columnaI+10; j++){
		ubicacion->SetPixel(j,filaI+5,crearColor('n',1));
		ubicacion->SetPixel(j,filaI+11,crearColor('n',1));
	}
	for(int j = columnaI+4; j < columnaI+11; j++){
		ubicacion->SetPixel(j,filaI+6,crearColor('n',1));
		ubicacion->SetPixel(j,filaI+10,crearColor('n',1));
	}
	ubicacion->SetPixel(columnaI+8,filaI+3,crearColor('n',1));
	ubicacion->SetPixel(columnaI+7,filaI+4,crearColor('n',1));
	ubicacion->SetPixel(columnaI+8,filaI+2,crearColor('r',1));
	ubicacion->SetPixel(columnaI+9,filaI+3,crearColor('r',1));
}

void agregarBarco(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas){
	int columnaI = totalColumnas*15 - 15*(totalColumnas-columna+1) ;
	int columnaF = columnaI + 15 ;
	int filaI = totalFilas*15 - 15*(totalFilas-fila+1) ;
	int filaF = filaI + 15 ;
	for(int i = columnaI; i < columnaF; i++){
		for(int j= filaI; j < filaI+9; j++){
			ubicacion->SetPixel(i,j,crearColor('c',1));
		}
	}
	for(int i = columnaI; i < columnaF; i++){
		for(int j= filaI+9; j < filaF; j++){
			ubicacion->SetPixel(i,j,crearColor('a',2));
		}
	}
	for(int i = columnaI; i < columnaF; i++){
		ubicacion->SetPixel(i,filaI,crearColor('n',1));
		ubicacion->SetPixel(i,filaF - 1,crearColor('n',1));
	}
	for(int j= filaI; j < filaF; j++){
		ubicacion->SetPixel(columnaI,j,crearColor('n',1));
		ubicacion->SetPixel(columnaF-1,j,crearColor('n',1));
	}
	for(int i = columnaI+2; i < columnaI+13; i++){
		ubicacion->SetPixel(i,filaI+8,crearColor('n',1));
		ubicacion->SetPixel(i,filaI+9,crearColor('t',1));
	}
	for(int i = columnaI+4; i < columnaI+11; i++){
		ubicacion->SetPixel(i,filaI+11,crearColor('n',1));
		ubicacion->SetPixel(i,filaI+10,crearColor('t',1));
	}
	ubicacion->SetPixel(columnaI+2,filaI+9,crearColor('n',1));
	ubicacion->SetPixel(columnaI+12,filaI+9,crearColor('n',1));
	ubicacion->SetPixel(columnaI+3,filaI+10,crearColor('n',1));
	ubicacion->SetPixel(columnaI+11,filaI+10,crearColor('n',1));
	ubicacion->SetPixel(columnaI+6,filaI+3,crearColor('n',1));
	ubicacion->SetPixel(columnaI+5,filaI+4,crearColor('n',1));
	ubicacion->SetPixel(columnaI+6,filaI+5,crearColor('n',1));
	ubicacion->SetPixel(columnaI+6,filaI+4,crearColor('t',1));
	for(int j= filaI+2; j < filaI+8; j++){
		ubicacion->SetPixel(columnaI+7,j,crearColor('n',1));
	}
}

void colorSector(int fila, int columna,BMP* ubicacion,int totalFilas, int totalColumnas){
	int columnaI = totalColumnas*15 - 15*(totalColumnas-columna+1) ;
	int columnaF = columnaI + 15 ;
	int filaI = totalFilas*15 - 15*(totalFilas-fila+1) ;
	int filaF = filaI + 15 ;
	for(int i = columnaI; i < columnaF; i++){
		for(int j= filaI; j < filaF; j++){
			ubicacion->SetPixel(i,j,crearColor('n',1));
		}
	}
}

void agregarAvion(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas){
	int columnaI = totalColumnas*15 - 15*(totalColumnas-columna+1) ;
	int columnaF = columnaI + 15 ;
	int filaI = totalFilas*15 - 15*(totalFilas-fila+1) ;
	int filaF = filaI + 15 ;
	for(int i = columnaI; i < columnaF; i++){
		for(int j= filaI; j < filaF; j++){
			ubicacion->SetPixel(i,j,crearColor('c',1));
		}
	}
	for(int i = columnaI; i < columnaF; i++){
		ubicacion->SetPixel(i,filaI,crearColor('n',1));
		ubicacion->SetPixel(i,filaF - 1,crearColor('n',1));
	}
	for(int j= filaI; j < filaF; j++){
		ubicacion->SetPixel(columnaI,j,crearColor('n',1));
		ubicacion->SetPixel(columnaF-1,j,crearColor('n',1));
	}
	for(int i = columnaI+4; i < columnaI+7; i++){
		ubicacion->SetPixel(i,filaI+2,crearColor('n',1));
		ubicacion->SetPixel(i,filaI+11,crearColor('n',1));
	}
	for(int i = columnaI+5; i < columnaI+8; i++){
		ubicacion->SetPixel(i,filaI+3,crearColor('n',1));
		ubicacion->SetPixel(i,filaI+10,crearColor('n',1));
	}
	for(int i = columnaI+6; i < columnaI+9; i++){
		ubicacion->SetPixel(i,filaI+4,crearColor('n',1));
		ubicacion->SetPixel(i,filaI+9,crearColor('n',1));
	}
	for(int i = columnaI+7; i < columnaI+12; i++){
		ubicacion->SetPixel(i,filaI+5,crearColor('n',1));
		ubicacion->SetPixel(i,filaI+8,crearColor('n',1));
	}
	for(int i = columnaI+2; i < columnaI+4; i++){
		ubicacion->SetPixel(i,filaI+4,crearColor('n',1));
		ubicacion->SetPixel(i,filaI+9,crearColor('n',1));
	}
	for(int i = columnaI+2; i < columnaI+5; i++){
		ubicacion->SetPixel(i,filaI+5,crearColor('n',1));
		ubicacion->SetPixel(i,filaI+8,crearColor('n',1));
	}
	for(int i = columnaI+3; i < columnaI+13; i++){
		ubicacion->SetPixel(i,filaI+6,crearColor('n',1));
		ubicacion->SetPixel(i,filaI+7,crearColor('n',1));
	}

}

void agregarTierra(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas){
	int columnaI = totalColumnas*15 - 15*(totalColumnas-columna+1) ;
	int columnaF = columnaI + 15 ;
	int filaI = totalFilas*15 - 15*(totalFilas-fila+1) ;
	int filaF = filaI + 15 ;
	for(int i = columnaI; i < columnaF; i++){
		for(int j= filaI; j < filaF; j++){
			ubicacion->SetPixel(i,j,crearColor('t',1));
		}
	}
	for(int i = columnaI; i < columnaF; i++){
		for(int j= filaI; j < filaF; j=j+2){
			ubicacion->SetPixel(i,j,crearColor('t',2));
		}
	}
	for(int i = columnaI; i < columnaF; i++){
		ubicacion->SetPixel(i,filaI,crearColor('n',1));
		ubicacion->SetPixel(i,filaF - 1,crearColor('n',1));
	}
	for(int j= filaI; j < filaF; j++){
		ubicacion->SetPixel(columnaI,j,crearColor('n',1));
		ubicacion->SetPixel(columnaF-1,j,crearColor('n',1));
	}

}

void agregarAgua(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas){
	int columnaI = totalColumnas*15 - 15*(totalColumnas-columna+1) ;
	int columnaF = columnaI + 15 ;
	int filaI = totalFilas*15 - 15*(totalFilas-fila+1) ;
	int filaF = filaI + 15 ;
	for(int i = columnaI; i < columnaF; i++){
		for(int j= filaI; j < filaF; j++){
			ubicacion->SetPixel(i,j,crearColor('a',2));
		}
	}
	for(int i = columnaI; i < columnaF; i++){
		for(int j= filaI+10; j < filaI+13; j++){
			ubicacion->SetPixel(i,j,crearColor('a',1));
		}
	}
	for(int i = columnaI; i < columnaF; i++){
		ubicacion->SetPixel(i,filaI,crearColor('n',1));
		ubicacion->SetPixel(i,filaF - 1,crearColor('n',1));
	}
	for(int j= filaI; j < filaF; j++){
		ubicacion->SetPixel(columnaI,j,crearColor('n',1));
		ubicacion->SetPixel(columnaF-1,j,crearColor('n',1));
	}
	for(int k = 0; k<9; k= k+7){
		for(int i = columnaI+2; i < columnaI+5; i++){
			ubicacion->SetPixel(i+k,filaI+9,crearColor('a',1));
		}
		for(int i = columnaI+2; i < columnaI+4; i++){
			ubicacion->SetPixel(i+k,filaI+8,crearColor('a',1));
		}
		for(int i = columnaI+3; i < columnaI+7; i++){
			ubicacion->SetPixel(i+k,filaI+7,crearColor('a',1));
			ubicacion->SetPixel(i+k,filaI+6,crearColor('a',1));
		}
		for(int i = columnaI+4; i < columnaI+6; i++){
			ubicacion->SetPixel(i+k,filaI+1,crearColor('a',1));
			ubicacion->SetPixel(i+k,filaI+5,crearColor('a',1));
		}
		for(int i = columnaI+3; i < columnaI+6; i++){
			ubicacion->SetPixel(i+k,filaI+2,crearColor('a',1));
		}
		for(int i = columnaI; i < columnaI+3; i++){
			ubicacion->SetPixel(i+k,filaI+3,crearColor('a',1));
		}
		ubicacion->SetPixel(columnaI+6+k,filaI+3,crearColor('a',1));
		ubicacion->SetPixel(columnaI+6+k,filaI+8,crearColor('a',1));
	}
}

void agregarCielo(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas){
	int columnaI = totalColumnas*15 - 15*(totalColumnas-columna+1) ;
	int columnaF = columnaI + 15 ;
	int filaI = totalFilas*15 - 15*(totalFilas-fila+1) ;
	int filaF = filaI + 15 ;
	for(int i = columnaI; i < columnaF; i++){
		for(int j= filaI; j < filaF; j++){
			ubicacion->SetPixel(i,j,crearColor('c',1));
		}
	}
	for(int k = 0; k<15; k = k+9){
		for(int i = columnaI+2; i < columnaI+5; i++){
			ubicacion->SetPixel(i+k,filaI+1,crearColor('b',1));
			ubicacion->SetPixel(i+k,filaI+3,crearColor('b',1));
			ubicacion->SetPixel(i+k,filaI+10,crearColor('b',1));
			ubicacion->SetPixel(i+k,filaI+12,crearColor('b',1));
		}
	}
	for(int k = 0; k<15; k = k+9){
			for(int i = columnaI; i < columnaI+6; i++){
				ubicacion->SetPixel(i+k,filaI+2,crearColor('b',1));
				ubicacion->SetPixel(i+k,filaI+11,crearColor('b',1));
			}
	}
	for(int i = columnaI; i < columnaF; i++){
		ubicacion->SetPixel(i,filaI,crearColor('n',1));
		ubicacion->SetPixel(i,filaF - 1,crearColor('n',1));
	}
	for(int j= filaI; j < filaF; j++){
		ubicacion->SetPixel(columnaI,j,crearColor('n',1));
		ubicacion->SetPixel(columnaF-1,j,crearColor('n',1));
	}
	for(int i = columnaI+6; i < columnaI+10; i++){
		ubicacion->SetPixel(i,filaI+6,crearColor('b',1));
		ubicacion->SetPixel(i,filaI+8,crearColor('b',1));
	}
	for(int i = columnaI+5; i < columnaI+11; i++){
		ubicacion->SetPixel(i,filaI+7,crearColor('b',1));
	}
}


void mostrarCapa(Tablero *tablero, int altura, BMP* ubicacion,int jugador){
	int totalFilas = tablero->getFila();
	int totalColumnas = tablero->getColumna();
	int tamano = tablero->getProfundidad();
	if (altura > tamano){
		throw "la altura no es valida";
	}
	ubicacion->SetSize(15*totalFilas,15*totalColumnas);
	ubicacion->SetBitDepth(8);
	if(altura < 6){
			for (int i = 1; i < totalFilas+1; i++){
				for (int j = 1; j < totalColumnas+1; j++){
					char elemento = tablero->obtenerCasillero(i,j,altura)->getFicha()->getElementoFicha();
					int jugadores = tablero->obtenerCasillero(i,j,altura)->getFicha()->getIdJugador();
					terreno_t terreno = tablero->obtenerCasillero(i,j,altura)->getTerreno();
					if (elemento == SOLDADO) {
						if(jugadores != jugador && jugadores!= 0){
							agregarTierra(i,j,ubicacion,totalFilas,totalColumnas);
						}else{
							agregarSoldado(i,j,ubicacion,totalFilas,totalColumnas);
						}
					} else if (elemento == MINA){
						if(jugadores != jugador && jugadores!= 0){
							agregarTierra(i,j,ubicacion,totalFilas,totalColumnas);
						}else{
							agregarMina(i,j,ubicacion,totalFilas,totalColumnas);
						}
					}else if (elemento == BARCO){
						if(jugadores != jugador && jugadores!= 0){
							agregarAgua(i,j,ubicacion,totalFilas,totalColumnas);
						}else{
							agregarBarco(i,j,ubicacion,totalFilas,totalColumnas);
						}
					}else if (terreno == AGUA) {
						agregarAgua(i,j,ubicacion,totalFilas,totalColumnas);
					} else if (terreno == TIERRA) {
						agregarTierra(i,j,ubicacion,totalFilas,totalColumnas);
					} else if (elemento == VACIO) {
						colorSector(i,j,ubicacion,totalFilas,totalColumnas);
					}
				}
			}
		}else{
			for (int i = 1; i < totalFilas+1; i++){
				for (int j = 1; j < totalColumnas+1; j++){
					char elemento = tablero->obtenerCasillero(i,j,altura)->getFicha()->getElementoFicha();
					int jugadores = tablero->obtenerCasillero(i,j,altura)->getFicha()->getIdJugador();
					agregarCielo(i,j,ubicacion,totalFilas,totalColumnas);
					if (elemento == AVION){
						if(jugadores != jugador && jugadores!= 0){
							agregarCielo(i,j,ubicacion,totalFilas,totalColumnas);
						}else{
							agregarAvion(i,j,ubicacion,totalFilas,totalColumnas);
						}
					}
				}
			}
		}
}

void mostrarTablero(Tablero *tablero, int jugador){
	int tamano = tablero->getProfundidad();
	for (int i = 1; i < tamano+1; i++){
		BMP ubicacion;
		mostrarCapa(tablero, i, &ubicacion,jugador);
		char nombre[11] = {0};
		if(i<10){
			char nombre2 [11]= {'p','i','s','o',' ',' ',(char)(i+48)};
			for(int j = 0; j < 11; j++){
				nombre[j] = nombre2[j];
			}
		} else {
			char nombre2 [11]= {'p','i','s','o',' ',' ',(char)((int)(i/10)+48),(char)(i-10+48)};
			for(int j = 0; j < 11; j++){
				nombre[j] = nombre2[j];
			}
		}
		ubicacion.WriteToFile(nombre);
	}
}


