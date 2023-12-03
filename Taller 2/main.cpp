#include <iostream>
#include <stdio.h>
#include <chrono>
#include "conectFour.h"
#include "Tree.h"
using namespace std;

void letsPlayMinimax(conectFour game, int mode)
{
    Tree tree;
    char player = 'X' , ia = 'O';
    cout<<"welcome to the easy mode conect 4!\nlest's begin!\n"<<endl;
    auto start_time = chrono::high_resolution_clock::now();
    while(true)
    {

        // comprobacion de que exista un empate
        if(game.isBoardFull())
        {
            game.printBoard();
            cout<<"--------------------\nUh... it's a tie!\n--------------------\n"<<endl;
            game.resetBoard();
            break;
        }
        game.printBoard();
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
        if(!game.playerMovements(player,playerMove))
        {
            cout<<"The column you selected is full, try another\n"<<endl;
            continue;
        }else{
            game.printBoard();
            cout<<"successful movement\n"<<endl;

            //comprobacion de victoria del jugador
            if(game.checkFourInLine(player))
            {
                game.printBoard();
                cout<<"------------------------------------\nCongratulations player you have won!\n------------------------------------\n"<<endl;
                game.resetBoard();
                break;
            }
        }
        // Turno de la computadora
        tree.generateTree(game, 4); 
        int cpuColumn;
        //la difilcutad dira la jugada adecuada 
        if(mode==1){
            cpuColumn = tree.findMediumMovement();
        }else if(mode == 2){
            auto better_start_time = chrono::high_resolution_clock::now();
            cpuColumn = tree.findBetterMovement();
            auto better_end_time = chrono::high_resolution_clock::now();

            // Calcula la duración de la llamada a findBetterMovement
            auto better_duration = chrono::duration_cast<chrono::microseconds>(better_end_time - better_start_time);

            cout << "Tiempo de findBetterMovement: " << better_duration.count() << " microsegundos\n" << endl;
        }

        if (game.playerMovements('O', cpuColumn)) {
            if (game.checkFourInLine('O')) {
                game.printBoard();
                cout <<"------------------------------------\nYou lost!! CPU win\n------------------------------------\n"<< endl;
                break;
            }
        } else {
            cout << "Error en el movimiento de la CPU." << endl;
        }
    } game.resetBoard();
}

void letsPlayMinimaxPAB(conectFour game, int mode)
{
    Tree tree;
    char player = 'X' , ia = 'O';
    cout<<"welcome to the easy mode conect 4!\nlest's begin!\n"<<endl;
    auto start_time = chrono::high_resolution_clock::now();
    while(true)
    {

        // comprobacion de que exista un empate
        if(game.isBoardFull())
        {
            game.printBoard();
            cout<<"--------------------\nUh... it's a tie!\n--------------------\n"<<endl;
            game.resetBoard();
            break;
        }
        game.printBoard();
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
        if(!game.playerMovements(player,playerMove))
        {
            cout<<"The column you selected is full, try another\n"<<endl;
            continue;
        }else{
            game.printBoard();
            cout<<"successful movement\n"<<endl;

            //comprobacion de victoria del jugador
            if(game.checkFourInLine(player))
            {
                game.printBoard();
                cout<<"------------------------------------\nCongratulations player you have won!\n------------------------------------\n"<<endl;
                game.resetBoard();
                break;
            }
        }
        // Turno de la computadora
        tree.generateTree(game, 4); 
        int cpuColumn;
        //la difilcutad dira la jugada adecuada 
        if(mode==1){
            cpuColumn = tree.findMediumMovementPAB();
        }else if(mode == 2){

            auto better_start_time = chrono::high_resolution_clock::now();
            cpuColumn = tree.findBetterMovementPAB();
            auto better_end_time = chrono::high_resolution_clock::now();

            // Calcula la duración de la llamada a findBetterMovement
            auto better_duration = chrono::duration_cast<chrono::microseconds>(better_end_time - better_start_time);

            cout << "Tiempo de findBetterMovement: " << better_duration.count() << " microsegundos\n" << endl;
        }

        if (game.playerMovements('O', cpuColumn)) {
            if (game.checkFourInLine('O')) {
                game.printBoard();
                cout <<"------------------------------------\nYou lost!! CPU win\n------------------------------------\n"<< endl;
                break;
            }
        } else {
            cout << "Error en el movimiento de la CPU." << endl;
        }
    } game.resetBoard();
}

void printMenu(conectFour game)
{
    cout << "\nHello, welcome to the game Connect 4!\n" <<endl;
    int v = true;
    int algorithm;
    cout << "(choose which algorithm you want to program the computer with)\n1.- minimax\n2.- minimax with poda alpha beta\n" <<endl;

    // validacion para ingresar el indice por teclado
    while(true)
    {
        try {
            string selection;
            cin>>selection;
            algorithm = stoi(selection);
            if(algorithm==1 || algorithm==2){
                break;
            }else{
                cout<<"invalid cin, try again\n"<<endl;
            }
        } catch (const invalid_argument& e) {
                cerr << "Error: Invalid entry. Please enter a valid number.\n" << endl;
        }
    }

    while (v) {
        string option;
        cout << "The difficulty levels that exist will be displayed below. Enter the number you want:\n1.- Easy.\n2.- Normal.\n3.- Hard.\n4.- Exit\n" <<endl;

        try {
            cin >> option;
            int optionNumber =stoi(option);
            int mode;
            switch (optionNumber) {
                case 1:
                    game.easyMode();
                    break;
                case 2:
                    mode = 1;
                    if(algorithm==1){
                        letsPlayMinimax(game,mode);
                    }else{
                        letsPlayMinimaxPAB(game,mode);
                    }
                    break;
                case 3:
                    mode = 2;
                    if(algorithm==1){
                        letsPlayMinimax(game,mode);
                    }else{
                        letsPlayMinimaxPAB(game,mode);
                    }
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

int main()
{
    conectFour game;
    printMenu(game);
    return 0;
}
