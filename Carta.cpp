#include "Carta.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Jugador.h"
#include "Tablero.h"
using namespace std;

Carta::Carta() {
    this->habilidadCarta = CARTA_SIN_EFECTO;
}

Carta::Carta(habilidadCarta_t efecto) {
    this->habilidadCarta = efecto;
}

habilidadCarta_t Carta::generarEfectoAleatorio() {

    int efectoRandom = (rand() % 6) + 1;
    return (habilidadCarta_t) efectoRandom;
}

void Carta::setHabilidad(habilidadCarta_t efecto) {
    this->habilidadCarta = efecto;
}

habilidadCarta_t Carta::getHabilidad() {
    return this->habilidadCarta;
}

Carta::~Carta() {

}

void Carta::imprimirHabilidadCarta() {
    switch (this->habilidadCarta) {
        case 0:
            std::cout << "CARTA SIN EFECTO " << std::endl;
            break;
        case 1:
            std::cout << "CARTA AVION RADAR " << std::endl;
            break;

        case 2:
            std::cout << "CARTA DISPARAR MISIL" << std::endl;
            break;

        case 3:
            std::cout << "CARTA ATAQUE QUIMICO " << std::endl;
            break;

        case 4:
            std::cout << "CARTA VOLVER JUGADA " << std::endl;
            break;

        case 5:
            std::cout << "CARTA ELIMINAR CARTA" << std::endl;
            break;

        case 6:
            std::cout << "CARTA ROBAR  " << std::endl;
            break;
        default:
            break;
    }
}

void Carta::obtenerRango() {

}

void Carta::avionRadar(Tablero *tablero, int idJugador) {
    bool poseeAvion = false;
    int i = 1;
    while (i <= tablero->getFila() && !poseeAvion) {
        int j = 1;
        while (j <= tablero->getColumna() && !poseeAvion) {
            int k = 1;
            while (k <= tablero->getProfundidad() && !poseeAvion) {
                int id = tablero->obtenerCasillero(i, j, k)->getFicha()->getIdJugador();
                if (tablero->obtenerCasillero(i, j, k)->getFicha()->getElementoFicha() == 'A' && id == idJugador) {
                    poseeAvion = true;
                }
                k++;
            }
            j++;
        }
        i++;
    }
    if (poseeAvion) {
        for (int i = 1; i <= tablero->getFila(); i++) {
            for (int j = 1; j <= tablero->getColumna(); j++) {
                for (int k = 1; k <= tablero->getProfundidad(); k++) {
                    int id = tablero->obtenerCasillero(i,j,k)->getFicha()->getIdJugador();
                    if((tablero->obtenerCasillero(i,j,k)->getFicha()->getElementoFicha() == 'M') && id != idJugador){
                        cout << "Mina en posicion: " << '[' << i << ']' << '[' << j << ']' << '[' << k << ']' << endl;
                    }
                }
            }
        }
    }
    else{
        cout << "Al no tener Avion no puedes la carta de Radar, por lo que perdiste la carta" << endl;
    }
}

void Carta::dispararMisil(Tablero *tablero, int idJugador) {

    bool poseeBarco = false;
    int i = 1;
    while (i <= tablero->getFila() && !poseeBarco) {
        int j = 1;
        while (j <= tablero->getColumna() && !poseeBarco) {
            int k = 1;
            while (k <= tablero->getProfundidad() && !poseeBarco) {
                int id = tablero->obtenerCasillero(i, j, k)->getFicha()->getIdJugador();
                if (tablero->obtenerCasillero(i, j, k)->getFicha()->getElementoFicha() == 'B' && id == idJugador) {
                    poseeBarco = true;
                }
                k++;
            }
            j++;
        }
        i++;
    }
    if(poseeBarco){
        int fila, columna, profundidad;
        solicitarIngresoDeCordenadas(fila, columna, profundidad);
        while (!(esFichaValida(tablero,fila, columna, profundidad))) {
            solicitarIngresoDeCordenadas(fila, columna, profundidad);
        }
        tablero->obtenerCasillero(fila,columna,profundidad)->getFicha()->bloquear(3);
    }
    else{
        cout << "Al no tener Barcos no puedes la carta de misil, por lo que perdiste la carta" << endl;
    }

}

void Carta::ataqueQuimico(Tablero *tablero) {
    int fila, columna, profundidad;
    solicitarIngresoDeCordenadas(fila, columna, profundidad);
    while (!(esFichaValida(tablero, fila, columna, profundidad))) {
        solicitarIngresoDeCordenadas(fila, columna, profundidad);
    }
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            for (int k = -2; k <= 2; k++) {
                int nuevaFila = fila + i;
                int nuevaColumna = columna + j;
                int nuevaProfundidad = profundidad + k;

                if (this->estaDentroDeTablero(tablero,nuevaFila,nuevaColumna,nuevaProfundidad)) {
                    if (nuevaFila == fila && nuevaColumna == columna && nuevaProfundidad == profundidad) {
                        tablero->obtenerCasillero(nuevaFila, nuevaColumna, nuevaProfundidad)->getFicha()->bloquear(10);
                    }
                    else if ((nuevaFila < fila-1 || nuevaFila > fila+1) ||
                             (nuevaColumna < columna-1 || nuevaColumna > columna+1) ||
                             (nuevaProfundidad < profundidad-1 || nuevaProfundidad > profundidad+1)) {
                        tablero->obtenerCasillero(nuevaFila, nuevaColumna, nuevaProfundidad)->getFicha()->bloquear(8);
                        }
                         else {
                            tablero->obtenerCasillero(nuevaFila, nuevaColumna, nuevaProfundidad)->getFicha()->bloquear(6);
                         }
                }
            }
        }
    }
}

void Carta::desarmarSoldados() {

}

void Carta::ataqueMultiple() {

}

void Carta::aumentarResistencia() {

}






void Carta::solicitarIngresoDeCordenadas(int &filas, int &columnas, int &profundidad) {
    cout << "Ingrese una fila :" << endl;
    cin >> filas;
    cout << "Ingrese una columna :" << endl;
    cin >> columnas;
    cout << "Ingrese una profundidad : " << endl;
    cin >> profundidad;
}

bool Carta::estaEnRangoValido(Tablero *tablero, int &fila, int &columna, int &profundidad) {
    int maxFilas = tablero->getFila();
    int maxColumnas = tablero->getColumna();
    int maxProfundidad = tablero->getProfundidad();
    if (fila < 1 || fila > maxFilas || columna < 1 || columna > maxColumnas || profundidad < 1 ||
        profundidad > maxProfundidad) {
        return false;
    }
    return true;
}

bool Carta::esFichaValida(Tablero *tablero, int &fila, int &columna, int &profundidad) {
    bool esValido = true;
    if (!estaEnRangoValido(tablero,fila, columna, profundidad)) {
        cout    << "->[Error]: ingresante un rango invalido, recuerda que va desde 1 al maximo,por favor ingrese devuelta"
                << endl;
        esValido = false;
    }
    return esValido;
}
bool Carta::estaDentroDeTablero(Tablero *tablero,int &fila, int &columna, int &profundidad){
    bool estaDentro = true;
    if (!estaEnRangoValido(tablero,fila, columna, profundidad)) {
        estaDentro = false;
    }
    return estaDentro;
}
