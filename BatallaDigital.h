#ifndef BATALLADIGITAL_H
#define BATALLADIGITAL_H#ifndef BATALLADIGITAL_H
#define BATALLADIGITAL_H

#include "Tablero.h"
#include "string"
#include "iostream"
#include "Jugador.h"
#include "Cola.h"
#include "Carta.h"

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
    //Post: se valida la posicion "fila" x "columna" x "profundidad"
    bool validar(int fila,int columna,int profundidad, terreno_t terreno);
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
    //Post: batalla digital queda asociada a una determinada cantidad de entidades permitidas por jugador
    void obtenerCantidadDeInsertsPorJugador();

    //Pre: recibe como parmetros un entero que representa la cantidad de posiciones a generar, un caracter que reprenta al simbolo que se desea generar y un puntero a jugador (no puede ser nulo) al que se le asociaran los elementos
    //Post: se inicializan en el tablero "cantidadElementos" fichas del tipo "simboloFicha" pertenecientes al jugador "jugador"
    void generarPosiciones(int cantidadElementos, char simboloFicha, Jugador *jugador);

    //Pre: -
    //Post: retorna el valor booleano true en caso de que "cantidadElemntos" entre en el rango permitido por "insertsdisponibles", en caso contrario retorna false
    bool validarInsertsDisponibles(int cantidadElementos, int insertsDisponibles);

    //Pre: -
    //Post: retorna el valor booleano true en caso de que exista la ficha en la posicion "fila" x "columna" x "profundidad"
    bool esFichaRangoValida(int fila, int columna, int profundidad);

    //Pre: -
    //Post: se agrega una mina en l posicion "fila" x "columna" x "profundidad"
    void agregarMina(int fila, int columna, int profundidad);

    //Pre: -
    //Post: pregunta por pantalla si se desea utilizar una carta, en caso afirmativo se ejecuta su habilidad
    void elegirCarta();

    //Pre: el jugador no debe superar el numero de cartas permitidos
    //Post: se reparte una carta aleatoria a un jugador
    void repartirCartas();

    //Pre: -
    //Post: solicita por consola la ralizacion de un movimiento en un entidad del juego prteneciente a un jugador
    void decidirMoverSoldadoArmamento(int fila, int columna, int profundidad);

    //Pre: recibe como parametro un caracter que represnta la posicion a la que se quiere mover una entidad del juego
    //Post: retorna el valor booleano true en caso de que el movimiento elegido se pueda efectuar y false en caso contrario
    bool validarMovimiento(char movimiento);

    //Pre: recibe como parametro la posicion del elemento que se desea mover ("fila" x "columna" x "profundidad"), el tipo de movimiento que se desea realizar y la nueva profundidad (esta debe ser o "profundidad" o "profundidad"+1 o "profundidad"-1)
    //Post: se realiza el movimiento del elemento
    void moverElemento(int fila, int columna, int profundidad, char movimiento, int nuevaProfundidad);

    //Pre: -
    //Post: retorna el valor booleano true en caso de que exista un soldado en la posicion "fila" x "columna" x "profundidad" y este sea del jugador seleccionado, retorna false en caso contrario
    bool validarSoldadoArmamentoElegido(int fila, int columna, int profundidad);

    //Pre: -
    //Post: retorna el valor booleano true en caso de que exista un soldado en la posicion "fila" x "columna" x "profundidad" y este sea del jugador seleccionado, retorna false en caso contrario
    bool existeMina(int fila, int columna, int profundidad);

    //Pre: existe un soldado ubicado en la posicion "fila" x "columna" x "profundidad"
    //Post: se elimina del tablero el soldado "fila" x "columna" x "profundidad"
    void eliminarSoldado(int fila, int columna, int profundidad);

    //Pre: -
    //Post: retorna el valor booleano true en caso de que exista un soldado en la posicion "fila" x "columna" x "profundidad" y que este sea de un jugador distinto al jugador que la utiliza, retorna false en caso contraro
    bool existeSoldadoEnemigo(int fila, int columna, int profundidad);

    //Pre: -
    //Post: retorna el valor booleano true en caso de que la ficha la posicion "fila" x "columna" x "profundidad", retorna false en caso contrario
    bool esPosicionBloqueada(int fila, int columna, int profundidad);

    //Pre: -
    //Post: se disminuye el tiempo de bloqueo de las fichas bloqueadas
    void decrementarTurnosFichas();

    //Pre: -
    //Post: se desbloquean las fichas que ya hayan estado inacivas el tiempo predeterminado
    void desbloquearFichas();

    //Pre: -
    //Post: el turno de jugada pasa al siguiete jugador
    void avanzarTurno();

    //Pre: -
    //Post: se validan la cantidad de elementos de cada jugador para corroborar si ya se debe dar por finalizado el juego
    void actualizarArmamento();

    //Pre:
    //Post: se actualiza la cantidad de elementos sobrevivientes
    void actualizarArmamento(const Ficha *ficha);

    //Pre: -
    //Post: se limpia el estado de la consola
    void limpiarConsola();

    //Pre: -
    //Post: retorna un entero que repesenta el id del jugador el cual gano la partida
    int getIdJugadorGanador() const;

    //Pre: idjugadorganador es in id existente en l lista de jugadores
    //Post: queda asociado el id del jugador que ha ganado la batalla
    void setIdJugadorGanador(int idJugadorGanador);

    //Pre: -
    //Post: retorna el valor booleano true en caso de que algún jugador haya ganado y retorna false en caso contrario
    bool isHayGanador() const;

    //Pre: -
    //Post: existe un ganador
    void setHayGanador(bool hayGanador);

    //Pre: -
    //Post: se libera la memoria asociada al mazo de cada jugador
    void deleteMazoJugadores();
    
    //Pre: -
    //Post: se libera la memoria asociada a cada jugador
    void deleteJugadores();
    
    //Pre: -
    //Post: se libera la memoria asociada al mazo
    void deleteMazoPrincipal();
};

#endif
