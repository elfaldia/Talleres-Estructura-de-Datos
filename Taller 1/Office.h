#pragma once
#include <iostream>
#include "Software.h"
using namespace std;

class Office:public Software
{
    private:
        int archives;
    public:
        Office(string name, string developer, string ageClassification, int price, int archives);
        ~Office();
        void dummy() override{}
        void setArchives(int archives);
        int getArchives();
        //elimina un archivo
        void deleteArchive();
        //agrega un archivo
        void addArchive();
};
//constructor de Office.h
Office:: Office(string name, string developer, string ageClassification, int price, int archives) : Software(name,developer,ageClassification,price){
    this -> archives = archives;
}
Office:: ~Office(){}
void Office::setArchives(int archives){
    this -> archives = archives;
}
int Office::getArchives(){
    return this -> archives;
}
void Office::deleteArchive(){
    this -> archives--;
}
void Office::addArchive(){
    this -> archives ++;;
}