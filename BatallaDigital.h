#ifndef BATALLADIGITAL_H
#define BATALLADIGITAL_H

#include "Tablero.h"
#include "string"
#include "iostream"

class BatallaDigital {
private:
    Tablero * tableroPrincipal;
public:
    BatallaDigital();
    ~BatallaDigital();
    void iniciarJuego();
    void crearTableroPrincipal();
};

#endif
