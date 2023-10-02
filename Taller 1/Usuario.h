#pragma once
#include <iostream>
using namespace std;

class Usuario {
private:
    string usuario;
    string contrasena;

public:
    Usuario(string usuario, string contrasena);
    string getUsuario();
    string getContrasena();
    void setUsuario(string usuario);
    void setContrasena(string contrasena);
};

Usuario::Usuario(string usuario, string contrasena) {
    this->usuario = usuario;
    this->contrasena = contrasena;
}

string Usuario::getUsuario() {
    return usuario;
}

string Usuario::getContrasena() {
    return contrasena;
}

void Usuario::setUsuario(string usuario) {
    this->usuario = usuario;
}

void Usuario::setContrasena(string contrasena) {
    this->contrasena = contrasena;
}