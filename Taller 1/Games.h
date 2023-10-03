#pragma once
#include <iostream>
#include "Software.h"
using namespace std;

class Games:public Software
{
private:
string gender;
public:
    Games(string name,string developer,string ageClassification,int price,string gender);
    ~Games();
    void setGender(string gender);
    string getGender();

};

Games::Games(string name,string developer,string ageClassification,int price,string gender):Software(name,developer,ageClassification,price)
{
    this -> name = name;
    this -> developer = developer;
    this -> ageClassification = ageClassification;
    this -> price = price;
    this -> gender = gender;
}
Games::~Games(){}

void Games::setGender(string gender){
    this -> gender = gender;
}

string Games::getGender(){
    return this -> gender;
}