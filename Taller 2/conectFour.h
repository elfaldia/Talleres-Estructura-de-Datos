#include <iostream>
#include <string>
using namespace std;

class conectFour
{
private:
    int row;
    int column;
    int** board;
public:
    conectFour();
    ~conectFour();
    void printBoard();
    int printMenu();
};

conectFour::conectFour()
{
    this->column = 7;
    this->row = 6;
    this->board = new int*[row];
    for(int i = 0; i < row; i++){
        this->board[i] = new int[column];
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            this-> board[i][j] = 0; 
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
}

int conectFour::printMenu()
{
    cout << "\nHello, welcome to the game Connect 4!" <<endl;
    while (true) {
        string option;
        cout << "The difficulty levels that exist will be displayed below. Enter the number you want:\n1.- Easy.\n2.- Normal.\n3.- Hard.\n" <<endl;

        try {
            cin >> option;
            int optionNumber =stoi(option);

            switch (optionNumber) {
                case 1:
                    return optionNumber;
                    break;
                case 2:
                    return optionNumber;
                    break;
                case 3:
                    return optionNumber;
                    break;
                default:
                    cout <<"Invalid menu, try again.\n"<<endl;
            }
        } catch (const invalid_argument& e) {
            cerr << "Error: Invalid entry. Please enter a valid number.\n" << endl;
        }
    }return -1;
}
