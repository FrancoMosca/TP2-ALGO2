#ifndef JUGADOR_H
#define JUGADOR_H

#include "string"
#include "Ficha.h"
#include "Carta.h"
#include "Lista.h"
#include "Mazo.h"

typedef int coordenada[3];


using namespace std;

class Jugador {
private:
    int idJugador;
    string nombreJugador;
    Ficha *ficha;
    Mazo *mazo;
    Lista<Casillero *> *jugadas;

public:
    Jugador(string nombre, char simboloDeFicha);

    int getIdJugador();

    void setIdJugador(int idJugador);

    const string &getNombreJugador();

    void setNombreJugador(string &nombreJugador);

    Ficha *getFicha();

    void setFicha(Ficha *ficha);

    Mazo *getMazo() const;

    void setMazo(Mazo *mazo);

    Lista<Casillero *> *getJugadas() const;

    void setJugadas(Lista<Casillero *> *jugadas);

};


#endif
