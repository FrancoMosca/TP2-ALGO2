#include "Interface.h"
#include "Ficha.h"
#include "Casillero.h"
#include "EasyBMP.h"

void colorSector(int fila, int columna,RGBApixel color,BMP* ubicacion,int totalFilas, int totalColumnas){
    for(int i = 640/totalColumnas*columna+1; i < 640/totalColumnas*(columna+1);i++){
        for (int j = 430/totalFilas*fila+1; j< 430/totalFilas*(fila+1); j++){
            ubicacion->SetPixel(i,j,color);
        }
    }
}

void agregarSoldado(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas){
    RGBApixel  color;
    RGBApixel blanco;
    blanco.Blue = 255;blanco.Green = 255; blanco.Red = 255;
    color.Red =69;color.Green = 36; color.Blue = 29;
    colorSector(fila,columna,color,ubicacion,totalFilas,totalColumnas);
    int iniciox = 640/totalColumnas*columna+1 + ((640/totalColumnas-4)/2);
    int inicioy = 430/totalFilas*fila+1 + ((430/totalFilas-5)/2);
    ubicacion->SetPixel(iniciox+1,inicioy,blanco);
    ubicacion->SetPixel(iniciox+2,inicioy,blanco);
    ubicacion->SetPixel(iniciox+3,inicioy,blanco);
    ubicacion->SetPixel(iniciox,inicioy+1,blanco);
    ubicacion->SetPixel(iniciox+1,inicioy+2,blanco);
    ubicacion->SetPixel(iniciox+2,inicioy+2,blanco);
    ubicacion->SetPixel(iniciox+3,inicioy+3,blanco);
    ubicacion->SetPixel(iniciox,inicioy+4,blanco);
    ubicacion->SetPixel(iniciox+1,inicioy+4,blanco);
    ubicacion->SetPixel(iniciox+2,inicioy+4,blanco);
}

void agregarMina(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas){
    RGBApixel negro;
    negro.Blue = 0;negro.Red = 0;negro.Green = 0;
    int iniciox = 640/totalColumnas*columna+1 + ((640/totalColumnas-5)/2);
    int inicioy = 430/totalFilas*fila+1 + ((430/totalFilas-5)/2);
    for(int j = 0; j<5; j++){
        ubicacion->SetPixel(iniciox,inicioy+j,negro);
        ubicacion->SetPixel(iniciox+4,inicioy+j,negro);
    }
    ubicacion->SetPixel(iniciox+1,inicioy+1,negro);
    ubicacion->SetPixel(iniciox+2,inicioy+2,negro);
    ubicacion->SetPixel(iniciox+3,inicioy+1,negro);
}



void agregarBarco(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas){
    RGBApixel  color;
    RGBApixel blanco;
    blanco.Red = 255;blanco.Green = 255; blanco.Blue = 255;
    color.Red =37;color.Green = 109; color.Blue = 123;
    colorSector(fila,columna,color,ubicacion,totalFilas,totalColumnas);
    int iniciox = 640/totalColumnas*columna+1 + ((640/totalColumnas-4)/2);
    int inicioy = 430/totalFilas*fila+1 + ((430/totalFilas-5)/2);
    for(int j = 0; j<5; j++){
        ubicacion->SetPixel(iniciox,inicioy+j,blanco);
    }
    for(int j = 1; j<3; j++){
        ubicacion->SetPixel(iniciox+j,inicioy,blanco);
        ubicacion->SetPixel(iniciox+j,inicioy+2,blanco);
        ubicacion->SetPixel(iniciox+j,inicioy+4,blanco);
    }
    ubicacion->SetPixel(iniciox+3,inicioy+1,blanco);
    ubicacion->SetPixel(iniciox+3,inicioy+3,blanco);
}

void agregarAvion(int fila,int columna,BMP* ubicacion,int totalFilas, int totalColumnas){
    RGBApixel  color;
    RGBApixel blanco;
    blanco.Red = 255;blanco.Green = 255; blanco.Blue = 255;
    color.Red =0;color.Green = 204; color.Blue = 255;
    colorSector(fila,columna,color,ubicacion,totalFilas,totalColumnas);
    int iniciox = 640/totalColumnas*columna+1 + ((640/totalColumnas-4)/2);
    int inicioy = 430/totalFilas*fila+1 + ((430/totalFilas-5)/2);
    for(int j = 0; j<5; j++){
        ubicacion->SetPixel(iniciox,inicioy+j,blanco);
        ubicacion->SetPixel(iniciox+3,inicioy+j,blanco);
    }
    for(int j = 1; j<3; j++){
        ubicacion->SetPixel(iniciox+j,inicioy,blanco);
        ubicacion->SetPixel(iniciox+j,inicioy+2,blanco);
    }
}

void crearTabla(BMP* ubicacion,int totalFilas, int totalColumnas){
    RGBApixel cuadrilla;
    cuadrilla.Blue = 25;
    for (int i =640/totalColumnas;i<640;i+= 640/totalColumnas){
        for (int j = 0; j<429; j ++)
            ubicacion->SetPixel((int)i,(int)j,cuadrilla);
    }
    for (int j =430/totalFilas;j<430;j+= 430/totalFilas){
        for (int i = 0; i<640; i ++)
            ubicacion->SetPixel((int)i,(int)j,cuadrilla);
    }
}

void mostrarCapa(Tablero *tablero, int altura, BMP* ubicacion,int jugador){
    int totalFilas = tablero->getFila();
    int totalColumnas = tablero->getColumna();
    int tamano = tablero->getProfundidad();
    if (altura > tablero->getProfundidad()){
        throw "la altura no es valida";
    }
    RGBApixel  agua,tierra,aire,vacio;
    agua.Red =37; agua.Green = 109; agua.Blue = 123;
    tierra.Red =69; tierra.Green = 36; tierra.Blue = 29;
    aire.Red =0; aire.Green = 204; aire.Blue = 255;
    vacio.Red =0; vacio.Green = 0; vacio.Blue = 0;
    ubicacion->SetSize(640,430);
    ubicacion->SetBitDepth(8);
    crearTabla(ubicacion,totalFilas,totalColumnas);
    if(altura < 6){
        for (int i = 1; i < totalFilas+1; i++){
            for (int j = 1; j < totalColumnas+1; j++){
                char elemento = tablero->obtenerCasillero(i,j,altura)->getFicha()->getElementoFicha();
                int jugadores = tablero->obtenerCasillero(i,j,altura)->getFicha()->getIdJugador();
                terreno_t terreno = tablero->obtenerCasillero(i,j,altura)->getTerreno();
                if (elemento == SOLDADO) {
                    if(jugadores != jugador || jugadores!= 0){
                        colorSector(i-1,j-1,tierra,ubicacion,totalFilas,totalColumnas);
                    }else{
                        agregarSoldado(i-1,j-1,ubicacion,totalFilas,totalColumnas);
                    }
                } else if (elemento == MINA){
                    if(jugadores != jugador || jugadores!= 0){
                        colorSector(i-1,j-1,tierra,ubicacion,totalFilas,totalColumnas);
                    }else{
                        agregarMina(i-1,j-1,ubicacion,totalFilas,totalColumnas);
                    }
                }else if (elemento == BARCO){
                    if(jugadores != jugador || jugadores!= 0){
                        colorSector(i-1,j-1,agua,ubicacion,totalFilas,totalColumnas);
                    }else{
                        agregarBarco(i-1,j-1,ubicacion,totalFilas,totalColumnas);
                    }
                }else if (terreno == AGUA) {
                    colorSector(i-1,j-1,agua,ubicacion,totalFilas,totalColumnas);
                } else if (terreno == TIERRA) {
                    colorSector(i-1,j-1,tierra,ubicacion,totalFilas,totalColumnas);
                } else if (elemento == VACIO) {
                    colorSector(i-1,j-1,vacio,ubicacion,totalFilas,totalColumnas);
                }
            }
        }
    }else{
        for (int i = 1; i < totalFilas+1; i++){
            for (int j = 1; j < totalColumnas+1; j++){
                colorSector(i-1,j-1,aire,ubicacion,totalFilas,totalColumnas);
                for (int k = 6; k < tamano; k++){
                    Ficha elemento = tablero->obtenerCasillero(i,j,k)->getFicha()->getElementoFicha();
                    int jugadores = tablero->obtenerCasillero(i,j,k)->getFicha()->getIdJugador();
                    if (elemento.getElementoFicha() == AVION){
                        if(jugadores != jugador || jugadores!= 0){
                            colorSector(i-1,j-1,aire,ubicacion,totalFilas,totalColumnas);
                        }else{
                            agregarAvion(i-1,j-1,ubicacion,totalFilas,totalColumnas);
                        }
                    }
                }
            }
        }
    }
}

void mostrarTablero(Tablero *tablero, int jugador){
    BMP capa_1;
    mostrarCapa(tablero, 1, &capa_1,jugador);
    capa_1.WriteToFile("primerNivel");
    int tamano = tablero->getProfundidad();
    if(tamano >1){
        BMP capa_2;
        mostrarCapa(tablero, 2, &capa_2,jugador);
        capa_2.WriteToFile("segundoNivel");
    }
    if(tamano>2){
        BMP capa_3;
        mostrarCapa(tablero, 3, &capa_3,jugador);
        capa_3.WriteToFile("tercerNivel");
    }
    if(tamano>3){
        BMP capa_4;
        mostrarCapa(tablero, 4, &capa_4,jugador);
        capa_4.WriteToFile("cuartoNivel");
    }
    if(tamano>4){
        BMP capa_5;
        mostrarCapa(tablero, 5, &capa_5,jugador);
        capa_5.WriteToFile("quintoNivel");
    }
    if(tamano>5){
        BMP capa_cielo;
        mostrarCapa(tablero, 6, &capa_cielo,jugador);
        capa_cielo.WriteToFile("cielo");
    }
}

