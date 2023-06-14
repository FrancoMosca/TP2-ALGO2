#ifndef TP2_ALGO2_CARTA_H
#define TP2_ALGO2_CARTA_H

#include "Tablero.h"


typedef enum {
    CARTA_SIN_EFECTO,
    CARTA_AVION_RADAR,
    CARTA_DISPARAR_MISIL,
    CARTA_ATAQUE_QUIMICO,
    CARTA_DESARMAR_SOLDADO,
    CARTA_ATAQUE_MULTIPLE,
    CARTA_AUMENTAR_RESISTENCIA,
} habilidadCarta_t;

class Carta {
private:
    habilidadCarta_t habilidadCarta;

public:
    //Pre:
    //Post:
    Carta();

    //Pre:
    //Post:
    Carta(habilidadCarta_t efectoCarta);

    //Pre:
    //Post:
    void setHabilidad(habilidadCarta_t numero);

    //Pre:
    //Post:
    habilidadCarta_t getHabilidad();

    //Pre:
    //Post:
    habilidadCarta_t generarEfectoAleatorio();

    //Pre:
    //Post:
    void imprimirHabilidadCarta();

    //Pre:
    //Post:
    void obtenerRango();

    //Pre:
    //Post:
    //Metodos carta avion
    void avionRadar(Tablero *tablero, int idJugador);

    //Pre:
    //Post:
    //Metodos carta barco
    void dispararMisil(Tablero *tablero, int idJugador);

    //Pre:
    //Post:
    //Metodos ataque quimico
    void ataqueQuimico(Tablero *tablero);

    //Pre:
    //Post:
    //Metodos granada
    void desarmarSoldados();

    //Pre:
    //Post:
    //Metodos ataque multiple
    void ataqueMultiple();

    //Pre:
    //Post:
    //Metodos escudo
    void aumentarResistencia();

    //Pre:
    //Post:
    void solicitarIngresoDeCordenadas(int &filas, int &columnas, int &profundidad);

    //Pre:
    //Post:
    bool estaEnRangoValido(Tablero *tablero, int &fila, int &columna, int &profundidad);

    //Pre:
    //Post:
    bool esFichaValida(int &fila, int &columna, int &profundidad);

    //Pre:
    //Post:
    virtual ~Carta();
};


#endif
