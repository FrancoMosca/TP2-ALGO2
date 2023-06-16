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
    int cantidadElementosVivos;
    bool perdioLaPartida;

public:
    //Pre: -
    //Post: se crea el jugador de nombre " nombre " y identiificador "simboloDeFicha"
    Jugador(string nombre, char simboloDeFicha);

    //Pre: -
    //Post: retorna un entero que representa el numero de identificacion asociado al jugador
    int getIdJugador();

    //Pre: -
    //Post: el jugador queda asociado al identificador "idJugador"
    void setIdJugador(int idJugador);

    //Pre: -
    //Post: retorna el nombre asociado al jugador
    const string &getNombreJugador();

    //Pre: -
    //Post: retorna un puntero a la ficha asociada al jugador
    Ficha *getFicha();

    //Pre: -
    //Post: reorna un puntero al mazo del jugador
    Mazo *getMazo() const;

    //Pre: -
    //Post: retorna un entero que representa la cantidad de elementos restantes del jugador
    int getCantidadElementosVivos() const;

    //Pre: "i" debe ser positivo
    //Post: el jugador tiene "i" elementos vivos
    void setCantidadElementosVivos(int i);

    //Pre: -
    //Post: retorna el valor booleano True en caso de que al jugador ya no le queden elementos con vida, retorna false en caso contrario
    bool isPerdioLaPartida() const;

    //Pre: -
    //Post: el jugador ha perdido la partida
    void setPerdioLaPartida(bool perdioLaPartida);

    //Pre: -
    //Post: el jugador tiene un mazo "mazo" de cartas
    void setMazo(Mazo *mazo);

    //Pre: -
    //Post: retorna un entero que representa la cantidad de elementos restantes permitidos que se pueden colocar en el tablero
    int getCantidadInsertsRestantes();

    //Pre: -
    //Post: el jugador tiene "cantidadInsertsRestantes" cantidad de elementos restantes permitidos que se pueden colocar en el tablero
    void setCantidadInsertsRestantes(int cantidadInsertsRestantes);

    //Pre: -
    //Post: se decrementa la cantidad de elementos vivos del jugador
    void decrementarElementosVivos();

    //Pre: -
    //Post: se umenta la cantidad de elementos vivos del jugador
    void aumentarElementosVivos();
};


#endif
