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
    Carta();

    Carta(habilidadCarta_t efectoCarta);

    void setHabilidad(habilidadCarta_t numero);

    habilidadCarta_t getHabilidad();

    habilidadCarta_t generarEfectoAleatorio();

    void imprimirHabilidadCarta();

    void obtenerRango ();

    //Metodos carta avion
    void avionRadar(Tablero * tablero, int idJugador);

    //Metodos carta barco
    void dispararMisil(Tablero * tablero, int idJugador);

    //Metodos ataque quimico
    void ataqueQuimico(Tablero * tablero);

    //Metodos granada
    void desarmarSoldados();

    //Metodos ataque multiple
    void ataqueMultiple();

    //Metodos escudo
    void aumentarResistencia();

    void solicitarIngresoDeCordenadas(int &filas, int &columnas, int &profundidad);

    bool estaEnRangoValido(Tablero * tablero, &fila, int &columna, int &profundidad);

    bool esFichaValida(int &fila, int &columna, int &profundidad);

    virtual ~Carta();
};


#endif
