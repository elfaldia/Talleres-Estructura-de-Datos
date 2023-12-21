#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include "Arista.h"
#include "Node.h"
using namespace std;

// clase grafo
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
    // Calculadora del tiempo (devuelve numero entero)
    // --------------------------------
    int calculadoraTiempo(int pesoMb,int velocidad){
        int division = 0;
        if(pesoMb < velocidad){
            return 1;
        }else{
            division = (pesoMb / velocidad);
            return (division+1);
        }
    }
    // --------------------------------
    // ALGORITMO BELLMAN-FORD
    // --------------------------------
    void bellmanFord(int nodoOrigen, int pesoMb, int destino) {
        // variables bellman
        int numNodos = nodos.size();
        vector<double> distancia(numNodos, numeric_limits<double>::infinity());
        vector<int> padre(numNodos, -1);
        double tiempoTotal = 0.0;

        distancia[nodoOrigen] = 0;

        for (int i = 0; i < numNodos - 1; ++i) {
            for (Node* nodo : nodos) {
                for (const Arista& arista : nodo->getNeighbors()) {
                    int u = nodo->getId();
                    int v = arista.getDestino();
                    int peso = arista.getSegundos();

                    // Calcular tiempo total
                    int tiempo = calculadoraTiempo(pesoMb,arista.getVelocidad());
                    double tiempoArista = tiempo * arista.getSegundos();

                    if (distancia[u] != numeric_limits<double>::infinity() && distancia[u] + tiempoArista < distancia[v]) {
                        // Actualizar la distancia y el padre
                        distancia[v] = distancia[u] + tiempoArista;
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

                // Calcular tiempo total
                int tiempo = calculadoraTiempo(pesoMb,arista.getVelocidad());
                double tiempoArista = tiempo * arista.getSegundos();

                if (distancia[u] != numeric_limits<double>::infinity() && distancia[u] + tiempoArista < distancia[v]) {
                    cerr << "El grafo contiene ciclos negativos." << endl;
                    return;
                }
            }
        }

        // Imprimir resultados
        cout << "Tiempo total a tardar desde " << nodoOrigen << " hasta " << destino << ": " << distancia[destino] << " segundos." << endl;

        // mostrar el camino de los nodos
        vector<int> camino;
        int nodoActual = destino;
        while (nodoActual != -1) {
            camino.push_back(nodoActual);
            nodoActual = padre[nodoActual];
        }

        reverse(camino.begin(), camino.end());

        cout << "Camino: ";
        for (int nodo : camino) {
            cout << nodo << " ";
        }
        cout << endl;

        // mostrar el camino de cada nodo por tiempo acumulado
        cout << "Camino en función del tiempo: " << endl;
        for (int i = 0; i < numNodos; ++i) {
            for(int j=0;j<camino.size();j++){
                if(camino[j] == i){
                    cout << "Nodo: " << i << ", Tiempo acumulado: " << distancia[i] << " segundos" << endl;
                }
            }
        }
    }
};