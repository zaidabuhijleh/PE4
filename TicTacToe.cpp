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
int* GetPlayerChoice()
{
    std::cout << "Please enter a location on the board. Enter response in form of <row> ENTER <column>, each ranging from 1-3:" << std::endl;
    int* position = new int[2];
    std::cin >> position[0];
    std::cin >> position[1];
    position[0]-=1;
    position[1]-=1;
    std::cout << "Index: " << position[0] << ", " << position[1] << std::endl;

    return position;
}


/**
    Sets the 'X' or 'O' marks on the board based on the player turn.

*/
void PlaceMarker(int* pos, int turnCount, char** board)
{
    int player = turnCount % 2;
    int a = pos[0];
    int b = pos[1];

    if(player == 0)
    {
        board[a][b] = 'X';
    }
    else
    {
        board[a][b] = 'O';
    }
}

bool isGameOver(char** board, int turnCount)
{

    for(int i = 0; i < 3; i++)
    {

        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            if(board[i][0] != '\0') {

                std::cout << "Player " << board[i][0] << " won!" << std::endl;
                return true;
            }
        }
    }
    for(int i = 0; i < 3; i++)
    {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            if(board[0][i] != '\0') {
                std::cout << "Player " << board[0][1] << " won!" << std::endl;
                return true;
            }
        }
    }
    if((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
    {
        if(board[1][1] != '\0') {
            std::cout << "Player " << board[1][1] << " won!" << std::endl;
            return true;
        }
    }
    if(turnCount == 8)
    {
        std::cout << "No one won!" << std::endl;
        return true;
    }
    return false;
}

int main()
{
    char** test = CreateBoard();
    DisplayBoard(test);
    int turnCount = 0;
    while(true)
    {
        int* choice = GetPlayerChoice();
        PlaceMarker(choice, turnCount, test);
        DisplayBoard(test);
        if(isGameOver(test, turnCount))
        {
            break;
        }
        turnCount++;
    }

    return 0;
}