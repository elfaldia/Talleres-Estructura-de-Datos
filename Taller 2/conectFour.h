#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include <limits.h>
#include <array>
#include <random>
#include <sstream>

using namespace std;

const int COLUMN = 7;
const int ROW = 6;
const char EMPTY = ' ';
const char PLAYER = 'X';
const char CPU = 'O';

class conectFour
{
private:
    char board[ROW][COLUMN];
public:
    conectFour();

    //---- funciones de utilidad para el juego ----
    void printBoard();
    void resetBoard();
    bool isBoardFull();
    bool checkFourInLine(char player);
    bool isColumnFull(int col);
    void removeTab(int col);
    int evaluateLine(char player, int row, int col, int rowDirection, int colDirection);
    int evaluateBoard();
    int getColumn();
    int getNumberOfPieces(int column, char piece);
    int getNumberOfEmptySpaces(int column);
    int evaluateLines(char player);
    //---------------------------------------------

    //----------- easy mode -----------
    bool playerMovements(char jugador,int index);
    bool easyIa(char ia);
    void easyMode();
    //---------------------------------

};

conectFour::conectFour()
{
    for (int i = 0; i < ROW; i++) {
	    for (int j = 0; j < COLUMN; j++) {
		    this->board[i][j] = ' ';
	    }
    }
}

int conectFour::getColumn(){
    int c = COLUMN;
    return c;
}

void conectFour::removeTab(int col)
{
    for (int i = 0; i < ROW; ++i) {
        if (board[i][col] == 'O') {
            this->board[i][col] = ' '; // Restablecer la última ficha de la CPU en la columna a un espacio vacío
            break;
        }
    }
}

int conectFour::evaluateLine(char player, int row, int col, int rowDirection, int colDirection) {
    int score = 0;
    char opponent = (player == PLAYER) ? CPU : PLAYER;

    int countPlayer = 0;
    int countEmpty = 0;
    for (int i = 0; i < 4; ++i) {
        int r = row + i * rowDirection;
        int c = col + i * colDirection;

        if (board[r][c] == player) {
            countPlayer++;
        } else if (board[r][c] == EMPTY) {
            countEmpty++;
        }
    }

    if (countPlayer == 4) {
        score += 1000;
    } else if (countPlayer == 3 && countEmpty == 1) {
        score += 100;
    } else if (countPlayer == 2 && countEmpty == 2) {
        score += 10;
    }

    int countOpponent = 0;
    countEmpty = 0;
    for (int i = 0; i < 4; ++i) {
        int r = row + i * rowDirection;
        int c = col + i * colDirection;

        if (board[r][c] == opponent) {
            countOpponent++;
        } else if (board[r][c] == EMPTY) {
            countEmpty++;
        }
    }

    if (countOpponent == 3 && countEmpty == 1) {
        score -= 90;
    } else if (countOpponent == 2 && countEmpty == 2) {
        score -= 9;
    }

    return score;
}

int conectFour::evaluateLines(char player) {
        int score = 0;
        for (int i = 0; i < ROW; ++i) {
            for (int j = 0; j <= COLUMN - 4; ++j) {
                score += evaluateLine(player, i, j, 0, 1);
            }
        }

        for (int i = 0; i <= ROW - 4; ++i) {
            for (int j = 0; j < COLUMN; ++j) {
                score += evaluateLine(player, i, j, 1, 0);
            }
        }

        for (int i = 0; i <= ROW - 4; ++i) {
            for (int j = 0; j <= COLUMN - 4; ++j) {
                score += evaluateLine(player, i, j, 1, 1);
            }
        }

        for (int i = 0; i <= ROW - 4; ++i) {
            for (int j = 3; j < COLUMN; ++j) {
                score += evaluateLine(player, i, j, 1, -1);
            }
        }

        return score;
    }

int conectFour::evaluateBoard() {
    int score = 0;
        score += evaluateLines(PLAYER);
        score -= evaluateLines(CPU);
        return score;
}

void conectFour::printBoard()
{
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COLUMN; ++j) {
            if (j == 0) {
                cout <<"["<< board[i][j]<<" "; 
            }else if(j == COLUMN-1){
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

int conectFour::getNumberOfPieces(int column, char piece) {
  int count = 0;
  for (int row = 0; row < ROW; row++) {
    if (board[row][column] == piece) {
      count++;
    }
  }
  return count;
}

int conectFour::getNumberOfEmptySpaces(int column) {
  int count = 0;
  for (int row = 0; row < ROW; row++) {
    if (board[row][column] == EMPTY) {
      count++;
    }
  }
  return count;
}

bool conectFour::isColumnFull(int col)
{
    for (int i = 0; i < ROW; ++i) {
        if (board[i][col] == ' ') {
            return false; // Si encuentra al menos un espacio vacío, la columna no está llena
        }
    }
    return true; // Si no se encontraron espacios vacíos, la columna está llena
}

bool conectFour::playerMovements(char player, int index)
{

    for(int i = ROW -1; i >= 0;i--){
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

    for(int i = ROW -1; i >= 0;i--){
        if(this -> board[i][index] == ' '){
            board[i][index] = ia;
            return true;
        }
    }return false;
}

void conectFour::resetBoard()
{
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            this->board[i][j] = ' ';
        }
    }
}

bool conectFour::isBoardFull() {
    // esta funcion verifica si las filas superiores estan todas llenas
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
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
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j <= COLUMN - 4; j++) {
            if (board[i][j] == player && board[i][j + 1] == player && board[i][j + 2] == player && board[i][j + 3] == player) {
                return true;
            }
        }
    }

    // se verificar en vertical
    for (int i = 0; i <= ROW - 4; i++) {
        for (int j = 0; j < COLUMN; j++) {
            if (board[i][j] == player && board[i + 1][j] == player && board[i + 2][j] == player && board[i + 3][j] == player) {
                return true;
            }
        }
    }

    // se verifica la diagonal de izquierda a derecha
    for (int i = 0; i <= ROW - 4; i++) {
        for (int j = 0; j <= COLUMN - 4; j++) {
            if (board[i][j] == player && board[i + 1][j + 1] == player && board[i + 2][j + 2] == player && board[i + 3][j + 3] == player) {
                return true;
            }
        }
    }
    // se verifica la diagonal de derecha a izquierda
    for (int i = 0; i <= ROW - 4; i++) {
        for (int j = 3; j < COLUMN; j++) {
            if (board[i][j] == player && board[i + 1][j - 1] == player && board[i + 2][j - 2] == player && board[i + 3][j - 3] == player) {
                return true;
            }
        }
    }
    return false;
}
