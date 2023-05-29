#ifndef CARTA_H_
#define CARTA_H_

#include <string>

#include "Tablero.h"
#include "Mina.h"

class Carta
{

private:

    int x,y,z;
    bool activo;
    int contador;
    int radio;
    std::string tipo;

public:

    Carta(int x,int y,int z,bool activo,int contador,int radio,std::string tipo);

    //Metodos compartidos
    void obtenerRango (std::string tipo);

    //Metodos carta avion
    void detectarMinas(Tablero* tablero);

    //Metodos carta barco
    void dispararMisil();

    //Metodos ataque quimico
    void ataqueQuimico();

    //Metodos granada
    void desarmarSoldados();

    //Metodos ataque multiple
    void ataqueMultiple();

    //Metodos escudo
    void aumentarResistencia();

    virtual ~Carta();

 static std::string obtenerTipoCartaAleatorio();
};

#endif //CARTA_H_