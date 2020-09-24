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

void DisplayBoard(char** board)
{
    std::cout << "----------" << std::endl;
    for(int i=0; i < 3; i++)
    {
        std::cout << "| ";
        for(int j= 0; j < 3; j++)
        {
            if(j == 2)
            {
                std::cout << board[i][j] << " |" << std::endl;
                std::cout << "----------" << std::endl;
            }
            else
            {
                std::cout << board[i][j] << " | ";
            }

        }
    }
    std::cout<<std::endl;
}

int main()
{
    char** test = CreateBoard();
    DisplayBoard(test);
    return 0;
}