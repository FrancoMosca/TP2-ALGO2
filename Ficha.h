#ifndef FICHA_H
#define FICHA_H

#include "string"

typedef enum {
    SOLDADO,
    MINA,
    BARCO,
    AVION,
    VACIO,
    TIERRA,
    AGUA,
    AIRE,
} elemento_t;

class Ficha {
private:
    char elementoF;
    bool estaBloqueada;
    int turnosRestantesParaDesbloqueo;
    elemento_t elemento;
public:
    Ficha();
    Ficha(elemento_t elementoFicha);
    char getElementoFicha();
};

#endif