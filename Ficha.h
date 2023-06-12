#ifndef FICHA_H
#define FICHA_H

#include "string"
#define VACIO '-'
typedef enum {
    SOLDADO,
    ARMAMENTO,
    MINA,
    BARCO,
    AVION,
} elemento_t;

class Ficha {
private:


    char simboloFicha;
    bool estaBloqueada;
    int turnosRestantesParaDesbloqueo;
    elemento_t elemento;
    int idJugador;
    int vidas;
public:
    Ficha(char simboloFicha);
    Ficha(char simboloFicha, int idJugador);
    char getElementoFicha();

    int getIdJugador() const;

    void setIdJugador(int idJugador);

    elemento_t getElementoFicha2();
    ~Ficha();
    int getJugador();
    bool getBloqueada();
    bool aumentarContador();
    void bloquear(int turnos);
    void cambiarElemento(elemento_t nuevoElemento);

    char getElementoF() const;

    void setElementoF(char elementoF);

    elemento_t getElemento() const;

    int getVidas() const;

    void setVidas(int vidas);

    void setElemento(elemento_t elemento);
};

#endif