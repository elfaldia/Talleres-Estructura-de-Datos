#pragma once
#include <iostream>
#include <vector>
#include "Software.h"
using namespace std;

class Social:public Software{

    public:
        Social(string name,string developer,string ageClassification,int price);
        ~Social(){}
        void dummy(){}
        void addFriend(int index,User user);
};
//constructor de Social.h
Social::Social(string name,string developer,string ageClassification,int price):Software(name,developer,ageClassification,price){}
//agrega un amigo a cada usuario de la lista userList de social
void Social::addFriend(int index,User user){   
    this -> userList[index].insertFriend(user);
}