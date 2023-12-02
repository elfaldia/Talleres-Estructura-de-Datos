#include <iostream>
#include <stdio.h>
#include "conectFour.h"
#include "Tree.h"
using namespace std;

void letsPlay(conectFour game, int mode)
{
    Tree tree;
    char player = 'X' , ia = 'O';
    cout<<"welcome to the easy mode conect 4!\nlest's begin!\n"<<endl;

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
        tree.generateTree(game, 4); // Ajusta la profundidad según sea necesario
        int cpuColumn;
        //la difilcutad dira la jugada adecuada 
        if(mode==1){
            cpuColumn = tree.findMediumMovement();
        }else if(mode == 2){
            cpuColumn = tree.findBetterMovement();
        }

        if (game.playerMovements('O', cpuColumn)) {
            if (game.checkFourInLine('O')) {
                cout << "¡La CPU ha ganado!" << endl;
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
                    letsPlay(game,mode);
                    break;
                case 3:
                    mode = 2;
                    letsPlay(game,mode);
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
