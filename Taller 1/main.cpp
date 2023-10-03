#include <iostream>
#include <vector>
#include "User.h"
#include "Child.h"
#include "Admin.h"
#include "Normal.h"
using namespace std;

//POBLA LA BASE DE DATOS DE USUARIOS
void populateUsers(vector<User>& u){
    u.push_back(Admin("elfaldia","da280855","elfaldia@ml.com"));u.push_back(Child("ian","warhammer35",10));u.push_back(Child("siziyi","pandeazucar",4));u.push_back(Child("kleytez","kidvoodoo",7));u.push_back(Child("etoile","fletoile",16));
    u.push_back(Normal("lorena","ema",23,"lorena@ml.com"));u.push_back(Normal("ronny","aki",19,"ronny@ml.com"));u.push_back(Normal("andrea","natacion12",20,"andrea@ml.com"));u.push_back(Normal("unflojo","ilovediablo",44,"unflojo@ml.com"));u.push_back(Normal("clerigo","darksouls",28,"clerigo@ml.com"));
    u.push_back(Normal("piromantico","fuego",39,"piromantico@ml.com"));u.push_back(Normal("carnicero","chanchos",33,"carnicero@ml.com"));u.push_back(Normal("rob","talcabelike",32,"rob@ml.com"));u.push_back(Normal("uchigatana","bestbuild",20,"uchigatana@ml.com"));u.push_back(Normal("claymore","fistbuild",50,"claymore@ml.com"));
}

int main(){

    vector<User> users;
    populateUsers(users);
    

    return 0;
};