#pragma once
#include "User.h"
#include <iostream>
using namespace std;

class Admin : public User{
    private:
        int age;
        string mail;
        bool loginAcces = true;
    public:
        Admin(string user, string password,string mail);
        ~Admin();
        void dummy() override{}
        void setMail(string mail);
        bool getAcces();
        string getMail();
        // age va a estar inicializada con 0, ya qe será lo que identifica a los admin
        int getAge(){
            return this -> age;
        }
};
//constructor de Admin.h
Admin::Admin(string user,string password,string mail):User(user,password){
    this -> mail = mail;
    this -> age = 0;
}
Admin::~Admin(){}
void Admin::setMail(string mail){
    this -> mail = mail;
}
string Admin::getMail(){
    return this -> mail;
}
bool Admin::getAcces(){
    return this -> loginAcces;
}
