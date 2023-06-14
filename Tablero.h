#ifndef TABLERO_H
#define TABLERO_H

#include "Casillero.h"
#include "Lista.h"
#include "string"

static const char SIMBOLO_FICHA_VACIO = '-';

class Tablero {
private:
    int fila;
    int columna;
    int profundidad;
    Lista<Lista<Lista<Casillero *> *> *> *casilleros;

public:
    //Pre: -
    //Post: Se crea un tablero de dimensiones fila x columna x profundidad  
    Tablero(int fila, int columna, int profundidad);

    //Pre: -
    //Post: Se libera la memoria solicitada para la creacion del tablero
    virtual ~Tablero();

    //Pre: recibe como parametros la posicion fila x columna x profundidad existente en el tablero
    //Post: retorna un puntero a la clase casillero ubicado en la pocion fila x columna x profundidad
    Casillero *obtenerCasillero(int fila, int columna, int profundidad);

    //Pre: recibe como parametros la posicion fila x columna x profundidad
    //Post: retorna un tipo de dato booleano, True en caso de existir dicha posicion en el tablero y False en caso contrario
    bool existeLaCasilla(int fila, int columna, int profundidad);

    //Pre: -
    //Post: retorna la cantidad de filas del tablero
    int getFila();

    //Pre: recibe un entero positivo que representa la cantidad de filas del tablero
    //Post: el tablero tiene "fila" filas
    void setFila(int fila);

    //Pre: -
    //Post: retorna la cantidad de columnas del tablero
    int getColumna();

    //Pre: recibe un entero positivo que representa la cantidad de columnas del tablero
    //Post: el tablero tiene "columna" columnas
    void setColumna(int columna);

    //Pre: -
    //Post: retorna la profundidad del tablero
    int getProfundidad();

    //Pre: recibe un entero positivo que representa la profundidad del tablero
    //Post: el talero tiene "profundidad" niveles de profundidad
    void setProfundidad(int profundidad);

    //Pre: recibe como parametro una posicion fila x columna x profundidad, una caracter que representa la ficha que se deasea colocar y un entero que reprenta al jugador al que se le atribuye dicha ficha
    //Post: el elemento "simboloFicha" se posiciona en la ubicacion "fila" x "columna" x "profundidad" y le pertenece al jugador "i" 
    void setCasilla(size_t fila, size_t columna, size_t profundidad, char simboloFicha, int i);

    //Pre: -
    //Post: retorna un entero que representa la cantidad de casilleros totales del tablero
    int obtenerCantidadDePosiciones();

    //Pre: definir
    //Post: definir
    void setCasillaMina(size_t fila, size_t columna, size_t profundidad, char simboloFicha);
};


#endif
