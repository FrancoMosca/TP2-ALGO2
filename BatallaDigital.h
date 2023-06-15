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
    int idJugadorGanador;
    bool hayGanador;
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

    //Pre:recibe como parametro tres referencias a enteros que representan la posicion "fila" x "columna" x "profundidad" en el tablero
    //Post: retorna el valor booleano False en caso de que la posición no ecista o se encuentre ocupada, retorna True en caso contrari
    bool esFichaValida(int &fila, int &columna, int &profundidad);

    //Pre:recibe como parametro tres referencias a enteros que representan la posicion "fila" x "columna" x "profundidad" en el tablero
    //Post: retorna False en caso de que la posición nl exista y True en caso contrario
    bool estaEnRangoValido(int &fila, int &columna, int &profundidad);

    //Pre:recibe como parametro tres referencias a enteros que representan la posicion "fila" x "columna" x "profundidad" en el tablero
    //Post: retorna el valor booleano true en caso de que el casillero se encuentre vacio y false en caso contrario
    bool estaCasilleroLibre(int &fila, int &columna, int &profundidad);

    //Pre: -
    //Post: el jugador obtiene una carta de manera aleatoria
    void repartirCartasAlJugadorActual();

    //Pre:-
    //Post: inicializa una lista de turnos durante una ronda
    void iniciarTurnos();

    //Pre: el jugador debe tener "numeroCarta" cantidad de cartas
    //Post: se efectúa la habilidad de la carta elegida y se elimina del mazo del jugador dicha carta
    void usarCarta(int numeroCarta);

    //Pre: "carta" no puede ser NULL
    //Post: efectua la habilidad de la carta sobre el tablero
    void aplicarHabilidadCarta(Carta *carta);

    //Pre: -
    //Post: se inicializa de forma aleatoria la cantidad de entidades del juego para el jugador
    void crearArmamentoDelJugador();

    //Pre: -
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
    bool esFichaRangoValida(int fila, int columna, int profundidad);

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

    //Pre:
    //Post:
    void decrementarTurnosFichas();

    //Pre:
    //Post:
    void desbloquearFichas();

    //Pre:
    //Post:
    void avanzarTurno();

    //Pre:
    //Post:
    void actualizarArmamento();

    //Pre:
    //Post
    void actualizarArmamento(const Ficha *ficha);

    //Pre:
    //Post:
    void limpiarConsola();

    //Pre:
    //Post:
    int getIdJugadorGanador() const;

    //Pre:
    //Post:
    void setIdJugadorGanador(int idJugadorGanador);

    //Pre:
    //Post:
    bool isHayGanador() const;
    
    //Pre:
    //Post:
    void setHayGanador(bool hayGanador);

};

#endif
