#pragma once
#include <iostream>
#include "Software.h"
using namespace std;

class Security:public Software{
    private:
        //tipo de malware que soluciona
        string malware;
    public:
        Security(string name,string developer,string ageClassification,int price,string malware);
        ~Security(){}
        void dummy(){}
        string getMalware();
        void changeMalware();
};
//constructor de Security.h
Security::Security(string name,string developer,string ageClassification,int price,string malware):Software(name,developer,ageClassification,price){
    this -> malware = malware;
}
string Security::getMalware(){
    return this -> malware;
}
//funcion que cambia el tipo de malware que resuelve
void Security::changeMalware(){
    
    cout<<"Ingrese el malware: "<<endl;
    bool v = true;
    while(v){
        cin>>this -> malware;
        if(malware == "Ransomware"|| malware == "Spyware"|| malware == "botnets" || malware == "rootkits"|| malware == "gusanos"|| malware == "troyanos"){
            v = false;
        }else{
            cout <<"El malware no existe. Ingrese un nuevamente"<<endl;
        }
    }     
}
    
