#ifndef CASILLERO_H
#define CASILLERO_H

#include "Ficha.h"
#include "string"

typedef enum {
    TIERRA,
    AGUA,
    AIRE,
} terreno_t;

class Casillero {
private:
    Ficha * ficha;
    bool estadoCasillero;
    terreno_t terreno;

public:
    //Pre: -
    //Post: se crea el casillero cuya ficha ubicada en el es "simboloFicha" y es del tipo "terreno" 
    Casillero(terreno_t terreno, char simboloFicha);
    //Pre: -
    //Post: retorna el puntero a la clase Ficha asociado al caillero 
    Ficha * getFicha();
    //Pre: -
    //Post: retorna el valor booleano True si la ficha asociada al casillero se encuentra vacia y False en caso contrario
    bool estaCasilleroVacio();
};

#endif
