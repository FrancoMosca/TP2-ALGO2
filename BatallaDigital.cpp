#include "BatallaDigital.h"
#include "Jugador.h"
#include <random>

using namespace std;

BatallaDigital::BatallaDigital() {
    this->tableroPrincipal = NULL;
    this->cantidadJugadasRealizadas = 0;
    this->mazo = NULL;
    this->jugadores = NULL;
    this->jugadorActual = NULL;
}

BatallaDigital::~BatallaDigital() {

}

void BatallaDigital::iniciarJuego() {
    cout << "--------------->Bienvenido a la Batalla Digital<-----------------------\n";
    this->crearTableroPrincipal();
    this->crearJugadores();
    this->imprimirJugadores();
    this->crearMazo();
    this->crearMazoPorJugador();
    this->obtenerCantidadDeInsertsPorJugador();
    this->crearSoldados();
    this->iniciarTurnos();

}

void BatallaDigital::crearTableroPrincipal() {
    size_t fila, columna, profundidad;

    cout << "Ingresa las dimensiones del tablero" << endl;
    cout << "Filas:" << endl;;
    cin >> fila;
    cout << "Columnas:" << endl;
    cin >> columna;
    cout << "Profundidad:" << endl;
    cin >> profundidad;

    while (fila < 2 || columna < 2 || profundidad < 2) {
        cout << "[Error]: La cantidad de filas, columnas y profundidad debe ser mayor a 1" << endl;
        cout << "Ingresa las dimensiones del tablero" << endl;
        cout << "Filas:" << endl;;
        cin >> fila;
        cout << "Columnas:" << endl;
        cin >> columna;
        cout << "Profundidad:" << endl;
        cin >> profundidad;
    }
    this->tableroPrincipal = new Tablero(fila, columna, profundidad);
}

void BatallaDigital::mostrarTableroPorCoordenadas() {
    Tablero *tablero = this->tableroPrincipal;
    int contador = 0;
    for (int i = 1; i <= tablero->getFila(); i++) {
        for (int j = 1; j <= tablero->getColumna(); j++) {
            for (int k = 1; k <= tablero->getProfundidad(); k++) {
                contador++;
                char ficha = tablero->obtenerCasillero(i, j, k)->getFicha()->getElementoFicha();
                if (ficha == 'S') {
                    cout << "Casillero [" << i << "]" << " [" << j << "]" << " [" << k << "]" << " " << ficha
                         << " en terreno " << tablero << endl;
                }
            }
        }
    }
    cout << contador << endl << endl;
}

void BatallaDigital::crearJugadores() {
    this->jugadores = new Lista<Jugador *>();
    string nombreJugador;
    Jugador *nuevoJugador = NULL;
    char simboloFicha = ' ';
    int cantidadJugadores = getCantidadJugadores();
    for (size_t i = 0; i < (size_t) cantidadJugadores; i++) {
        cout << "Ingrese el nombre del idJugador " << i + 1 << ":\n";
        cin >> nombreJugador;
        cout << "Ingrese la ficha del idJugador " << i + 1 << " (1 caracter):\n";
        cin >> simboloFicha;
        while (esFichaOcupadaPorOtroJugador(simboloFicha)) {
            cout << "[Error]: La ficha elegida ya esta en uso por otro idJugador, seleccione otra: ";
            cin >> simboloFicha;
        }
        nuevoJugador = new Jugador(nombreJugador, simboloFicha);
        nuevoJugador->setIdJugador(i + 1);

        this->jugadores->agregar(nuevoJugador);
    }
}

int BatallaDigital::getCantidadJugadores() {
    int inputCantidadJugadores = 0;
    cout << "Ingrese la cantidad de jugadores: \n";
    cin >> inputCantidadJugadores;
    while (inputCantidadJugadores < 2 || inputCantidadJugadores > 6) {
        cout << "[Error]: Deben jugar de 2 a 6 jugadores: ";
        cin >> inputCantidadJugadores;
    }
    return inputCantidadJugadores;
}

bool BatallaDigital::esFichaOcupadaPorOtroJugador(char simboloFichaElegido) {
    this->jugadores->iniciarCursor();
    while (this->jugadores->avanzarCursor()) {
        if (this->jugadores->obtenerCursor()->getFicha()->getElementoFicha() == simboloFichaElegido) {
            return true;
        }
    }
    return false;
}

void BatallaDigital::imprimirJugadores() {
    cout << "-----------JUGADORES DE LA PARTIDA ------------------\n";
    this->jugadores->iniciarCursor();
    while (this->jugadores->avanzarCursor()) {
        cout << "[" << (this->jugadores->obtenerCursor())->getIdJugador() << "]";
        cout << (this->jugadores->obtenerCursor())->getNombreJugador();
        cout << " con la ficha : " << this->jugadores->obtenerCursor()->getFicha()->getElementoFicha() << "\n";
    }
    cout << "-------------------------------------------\n";
}

void BatallaDigital::crearMazo() {
    cout << "Iniciando proceso de creacion de Mazo" << endl;
    Mazo *nuevoMazo = NULL;
    nuevoMazo = new Mazo(CANTIDAD_CARTAS_MAZO_PRINCIPAL);
    nuevoMazo->barajarMazo();
    this->mazo = nuevoMazo;
    cout << "Mazo creado satisfactoriamente" << endl;
}

void BatallaDigital::crearMazoPorJugador() {
    cout << "Iniciando proceso de repartision de cartas para el idJugador" << endl;
    this->jugadores->iniciarCursor();
    while (this->jugadores->avanzarCursor()) {
        Mazo *nuevoMazo = new Mazo();
        this->jugadores->obtenerCursor()->setMazo(nuevoMazo);
    }
    cout << "Proceso de repartision terminado " << endl;
}

void BatallaDigital::jugarJuego() {

    cout << "Jugar juego " << endl;
    bool hayJugadorUnicoConSoldados = false;
    int fila, columna, profundidad;
    char simboloFicha;
    while (!hayJugadorUnicoConSoldados) {
        this->cantidadJugadasRealizadas++;
        this->jugadorActual = turnos.desacolar();
        cout << "[ Ronda: " << this->cantidadJugadasRealizadas << " ] Es el turno del idJugador"
             << this->jugadorActual->getNombreJugador() << endl;


        if (this->mazo->getCantidadCartas() > 0 &&
            this->jugadorActual->getMazo()->getCantidadCartas() < CANTIDAD_CARTAS_MAZO_JUGADORES) {
            cout << "Repartiendo Cartas para los jugadores " << endl;
            this->repartirCartasAlJugadorActual();
        }

        char usarCarta;
        cout << "Desea usar la carta obtenida ? Ingrese 'S' " << endl;
        cin >> usarCarta;

        if (usarCarta == 'S') {
            int numeroCarta;
            cout << "Ingrese la carta que desea usar: " << endl;
            cin >> numeroCarta;
            this->usarCarta(numeroCarta);
        }
    }
}

void BatallaDigital::solicitarIngresoDeCordenadas(int &filas, int &columnas, int &profundidad) {
    cout << "Ingrese una fila :" << endl;
    cin >> filas;
    cout << "Ingrese una columna :" << endl;
    cin >> columnas;
    cout << "Ingrese una profundidad : " << endl;
    cin >> profundidad;
}

bool BatallaDigital::esFichaValida(int &fila, int &columna, int &profundidad) {
    bool esValido = true;
    if (!estaEnRangoValido(fila, columna, profundidad)) {
        cout << "->[Error]: ingresante un rango invalido, recuerda que va desde 1 al maximo,por favor ingrese devuelta"
             << endl;
        esValido = false;
    } else if (!estaCasilleroLibre(fila, columna, profundidad)) {
        cout << "->[Error]: La casilla ya se encuentra ocupada,por favor elige otra :\n";
        esValido = false;
    }
    return esValido;
}

bool BatallaDigital::estaEnRangoValido(int &fila, int &columna, int &profundidad) {
    int maxFilas = this->tableroPrincipal->getFila();
    int maxColumnas = this->tableroPrincipal->getColumna();
    int maxProfundidad = this->tableroPrincipal->getProfundidad();
    if (fila < 1 || fila > maxFilas || columna < 1 || columna > maxColumnas || profundidad < 1 ||
        profundidad > maxProfundidad) {
        return false;
    }
    return true;
}

bool BatallaDigital::estaCasilleroLibre(int &fila, int &columna, int &profundidad) {
    return (this->tableroPrincipal->obtenerCasillero(fila, columna, profundidad)->estaCasilleroVacio());

}

void BatallaDigital::repartirCartasAlJugadorActual() {
    Carta *carta = this->mazo->obtenerCartaSuperior();
    this->jugadorActual->getMazo()->agregarCarta(carta);
    cout << "Jugador: " << this->jugadorActual->getNombreJugador() << endl;
    cout << "Obtuviste la carta " << endl;
    carta->imprimirHabilidadCarta();
}

void BatallaDigital::iniciarTurnos() {
    this->jugadores->iniciarCursor();
    while (this->jugadores->avanzarCursor()) {
        this->turnos.acolar(this->jugadores->obtenerCursor());
    }
}

void BatallaDigital::usarCarta(int numero) {
    if (this->jugadorActual->getMazo()->getCantidadCartas() >= numero) {
        Carta *carta = this->jugadorActual->getMazo()->getMazoCartas().obtener(numero);
        aplicarHabilidadCarta(carta);
        this->jugadorActual->getMazo()->eliminarCarta(numero);
        delete carta;
    }
}

void BatallaDigital::aplicarHabilidadCarta(Carta *carta) {
    habilidadCarta_t habilidad = carta->getHabilidad();
    if (habilidad == CARTA_DETECTAR_MINA) {
        carta->detectarMinas(this->tableroPrincipal);
    } else if (habilidad == CARTA_DISPARAR_MISIL) {
        carta->dispararMisil();
    } else if (habilidad == CARTA_ATAQUE_QUIMICO) {
        carta->ataqueQuimico();
    } else if (habilidad == CARTA_DESARMAR_SOLDADO) {
        carta->desarmarSoldados();
    } else if (habilidad == CARTA_ATAQUE_MULTIPLE) {
        carta->ataqueMultiple();
    } else if (habilidad == CARTA_AUMENTAR_RESISTENCIA) {
        carta->aumentarResistencia(this->tableroPrincipal);
    }
}

void BatallaDigital::crearSoldados() {
    this->jugadores->iniciarCursor();
    while (this->jugadores->avanzarCursor()) {
        Jugador * jugador = this->jugadores->obtenerCursor();
        int cantidadSoldados, cantidadBarcos, cantidadAviones, cantidadMinas;
        cout << endl << endl;
        cout << "Se iniciara la creacion de soldados" << endl;
        cout << "La creacion de soldados es tolamente automatica, no hace falta ingresar posiciones" << endl;
        cout << "Usted tiene " << jugador->getCantidadInsertsRestantes() << " . Puede decir que cantidad de soldados/armamento puede crear";
        cout << "Cuantos soldados quiere agregar: ";
        cin >> cantidadSoldados;
        generarPosiciones(cantidadSoldados, 'S', jugador);
        /*
        cout << endl << "Cuantos Barcos quiere agregar: ";
        cin >> cantidadBarcos;
        generarPosiciones(cantidadBarcos, 'B', idJugador);
        cout << endl << "Cuantos aviones quiere agregar ";
        cin >> cantidadAviones;
        generarPosiciones(cantidadAviones, 'A', idJugador);
        cout << endl << "Cuantas minas quiere agregar ";
        cin >> cantidadMinas;
        generarPosiciones(cantidadMinas, 'M', idJugador);
         */
    }
}

void BatallaDigital::generarPosiciones(int cantidadElementos, char simboloFicha, Jugador * jugador) {
    for (int i = 0; i < jugador->getCantidadInsertsRestantes(); i++) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(1, 10);
        int fila = dist(gen), columna = dist(gen), profundidad = dist(gen);
        //char simboloFicha;
        //cout << "Debe colocar un soldado o un armamento" << endl;
        //cout << "Ingresar el simbolo de su ficha, S (soldado) o A (armamento): ";
        //cin >> simboloFicha;
        //this->solicitarIngresoDeCordenadas(fila, columna, profundidad);
        while (!esFichaValida(fila, columna, profundidad)) {
//        this->solicitarIngresoDeCordenadas(fila, columna, profundidad);
            fila = dist(gen), columna = dist(gen), profundidad = dist(gen);
        }
        tableroPrincipal->setCasilla(fila, columna, profundidad, simboloFicha, jugador->getIdJugador());
        cout << "Se inserto la casilla [" << fila << "][" << columna << "][" << profundidad << "] = " << simboloFicha
             << endl << endl;
    }
}

void BatallaDigital::obtenerCantidadDeInsertsPorJugador() {
    this->cantidadInsertsPorJugador = this->tableroPrincipal->obtenerCantidadDePosiciones() / this->jugadores->contarElementos();
    this->jugadores->iniciarCursor();
    while (this->jugadores->avanzarCursor()) {
        this->jugadores->obtenerCursor()->setCantidadInsertsRestantes(cantidadInsertsPorJugador);
    }
}

