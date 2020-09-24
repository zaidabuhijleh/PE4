#include <iostream>
#include <string>

char** CreateBoard()
{
    char** board = new char*[3];
    for(int i = 0; i < 3; i++) {
        board[i] = new char[3];
        // for(int j = 0; j < 3; j++) {
        //     board[i][j] = ' ';
        // }
    }
    return board;
}

int main()
{
    char** test = CreateBoard();
    return 0;
}