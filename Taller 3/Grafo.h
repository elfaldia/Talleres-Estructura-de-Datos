#include <iostream>
#include <vector>
#include <limits>
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
        // --------------------------------
        // ALGORITMO BELLMAN-FORD
        // --------------------------------
        void bellmanFord(int nodoOrigen, int pesoMb, int destino) {
            int numNodos = nodos.size();
            vector<int> distancia(numNodos, numeric_limits<int>::max());
            vector<int> padre(numNodos, -1);
            double tiempoTotal = 0.0;

            distancia[nodoOrigen] = 0;

            // Aplicar el algoritmo de Bellman-Ford
            for (int i = 0; i < numNodos - 1; ++i) {
                for (Node* nodo : nodos) {
                    for (const Arista& arista : nodo->getNeighbors()) {
                        int u = nodo->getId();
                        int v = arista.getDestino();
                        int peso = arista.getSegundos();

                        if (distancia[u] != numeric_limits<int>::max() && distancia[u] + peso < distancia[v]) {
                            
                            double importante = (pesoMb / arista.getVelocidad())*arista.getSegundos();
                            tiempoTotal += importante;

                            distancia[v] = distancia[u] + peso;
                            padre[v] = u;
                        }
                    }
                }
            }

            // Verificar ciclos negativos
            for (Node* nodo : nodos) {
                for (const Arista& arista : nodo->getNeighbors()) {
                    int u = nodo->getId();
                    int v = arista.getDestino();
                    int peso = arista.getSegundos();

                    if (distancia[u] != numeric_limits<int>::max() && distancia[u] + peso < distancia[v]) {
                        cerr << "El grafo contiene ciclos negativos." << endl;
                        return;
                    }
                }
            }

            // Imprimir resultados (opcional)
            for (int i = 0; i < numNodos; ++i) {
                if(i == destino){
                    cout << "Distancia desde " << nodoOrigen << " hasta " << i << ": " << distancia[i] << endl;
                    cout << "Segundos a tardar: " << tiempoTotal << endl;
                }
            }
        }

};