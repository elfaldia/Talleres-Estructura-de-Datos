#pragma once
#include <iostream>
#include "Software.h"
using namespace std;

class Production:public Software
{
    private:
        string solutionType;
    public:
        Production(string name, string developer, string ageClassification, int price, string solutionType);
        ~Production(){}
        void dummy() override{}
        void changeTypeSolution();
        string getSolutionType();
};

Production:: Production(string name, string developer, string ageClassification, int price, string solutionType) : Software(name,developer,ageClassification,price){
    this -> solutionType = solutionType;
}
string Production:: getSolutionType(){
    return this -> solutionType;
}
void Production:: changeTypeSolution(){
    cout<<"Ingrese el tipo de solución: "<<endl;
    bool v = true;
    while(v){
        cin>>this -> solutionType;
        if(solutionType == "streaming" || solutionType == "musica" || solutionType == "fotos" || solutionType == "video"){
            cout<<"El tipo de solución se cambió exitosamente"<<endl;
            v = false;
        }else{
            cout<<"El tipo de solución debe ser: streaming, musica, fotos o video. Intente de nuevo"<<endl;
        }
    }
}