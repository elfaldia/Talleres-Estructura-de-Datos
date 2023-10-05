#pragma once
#include "User.h"
#include <iostream>
using namespace std;

class Normal : public User{
    private:
        int age;
        string mail;
        bool loginAcces = false;
    public:
        Normal(string user, string password,int age,string mail);
        ~Normal();
        void dummy() override{}
        void setAge(int age);
        void setMail(string mail);
        bool getAcces();
        int getAge();
        string getMail();
        int ageVerification(int age,string user);
};

int Normal::ageVerification(int age,string user){
    while(age < 18){
        cout<<"La edad del usuario "<<user<<" no es valida, ingrese nuevamente: "<<endl;
        cin >> age;
    }return age;
}

Normal::Normal(string user,string password,int age,string mail):User(user,password){
    this -> age = ageVerification(age,user);
    this -> mail = mail;
}
Normal::~Normal(){}
void Normal::setAge(int age){
    this -> age = age;
}
void Normal::setMail(string mail){
    this -> mail = mail;
}
int Normal::getAge(){
    return this -> age;
}
string Normal::getMail(){
    return this -> mail;
}
bool Normal::getAcces(){
    return this -> loginAcces;
}
