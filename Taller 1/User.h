#pragma once
#include <iostream>
using namespace std;

class User {
private:
    string user;
    string password;

public:
    User(string user, string password);
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
    return user;
}

string User::getPassword() {
    return password;
}

void User::setUser(string user) {
    this->user = user;
}

void User::setPassword(string password) {
    this->password = password;
}