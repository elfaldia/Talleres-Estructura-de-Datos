#pragma once
#include "User.h"
#include <iostream>
using namespace std;

class Admin : public User{
    private:
        string mail;
        bool loginAcces = true;
    public:
        Admin(string user, string password,string mail);
        ~Admin();
        void setMail(string mail);
        bool getAcces();
        string getMail();
};

Admin::Admin(string user,string password,string mail):User(user,password){
    this -> mail = mail;
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
