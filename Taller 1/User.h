#pragma once
#include <iostream>
using namespace std;

class User {
private:
    string user;
    string password;

public:
    User(string user, string password);
    virtual ~User(){}
    virtual void dummy(){}
    string getUser();
    string getPassword();
    void setUser(string user);
    void setPassword(string password);
};

User::User(string user, string password) {
    this->user = user;
    this->password = password;
}

string User::getUser() {
    return this ->  user;
}

string User::getPassword() {
    return this -> password;
}

void User::setUser(string user) {
    this->user = user;
}

void User::setPassword(string password) {
    this->password = password;
}