#include <iostream>
#include <vector>
#include "Arista.h"
#include "Node.h"
using namespace std;

class Grafo{
    private:
        vector<Node*> nodos;
    public:
       void addNode(Node*& newNode) {
            nodos.push_back(newNode);
        }

        void addArista(int idNodoUno, int idNodoDos, int velocidad, int segundos) {
            Node* node1 = nullptr;
            Node* node2 = nullptr;

            for (Node* node : nodos) {
                if (node->getId() == idNodoUno) {
                    node1 = node;
                } else if (node->getId() == idNodoDos) {
                    node2 = node;
                }

                if (node1 != nullptr && node2 != nullptr) {
                    break;
                }
            }

            if (node1 != nullptr && node2 != nullptr) {
                node1->addNeighbor(idNodoDos, velocidad, segundos);
                node2->addNeighbor(idNodoUno, velocidad, segundos);
            } else {
                cout << "Error: No se encontraron nodos con los IDs proporcionados." << endl;
            }
        }
        vector<Node*> getNodos(){
            return nodos;
        }
};
