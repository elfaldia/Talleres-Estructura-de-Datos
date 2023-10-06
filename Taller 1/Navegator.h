#pragma once
#include <iostream>
#include <queue>
#include "Software.h"
using namespace std;

class Navegator : public Software
{   
    private:
        //cola que contiene el historial de sitios visitados
        queue<string> records;
    public:
        Navegator(string name, string developer, string ageClassification, int price);
        ~Navegator(){}
        void dummy() override{}
        void addRecord(string record);
};
//constructor del Navegator.h
Navegator :: Navegator(string name, string developer, string ageClassification, int price) : Software(name,developer,ageClassification,price){}

//función unica de Navegador.h que permite agregar a la busqueda
void Navegator :: addRecord(string record){
    
    if(records.empty()){
        records.push(record);
    }else{
        if(records.size() <= 10){
            records.push(record);
        }else{
            records.pop();
            records.push(record);
        }
    }
}