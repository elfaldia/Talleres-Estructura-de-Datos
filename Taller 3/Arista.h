#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Arista{
    private:
        int destino;
        int velocidad;
        int segundos;
    public:
        Arista(int dest, int vel, int seg) : destino(dest), velocidad(vel),segundos(seg) {}
        int getDestino() { 
            return this-> destino;
        }
        int getVelocidad() { 
            return this-> velocidad;
        }
        int getSegundos() { 
            return this-> segundos; 
        }
};
