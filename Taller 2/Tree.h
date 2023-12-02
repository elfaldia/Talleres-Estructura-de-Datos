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
    void generateTreeRec(Node* node, conectFour& game, int depth, bool maximizingPlayer);
    int minimax(Node* node, bool maximizingPlayer);
    int findBetterMovement();
    int findMediumMovement();
    int normalizeScore(int score);
};

Tree::Tree()
{
    this->root = nullptr;
}

Tree::~Tree()
{
    for (Node* child : root->children) {
        delete child;
    }
}

void Tree::generateTree(conectFour& game, int depth) {
        root = new Node();
        generateTreeRec(root, game, depth, true);
}

void Tree::generateTreeRec(Node* node, conectFour& game, int depth, bool maximizingPlayer) {
    if (depth == 0 || game.isBoardFull() || game.checkFourInLine('X') || game.checkFourInLine('O')) {
        node->value = normalizeScore(game.evaluateBoard());
        return;
    }

    for (int col = 0; col < game.getColumn(); ++col) {
        if (!game.isColumnFull(col)) {
            conectFour copyGame(game);
            if (maximizingPlayer) {
                copyGame.playerMovements('X',col);
            } else {
                copyGame.playerMovements('O',col);
            }

            Node* child = new Node();
            child->column = col;
            node->children.push_back(child);

            generateTreeRec(child, copyGame, depth - 1, !maximizingPlayer);
        }
    }

    // Actualizar el valor del nodo padre después de que todos los nodos hijos hayan sido evaluados
    if (maximizingPlayer) {
        node->value = INT_MIN;
        for (Node* child : node->children) {
            node->value = max(node->value, child->value);
        }
    } else {
        node->value = INT_MAX;
        for (Node* child : node->children) {
            node->value = min(node->value, child->value);
        }
    }
}

int Tree::minimax(Node* node, bool maximizingPlayer) {
    if (node->children.empty()) {
            return node->value;
    }

    if (maximizingPlayer) {
        int maxEval = INT_MIN;
        for (Node* child : node->children) {
            int eval = minimax(child, false);
            maxEval = max(maxEval, eval);
        }
        return maxEval;
    } else {
        int minEval = INT_MAX;
        for (Node* child : node->children) {
            int eval = minimax(child, true);
            minEval = min(minEval, eval);
        }
        return minEval;
    }
}


int Tree::findBetterMovement() {
    int bestMove = -1;
    int bestValue = INT_MIN;

    for (Node* child : root->children) {
        int eval = minimax(child, false);
        if (eval > bestValue) {
            bestValue = eval;
            bestMove = child->column;
        }
    }

    return bestMove;
}

int Tree::findMediumMovement() {
    int bestMove = -1;
    int bestValue = INT_MIN;

    // Encuentra la mejor jugada y su valor
    for (Node* child : root->children) {
        int eval = minimax(child, false);
        if (eval > bestValue) {
            bestValue = eval;
            bestMove = child->column;
        }
    }

    // Encuentra una jugada que no sea la mejor, pero tenga un valor entre el 50% y el 100% del mejor
    int mediumMove = -1;

    for (Node* child : root->children) {
        int eval = minimax(child, false);
        if (eval > 0.5 * bestValue && eval <= bestValue) {
            mediumMove = child->column;
            break;
        }
    }

    // Si no se encuentra una jugada media, devuelve la mejor jugada
    return (mediumMove != -1) ? mediumMove : bestMove;
}

int Tree::normalizeScore(int score) {
    return static_cast<int>((score + 1000.0) / 20.0);
}
