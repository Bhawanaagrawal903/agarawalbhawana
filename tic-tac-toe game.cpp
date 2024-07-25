#include <iostream>
#include<cstdlib>
using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

void displayBoard() {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(char mark) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark)
            return true;
    }
    // Check columns
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == mark && board[1][j] == mark && board[2][j] == mark)
            return true;
    }
    // Check diagonals
    if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark)
        return true;
    if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)
        return true;
    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    int row, col;
    char currentPlayer = 'X';

    string first;
    string second;

    cout<<"write player name";
    cin>>first>>second;

    system("cls");


    //some rules
    cout<<"1.Each player assigned distinct symbol('x','o')"<<endl;
    cout<<"2.The First player marks the grid with 'x' and the Second player marks with 'o'"<<endl;
    cout<<"3.Player can not overwrite or remove their opponents mark"<<endl;
    cout<<"4.The game continues until one player achieves three marks in a row,column,diagonal or the grid is filled with no winner."<<endl;
    cout<<endl;
    flush(cout);

    system("cls");

    while (true) {
        displayBoard();
        cout << "Player " << currentPlayer << "'s turn. Enter row and column (0-2): ";
        cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin(currentPlayer)) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        } else if (checkDraw()) {
            displayBoard();
            cout << "It's a draw!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
