#include <iostream>
#include <vector>
#include <string>
#include "User.h"
#include "Software.h"
#include "Child.h"
#include "Admin.h"
#include "Normal.h"
#include "Games.h"
#include "Office.h"
#include "Production.h"
#include "Navegator.h"
#include "Security.h"
#include "Social.h"
using namespace std;

//RELLENAR LISTA DE USUARIOS EN CADA SOFTWARE  
void fillUsersInSoftware(vector<Software*>& s, vector<User*>& u){
    for(int i = 0; i < s.size(); i++){
        string v = s[i]->getAgeClassificion();
        int n = 0;
        if(v[0] == '+'){
            v = v.substr(1);
            n = stoi(v);            
        }else{
            n = stoi(v); 
        }
        for(int j = 0; j < u.size(); j++){
            Admin* admin = dynamic_cast<Admin*>(u[j]);
                if(admin){
                    s[i]->insertUser(*u[j]);
                }

            if(n < 18 && n != 0){
                Child* child = dynamic_cast<Child*>(u[j]);
                if(child){
                    s[i]->insertUser(*u[j]);
                }
            }else{
                if(n >= 18||n != 0){
                    Normal* normal = dynamic_cast<Normal*>(u[j]);
                    if(normal){
                        s[i]->insertUser(*u[j]);
                    }
                }
            }
        }
    }
}

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

// RELLENANDO JUEGOS
void populateGames(vector<Software*>& s){

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
    s.push_back(new Games("Uncharted 4","Naughty Dog","+14",37,"Puzzle"));
    s.push_back(new Games("The Last of Us","Naughty Dog","+16",41,"Puzzle"));
    s.push_back(new Games("Tom Clancy's Rainbow Six: Siege","Ubisoft Montreal","+12",16,"Tactical shooter"));
    s.push_back(new Games("Counter-Strike: Global Offensive","Jess Cliffe","+14",8,"Tactical shooter"));
    s.push_back(new Games("StarCraft II: Wings of Liberty","Blizzard Entertainment","+10",47,"Strategy"));
    s.push_back(new Games("Age of Empires IV","Relic Entertainment","+10",29,"Strategy"));
    s.push_back(new Games("Tekken 7"," Bandai Namco Entertainment","+12",12,"Fight"));
    s.push_back(new Games("For Honor","Ubisoft Montreal","+16",32,"Fight"));
}

//RELLENANDO OFIMÁTICA
void populateOfficeAutomation(vector<Software*>& o){
    o.push_back(new Office("Google Drive","uchigatana","+18",20,3));
    o.push_back(new Office("Microsoft Excel","ian","+14",45,9));
    o.push_back(new Office("Dropbox","clerigo","+18",28,4));
    o.push_back(new Office("Microsoft Word","etoile","+10",34,6));
    o.push_back(new Office("Microsoft PowerPoint","siziyi","+14",24,7));
}

//RELLENANDO PRODUCCION
void populateProduction(vector<Software*>& p){
    p.push_back(new Production("Netflix","Reed Hastings","+18+",4, "streaming"));
    p.push_back(new Production("Spotify","Daniel Ek","+18+",6, "musica"));
    p.push_back(new Production("Photoshop","Adobe Systems Incorporated","+18+",21, "fotos"));
    p.push_back(new Production("Youtube","Neal Mohan","+18+",2, "video"));
}

//RELLENANDO NAVIGADOR
void populateNavegator(vector<Software*>& n){
    n.push_back(new Navegator("Opera GX","Opera Software ASA","+12",24));
    n.push_back(new Navegator("Google","Google corporation","+14",32));
}

//RELLENANDO SEGURIDAD
void populateSecurity(vector<Software*>& s){
    s.push_back(new Security("Avast One","Avas inc","0",47,"Ransomware"));
    s.push_back(new Security("Avira","Avira inc","0",49,"Spyware"));
    s.push_back(new Security("Bitdefender","Bitdefender inc","0",21,"Botnets"));
    s.push_back(new Security("Kaspersky Premium","Kaspersky inc","0",32,"rootkits"));
    s.push_back(new Security("AVG Ultimate","AVG inc","0",43,"gusanos"));
    s.push_back(new Security("Malwarebytes Essential","Malwarebytes Essential inc","0",26,"troyanos"));
}

//RELLENA LOS SOFTWARE DE TIPO SOCIAL
void populateSocial(vector<Software*>& s){
    s.push_back(new Social("Instagram","Instagram company","+14",640));
    s.push_back(new Social("WhasApp","Meta","+18",600));
}
   
//RELLENA A CADA USUARIO DE TIPO SOCIAL CON SUS AMIGOS
void populateFriends(vector<Software*>& s,vector<User*>& u){
    for(int i = 0; i < s.size(); i++){
        Social* social = dynamic_cast<Social*>(s[i]);
        if(social){
            string v = s[i]->getAgeClassificion();
            int n = 0;
            if(v[0] == '+'){
                v = v.substr(1);
                n = stoi(v);            
            }else{
                n = stoi(v); 
            }
            for(int j = 0; j < social->getNumberOfUsers(); j++){
                int cont = 0;
                for(int k = 0; k < u.size(); k++){
                    if(cont == 2){
                        break;
                    }
                    if(social->getUser(j).getUser() == u[k]->getUser()){
                        continue;
                    }else{
                        if(n == 0){
                            social->addFriend(j,*u[k]);
                            cont++;
                        }
                        if(n < 18 && n != 0){
                            Child* child = dynamic_cast<Child*>(u[k]);
                            if(child){
                                social->addFriend(j,*u[k]);
                                cont++;
                            }
                        }else{
                            social->addFriend(j,*u[k]);
                            cont++;
                        }
                    }
                }
            }
        }
    }
}

//RELLENANDO TODOS LOS SOFTWARE
void populateSoftware(vector<Software*>& s){
    populateGames(s);
    populateOfficeAutomation(s);
    populateProduction(s);
    populateNavegator(s);
    populateSecurity(s);
    populateSocial(s);
}

//RELLENANDO TODO, TANTO BASES DE USUARIOS COMO DE SOFTWARE
void populateEverything(vector<Software*>& s,vector<User*>& u){
    populateUsers(u);
    populateSoftware(s);
    fillUsersInSoftware(s,u);
    populateFriends(s,u);
}

//VERIFICANDO USUARIO
User* userVerification(const string& userName,const string& password, vector<User*>& u) {
    for (int i = 0; i < u.size(); i++) {
        if (userName == u[i]->getUser()) {
            if (password == u[i]->getPassword()) {
                return u[i];
            } 
        }
    }
    return nullptr; 
}

//Completa el menu para la funcion agregar usuario
void addSoftware(User* user,vector<Software*>& s,vector<Software*>& userS){
    
    cout<<"A continuación se desplegarán los software disponibles para ti: "<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
    vector<int> indices;
    int index;
    for(int i = 0; i < s.size(); i++){
        string v = s[i]->getAgeClassificion();
        int n = 0;
        if(v[0] == '+'){
            v = v.substr(1);
            n = stoi(v);            
        }else{
            n = stoi(v); 
        }
        int x = -1;
        for(int j = 0; j < userS.size(); j++){
            if(userS[j] == s[i]){
                x++;
            }
        }if(x==-1){
            Admin* admin = dynamic_cast<Admin*>(user);
            if(admin){
                cout<<i<<".- (Nombre): "<<s[i]->getName()<<" (Clasificación de edad): "<<s[i]->getAgeClassificion()<<"  (Precio): "<<s[i]->getPrice()<<endl;   
                indices.push_back(i);
            }
            if(n < 18 && n != 0){
                Child* child = dynamic_cast<Child*>(user);
                if(child){
                    cout<<i<<".- (Nombre): "<<s[i]->getName()<<" (Clasificación de edad): "<<s[i]->getAgeClassificion()<<"  (Precio): "<<s[i]->getPrice()<<endl;
                    indices.push_back(i);
                }else{
                    Normal* normal = dynamic_cast<Normal*>(user);
                    if(normal){
                        cout<<i<<".- (Nombre): "<<s[i]->getName()<<" (Clasificación de edad): "<<s[i]->getAgeClassificion()<<"  (Precio): "<<s[i]->getPrice()<<endl;
                        indices.push_back(i);
                    }
                }
            }    
        }
    }
    cout<<"------------------------------------------------------------------"<<endl;
    cout<<"Selecciona el indice del software que deseas agregar: "<<endl;
    cin>>index;
    cout<<"------------------------------------------------------------------"<<endl;
    int v = -1;
    for(int i = 0; i < indices.size(); i++){
        if(indices[i] == index){
            userS.push_back(s[index]);
            cout<<"El software fue agregado exitosamente."<<endl;
            v++;
            break;
        }
    }
    if(v == -1){
        cout<<"El indice no fue ingresado correctamente."<<endl;
    }
}

//Completa el menu para la funcion eliminar usuario
void deleteSoftware(vector<Software*>& userS){
    vector<int> indices;
    int index;
    if(userS.empty()){
        cout<<"No hay software en tu lista"<<endl;
    }else{
        cout<<"\nA continuación se desplegarán los software disponibles actualemente en la biblioteca general: "<<endl;
        cout<<"------------------------------------------------------------------"<<endl;
        for(int i = 0; i < userS.size(); i++){
            cout<<i<<".- (Nombre): "<<userS[i]->getName()<<" (Clasificación de edad): "<<userS[i]->getAgeClassificion()<<"  (Precio): "<<userS[i]->getPrice()<<endl;
            indices.push_back(i);
        }
        cout<<"------------------------------------------------------------------"<<endl;
        cout<<"Selecciona el indice del software que deseas eliminar: "<<endl;
        cin>>index;
        cout<<"------------------------------------------------------------------"<<endl;
        string consulta;
        cout<<"Los usuarios permiten elminar software? S/N"<<endl;
        cin>>consulta;
        cout<<"------------------------------------------------------------------"<<endl;
        if(consulta == "S" || consulta == "s"){
            int v = -1;
            for(int i = 0; i < indices.size(); i++){
                if(indices[i] == index){
                    userS.erase(userS.begin()+index);
                    cout<<"El software fue eliminado exitosamente."<<endl;
                    v++;
                    break;
                }
            }
            if(v == -1){
                cout<<"El indice no fue ingresado correctamente."<<endl;
            }
        }else{
            if(consulta == "N" || consulta == "n"){
                cout<<"No se permitio elminar el software."<<endl;
            }
        }
    }
}

//Completa el menu para la funcion ver todos los software
void seeSoftware(vector<Software*>& u){
    if(u.empty()){
        cout<<"Acualmente no hay ningun software en tu lista"<<endl;
    }else{
        for(int i = 0; i < u.size(); i++){
            cout<<i<<".- (Nombre): "<<u[i]->getName()<<" (Clasificación de edad): "<<u[i]->getAgeClassificion()<<"  (Precio): "<<u[i]->getPrice()<<endl;
        }
    }  
}

//Log de los software de juego
void logGame(vector<Software*>& u,User* user){
    Admin* admin = dynamic_cast<Admin*>(user);
    vector<int> indices;
    if(admin){
        cout<<"-> Eres admin!"<<"\n"<<"A continuación se desplegaran los software de juego disponibles a los cuales podras ver las horas totales de cada uno."<<"\n"<<"Ingresa el indice del software."<<endl;
        cout<<"------------------------------------------------------------------"<<endl;
        for(int i = 0; i < u.size(); i++){
            Games* games = dynamic_cast<Games*>(u[i]);
            if(games){
                cout<<i<<".- (Nombre): "<<u[i]->getName()<<" (Clasificación de edad): "<<u[i]->getAgeClassificion()<<"  (Precio): "<<u[i]->getPrice()<<endl;
                indices.push_back(i);
            }
        }
        cout<<"------------------------------------------------------------------"<<endl;
        int index;
        cin>>index;
        int v =-1;
        cout<<"------------------------------------------------------------------"<<endl;
        for(int i = 0; i < indices.size(); i++){
            if(indices[i] == index){
                Games* games = dynamic_cast<Games*>(u[index]);
                cout<<"-> El juego "<<games->getName()<<" se ha jugado "<<games->playedtHours()<<" horas."<<endl;
                cout<<"------------------------------------------------------------------"<<endl;
                v++;
                break;
            }
        }
        if(v == -1){
            cout<<"El indice no fue ingresado correctamente."<<endl;
        }
    }else{
        cout<<"-> No tienes permiso para ingresar."<<endl;
        cout<<"------------------------------------------------------------------"<<endl;
    }
}

//MENU CON SUS OPCIONES
void menu(User* user,vector<Software*>& s, vector<User*>& u){
    bool verification = true;
    int option;
    vector<Software*> userSoftwares;
    while(verification){

        cout<<"------------------------------------------------------------------"<<endl;
        cout<<"Bienvenindo a tu biblioteca -> "<<user->getUser()<<"\n"<<"Opciones: "<<endl;
        cout<<"1.- Comprar software."<<"\n"<<"2.- Eliminar Software."<<"\n"<<"3.- Ver Softwares actuales en tu biblioteca."<<"\n"<<"4.- Ingresar al log de los softaware de juego."<<"\n"<<"5.- Log out"<<endl;
        cout<<"------------------------------------------------------------------"<<endl;
        cin>>option;
        cout<<"------------------------------------------------------------------"<<endl;
        switch (option)
        {
        case 1:
            addSoftware(user,s,userSoftwares);
            break;
        case 2:
            deleteSoftware(userSoftwares);
            break;
        case 3:
            seeSoftware(userSoftwares);
            break;
        case 4:
            logGame(s,user);
            break;
        case 5:
            cout<<"Hasta luego :)"<<endl;
            verification = false;
            break;
        default:
            cout<<"Opciones invalidas, Intenta nuevamente"<<endl;
            break;
        }
    }
}

//FUNCIÓN QUE TENDRÁ EL PROGRAMA GENERAL
void system(vector<Software*>& s, vector<User*>& u) {
    bool verification = true; 
    while (verification) {
        string option;
        do {
            cout << "------------------------------------------------------------------" << endl;
            cout << "\nBienvenidos al sistema!" << "\n" << "A continuación se desplegarán dos opciones, ingrese el numero que lo identifica:" << endl;
            cout << "1.- Log in" << "\n" << "2.- Close system" << endl;
            cout << "------------------------------------------------------------------" << endl;
            cin >> option;
            cout << "------------------------------------------------------------------" << endl;

            if(option != "1" && option != "2") {
                cout << "Opción invalida, intenta nuevamente" << endl;
            }

        } while (option != "1" && option != "2"); 

        if (option == "2") {
            verification = false;
        } else {
            if (option == "1") {
                cout << "Ingresa tu usuario:" << "\n";
                string userName, password;
                cin >> userName;
                cout << "Ingresa la contraseña:" << "\n";
                cin >> password;
                User* user = userVerification(userName, password, u);
                if (user != nullptr) {
                    menu(user, s, u);
                    cout << "------------------------------------------------------------------" << endl;
                } else {
                    cout << "------------------------------------------------------------------" << endl;
                    cout << "Usuario no encontrado" << endl;
                }
            }
        }
    }
}

int main(){
    vector<User*> users; //se inicializa el vector users
    vector<Software*> softwares;//se inicializa el vector software 
    populateEverything(softwares,users);
    system(softwares,users);
    return 0;
};

