#include "Carta.h"
#include <cstdlib>
#include <iostream>
#include "Tablero.h"

using namespace std;

Carta::Carta() {
    this->habilidadCarta = CARTA_SIN_EFECTO;
}

Carta::Carta(habilidadCarta_t efecto) {
    this->habilidadCarta = efecto;
}

void Carta::setHabilidad(habilidadCarta_t efecto) {
    this->habilidadCarta = efecto;
}


habilidadCarta_t Carta::getHabilidad() {
    return this->habilidadCarta;
}

habilidadCarta_t Carta::generarEfectoAleatorio() {

    int efectoRandom = (rand() % 6) + 1;
    return (habilidadCarta_t) efectoRandom;
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
            std::cout << "CARTA AVION KAMIKAZE " << std::endl;
            break;

        case 5:
            std::cout << "CARTA TORMENTA ELECTRICA" << std::endl;
            break;

        case 6:
            std::cout << "CARTA FRANCOTIRADOR  " << std::endl;
            break;
        default:
            break;
    }
}

Carta::~Carta() {

}


void Carta::avionRadar(Tablero *tablero, int idJugador) {
    bool hayMinas = false;
    if (this->poseeAvion(tablero, idJugador)) {
        cout << "AVION RADAR " << endl << endl << "BUSCANDO MINAS... " << endl;
        for (int i = 1; i <= tablero->getFila(); i++) {
            for (int j = 1; j <= tablero->getColumna(); j++) {
                for (int k = 1; k <= tablero->getProfundidad(); k++) {
                    int id = tablero->obtenerCasillero(i, j, k)->getFicha()->getIdJugador();
                    if ((tablero->obtenerCasillero(i, j, k)->getFicha()->getElementoFicha() == 'M') &&
                        id != idJugador) {
                        hayMinas = true;
                        cout << "MINA EN POSICION: " << '[' << i << ']' << '[' << j << ']' << '[' << k << ']' << endl;
                    }
                }
            }
        }
        if(!hayMinas){
            cout << endl << "NO SE ENCONTRARON MINAS" << endl;
        }
    } else {
        cout << "AL NO TENER AVION NO PUEDES USAR ESTA CARTA, PIERDES LA CARTA" << endl;
    }
}

void Carta::dispararMisil(Tablero *tablero, int idJugador) {

    if (this->poseeBarco(tablero, idJugador)) {
        int fila, columna, profundidad;
        cout << "DISPARAR MISIL " << endl << endl << "INGRESE COORDENADAS A ATACAR: " << endl;
        solicitarIngresoDeCordenadas(fila, columna, profundidad);
        while (!(esFichaValida(tablero, fila, columna, profundidad))) {
            solicitarIngresoDeCordenadas(fila, columna, profundidad);
        }
        tablero->obtenerCasillero(fila, columna, profundidad)->getFicha()->bloquear(3);
    } else {
        cout << "AL NO TENER BARCOS NO PUEDES USAR ESTRA CARTA, PIERDES LA CARTA" << endl;
    }

}

void Carta::ataqueQuimico(Tablero *tablero) {
    int fila, columna, profundidad;
    cout << "ATAQUE QUIMICO" << endl << endl << "INGRESE COORDENADAS A ATACAR (RANGO DE EXPLOSION 5x5x5)" << endl;
    solicitarIngresoDeCordenadas(fila, columna, profundidad);
    while (!(esFichaValida(tablero, fila, columna, profundidad))) {
        solicitarIngresoDeCordenadas(fila, columna, profundidad);
    }
    for (int i = -RANGO_DE_EXPLOSION; i <= RANGO_DE_EXPLOSION; i++) {
        for (int j = -RANGO_DE_EXPLOSION; j <= RANGO_DE_EXPLOSION; j++) {
            for (int k = -RANGO_DE_EXPLOSION; k <= RANGO_DE_EXPLOSION; k++) {
                int nuevaFila = fila + i;
                int nuevaColumna = columna + j;
                int nuevaProfundidad = profundidad + k;

                if (this->estaDentroDeTablero(tablero, nuevaFila, nuevaColumna, nuevaProfundidad)) {
                    if (nuevaFila == fila && nuevaColumna == columna && nuevaProfundidad == profundidad) {
                        tablero->obtenerCasillero(nuevaFila, nuevaColumna, nuevaProfundidad)->getFicha()->bloquear(10);
                        cout << "ATAQUE QUIMICO EXITOSO" << endl << endl;
                    } else if ((nuevaFila < fila - 1 || nuevaFila > fila + 1) ||
                               (nuevaColumna < columna - 1 || nuevaColumna > columna + 1) ||
                               (nuevaProfundidad < profundidad - 1 || nuevaProfundidad > profundidad + 1)) {
                        tablero->obtenerCasillero(nuevaFila, nuevaColumna, nuevaProfundidad)->getFicha()->bloquear(8);
                    } else {
                        tablero->obtenerCasillero(nuevaFila, nuevaColumna, nuevaProfundidad)->getFicha()->bloquear(6);
                    }
                }
            }
        }
    }
}

void Carta::avionKamikaze(Tablero *tablero, int idJugador) {

    if (this->poseeAvion(tablero, idJugador)) {
        bool hayBarcoEnemigo = false;
        int i = 1;
        while (i <= tablero->getFila() && !hayBarcoEnemigo) {
            int j = 1;
            while (j <= tablero->getColumna() && !hayBarcoEnemigo) {
                int k = 1;
                while (k <= tablero->getProfundidad() && !hayBarcoEnemigo) {
                    int id = tablero->obtenerCasillero(i, j, k)->getFicha()->getIdJugador();
                    if (tablero->obtenerCasillero(i, j, k)->getFicha()->getElementoFicha() == 'B' && id != idJugador) {
                        hayBarcoEnemigo = true;
                        tablero->obtenerCasillero(i, j, k)->getFicha()->bloquear(1);
                        cout << "BARCO DESTRUIDO EN: " << '[' << i << ']' << '[' << j << ']' << '[' << k << ']' << endl;
                    }
                    k++;
                }
                j++;
            }
            i++;
        }
        if (!hayBarcoEnemigo) {
            cout << "NO HAY BARCOS ENEMIGOS, LA CARTA SE DESTRUYE" << endl;
        } else {
            bool avionADestruir = false;
            int i = 1;
            while (i <= tablero->getFila() && !avionADestruir) {
                int j = 1;
                while (j <= tablero->getColumna() && !avionADestruir) {
                    int k = 1;
                    while (k <= tablero->getProfundidad() && !avionADestruir) {
                        int id = tablero->obtenerCasillero(i, j, k)->getFicha()->getIdJugador();
                        if (tablero->obtenerCasillero(i, j, k)->getFicha()->getElementoFicha() == 'A' &&
                            id == idJugador) {
                            tablero->obtenerCasillero(i, j, k)->getFicha()->bloquear(1);
                            cout << "AVION ENCONTRADO EN: " << '[' << i << ']' << '[' << j << ']' << '[' << k
                                 << ']' << "HA HUNDIDO UN BARCO CON SU SACRIFICIO";
                            avionADestruir = true;
                        }
                        k++;
                    }
                    j++;
                }
                i++;
            }
        }
    }
    cout << "AL NO TENER AVION NO PUEDE USAR ESTA CARTA, SE ELIMINA LA CARTA" << endl;
}


void Carta::tormentaElectrica(Tablero *tablero) {
    int fila, columna, profundidad;
    cout << "TORMENTA ELECTRICA" << endl << endl << "INGRESE COORDENADAS DE TORMENTA (RANGO DE EFECTO 5x5x5)" << endl;
    solicitarIngresoDeCordenadas(fila, columna, profundidad);
    while (!(this->estaEnElAire(tablero, fila, columna, profundidad))) {
        cout << "COORDENADAS INGRESADAS INVALIDAS, POR FAVOR INGRESE NUEVAMENTE: ";
        solicitarIngresoDeCordenadas(fila, columna, profundidad);
    }
    for (int i = -RANGO_DE_EXPLOSION; i <= RANGO_DE_EXPLOSION; i++) {
        for (int j = -RANGO_DE_EXPLOSION; j <= RANGO_DE_EXPLOSION; j++) {
            for (int k = -RANGO_DE_EXPLOSION; k <= RANGO_DE_EXPLOSION; k++) {
                int nuevaFila = fila + i;
                int nuevaColumna = columna + j;
                int nuevaProfundidad = profundidad + k;

                if (this->estaDentroDeTablero(tablero, nuevaFila, nuevaColumna, nuevaProfundidad) &&
                    this->estaEnElAire(tablero, nuevaFila, nuevaColumna, nuevaProfundidad)) {
                    if (tablero->obtenerCasillero(nuevaFila, nuevaColumna,
                                                  nuevaProfundidad)->getFicha()->getElementoFicha() == 'A')
                        tablero->obtenerCasillero(nuevaFila, nuevaColumna, nuevaProfundidad)->getFicha()->bloquear(3);
                        cout << "TORMENTA ELECTRICA COLOCADA EN: " << '[' << i << ']' << '[' << j << ']' << '[' << k << ']' << endl;
                }
            }
        }
    }
}


void Carta::francotirador(Tablero *tablero, int idJugador) {
    cout << "FRANCOTIRADOR " << endl;
    bool haySoldadoEnemigo = false;
    if (this->poseeSoldado(tablero, idJugador)) {
        for (int i = 1; i <= tablero->getFila(); i++) {
            for (int j = 1; j <= tablero->getColumna(); j++) {
                for (int k = 1; k <= tablero->getProfundidad(); k++) {
                    int id = tablero->obtenerCasillero(i, j, k)->getFicha()->getIdJugador();
                    if ((tablero->obtenerCasillero(i, j, k)->getFicha()->getElementoFicha() == 'S') &&
                        id != idJugador) {
                        haySoldadoEnemigo = true;
                        cout << "SOLDADO ENEMIGO EN POSICION : " << '[' << i << ']' << '[' << j << ']' << '[' << k << ']'
                             << endl;

                    }
                }
            }
        }

        int fila, columna, profundidad;
        if (haySoldadoEnemigo) {
            cout << endl << "INGRESE COORDENADAS A ATACAR: " << endl;
            solicitarIngresoDeCordenadas(fila, columna, profundidad);
            while (!(esFichaValida(tablero, fila, columna, profundidad)) &&
                   !(estaEnElAire(tablero, fila, columna, profundidad))) {
                solicitarIngresoDeCordenadas(fila, columna, profundidad);
            }
            tablero->obtenerCasillero(fila, columna, profundidad)->getFicha()->bloquear(1);
            cout <<"SOLDADO ELIMINADO" << endl;
        } else {
            cout << endl << "NO HAY SOLDADO ENEMIGO A LA VISTA" << endl;
        }
    } else {
        cout << "AL NO TENER SOLDADOS NO PUEDES USAR ESTA CARTA, POR LO QUE PERDISTE LA CARTA" << endl;
    }

}


void Carta::solicitarIngresoDeCordenadas(int &filas, int &columnas, int &profundidad) {
    cout << "INGRESE UNA FILA :" << endl;
    cin >> filas;
    cout << "INGRESE UNA COLUMNA :" << endl;
    cin >> columnas;
    cout << "INGRESE UNA PROFUNDIDAD : " << endl;
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
    if (!estaEnRangoValido(tablero, fila, columna, profundidad)) {
        cout << "->[ERROR]: INGRESASTE UN RANGO INVALIDO, RECUERDA QUE VADESDE 1 AL MAXIMO, POR FAVOR INGRESE NUEVAMENTE"
             << endl;
        esValido = false;
    }
    return esValido;
}

bool Carta::estaDentroDeTablero(Tablero *tablero, int &fila, int &columna, int &profundidad) {
    bool estaDentro = true;
    if (!estaEnRangoValido(tablero, fila, columna, profundidad)) {
        estaDentro = false;
    }
    return estaDentro;
}

bool Carta::poseeAvion(Tablero *tablero, int idJugador) {
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
    return poseeAvion;
}

bool Carta::poseeBarco(Tablero *tablero, int idJugador) {
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
    return poseeBarco;
}

bool Carta::poseeSoldado(Tablero *tablero, int idJugador) {
    bool poseeSoldado = false;
    int i = 1;
    while (i <= tablero->getFila() && !poseeSoldado) {
        int j = 1;
        while (j <= tablero->getColumna() && !poseeSoldado) {
            int k = 1;
            while (k <= tablero->getProfundidad() && !poseeSoldado) {
                int id = tablero->obtenerCasillero(i, j, k)->getFicha()->getIdJugador();
                if (tablero->obtenerCasillero(i, j, k)->getFicha()->getElementoFicha() == 'S' && id == idJugador) {
                    poseeSoldado = true;
                }
                k++;
            }
            j++;
        }
        i++;
    }
    return poseeSoldado;
}

bool Carta::estaEnElAire(Tablero *tablero, int &fila, int &columna, int &profundidad) {
    int maxFilas = tablero->getFila();
    int maxColumnas = tablero->getColumna();
    int maxProfundidad = tablero->getProfundidad();
    if (fila < 1 || fila > maxFilas || columna < 1 || columna > maxColumnas || profundidad < 6 ||
        profundidad > maxProfundidad) {
        return false;
    }
    return true;
}








