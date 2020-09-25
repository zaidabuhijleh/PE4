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

int* PlayerChoice()
{
    std::cout << "Please enter a location on the board. Enter response in form of <row> ENTER <column>, each ranging from 0-2:" << std::endl;
    int position[2];
    std::cin >> position[0];
    std::cin >> position[1];
//    std::cout << "HERE: " << position << std::endl;
    return position;
}

void PlacePlayer(int* pos, int turnCount, char** board)
{
    int player = turnCount % 2;
    if(player == 0)
    {
        board[pos[0]][pos[1]] = 'X';
    }
    else
    {
        board[pos[0]][pos[1]] = 'O';
    }

}

int main()
{
    char** test = CreateBoard();
    DisplayBoard(test);
    int turnCount = 0;
    while(true)
    {
        int* choice = PlayerChoice();
        PlacePlayer(choice, turnCount, test);
        DisplayBoard(test);
        turnCount++;
    }
    return 0;
}