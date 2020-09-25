#include <iostream>
#include <string>

/**
    Creates a new 3x3 tic tac toe board

    @return char array representing an empty board
*/
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

/**
    Gets user input for where to make a move on the board

    @return     array with coordinate
*/
int *GetPlayerChoice(){
    int pos[2];
    std::string input;
    std::cout << "Please enter a coordinate where you would like to place your move using the format <row> ENTER <column> from available coordinates 1-3: ";
    std::cin >> pos[0];
    std::cin >> pos[1];
    //convert to array coords
    pos[0]-=1;
    pos[1]-=1;
    std::cout << pos[0] << "," << pos[1] << std::endl;

    return pos;
}

int main()
{
    char** test = CreateBoard();
    DisplayBoard(test);
    GetPlayerChoice();
    return 0;
} 