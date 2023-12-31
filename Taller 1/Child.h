#pragma once
#include "User.h"
#include <iostream>
using namespace std;

class Child : public User {
    private:
        int age;
        bool loginAcces = false;

    public:
        Child(string user, string password, int age);
        ~Child();
        void dummy() override{}
        void setAge(int age);
        bool getAcces();
        int getAge();
        int ageVerification(int age,string user);
};
//Confirma que el usuario sea menor a 18 años
int Child::ageVerification(int age,string user){
    while(age >= 18){
        cout<<"La edad del usuario "<<user<<" no es valida, ingrese nuevamente: "<<endl;
        cin >> age;
    }return age;
}
//constructor de Child.h
Child::Child(string user, string password, int age) : User(user, password) {
    this->age = ageVerification(age,user);
}
Child::~Child(){}
void Child::setAge(int age) {
    this->age = age;
}
int Child::getAge() {
    return this->age;
}
bool Child::getAcces(){
    return this -> loginAcces;
}