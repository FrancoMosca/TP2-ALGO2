#include "BatallaDigital.h"

using namespace std;

BatallaDigital::BatallaDigital() {
    this->tableroPrincipal = NULL;
}

BatallaDigital::~BatallaDigital() {

}

void BatallaDigital::iniciarJuego() {
    cout << "--------------->Bienvenido a la Batalla Digital<-----------------------\n";
    this->crearTableroPrincipal();

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

    while(fila < 2 || columna< 2 || profundidad < 2) {
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
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                char ficha = this->tableroPrincipal->obtenerCasillero(i, j, k)->getFicha()->getElementoFicha();
                cout << "Casillero [" << i << "]" << " [" << j << "]" << " [" << k << "]" << ficha;
            }
        }
    }
}




