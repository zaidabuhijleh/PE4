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

/**
    Displays the tic tac toe board in the terminal

    @param b    2D array representing the board to display
*/
void DisplayBoard(char **b){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            std::cout << "\t" << b[i][j];
            if(j==0 || j==1){
                std::cout << "\t|";
            }
        }
        if(i!=2){
            std::cout << "\n\t----------------------------------";
        }
        std::cout << std::endl;
    }
}

int main()
{
    char** test = CreateBoard();
    DisplayBoard(test);
    return 0;
}