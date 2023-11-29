#include <iostream>
#include <string>
#include <random>
#include <cstring>
#pragma once
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
    void printBoard();
    void printMenu(); 
    void resetBoard();
    bool isBoardFull();
    bool checkFourInLine(char player);

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
    for(int i = 0; i < column; i++){
        delete[] this->board[i];
    }
    delete[] this->board;
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

void conectFour::printMenu()
{
    cout << "\nHello, welcome to the game Connect 4!\n" <<endl;
    int v = true;
    while (v) {
        string option;
        cout << "The difficulty levels that exist will be displayed below. Enter the number you want:\n1.- Easy.\n2.- Normal.\n3.- Hard.\n4.- Exit\n" <<endl;

        try {
            cin >> option;
            int optionNumber =stoi(option);

            switch (optionNumber) {
                case 1:
                    easyMode();
                    break;
                case 2:
                    
                    break;
                case 3:
                    
                    break;
                case 4:
                    cout<<"Thanks for playing with us!\n"<<endl;
                    v = false;
                    break;
                default:
                    cout <<"Invalid menu, try again.\n"<<endl;
            }
        } catch (const invalid_argument& e) {
            cerr << "Error: Invalid entry. Please enter a valid number.\n" << endl;
        }
    }
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
    for (int j = 0; j < column; j++) {
        if (board[0][j] == ' ') {
            return false;
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