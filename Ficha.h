#ifndef FICHA_H
#define FICHA_H

#include "string"

#define VACIO '-'
#define AVION 'A'
#define BARCO 'B'
#define MINA 'M'
#define SOLDADO 'S'

class Ficha {
private:
    char simboloFicha;
    bool estaBloqueada;
    int turnosRestantesParaDesbloqueo;
    int idJugador;
    int vidas;

public:
    //pre: -
    //post: Crea una ficha del tipo "simboloFicha" la cual no se asocia a ningun jugador
    Ficha(char simboloFicha);

    //pre: -
    //post: Crea una ficha del tipo "simboloFicha" la cual se asocia al jugador "idJugador"
    Ficha(char simboloFicha, int idJugador);

    //pre: -
    //post: retorna un caracter que representa el elemento ubicado en la ficha 
    char getElementoFicha();

    //pre: -
    //post: retorna el id del jugador asociado a la ficha
    int getIdJugador() const;

    //pre: recibe como parametro un entero que representa al jugador al cual se le quiere asociar la ficha
    //post: la ficha queda asociada al jugador "idJugador"
    void setIdJugador(int idJugador);

    //pre: -
    //post: se libera la memoria solicitada
    ~Ficha();

    //pre: -
    //post: retorna un valor booleano, True en caso de que la ficha se escuentra bloqueada y Fals en caso contrario
    bool getBloqueada();

    //pre: la ficha se encuentra bloqueada
    //post: disminuye la cantidad de turnos restantes para desbloquear la ficha y retorna un valor booleano, True en caso de que la ficha continue bloqueada y False en caso de que se requiera desbloquear
    bool aumentarContador();

    //pre: recibe como parametro un entero positivo que representa la cantidad de turnos que se encontrara bloqueada la ficha
    //post: la fich se mantiene inactiva durante "turnos" cantidad de turnos
    void bloquear(int turnos);

    //pre: -
    //post: la ficha es del tipo "elementoF"
    void setSimboloFecha(char elementoF);

    //pre: -
    //post: retorna un entero que reprenta la cantidad de vidas que tiene la ficha 
    int getVidas() const;

    //pre: -
    //post: la ficha tiene "vidas" vidas
    void setVidas(int vidas);
};

#endif
