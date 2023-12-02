#pragma once
#include "conectFour.h"
#include "Node.h"
#include <iostream>
#include <climits>
using namespace std;

class Tree
{
private:
    Node* root;
public:
    Tree();
    ~Tree();
    void generateTree(conectFour& game, int depth);
    int minimax(Node* node, int depth, bool maximizingPlayer, conectFour& game);
    int findBetterMovement();
};

Tree::Tree()
{
    this->root = nullptr;
}

Tree::~Tree()
{
    delete root;
}

void Tree::generateTree(conectFour& game, int depth)
{
    root = new Node();

    for (int col = 0; col < game.getColumn(); col++) {
        if (!game.isColumnFull(col)) {
            game.playerMovements('O', col); // Simular el movimiento de la CPU
            Node* child = new Node();
            child->column = col;
            child->value = minimax(child, depth - 1, false, game);
            child->father = root;
            root->children.push_back(child);
            game.removeTab(col); // Deshacer el movimiento simulado
        }
    }
}

int Tree::minimax(Node* node, int depth, bool maximizingPlayer,conectFour& game) {
    if (depth == 0 || game.isBoardFull()) {
        return game.evaluateBoard();
    }

    if (maximizingPlayer) {
        int maxEval = 0;
        for (Node* child : node->children) {
            int eval = minimax(child, depth - 1, false,game);
            maxEval = max(maxEval, eval);
        }
        return maxEval;
    } else {
        int minEval = 100;
        for (Node* child : node->children) {
            child->value = minimax(child, depth - 1, false, game);
            minEval = min(minEval, child->value);
        }
        return minEval;
    }
}

int Tree::findBetterMovement() {
    int betterMovement = -1;
    int betterValue = 0;

    for (Node* child : root->children) {
        if (child->value > betterValue) {
            betterValue = child->value;
            betterMovement = child->column;
        }
    }
    return betterMovement;
}
