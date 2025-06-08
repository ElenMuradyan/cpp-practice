#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void printBoard (string board[3][3]) {
    for(int i = 0; i < 3; i++){
        cout << "------------" << endl;
        for(int j = 0; j < 3; j++){
            cout << " " << board[i][j] << " |";
        }
        cout << endl;
    }
    cout << "------------" << endl;
}

bool makeMove (string player, string board[3][3]) {
    int row, column;
    cout << "Enter the row (0-2): " << endl;
    cin >> row;
    cout << "Enter the column (0-2): " << endl;
    cin >> column;

    if(row < 0 || row > 2 || column < 0 || column > 2){
        cout << "Unavailable move, you lost:(" << endl;
        return false;
    }

    if(board[row][column] == " "){
        board[row][column] = player;
        cout << "Good move ;) " << endl;
        return true;
    }else{
        cout << "Unavailable move, you lost:(" << endl;
        return false;
    }
}

bool didWin (string player, string board[3][3]) {
    for(int a = 0; a < 3; a++) {
        if(player == board[a][0] && board[a][0] == board[a][1] && board[a][1] == board[a][2]){
            return true;
        }

        if(player == board[0][a] && board[0][a] == board[1][a] && board[1][a] == board[2][a]){
            return true;
        }
    }
    if(player == board[0][0] && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;

    if(player == board[0][2] && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false;
}

int main() {
    const string player1 = "x";
    const string player2 = "o";

    string board[3][3] = {
        {" ", " ", " "},
        {" ", " ", " "},
        {" ", " ", " "},
    };

    for(int steps = 1; steps <= 9; steps++){
        string player = steps % 2 ? player1 : player2;
        cout << player << "'s move, good luck ;)" << endl;
        bool didMakeRightMove = makeMove(player, board);
        if(!didMakeRightMove){
            cout << "The game is finshed, wrog move :(" << endl;
            return 0;
        }
        printBoard(board);
        if(steps >= 5){
            if(didWin(player, board)){
                cout << "The game is finished," << player << " player SLAYED the game ;)" << endl;
                return 0;
            }
        }
    }
    cout << "Both Failed, HAHA :0" << endl;
    return 0;
}