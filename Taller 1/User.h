#pragma once
#include <iostream>
#include <vector>
using namespace std;

class User {
private:
    string user;
    string password;
    vector<User> friendList;

public:
    User(string user, string password);
    virtual ~User(){}
    virtual void dummy(){}
    string getUser();
    string getPassword();
    void setUser(string user);
    void setPassword(string password);
    void insertFriend(User user){
        this -> friendList.push_back(user);
    }
    int numberOfFriends(){
        return this -> friendList.size();
    }
    User getFriend(int index){
        return this -> friendList[index];
    }

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