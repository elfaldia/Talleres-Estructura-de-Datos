#include <iostream>
#include <stdio.h>
#include "conectFour.h"
using namespace std;

int main()
{
    conectFour game;
    //game.printBoard();
	game.printMenu();
    game.~conectFour();
    return 0;
}
