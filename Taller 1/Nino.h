#pragma once
#include "Usuario.h"

class Nino : public Usuario {
private:
    int edad;

public:
    Nino(string usuario, string contrasena, int edad);
    ~Nino();
    void setEdad(int edad);
    int getEdad();
};

Nino::Nino(string usuario, string contrasena, int edad) : Usuario(usuario, contrasena) {
    this->edad = edad;
}

void Nino::~Nino(){cout<<"se elimino el usuario"<<endl;}

void Nino::setEdad(int edad) {
    this->edad = edad;
}

int Nino::getEdad() {
    return this->edad;
}