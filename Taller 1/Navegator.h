#pragma once
#include <iostream>
#include <queue>
#include "Software.h"
using namespace std;

class Navegator : public Software
{   
    private:
        queue<string> records;
    public:
        Navegator(string name, string developer, string ageClassification, int price);
        ~Navegator(){}
        void dummy() override{}
        void addRecord(string record);
};
Navegator :: Navegator(string name, string developer, string ageClassification, int price) : Software(name,developer,ageClassification,price){}
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