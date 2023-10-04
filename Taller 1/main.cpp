#include <iostream>
#include <vector>
#include "User.h"
#include "Child.h"
#include "Admin.h"
#include "Normal.h"
#include "Games.h"
#include " OfficeAutomation.h"
using namespace std;

//POBLA LA BASE DE DATOS DE USUARIOS
void populateUsers(vector<User*>& u){
    u.push_back(new Admin("elfaldia","da280855","elfaldia@ml.com"));
    u.push_back(new Child("ian","warhammer35",10));
    u.push_back(new Child("siziyi","pandeazucar",4));
    u.push_back(new Child("kleytez","kidvoodoo",7));
    u.push_back(new Child("etoile","fletoile",16));
    u.push_back(new Normal("lorena","ema",23,"lorena@ml.com"));
    u.push_back(new Normal("ronny","aki",19,"ronny@ml.com"));
    u.push_back(new Normal("andrea","natacion12",20,"andrea@ml.com"));
    u.push_back(new Normal("unflojo","ilovediablo",44,"unflojo@ml.com"));
    u.push_back(new Normal("clerigo","darksouls",28,"clerigo@ml.com"));
    u.push_back(new Normal("piromantico","fuego",39,"piromantico@ml.com"));
    u.push_back(new Normal("carnicero","chanchos",33,"carnicero@ml.com"));
    u.push_back(new Normal("rob","talcabelike",32,"rob@ml.com"));
    u.push_back(new Normal("uchigatana","bestbuild",20,"uchigatana@ml.com"));
    u.push_back(new Normal("claymore","fistbuild",50,"claymore@ml.com"));
}

void populateGames(vector<Software*>& s){
    // RELLENANDO JUEGOS

    s.push_back(new Games("Dark souls","fromsoftware","+18",36,"RPG"));
    s.push_back(new Games("Bloodborne","fromsoftware","+18",38,"RPG"));
    s.push_back(new Games("Red dead redemption","Rockstar Games","+18",60,"mundo abierto"));
    s.push_back(new Games("Red dead redemption II","Rockstar Games","+18",74,"mundo abierto"));
    s.push_back(new Games("Call of duty","Activision","+18",50,"FPS"));
    s.push_back(new Games("Fortnite","Epic games","+14",5,"FPS"));
    s.push_back(new Games("Apex legends","Electronic Arts","+16",10,"Battle royale"));
    s.push_back(new Games("Pubg","Bluehole","+12",60,"Battle royale"));
    s.push_back(new Games("World of Warcraft","Blizzard Entertainment","+10",25,"MMO"));
    s.push_back(new Games("Albion online","Sandbox Interactive","+10",9,"MMO"));
    s.push_back(new Games("FIFA 23","Electronic Arts","+10",90,"Deportes"));
    s.push_back(new Games("NBA 2k21","Visuals concepts","+12",51,"Deportes"));
    s.push_back(new Games("Uncharted 4","Naughty Dog","+14",37,"Acción y aventura"));
    s.push_back(new Games("The Last of Us","Naughty Dog","+16",41,"Acción y aventura"));
    s.push_back(new Games("Tom Clancy's Rainbow Six: Siege","Ubisoft Montreal","+12",16,"Tactical shooter"));
    s.push_back(new Games("Counter-Strike: Global Offensive","Jess Cliffe","+14",8,"Tactical shooter"));
    s.push_back(new Games("StarCraft II: Wings of Liberty","Blizzard Entertainment","+10",47,"Strategy"));
    s.push_back(new Games("Age of Empires IV","Relic Entertainment","+10",29,"Strategy"));
    s.push_back(new Games("Tekken 7"," Bandai Namco Entertainment","+12",12,"Fight"));
    s.push_back(new Games("For Honor","Ubisoft Montreal","+16",32,"Fight"));
}
void populateOfficeAutomation(vector<Software*>& o){
    o.push_back(new OfficeAutomation("Google Drive","uchigatana","+18",20,3));
    o.push_back(new OfficeAutomation("Microsoft Excel","ian","+14",45,9));
    o.push_back(new OfficeAutomation("Dropbox","clerigo","+18",28,4));
    o.push_back(new OfficeAutomation("","etoile","+10",34,6));
    o.push_back(new OfficeAutomation("","siziyi","+14",24,7));

}

int main(){

    vector<User*> users;
    vector<Software*> softwares;
    populateUsers(users);
    populateGames(softwares);
    
    return 0;
};