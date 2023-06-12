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
    int cantidadInsertsRestantes;

public:
    Jugador(string nombre, char simboloDeFicha);

    int getIdJugador();

    void setIdJugador(int idJugador);

    const string &getNombreJugador();

    Ficha *getFicha();

    Mazo *getMazo() const;

    void setMazo(Mazo *mazo);

    int getCantidadInsertsRestantes() const;

    void setCantidadInsertsRestantes(int cantidadInsertsRestantes);

};


#endif
