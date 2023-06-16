#include "BatallaDigital.h"
#include "Jugador.h"
#include <cstdlib>
#include <ctime>
#include "Interface.h"

using namespace std;

BatallaDigital::BatallaDigital() {
    this->tableroPrincipal = NULL;
    this->cantidadJugadasRealizadas = 0;
    this->mazo = NULL;
    this->jugadores = NULL;
    this->jugadorActual = NULL;
    this->hayGanador = false;
}

void BatallaDigital::deleteMazoJugadores() {
    this->jugadores->iniciarCursor();
    while (this->jugadores->avanzarCursor()) {
        this->jugadores->obtenerCursor()->getMazo()->destruirMazo();
        delete this->jugadores->obtenerCursor()->getMazo();
    }
}

void BatallaDigital::deleteJugadores() {
    this->jugadores->iniciarCursor();
    while (this->jugadores->avanzarCursor()) {
        this->jugadores->obtenerCursor()->destruirFichaJugador();
        delete this->jugadores->obtenerCursor();
    }
}

void BatallaDigital::deleteMazoPrincipal() {
    this->mazo->destruirMazo();
    delete this->mazo;
}

BatallaDigital::~BatallaDigital() {
    this->deleteMazoJugadores();
    this->deleteJugadores();
    this->deleteMazoPrincipal();
    delete this->tableroPrincipal;
}

void BatallaDigital::iniciarJuego() {
    cout << "--------------->Bienvenido a la Batalla Digital<-----------------------\n";
    this->crearTableroPrincipal();
    this->crearJugadores();
    this->imprimirJugadores();
    this->crearMazo();
    this->crearMazoPorJugador();
    this->obtenerCantidadDeInsertsPorJugador();
    this->limpiarConsola();
    this->crearArmamentoDelJugador();
    this->limpiarConsola();
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

    while (fila < 6 || columna < 6 || profundidad < 6) {
        cout << "[Error]: La cantidad de filas, columnas y profundidad debe ser mayor o igual a 7" << endl;
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
    for (int i = 1; i <= tablero->getFila(); i++) {
        for (int j = 1; j <= tablero->getColumna(); j++) {
            for (int k = 1; k <= tablero->getProfundidad(); k++) {
                int id = tablero->obtenerCasillero(i, j, k)->getFicha()->getIdJugador();
                cout << "Casillero [" << i << "]" << " [" << j << "]" << " [" << k << "]" << " " << id
                     << " " << tableroPrincipal->obtenerCasillero(i, j, k)->getFicha()->getElementoFicha() << endl;
            }
        }
    }
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
    cout << "Proceso de reparticion terminado " << endl;
}

void BatallaDigital::jugarJuego() {

    cout << "Jugar juego " << endl;
    int fila, columna, profundidad;
    while (!this->hayGanador) {
        this->cantidadJugadasRealizadas++;
        this->jugadorActual = turnos.desacolar();
        cout << "[ RONDA: " << this->cantidadJugadasRealizadas << " ] ES EL TURNO DEL JUGADOR: "
             << this->jugadorActual->getNombreJugador() << endl << endl;
        cout << "revise las imagenes para ver el estado del tablero" << endl;
        mostrarTablero(this->tableroPrincipal, jugadorActual->getIdJugador());
        this->repartirCartas();
        this->elegirCarta();
        this->limpiarConsola();
        this->agregarMina(fila, columna, profundidad);
        this->decidirMoverSoldadoArmamento(fila, columna, profundidad);
        this->limpiarConsola();
        this->decrementarTurnosFichas();
        this->desbloquearFichas();
        this->actualizarArmamento();
        this->avanzarTurno();
    }
    cout << "FELICIDADES: " << this->nombreJugadorGanador << endl;
}

void BatallaDigital::repartirCartas() {
    if (mazo->getCantidadCartas() > 0 &&
        jugadorActual->getMazo()->getCantidadCartas() < CANTIDAD_CARTAS_MAZO_JUGADORES) {
        cout << "REPARTIENDO CARTAS PARA LOS JUGADORES " << endl << endl;
        this->repartirCartasAlJugadorActual();
    }
}

void BatallaDigital::elegirCarta() {
    jugadorActual->getMazo()->imprimirMazo();
    char usarCarta;
    cout << endl << "DESEA USAR LA CARTA OBTENIDA. Ingrese 'S' SI ES AFIRMATIVO " << endl;
    cin >> usarCarta;
    if (usarCarta == 'S') {
        int numeroCarta;
        cout << "INGRESE EL NUMERO DE CARTA QUE DESEA UTILIZAR: " << endl;
        cin >> numeroCarta;
        this->usarCarta(numeroCarta);
    }
}

void BatallaDigital::agregarMina(int fila, int columna, int profundidad) {
    cout << "Ahora Debes ingresar una mina" << endl;
    solicitarIngresoDeCordenadas(fila, columna, profundidad);
    while (!(esFichaRangoValida(fila, columna, profundidad))) {
        solicitarIngresoDeCordenadas(fila, columna, profundidad);
    }
    Ficha *ficha = tableroPrincipal->obtenerCasillero(fila, columna, profundidad)->getFicha();
    if (!ficha->getBloqueada() && ficha->getElementoFicha() == VACIO &&
        ficha->getIdJugador() != jugadorActual->getIdJugador() &&
        tableroPrincipal->obtenerCasillero(fila, columna, profundidad)->getTerreno() == TIERRA) {
        tableroPrincipal->setCasilla(fila, columna, profundidad, MINA, jugadorActual->getIdJugador());
        cout << "MINA INSERTADA, ESPEREMOS QUE ALGUIEN LA PISE JEJE" << endl;
    } else if (ficha->getElementoFicha() != VACIO) {
        ficha->bloquear(5);
        cout << "UN SOLDADO MURIO, PUEDE SER ENEMIGO O UN SOLDADO COMPAÑERO. ATENTO A DONDE TIRAS LAS MINAS" << endl;
    } else if (tableroPrincipal->obtenerCasillero(fila, columna, profundidad)->getTerreno() != TIERRA) {
        cout << "La mina se ha perdido, recuerde que solo se pueden ubicar minas en las coordenadas donde haya tierra"
             << endl;
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
    if (!estaEnRangoValido(fila, columna, profundidad)) {
        cout << "->[Error]: ingresante un rango invalido, recuerda que va desde 1 al maximo,por favor ingrese devuelta"
             << endl;
        return false;
    } else if (!estaCasilleroLibre(fila, columna, profundidad)) {
        cout << "->[Error]: La casilla ya se encuentra ocupada,por favor elige otra :\n";
        return false;
    }
    return true;
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
    cout << "JUGADOR: " << this->jugadorActual->getNombreJugador() << endl;
    cout << "OBTUVISTE LA CARTA " << endl;
    carta->imprimirHabilidadCarta();
}

void BatallaDigital::iniciarTurnos() {
    this->jugadores->iniciarCursor();
    while (this->jugadores->avanzarCursor()) {
        this->turnos.acolar(this->jugadores->obtenerCursor());
    }
}

void BatallaDigital::usarCarta(int numero) {
    if (((int) (this->jugadorActual->getMazo()->getCantidadCartas())) >= numero) {
        Carta *carta = this->jugadorActual->getMazo()->getMazoCartas().obtener(numero);
        aplicarHabilidadCarta(carta);
        this->jugadorActual->getMazo()->eliminarCarta(numero);
        delete carta;
    }
}

void BatallaDigital::aplicarHabilidadCarta(Carta *carta) {
    habilidadCarta_t habilidad = carta->getHabilidad();
    if (habilidad == CARTA_AVION_RADAR) {
        carta->avionRadar(this->tableroPrincipal, this->jugadorActual->getIdJugador());
    } else if (habilidad == CARTA_DISPARAR_MISIL) {
        carta->dispararMisil(this->tableroPrincipal, this->jugadorActual->getIdJugador());
    } else if (habilidad == CARTA_ATAQUE_QUIMICO) {
        carta->ataqueQuimico(this->tableroPrincipal);
    } else if (habilidad == CARTA_AVION_KAMIKAZE) {
        carta->avionKamikaze(this->tableroPrincipal, this->jugadorActual->getIdJugador());
    } else if (habilidad == CARTA_TORMENTA_ELECTRICA) {
        carta->tormentaElectrica(this->tableroPrincipal);
    } else if (habilidad == CARTA_FRANCOTIRADOR) {
        carta->francotirador(this->tableroPrincipal, this->jugadorActual->getIdJugador());
    }
}

void BatallaDigital::crearArmamentoDelJugador() {
    this->jugadores->iniciarCursor();
    while (this->jugadores->avanzarCursor()) {
        Jugador *jugador = this->jugadores->obtenerCursor();
        int cantidadSoldados, cantidadBarcos, cantidadAviones;
        cout << endl << endl;
        cout << "JUGADOR: " << jugador->getNombreJugador() << endl << endl;
        cout << "SE INICIARA LA CREACION DE ARMAMENTO, TANTO SOLDADOS COMO BARCOS Y AVIONES" << endl << endl;
        cout << "LA CREACION DE SOLDADOS ES AUTOMATICA, NO HACE FALTA INGRESAR POSICIONES" << endl;
        cout << "USTED TIENE: " << jugador->getCantidadInsertsRestantes()
             << " .PUEDE DECIR QUE CANTIDAD DE ARMAMENTO CREAR, TANTO COMO SOLDADOS, BARCOS Y AVIONES" << endl << endl;
        cout << "CUANTOS SOLDADOS QUIERE AGREGAR: ";
        cin >> cantidadSoldados;
        while (this->validarInsertsDisponibles(cantidadSoldados, jugador->getCantidadInsertsRestantes()) ||
               (cantidadSoldados > (this->tableroPrincipal->getFila() * this->tableroPrincipal->getColumna() * 2 /
                                    jugadores->contarElementos()))) {
            cout << "SON DEMASIADOS, PUEDE AGREGAR HASTA "<<(this->tableroPrincipal->getColumna()) * ( this->tableroPrincipal->getColumna()) * 2 / (jugadores->contarElementos())<< " SOLDADOS, CUANTOS SOLDADOS QUIERE AGREGAR: ";
            cin >> cantidadSoldados;
        }
        generarPosiciones(cantidadSoldados, 'S', jugador);
        cout << endl << endl;
        cout << "USTED TIENE: " << jugador->getCantidadInsertsRestantes()
             << " .PUEDE DECIR QUE CANTIDAD DE ARMAMENTO CREAR, TANTO COMO SOLDADOS, BARCOS Y AVIONES" << endl;
        cout << endl << "CUANTOS BARCOS QUIERE AGREGAR: ";
        cin >> cantidadBarcos;
        while ((this->validarInsertsDisponibles(cantidadBarcos, jugador->getCantidadInsertsRestantes())) ||
               (cantidadBarcos > (this->tableroPrincipal->getFila() * this->tableroPrincipal->getColumna() * 3 /
                                  jugadores->contarElementos()))) {
            cout << "BARCOS DE MAS, SOLO PUEDE AGREGAR "<<(this->tableroPrincipal->getColumna()) * ( this->tableroPrincipal->getColumna()) * 3 / (jugadores->contarElementos())<<" BARCOS, CUANTOS BARCOS QUIERE AGREGAR:" << endl;
            cin >> cantidadBarcos;
        }
        generarPosiciones(cantidadBarcos, 'B', jugador);
        cout << "Usted tiene " << jugador->getCantidadInsertsRestantes()
             << " . Puede decir que cantidad de soldados/armamento puede crear" << endl;
        cout << endl << "Cuantos aviones quiere agregar ";
        cin >> cantidadAviones;
        while (this->validarInsertsDisponibles(cantidadAviones, jugador->getCantidadInsertsRestantes()) ||
               (cantidadAviones > (this->tableroPrincipal->getFila() * this->tableroPrincipal->getColumna() *
                                   (this->tableroPrincipal->getProfundidad() - 5) / jugadores->contarElementos()))) {
            cout << "aviones de mas, solo puede agregar "<<(this->tableroPrincipal->getColumna()) * ( this->tableroPrincipal->getColumna()) * (this->tableroPrincipal->getProfundidad() -5) / (jugadores->contarElementos())<<" aviones, Cuantos aviones quiere agregar: ";
            cin >> cantidadAviones;
        }
        generarPosiciones(cantidadAviones, 'A', jugador);
        this->limpiarConsola();
    }

}

bool BatallaDigital::validar(int fila, int columna, int profundidad, terreno_t terreno) {
    if (!esFichaValida(fila, columna, profundidad)) {
        return false;
    }
    if (esFichaValida(fila, columna, profundidad)) {
        if (this->tableroPrincipal->obtenerCasillero(fila, columna, profundidad)->getTerreno() == terreno) {
            return true;
        }
    }
    return false;
}

void BatallaDigital::generarPosiciones(int cantidadElementos, char simboloFicha, Jugador *jugador) {
    terreno_t terreno;
    if (simboloFicha == SOLDADO) {
        terreno = TIERRA;
    }
    if (simboloFicha == BARCO) {
        terreno = AGUA;
    }
    if (simboloFicha == AVION) {
        terreno = AIRE;
    }
    for (int i = 0; i < cantidadElementos; i++) {
        std::srand(std::time(NULL));
        int fila = (1 + std::rand() % (this->tableroPrincipal->getFila() - 1));
        int columna = (1 + std::rand() % (this->tableroPrincipal->getColumna() - 1));
        int profundidad = (1 + std::rand() % (this->tableroPrincipal->getProfundidad() - 1));
        while (!validar(fila, columna, profundidad, terreno)) {
            fila = (1 + std::rand() % (this->tableroPrincipal->getFila() - 1));
            columna = (1 + std::rand() % (this->tableroPrincipal->getColumna() - 1));
            profundidad = (1 + std::rand() % (this->tableroPrincipal->getProfundidad() - 1));
        }
        tableroPrincipal->setCasilla(fila, columna, profundidad, simboloFicha, jugador->getIdJugador());
        cout << "Se inserto la casilla [" << fila << "][" << columna << "][" << profundidad << "] = " << simboloFicha
             << endl << endl;
    }
    jugador->setCantidadInsertsRestantes(jugador->getCantidadInsertsRestantes() - cantidadElementos);
}

void BatallaDigital::obtenerCantidadDeInsertsPorJugador() {
    this->cantidadInsertsPorJugador =
            this->tableroPrincipal->obtenerCantidadDePosiciones() / this->jugadores->contarElementos();
    this->jugadores->iniciarCursor();
    while (this->jugadores->avanzarCursor()) {
        this->jugadores->obtenerCursor()->setCantidadInsertsRestantes(cantidadInsertsPorJugador);
    }
}

bool BatallaDigital::validarInsertsDisponibles(int cantidadElementos, int insertsDisponibles) {
    bool esInsertValido = false;
    if (cantidadElementos > insertsDisponibles) {
        esInsertValido = true;
    }
    return esInsertValido;
}

bool BatallaDigital::esFichaRangoValida(int fila, int columna, int profundidad) {
    bool esValido = true;
    if (!estaEnRangoValido(fila, columna, profundidad)) {
        cout << "->[Error]: ingresante un rango invalido, recuerda que va desde 1 al maximo,por favor ingrese devuelta"
             << endl;
        esValido = false;
    }
    return esValido;
}

void BatallaDigital::decidirMoverSoldadoArmamento(int fila, int columna, int profundidad) {
    cout << "Ahora Debes  mover un soldado o un armamento (AVION O BARCO)" << endl;
    cout << "Elige un soldado tuyo:" << endl;
    solicitarIngresoDeCordenadas(fila, columna, profundidad);
    while (!(esFichaRangoValida(fila, columna, profundidad))) {
        solicitarIngresoDeCordenadas(fila, columna, profundidad);
    }
    char movimiento;
    cout << "Ingrese Movimiento (movimientos validos: w,s,a,d,x,z (puede ser en mayuscula))" << endl;
    cin >> movimiento;

    int nuevaProfundidad;
    cout << "Ingrese la nueva profundidad, debe ser 1 mayor o menor que la del soldado elegido" << endl;
    cin >> nuevaProfundidad;
    if (validarSoldadoArmamentoElegido(fila, columna, profundidad) && validarMovimiento(movimiento) &&
        (this->tableroPrincipal->obtenerCasillero(fila, columna, profundidad)->getTerreno() ==
         this->tableroPrincipal->obtenerCasillero(fila, columna, nuevaProfundidad)->getTerreno())) {
        moverElemento(fila, columna, profundidad, movimiento, nuevaProfundidad);
    } else {
        cout << "Perdiste Un turno por haber elegido mal, sorry :( " << endl;
    }
}

void BatallaDigital::moverElemento(int fila, int columna, int profundidad, char movimiento, int nuevaProfundidad) {
    switch (movimiento) {
        case 'w':
        case 'W': {
            this->tableroPrincipal->setCasilla(fila, columna, profundidad, VACIO, 0);
            if (esPosicionBloqueada(fila - 1, columna, nuevaProfundidad)) {
                cout << "Es Posicion bloqueada, perdiste un turno " << endl;
            } else if (existeMina(fila - 1, columna, nuevaProfundidad)) {
                eliminarSoldado(fila - 1, columna, nuevaProfundidad);
            } else if (existeSoldadoEnemigo(fila - 1, columna, nuevaProfundidad)) {
                this->tableroPrincipal->setCasilla(fila - 1, columna, nuevaProfundidad, VACIO, 0);
            } else if (this->tableroPrincipal->obtenerCasillero(fila, columna, profundidad)->getTerreno() !=
                       this->tableroPrincipal->obtenerCasillero(fila - 1, columna, profundidad)->getTerreno()) {
                cout << "te moviste a un bioma no adecuado, se ha predido el turno" << endl;

            } else {
                this->tableroPrincipal->setCasilla(fila - 1, columna, nuevaProfundidad, SOLDADO,
                                                   this->jugadorActual->getIdJugador());
            }
            break;
        }
        case 's':
        case 'S': {
            this->tableroPrincipal->setCasilla(fila, columna, profundidad, VACIO, 0);
            if (esPosicionBloqueada(fila + 1, columna, nuevaProfundidad)) {
                cout << "Es Posicion bloqueada, perdiste un turno" << endl;
            } else if (existeMina(fila + 1, columna, nuevaProfundidad)) {
                eliminarSoldado(fila + 1, columna, nuevaProfundidad);
            } else if (existeSoldadoEnemigo(fila + 1, columna, nuevaProfundidad)) {
                this->tableroPrincipal->setCasilla(fila + 1, columna, nuevaProfundidad, VACIO, 0);
            } else if (this->tableroPrincipal->obtenerCasillero(fila, columna, profundidad)->getTerreno() !=
                       this->tableroPrincipal->obtenerCasillero(fila + 1, columna, profundidad)->getTerreno()) {
                cout << "te moviste a un bioma no adecuado, se ha predido el turno" << endl;

            } else {
                this->tableroPrincipal->setCasilla(fila + 1, columna, nuevaProfundidad, SOLDADO,
                                                   this->jugadorActual->getIdJugador());
            }
            break;
        }
        case 'a':
        case 'A': {
            this->tableroPrincipal->setCasilla(fila, columna, profundidad, VACIO, 0);
            if (esPosicionBloqueada(fila, columna - 1, nuevaProfundidad)) {
                cout << "Es Posicion bloqueada, perdiste un turno boludo " << endl;
            } else if (existeMina(fila, columna - 1, nuevaProfundidad)) {
                eliminarSoldado(fila, columna - 1, nuevaProfundidad);
            } else if (existeSoldadoEnemigo(fila, columna - 1, nuevaProfundidad)) {
                this->tableroPrincipal->setCasilla(fila, columna - 1, nuevaProfundidad, VACIO, 0);
            } else if (this->tableroPrincipal->obtenerCasillero(fila, columna, profundidad)->getTerreno() !=
                       this->tableroPrincipal->obtenerCasillero(fila, columna - 1, profundidad)->getTerreno()) {
                cout << "te moviste a un bioma no adecuado, se ha predido el turno" << endl;

            } else {
                this->tableroPrincipal->setCasilla(fila, columna - 1, nuevaProfundidad, SOLDADO,
                                                   this->jugadorActual->getIdJugador());
            }
            break;
        }
        case 'd':
        case 'D': {
            this->tableroPrincipal->setCasilla(fila, columna, profundidad, VACIO, 0);
            if (esPosicionBloqueada(fila, columna + 1, nuevaProfundidad)) {
                cout << "Es Posicion bloqueada, perdiste un turno boludo " << endl;
            } else if (existeMina(fila, columna + 1, nuevaProfundidad)) {
                eliminarSoldado(fila, columna + 1, nuevaProfundidad);
            } else if (existeSoldadoEnemigo(fila, columna + 1, nuevaProfundidad)) {
                this->tableroPrincipal->setCasilla(fila, columna + 1, nuevaProfundidad, VACIO, 0);
            } else if (this->tableroPrincipal->obtenerCasillero(fila, columna, profundidad)->getTerreno() !=
                       this->tableroPrincipal->obtenerCasillero(fila, columna + 1, profundidad)->getTerreno()) {
                cout << "te moviste a un bioma no adecuado, se ha predido el turno" << endl;

            } else {
                this->tableroPrincipal->setCasilla(fila, columna + 1, nuevaProfundidad, SOLDADO,
                                                   this->jugadorActual->getIdJugador());
            }
            break;
        }
        case 'q':
        case 'Q': {
            this->tableroPrincipal->setCasilla(fila, columna, profundidad, VACIO, 0);
            if (esPosicionBloqueada(fila - 1, columna - 1, nuevaProfundidad)) {
                cout << "Es Posicion bloqueada, perdiste un turno boludo " << endl;
            } else if (existeMina(fila - 1, columna - 1, nuevaProfundidad)) {
                eliminarSoldado(fila - 1, columna - 1, nuevaProfundidad);
            } else if (existeSoldadoEnemigo(fila - 1, columna - 1, nuevaProfundidad)) {
                this->tableroPrincipal->setCasilla(fila - 1, columna - 1, nuevaProfundidad, VACIO, 0);
            } else if (this->tableroPrincipal->obtenerCasillero(fila, columna, profundidad)->getTerreno() !=
                       this->tableroPrincipal->obtenerCasillero(fila - 1, columna - 1, profundidad)->getTerreno()) {
                cout << "te moviste a un bioma no adecuado, se ha predido el turno" << endl;

            } else {
                this->tableroPrincipal->setCasilla(fila - 1, columna - 1, nuevaProfundidad, SOLDADO,
                                                   this->jugadorActual->getIdJugador());
            }
            break;
        }
        case 'e':
        case 'E': {
            this->tableroPrincipal->setCasilla(fila, columna, profundidad, VACIO, 0);
            if (esPosicionBloqueada(fila - 1, columna + 1, nuevaProfundidad)) {
                cout << "Es Posicion bloqueada, perdiste un turno boludo " << endl;
            } else if (existeMina(fila - 1, columna + 1, nuevaProfundidad)) {
                eliminarSoldado(fila - 1, columna + 1, nuevaProfundidad);
            } else if (existeSoldadoEnemigo(fila - 1, columna + 1, nuevaProfundidad)) {
                this->tableroPrincipal->setCasilla(fila - 1, columna + 1, nuevaProfundidad, VACIO, 0);
            } else if (this->tableroPrincipal->obtenerCasillero(fila, columna, profundidad)->getTerreno() !=
                       this->tableroPrincipal->obtenerCasillero(fila - 1, columna + 1, profundidad)->getTerreno()) {
                cout << "te moviste a un bioma no adecuado, se ha predido el turno" << endl;

            } else {
                this->tableroPrincipal->setCasilla(fila - 1, columna + 1, nuevaProfundidad, SOLDADO,
                                                   this->jugadorActual->getIdJugador());
            }
            break;
        }
        case 'z':
        case 'Z': {
            this->tableroPrincipal->setCasilla(fila, columna, profundidad, VACIO, 0);
            if (esPosicionBloqueada(fila + 1, columna - 1, nuevaProfundidad)) {
                cout << "Es Posicion bloqueada, perdiste un turno boludo " << endl;
            } else if (existeMina(fila + 1, columna - 1, nuevaProfundidad)) {
                eliminarSoldado(fila + 1, columna - 1, nuevaProfundidad);
            } else if (existeSoldadoEnemigo(fila + 1, columna - 1, nuevaProfundidad)) {
                this->tableroPrincipal->setCasilla(fila + 1, columna - 1, nuevaProfundidad, VACIO, 0);
            } else if (this->tableroPrincipal->obtenerCasillero(fila, columna, profundidad)->getTerreno() !=
                       this->tableroPrincipal->obtenerCasillero(fila + 1, columna - 1, profundidad)->getTerreno()) {
                cout << "te moviste a un bioma no adecuado, se ha predido el turno" << endl;

            } else {
                this->tableroPrincipal->setCasilla(fila + 1, columna - 1, nuevaProfundidad, SOLDADO,
                                                   this->jugadorActual->getIdJugador());
            }
            break;
        }
        case 'x':
        case 'X': {
            this->tableroPrincipal->setCasilla(fila, columna, profundidad, VACIO, 0);
            if (esPosicionBloqueada(fila + 1, columna + 1, nuevaProfundidad)) {
                cout << "Es Posicion bloqueada, perdiste un turno boludo " << endl;
            } else if (existeMina(fila + 1, columna + 1, nuevaProfundidad)) {
                eliminarSoldado(fila + 1, columna + 1, nuevaProfundidad);
            } else if (existeSoldadoEnemigo(fila + 1, columna + 1, nuevaProfundidad)) {
                this->tableroPrincipal->setCasilla(fila + 1, columna + 1, nuevaProfundidad, VACIO, 0);
            } else if (this->tableroPrincipal->obtenerCasillero(fila, columna, profundidad)->getTerreno() !=
                       this->tableroPrincipal->obtenerCasillero(fila + 1, columna + 1, profundidad)->getTerreno()) {
                cout << "te moviste a un bioma no adecuado, se ha predido el turno" << endl;

            } else {
                this->tableroPrincipal->setCasilla(fila + 1, columna + 1, nuevaProfundidad, SOLDADO,
                                                   this->jugadorActual->getIdJugador());
            }
            break;
        }
    }
}

bool BatallaDigital::validarMovimiento(char movimiento) {
    bool esMovimientoValido = false;
    if (movimiento == 'w' || movimiento == 'W' || movimiento == 'a' || movimiento == 'A' ||
        movimiento == 's' || movimiento == 'S' || movimiento == 'd' || movimiento == 'D' ||
        movimiento == 'z' || movimiento == 'Z' || movimiento == 'x' || movimiento == 'X') {
        esMovimientoValido = true;
    }
    return esMovimientoValido;
}

bool BatallaDigital::validarSoldadoArmamentoElegido(int fila, int columna, int profundidad) {
    Ficha *ficha = this->tableroPrincipal->obtenerCasillero(fila, columna, profundidad)->getFicha();
    if (ficha->getIdJugador() == this->jugadorActual->getIdJugador() && ficha->getElementoFicha() == SOLDADO) {
        return true;
    }
    return false;
}

bool BatallaDigital::existeMina(int fila, int columna, int profundidad) {
    Ficha *ficha = this->tableroPrincipal->obtenerCasillero(fila, columna, profundidad)->getFicha();
    if (ficha->getElementoFicha() == MINA && ficha->getIdJugador() != this->jugadorActual->getIdJugador()) {
        return true;
    }
    return false;
}

void BatallaDigital::eliminarSoldado(int fila, int columna, int profundidad) {
    Ficha *ficha = this->tableroPrincipal->obtenerCasillero(fila, columna, profundidad)->getFicha();
    actualizarArmamento(ficha);
    ficha->bloquear(5);
}

void BatallaDigital::actualizarArmamento(const Ficha *ficha) {
    jugadores->iniciarCursor();
    while (jugadores->avanzarCursor()) {
        Jugador *jugador = jugadores->obtenerCursor();
        if (jugador->getIdJugador() == ficha->getIdJugador()) {
            jugador->decrementarElementosVivos();
            break;
        }
    }
}

bool BatallaDigital::existeSoldadoEnemigo(int fila, int columna, int profundidad) {
    Ficha *ficha = this->tableroPrincipal->obtenerCasillero(fila, columna, profundidad)->getFicha();
    if (ficha->getElementoFicha() == SOLDADO && ficha->getIdJugador() != this->jugadorActual->getIdJugador()) {
        return true;
    }
    return false;
}

bool BatallaDigital::esPosicionBloqueada(int fila, int columna, int profundidad) {
    Ficha *ficha = this->tableroPrincipal->obtenerCasillero(fila, columna, profundidad)->getFicha();
    if (ficha->getBloqueada()) {
        return true;
    }
    return false;
}

void BatallaDigital::decrementarTurnosFichas() {
    for (int i = 1; i <= this->tableroPrincipal->getFila(); i++) {
        for (int j = 1; j <= this->tableroPrincipal->getColumna(); j++) {
            for (int k = 1; k <= this->tableroPrincipal->getProfundidad(); k++) {
                Ficha *ficha = this->tableroPrincipal->obtenerCasillero(i, j, k)->getFicha();
                if (ficha->getBloqueada()) {
                    ficha->decrementarTurnosRestantesDesbloqueo();
                }
            }
        }
    }
}

void BatallaDigital::desbloquearFichas() {
    for (int i = 1; i <= this->tableroPrincipal->getFila(); i++) {
        for (int j = 1; j <= this->tableroPrincipal->getColumna(); j++) {
            for (int k = 1; k <= this->tableroPrincipal->getProfundidad(); k++) {
                Ficha *ficha = this->tableroPrincipal->obtenerCasillero(i, j, k)->getFicha();
                if (ficha->getBloqueada() && ficha->getTurnosRestantesParaDesbloqueo() == 0) {
                    ficha->desbloquearFicha();
                }
            }
        }
    }
}

void BatallaDigital::avanzarTurno() {
    this->turnos.acolar(this->jugadorActual);
}

void BatallaDigital::actualizarArmamento() {
    this->jugadores->iniciarCursor();
    while (this->jugadores->avanzarCursor()) {
        this->jugadores->obtenerCursor()->setCantidadElementosVivos(0);
    }
    
    for (int i = 1; i <= this->tableroPrincipal->getFila(); i++) {
        for (int j = 1; j <= this->tableroPrincipal->getColumna(); j++) {
            for (int k = 1; k <= this->tableroPrincipal->getProfundidad(); k++) {
                Ficha *ficha = this->tableroPrincipal->obtenerCasillero(i, j, k)->getFicha();
                this->jugadores->iniciarCursor();
                while (this->jugadores->avanzarCursor()) {
                    Jugador *jugador = this->jugadores->obtenerCursor();
                    if (jugador->getIdJugador() == ficha->getIdJugador() && ficha->getElementoFicha() == SOLDADO) {
                        jugador->aumentarElementosVivos();
                    }
                }
            }
        }
    }

    int cantidadJugadoresConSoldados = 0;
    string nombreGanador;
    this->jugadores->iniciarCursor();
    while (this->jugadores->avanzarCursor()) {
        Jugador *jugador = this->jugadores->obtenerCursor();
        if (jugador->getCantidadElementosVivos() > 0) {
            cantidadJugadoresConSoldados++;
            nombreGanador = jugador->getNombreJugador();
        }
    }

    if (cantidadJugadoresConSoldados == 1) {
        this->setNombreJugadorGanador(nombreGanador);
        this->setHayGanador(true);
    } else {
        this->setHayGanador(false);
    }
}

void BatallaDigital::limpiarConsola() {
    system("cls");
}

bool BatallaDigital::isHayGanador() const {
    return hayGanador;
}

void BatallaDigital::setHayGanador(bool hayGanador) {
    BatallaDigital::hayGanador = hayGanador;
}

const string &BatallaDigital::getNombreJugadorGanador() const {
    return nombreJugadorGanador;
}

void BatallaDigital::setNombreJugadorGanador(const string &nombreJugadorGanador) {
    BatallaDigital::nombreJugadorGanador = nombreJugadorGanador;
}


