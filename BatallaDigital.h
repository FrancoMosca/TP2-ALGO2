#ifndef BATALLADIGITAL_H
#define BATALLADIGITAL_H

#include "Tablero.h"
#include "string"
#include "iostream"
#include "Jugador.h"
#include "Cola.h"

#define CANTIDAD_CARTAS_MAZO_PRINCIPAL 50
#define CANTIDAD_CARTAS_MAZO_JUGADORES 7


class BatallaDigital {
private:
    Tablero * tableroPrincipal;
    Lista<Jugador*> *jugadores;
    Cola<Jugador*> turnos;
    Mazo *mazo;
    Jugador * jugadorActual;
    int cantidadJugadasRealizadas;
    int cantidadInsertsPorJugador;
public:
    BatallaDigital();
    ~BatallaDigital();
    void iniciarJuego();
    void crearTableroPrincipal();
    void crearJugadores();
    bool esFichaOcupadaPorOtroJugador(char simboloFichaElegido);
    void imprimirJugadores();
    void mostrarTableroPorCoordenadas();
    int getCantidadJugadores();
    void crearMazo();
    void crearMazoPorJugador();
    // Funciones para iniciar el juego
    void jugarJuego();
    void solicitarIngresoDeCordenadas(int &filas, int &columnas, int &profundidad);
    bool esFichaValida(int &fila, int &columna, int &profundidad);
    bool estaEnRangoValido(int &fila, int &columna, int &profundidad);
    bool estaCasilleroLibre(int &fila, int &columna, int &profundidad);
    void repartirCartasAlJugadorActual();
    void iniciarTurnos();
    void usarCarta(int numeroCarta);


    void aplicarHabilidadCarta(Carta *carta);

    void crearArmamentoDelJugador();

    void obtenerCantidadDeInsertsPorJugador();
    void generarPosiciones(int cantidadElementos, char simboloFicha, Jugador *jugador);

    bool validarInsertsDisponibles(int cantidadElementos, int insertsDisponibles);

    bool esFichaValidaMina(int fila, int columna, int profundidad);

    void agregarMina(int fila, int columna, int profundidad);

    void elegirCarta();

    void repartirCartas();

    void decidirMoverSoldadoArmamento(int fila, int columna, int profundidad);

    bool validarMovimiento(char movimiento);

    void moverElemento(int fila, int columna, int profundidad, char movimiento, int nuevaProfundidad);

    bool validarSoldadoArmamentoElegido(int fila, int columna, int profundidad);

    bool existeMina(int fila, int columna, int profundidad);

    void eliminarSoldado(int fila, int columna, int profundidad);
};

#endif
