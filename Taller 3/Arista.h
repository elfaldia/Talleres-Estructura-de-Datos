#pragma once
#include <iostream>
#include <vector>
using namespace std;

// clase arista
class Arista{
    private:
        int destino;
        int velocidad;
        int segundos;
    public:
        Arista(int dest, int vel, int seg) : destino(dest), velocidad(vel),segundos(seg) {}
        int getDestino() const { 
            return this-> destino;
        }
        int getVelocidad() const { 
            return this-> velocidad;
        }
        int getSegundos() const { 
            return this-> segundos; 
        }
};