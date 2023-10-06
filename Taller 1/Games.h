#pragma once
#include <iostream>
#include <random>
#include "Software.h"
using namespace std;

class Games:public Software
{
private:
//tipo de genero del juego
    string gender;
    int hours;
    random_device rd; 

public:
    Games(string name,string developer,string ageClassification,int price,string gender);
    ~Games();
    void dummy() override{}
    void setGender(string gender);
    string getGender();
    //función única de Games.h que te entrega las horas jugadas por juego
    int playedtHours(){
        return this-> hours;
    }
};
//constructor de Games.h
Games::Games(string name,string developer,string ageClassification,int price,string gender):Software(name,developer,ageClassification,price)
{
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(0, 2000);
    this -> gender = gender;
    this -> hours = distribution(gen);
}
Games::~Games(){}

void Games::setGender(string gender){
    this -> gender = gender;
}

string Games::getGender(){
    return this -> gender;
}