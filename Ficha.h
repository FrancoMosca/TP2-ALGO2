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


    char elementoF;
    bool estaBloqueada;
    int turnosRestantesParaDesbloqueo;
    elemento_t elemento;
    int jugador;
    int vidas;
public:
    Ficha();
    Ficha(char simboloFicha);
    Ficha(elemento_t elementoFicha,int jugador);
    Ficha(elemento_t elementoFicha);
    char getElementoFicha();
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