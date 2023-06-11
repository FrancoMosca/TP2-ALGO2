#ifndef TP2_ALGO2_CARTA_H
#define TP2_ALGO2_CARTA_H

#include "Tablero.h"
typedef enum {
    CARTA_SIN_EFECTO,
    CARTA_DETECTAR_MINA,
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
    void detectarMinas(Tablero* tablero);

    //Metodos carta barco
    void dispararMisil();

    //Metodos ataque quimico
    void ataqueQuimico();

    //Metodos granada
    void desarmarSoldados();

    //Metodos ataque multiple
    void ataqueMultiple();

    //Metodos escudo
    void aumentarResistencia(Tablero * tablero);

    virtual ~Carta();
};


#endif
