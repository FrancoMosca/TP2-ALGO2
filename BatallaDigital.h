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
    Tablero *tableroPrincipal;
    Lista<Jugador *> *jugadores;
    Cola<Jugador *> turnos;
    Mazo *mazo;
    Jugador *jugadorActual;
    int cantidadJugadasRealizadas;
    int cantidadInsertsPorJugador;
public:
    //Pre: -
    //Post: Crea una batalla no inicializada 
    BatallaDigital();

    //Pre: -
    //Post: se libera la memoria solicitada 
    ~BatallaDigital();

    //Pre: -
    //Post: Se inicializan todas las entidades del juego (tablero, jugadores, fichas, mazo de cartas)
    void iniciarJuego();

    //Pre: -
    //Post: se solicitan por pantalla las dimensiones del tablero y se crea el tablero donde se realizara el juego
    void crearTableroPrincipal();

    //Pre: -
    //Post: se solicitan los datos de cada jugador presente 
    void crearJugadores();

    //Pre: -
    //Post: retorna el valor boolenao True en caso de que ya exista un jugador con el identificador "simboloFichaElegido", en caso cotrario retorna False 
    bool esFichaOcupadaPorOtroJugador(char simboloFichaElegido);

    //Pre: -
    //Post: se muestren por pantalla los jugadores presentes en la partida 
    void imprimirJugadores();

    //Pre: -
    //Post: se muestra el estado del tablero en formato txt
    void mostrarTableroPorCoordenadas();

    //Pre: -
    //Post: retorna un entero que reprenta la cantidad de jugadores totales en el juego
    int getCantidadJugadores();

    //Pre: -
    //Post: se crea un mazo donde se encotraran todas las cartas disponibles para usar durante la partida 
    void crearMazo();

    //Pre: -
    //Post: se crea un mazo por cada jugador en el que se encontraran las cartas disponibles para cada uno
    void crearMazoPorJugador();

    // Funciones para iniciar el juego
    //Pre: -
    //Post: se realiza una ronda completa de jugadas
    void jugarJuego();

    //Pre: -
    //Post: se solicita por pantalla la eleccion de numero de fila, columna y profundidad, su valor permanecera guardado en "filas","columnas","profundidad"  
    void solicitarIngresoDeCordenadas(int &filas, int &columnas, int &profundidad);

    //Pre:recibe como parametro tres enteros que representan
    //Post:
    bool esFichaValida(int &fila, int &columna, int &profundidad);

    //Pre:
    //Post:
    bool estaEnRangoValido(int &fila, int &columna, int &profundidad);

    //Pre:
    //Post:
    bool estaCasilleroLibre(int &fila, int &columna, int &profundidad);

    //Pre:
    //Post:
    void repartirCartasAlJugadorActual();

    //Pre:
    //Post:
    void iniciarTurnos();

    //Pre:
    //Post:
    void usarCarta(int numeroCarta);

    //Pre:
    //Post:
    void aplicarHabilidadCarta(Carta *carta);

    //Pre:
    //Post:
    void crearArmamentoDelJugador();

    //Pre:
    //Post:
    void obtenerCantidadDeInsertsPorJugador();

    //Pre:
    //Post:
    void generarPosiciones(int cantidadElementos, char simboloFicha, Jugador *jugador);

    //Pre:
    //Post:
    bool validarInsertsDisponibles(int cantidadElementos, int insertsDisponibles);

    //Pre:
    //Post:
    bool esFichaValidaMina(int fila, int columna, int profundidad);

    //Pre:
    //Post:
    void agregarMina(int fila, int columna, int profundidad);

    //Pre:
    //Post:
    void elegirCarta();

    //Pre:
    //Post:
    void repartirCartas();

    //Pre:
    //Post:
    void decidirMoverSoldadoArmamento(int fila, int columna, int profundidad);

    //Pre:
    //Post:
    bool validarMovimiento(char movimiento);

    //Pre:
    //Post:
    void moverElemento(int fila, int columna, int profundidad, char movimiento, int nuevaProfundidad);

    //Pre:
    //Post:
    bool validarSoldadoArmamentoElegido(int fila, int columna, int profundidad);

    //Pre:
    //Post:
    bool existeMina(int fila, int columna, int profundidad);

    //Pre:
    //Post:
    void eliminarSoldado(int fila, int columna, int profundidad);

    //Pre:
    //Post:
    bool existeSoldadoEnemigo(int fila, int columna, int profundidad);

    //Pre:
    //Post:
    bool esPosicionBloqueada(int fila, int columna, int profundidad);
};

#endif
