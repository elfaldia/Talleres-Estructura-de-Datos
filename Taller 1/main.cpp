#include <iostream>
using namespace std;
#include "Usuario.h"
#include "Nino.h"

int main(){

    Nino* n = new Nino("elfaldia","da280855",23);
    cout<< n -> getUsuario()<< n ->getEdad()<<endl;

    return 0;
};