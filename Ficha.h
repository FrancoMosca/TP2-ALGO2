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
    //pre:
    //post:
    Ficha(char simboloFicha);
    Ficha(char simboloFicha, int idJugador);
    char getElementoFicha();
    int getIdJugador() const;
    void setIdJugador(int idJugador);
    ~Ficha();
    bool getBloqueada();
    bool aumentarContador();
    void bloquear(int turnos);
    void setSimboloFecha(char elementoF);
    int getVidas() const;
    void setVidas(int vidas);
};

#endif
