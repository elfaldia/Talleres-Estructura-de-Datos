#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include <limits.h>
#include <array>
#include <random>
#include <sstream>

using namespace std;

class conectFour
{
private:
    int row;
    int column;
    char** board;

public:
    conectFour();
    ~conectFour();

    //---- funciones de utilidad para el juego ----
    void printBoard();
    void resetBoard();
    bool isBoardFull();
    bool checkFourInLine(char player);
    bool isColumnFull(int col);
    int getColumn();
    void removeTab(int col);
    int evaluateLine(char c1, char c2, char c3, char c4)const;
    int evaluateBoard()const;
    //---------------------------------------------

    //----------- easy mode -----------
    bool playerMovements(char jugador,int index);
    bool easyIa(char ia);
    void easyMode();
    //---------------------------------

};

conectFour::conectFour()
{
    this->column = 7;
    this->row = 6;
    this->board = nullptr;

    this->board = new char*[row];
    for(int i = 0; i < row; i++){
        this->board[i] = new char[column];
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            this-> board[i][j] = ' '; 
        }
    }
}

conectFour::~conectFour()
{
    if (board != nullptr) {
        // Liberar memoria de cada fila
        for (int i = 0; i < row; ++i) {
            delete[] board[i];
        }

        // Liberar memoria de la matriz
        delete[] board;
    }
}

int conectFour::getColumn(){return this->column; }

void conectFour::removeTab(int col)
{
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 'O') {
            this->board[i][col] = ' '; // Restablecer la última ficha de la CPU en la columna a un espacio vacío
            break;
        }
    }
}

int conectFour::evaluateLine(char c1, char c2, char c3, char c4)const
{
     // Otorgamos puntos si hay al menos una ficha del jugador humano y ninguna de la CPU.
    int score = 0;

    if (c1 == 'X') score += 25;
    if (c2 == 'X') score += 25;
    if (c3 == 'X') score += 25;
    if (c4 == 'X') score += 25;

    if (c1 == 'O') score -= 25;
    if (c2 == 'O') score -= 25;
    if (c3 == 'O') score -= 25;
    if (c4 == 'O') score -= 25;

    return score;
}

int conectFour::evaluateBoard() const {
 
    // Mostramos una evaluación simple contando las fichas en línea.

    int score = 0;

    // Evaluar filas
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j <= column - 4; ++j) {
            score += evaluateLine(board[i][j], board[i][j + 1], board[i][j + 2], board[i][j + 3]);
        }
    }

    // Evaluar columnas
    for (int j = 0; j < column; ++j) {
        for (int i = 0; i <= row - 4; ++i) {
            score += evaluateLine(board[i][j], board[i + 1][j], board[i + 2][j], board[i + 3][j]);
        }
    }

    // Evaluar diagonales ascendentes
    for (int i = 3; i < row; ++i) {
        for (int j = 0; j <= column - 4; ++j) {
            score += evaluateLine(board[i][j], board[i - 1][j + 1], board[i - 2][j + 2], board[i - 3][j + 3]);
        }
    }

    // Evaluar diagonales descendentes
    for (int i = 0; i <= row - 4; ++i) {
        for (int j = 0; j <= column - 4; ++j) {
            score += evaluateLine(board[i][j], board[i + 1][j + 1], board[i + 2][j + 2], board[i + 3][j + 3]);
        }
    }

    // Asegurar que el score esté en el rango de 0 a 100
    score = max(0, min(100, score));

    return score;
}

void conectFour::printBoard()
{
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if (j == 0) {
                cout <<"["<< board[i][j]<<" "; 
            }else if(j == column-1){
                cout<< board[i][j]<<"]"; 
            }else{
                cout<< board[i][j]<<" "; 
            }
        }
        cout<<endl;
    }
    cout<<"---------------"<<endl;
    cout<<"[0 1 2 3 4 5 6]\n"<<endl;
}

void conectFour::easyMode()
{   
    char player = 'X' , ia = 'O';
    cout<<"welcome to the easy mode conect 4!\nlest's begin!\n"<<endl;

    while(true)
    {

        // comprobacion de que exista un empate
        if(isBoardFull())
        {
            printBoard();
            cout<<"--------------------\nUh... it's a tie!\n--------------------\n"<<endl;
            resetBoard();
            break;
        }
        printBoard();
        cout<<"player's turn...\n"<<endl;
        int playerMove;

        // validacion para ingresar el indice por teclado
        while(true)
        {
            string selection;
            cout<<"Enter your movement, remember that it must be (0-6)\n"<<endl;
            try {
                cin>>selection;
                playerMove = stoi(selection);
                if(playerMove>=0 && playerMove<=6){
                    break;
                }else{
                    cout<<"invalid column, try again\n"<<endl;
                }
            } catch (const invalid_argument& e) {
                cerr << "Error: Invalid entry. Please enter a valid number.\n" << endl;
            }
        }

        // verificacion de ingreso exitoso por parte del jugador
        if(!playerMovements(player,playerMove))
        {
            cout<<"The column you selected is full, try another\n"<<endl;
            continue;
        }else{
            cout<<"successful movement\n"<<endl;

            //comprobacion de victoria del jugador
            if(checkFourInLine(player))
            {
                printBoard();
                cout<<"------------------------------------\nCongratulations player you have won!\n------------------------------------\n"<<endl;
                resetBoard();
                break;
            }

        // verificacion de ingreso exitoso por parte de la IA
        }if(!easyIa(ia))
        {
            cout<<"There is no more space\n"<<endl;
            continue;
        }else{
            cout<<"successful IA movement\n"<<endl;

            //comprobacion de victoria de la ia
            if(checkFourInLine(ia))
            {
                printBoard();
                cout<<"-----------------------\nYou lost, the CPU won!\n-----------------------\n"<<endl;
                resetBoard();
                break;
            }
        }
    }
}

bool conectFour::isColumnFull(int col)
{
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == ' ') {
            return false; // Si encuentra al menos un espacio vacío, la columna no está llena
        }
    }
    return true; // Si no se encontraron espacios vacíos, la columna está llena
}

bool conectFour::playerMovements(char player, int index)
{
    for(int i = row -1; i >= 0;i--){
        if(this -> board[i][index] == ' '){
            this -> board[i][index] = player;
            return true;
        }
    }return false;
}

bool conectFour::easyIa(char ia)
{

    cout<<"CPU's turn...\n"<<endl;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 6);
    int index = dis(gen);

    for(int i = row -1; i >= 0;i--){
        if(this -> board[i][index] == ' '){
            board[i][index] = ia;
            return true;
        }
    }return false;
}

void conectFour::resetBoard()
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            this->board[i][j] = ' ';
        }
    }
}

bool conectFour::isBoardFull() {
    // esta funcion verifica si las filas superiores estan todas llenas
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool conectFour::checkFourInLine(char player)
{
    // se verificar en horizontal
    for (int i = 0; i < row; i++) {
        for (int j = 0; j <= column - 4; j++) {
            if (board[i][j] == player && board[i][j + 1] == player && board[i][j + 2] == player && board[i][j + 3] == player) {
                return true;
            }
        }
    }

    // se verificar en vertical
    for (int i = 0; i <= row - 4; i++) {
        for (int j = 0; j < column; j++) {
            if (board[i][j] == player && board[i + 1][j] == player && board[i + 2][j] == player && board[i + 3][j] == player) {
                return true;
            }
        }
    }

    // se verifica la diagonal de izquierda a derecha
    for (int i = 0; i <= row - 4; i++) {
        for (int j = 0; j <= column - 4; j++) {
            if (board[i][j] == player && board[i + 1][j + 1] == player && board[i + 2][j + 2] == player && board[i + 3][j + 3] == player) {
                return true;
            }
        }
    }
    // se verifica la diagonal de derecha a izquierda
    for (int i = 0; i <= row - 4; i++) {
        for (int j = 3; j < column; j++) {
            if (board[i][j] == player && board[i + 1][j - 1] == player && board[i + 2][j - 2] == player && board[i + 3][j - 3] == player) {
                return true;
            }
        }
    }
    return false;
}
