#pragma once
#include <iostream>
#include <vector>
#include "Software.h"
#include "User.h"
using namespace std;

class OfficeAutomation:public Software{
    private:
        int archives;
    public:
        OfficeAutomation(string name,string developer,string ageClassification,int price,int archives)();
        ~OfficeAutomation();
        void setArchives(int archives);
        string getArchives();
        void deleteArchive();
        void addArchive();
}

OfficeAutomation:: OfficeAutomation(string name,string developer,string ageClassification,int price,int archives): Software(name,developer,ageClassification,price){
    this -> archives = archives;
}
OfficeAutomation:: ~OfficeAutomation(){}
void OfficeAutomation::setArchives(int archives){
    this -> archives = archives;
}
int OfficeAutomation::getArchives(){
    return this -> archives;
}
void OfficeAutomation::deleteArchive(){
    this -> archives = archives - 1;;
}
void OfficeAutomation::addArchive(){
    this -> archives ++;;
}