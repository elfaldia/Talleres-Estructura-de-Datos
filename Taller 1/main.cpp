#include <iostream>
#include <vector>
#include "User.h"
#include "Child.h"
#include "Admin.h"
#include "Normal.h"
#include "Games.h"
using namespace std;

//POBLA LA BASE DE DATOS DE USUARIOS
void populateUsers(vector<User>& u){
    u.push_back(Admin("elfaldia","da280855","elfaldia@ml.com"));
    u.push_back(Child("ian","warhammer35",10));
    u.push_back(Child("siziyi","pandeazucar",4));
    u.push_back(Child("kleytez","kidvoodoo",7));
    u.push_back(Child("etoile","fletoile",16));
    u.push_back(Normal("lorena","ema",23,"lorena@ml.com"));
    u.push_back(Normal("ronny","aki",19,"ronny@ml.com"));
    u.push_back(Normal("andrea","natacion12",20,"andrea@ml.com"));
    u.push_back(Normal("unflojo","ilovediablo",44,"unflojo@ml.com"));
    u.push_back(Normal("clerigo","darksouls",28,"clerigo@ml.com"));
    u.push_back(Normal("piromantico","fuego",39,"piromantico@ml.com"));
    u.push_back(Normal("carnicero","chanchos",33,"carnicero@ml.com"));
    u.push_back(Normal("rob","talcabelike",32,"rob@ml.com"));
    u.push_back(Normal("uchigatana","bestbuild",20,"uchigatana@ml.com"));
    u.push_back(Normal("claymore","fistbuild",50,"claymore@ml.com"));
}
void populateSoftwares(vector<Software> s){
    // RELLENANDO JUEGOS
    s.push_back(Games("Dark souls","fromsoftware","+18",36,"RPG"));
    s.push_back(Games("Bloodborne","fromsoftware","+18",38,"RPG"));
    s.push_back(Games("Red dead redemption","Rockstar Games","+18",60,"mundo abierto"));
    s.push_back(Games("Red dead redemption II","Rockstar Games","+18",74,"mundo abierto"));
    s.push_back(Games("Call of duty","Activision","+18",50,"FPS"));
    s.push_back(Games("Fortnite","Epic games","+14",5,"FPS"));
    s.push_back(Games("Apex legends","Electronic Arts","+16",10,"Battle royale"));
    s.push_back(Games("Pubg","Bluehole","+12",60,"Battle royale"));
    s.push_back(Games("World of Warcraft","Blizzard Entertainment","+10",25,"MMO"));
    s.push_back(Games("Albion online","Sandbox Interactive","+10",9,"MMO"));
    s.push_back(Games("FIFA 23","Electronic Arts","+10",90,"Deportes"));
    s.push_back(Games("NBA 2k21","Visuals concepts","+12",51,"Deportes"));
    s.push_back(Games("","","",,""));
    s.push_back(Games("","","",,""));
    s.push_back(Games("","","",,""));
    s.push_back(Games("","","",,""));
    s.push_back(Games("","","",,""));
    s.push_back(Games("","","",,""));
    s.push_back(Games("","","",,""));
    s.push_back(Games("","","",,""));
}

int main(){

    vector<User> users;
    vector<Software> softwares;
    populateUsers(users);
    

    return 0;
};