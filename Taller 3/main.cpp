#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Node.h"
#include "Grafo.h"
#include "Arista.h"
using namespace std;

void fillVector(vector<Node*>& lista){
    ifstream readFile("servidores.csv");
    string line;
    char delimiter = ',';

    if (!readFile.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return; // o manejar el error de alguna otra manera
    }

    // Se lee la primera linea que contiene los atributos de cada casilla
    getline(readFile,line);

    // Se leen todas las lineas
    while(getline(readFile,line)){

        if (line.empty()) {
            continue; // Ignorar líneas vacías
        }
        
        stringstream stream(line); // Se convierte a un stream
        string id, serverName, type;

        // Se sacan los valores del archivo
        getline(stream, id, delimiter);
        getline(stream, serverName,delimiter);
        getline(stream, type, delimiter);
        int idNumber = stoi(id);
        // Se rellena el vector
        Node *nodo = new Node(idNumber,serverName,type);
        lista.push_back(nodo);
    }
    readFile.close();
}

Node* getNode(vector<Node*>& lista, int id){
    for(Node* nodo: lista){
        if(nodo->getId() == id){
            return nodo;
        }
    }
    return nullptr;
}

void fillGrafo(vector<Node*>& lista, Grafo& grafo){
    for(Node* nodo:lista){
        grafo.addNode(nodo);
    }
}

void createConections(Grafo& grafo){

    ifstream readFile("conexiones.csv");
    string line;
    char delimiter = ',';

    if (!readFile.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return; // o manejar el error de alguna otra manera
    }

    // Se lee la primera linea que contiene los atributos de cada casilla
    getline(readFile,line);

    // Se leen todas las lineas
    while(getline(readFile,line)){

        if (line.empty()) {
            continue; // Ignorar líneas vacías
        }
        
        stringstream stream(line); // Se convierte a un stream
        string idCliente, idServidor, velocidad, segundo;

        // Se sacan los valores del archivo
        getline(stream, idCliente, delimiter);
        getline(stream, idServidor,delimiter);
        getline(stream, velocidad, delimiter);
        getline(stream, segundo, delimiter);
        int idClienteNumero = stoi(idCliente), idServidorNumero = stoi(idServidor), velocidadNumero = stoi(velocidad), segundosNumero = stoi(segundo);
        grafo.addArista(idClienteNumero,idServidorNumero,velocidadNumero,segundosNumero);

    }
    readFile.close();
}

int main()
{
    // variables
    Grafo grafo;
    vector<Node*> nodos;

    //funciones
    fillVector(nodos);
    fillGrafo(nodos,grafo);
    createConections(grafo);
    vector<Node*> vectorNode = grafo.getNodos();

    // esto es un print trucho para para que veas como funcionan las conexiones 
    /*
    for (Node* nodo : vectorNode) {
        cout << "Nodo " << nodo->getId() << " - " << nodo->getServerName() << " - " << nodo->getType() << endl;
        cout << "Aristas:" << endl;
        for (Arista& arista : nodo->getNeighbors()) {
            cout << "  Destino: " << arista.getDestino() << " (Velocidad: " << arista.getVelocidad() << ", Segundos: " << arista.getSegundos() << ")" << endl;
        }
        cout << endl;
    }
    */

    int idNodo, pesoElegido, idDestino;
    bool menuBool = true;
    string eleccion;
    
    while(menuBool){
        cout << "-----------------------------------" << endl;
        cout << "                Menu             " << endl;
        cout << "-----------------------------------" << endl;

        cout << "Ingrese la id del origen: " << endl;
        cin >> idNodo;
        cout << "Ingrese el peso del archivo(mb): " << endl;
        cin >> pesoElegido;
        cout << "Ingrese la id del destino: " << endl;
        cin >> idDestino;
        cout << "-----------------------------------" << endl;

        grafo.bellmanFord(idNodo,pesoElegido,idDestino);

        cout << "-----------------------------------" << endl;
        cout << "Desea elegir otro destino?: (si/no)" << endl;
        cout << "-----------------------------------" << endl;
        cin >> eleccion;
        if(eleccion == "no"){
            menuBool = false;
        }
        cout << "-----------------------------------" << endl;
    }

    cout << "Saliendo del programa." << endl;
    cout << "-----------------------------------" << endl;


    return 0;
}