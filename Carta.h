#ifndef TP2_ALGO2_CARTA_H
#define TP2_ALGO2_CARTA_H

#include "Tablero.h"


typedef enum {
    CARTA_SIN_EFECTO,
    CARTA_AVION_RADAR,
    CARTA_DISPARAR_MISIL,
    CARTA_ATAQUE_QUIMICO,
    CARTA_AVION_KAMIKAZE,
    CARTA_TORMENTA_ELECTRICA,
    CARTA_FRANCOTIRADOR,
} habilidadCarta_t;

class Carta {
private:
    habilidadCarta_t habilidadCarta;

public:
    //Pre:
    //Post: Crea una carta con habilidad sin efecto.
    Carta();

    //Pre:
    //Post: Crea una carta con habilidad el efecto dado.
    Carta(habilidadCarta_t efectoCarta);

    //Pre:
    //Post: Setea una habilidad del enum.
    void setHabilidad(habilidadCarta_t numero);

    //Pre:
    //Post: Retorna la habilidad de la carta.
    habilidadCarta_t getHabilidad();

    //Pre:
    //Post: Devuelve una habilidad random de las que estan en el enum.
    habilidadCarta_t generarEfectoAleatorio();

    //Pre:
    //Post: Imprime por consola el nombre de la habilidad de la carta.
    void imprimirHabilidadCarta();

    //Pre:
    //Post: Se destruye la carta.
    virtual ~Carta();

    //Pre: El jugador tiene que poseer un avion en el tablero.
    //Post: Activa la carta Radar que obtiene y muestra por pantalla las minas de los enemigos.
    void avionRadar(Tablero *tablero, int idJugador);

    //Pre: El jugador tienen que poseer un barco en el tablero.
    //Post: Activa la carta disparar Misil. Dispara y destruye la ficha en la coordenada dada por el jugador y bloquea la casilla por 3 turnos.
    void dispararMisil(Tablero *tablero, int idJugador);

    //Pre:
    //Post: Activa la carta ataque Quimica la cual contamina y destruye la ficha en la coordenada indicada bloqueando por 10 turnos el centro, por 8 las casillas adyacentes, y por 6 las
    //      mas alejadas del centro. Teniendo un rango de 5x5x5. 125 casillas.
    void ataqueQuimico(Tablero *tablero);

    //Pre: El jugador tiene que poseer un avion en el tablero y deben haber barcos enemigos.
    //Post: Se activa la carta avion Kamikaze. Que destruye un avion aliado para destruir un barco enemigo aleatorio.
    void avionKamikaze(Tablero *tablero, int idJugador);

    //Pre: Solo se puede usar en las casillas que son de terreno AIRE.
    //Post: Se activa la carta tormenta electrica. Que genera un tornado de 5x5x5, en cualquier casilla que sea de Aire y detruye todos los aviones en ella.
    void tormentaElectrica(Tablero *tablero);
    //Pre: El jugador tiene que poseer un soldado en el tablero.
    //Post: Se activa la carta francotirador. Que le muestra al jugador un listado de los soldados enemigos, el cual podra eliminar a uno de ellos.
    void francotirador(Tablero *tablero, int idJugador);

    //Pre:
    //Post: Solicita al usuario el ingreso de coordenadas. Fila, columna y profundidad.
    void solicitarIngresoDeCordenadas(int &filas, int &columnas, int &profundidad);

    //Pre:
    //Post: Valida que las coordenadas dadas no esten fuera de rango.
    bool estaEnRangoValido(Tablero *tablero, int &fila, int &columna, int &profundidad);

    //Pre:
    //Post: Valida que las coordenadas dadas no esten fuera del tablero y le indica al usuario.
    bool esFichaValida(Tablero *tablero,int &fila, int &columna, int &profundidad);

    //Pre:
    //Post: Valida que las coordenadas dadas no esten fuera del tablero.
    bool estaDentroDeTablero(Tablero *tablero,int &fila, int &columna, int &profundidad);
    //Pre:
    //Post: Valida si el jugador pasado posee un avion en el tablero.
    bool poseeAvion(Tablero *tablero, int idJugador);
    //Pre:
    //Post: Valida si el jugador pasado posee un barco en el tablero.
    bool poseeBarco(Tablero *tablero, int idJugador);
    //Pre:
    //Post: Valida si el jugador pasado posee un soldado en el tablero.
    bool poseeSoldado(Tablero *tablero, int idJugador);
    //Pre:
    //Post: Valida que las coordenadas dadas sea un casillero de AIRE.
    bool estaEnElAire(Tablero *tablero, int &fila, int &columna, int &profundidad);

};


#endif
