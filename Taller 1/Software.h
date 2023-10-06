#pragma once
#include <iostream>
#include <vector>
#include "User.h"
using namespace std;

class Software{
    private:
        string name;
        string developer;
        string ageClassification;
        int price;
    protected:
        vector<User> userList;
    public:
        Software(string name,string developer,string ageClassification,int price);
        virtual ~Software(){}
        virtual void dummy(){}
        string getName();
        string getDeveloper();
        string getAgeClassificion();
        int getPrice();
        void setName(string name);
        void setDeveloper(string developer);
        void setAgeClassification(string ageClassification);
        void setPrice(int price);
        void insertUser(User user);
        User getUser(int index);
        int getNumberOfUsers(){
            return this -> userList.size();
        }
};

Software::Software(string name,string developer,string ageClassification,int price){
    this -> name = name;
    this -> developer = developer;
    this -> ageClassification = ageClassification;
    this -> price = price;   
}

string Software::getName(){
    return this -> name;
}
string Software::getDeveloper(){
    return this -> developer;
}
string Software::getAgeClassificion(){
    return this -> ageClassification;
}
int Software::getPrice(){
    return this -> price;
}
void Software::setName(string name){
    this -> name = name;
}
void Software::setDeveloper(string developer){
    this -> developer = developer;
}
void Software::setAgeClassification(string ageClassification){
    this -> ageClassification = ageClassification;
}
void Software::setPrice(int price){
    this -> price = price;
}
void Software::insertUser(User user){
    this -> userList.push_back(user);
}
User Software::getUser(int index){
    return this -> userList[index];
}
