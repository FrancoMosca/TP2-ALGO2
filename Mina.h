#ifndef MINA_H_
#define MINA_H_
#include <string>

typedef int coordenada [3];

class Mina{
private:
	int posicion[3];
	std::string jugador;
	bool activa;
	int turnos;
	int contador;
public:
	Mina(int posicion[3],std::string jugador); //tendria que recibir tambien lista de soldados y armamentos del resto de jugadores,si hay algo la mina queda activada
	~Mina();
	int* getPosicion();
	std::string getJugador();
	bool getActiva();
	bool aumentarContador();
	void activarMina(int turnos);
};

#endif /* MINA_H_ */
