#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Node.h"
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

int main()
{
    vector<Node*> nodos;
    fillVector(nodos);
    for(Node* nodo : nodos){
        cout<<nodo->getServerName()<<endl;
    }
    return 0;
}