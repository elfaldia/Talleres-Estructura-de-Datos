#pragma once
#include <iostream>
#include <vector>
#include "Arista.h"
using namespace std;

// clase nodo
class Node{
    private:

        int id;
        string serverName;
        string type;
        vector<Arista> neighbors;
    public:

        Node(int id,string serverName,string type){
            this->id=id;
            this->serverName = serverName;
            this->type = type;
        }
        int getId(){
            return this->id;
        }
        string getServerName(){
            return this->serverName;
        }
        string getType(){
            return this->type;
        }
        const vector<Arista>& getNeighbors() const {
        return neighbors;
        }
        void addNeighbor(int idNeighbor, int velocidad, int segundos) {
            neighbors.push_back(Arista(idNeighbor, velocidad, segundos));
        }
        vector<Arista> getNeighbors(){
            return neighbors;
        }
};