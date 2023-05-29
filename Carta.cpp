#include "Carta.h"
#include <iostream>
#include <cstdlib> // Para la generación de números aleatorios
#include <ctime> // Para inicializar la semilla aleatoria
using namespace std;


Carta::Carta(int _x,int _y, int _z,bool _activo,int _contador, int _radio, string _tipo){
    x=_x;
    y=_y;
    z=_z;
    activo=_activo;
    contador=_contador;
    radio=_radio;
    tipo=_tipo;
}

static std::string obtenerTipoCartaAleatorio(){
    std::string tipos[] = {"Avion", "Barco", "AtaqueQuimico", "Granada", "AtaqueMultiple", "Escudo"};
    int numTipos = sizeof(tipos) / sizeof(tipos[0]);

    // Inicializar la semilla aleatoria
    std::srand(static_cast<unsigned int>(time(nullptr)));

    // Generar un índice aleatorio dentro del rango de tipos
    int indice = std::rand() % numTipos;

    // Devolver el tipo de carta correspondiente al índice generado
    return tipos[indice];
}

void Carta::obtenerRango(string tipo){

    if(tipo == "ataqueQuimico"){
        radio=5;
    };

    if((tipo == "Avion") || (tipo =="Granada")){
        radio=3;
    };

    if(tipo == "Barco"){
        radio=2;
    };

    if(tipo == "ataqueMultiple"){
        radio=4;
    }
}

void Carta::detectarMinas(Tablero *tablero) {
    int filaTablero = tablero->getFila();
    int columnaTablero = tablero->getColumna();
    int profundidadTablero = tablero->getProfundidad();

    for (int fila = 0; fila < filaTablero; fila++) {
         for (int columna = 0; columna < columnaTablero; columna++) {
             for (int profundidad = 0; profundidad < profundidadTablero; profundidad++) {
                 Casillero* casillero = tablero->obtenerCasillero(fila, columna, profundidad);
                 if (casillero->getFicha() && casillero->getFicha()->getElementoFicha() == MINA) {
//                     mina->aumentarContador();
                 }
             }
         }
    }
}


