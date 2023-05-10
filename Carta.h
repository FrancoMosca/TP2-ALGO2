/*
*Carta.h
*
*Created on :24/04/2023
*   Author:algo2
*/

class Carta
{
private:
    unsigned int x,y,z;
    bool activo;
    int contador;
    int radio;

public:
    //Metodos carta avion
    void detectarMinas();

    //Metodos carta barco
    void dispararMisil();

    //Metodos ataque quimico
    void ataqueQuimico();

    //Metodos compartidos
    void obtenerRango(int radio);

    //Metodos granada
    void desarmarSoldados();

    //Metodos ataque multiple
    void ataqueMultiple();

    //Metodos escudo
    void aumentarResistencia();

};