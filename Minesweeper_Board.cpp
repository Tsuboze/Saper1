#include "Minesweeper_Board.h"
#include <iostream>



void MinesweeperBoard::Debug_Display() const
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            std::cout << "[";
            if (board[i][j].hasMine)
            {
                std::cout << "M";

            }

            else
            {
                std::cout << ".";
            }
            if (board[i][j].isRevealed)
            {
                std::cout << "o";
            }
            else
            {
                std::cout << ".";
            }
            if (board[i][j].hasFlag)
            {
                std::cout << "f";
            }
            else
            {
                std::cout << ".";
            }
            std::cout << "]";
        }
        std::cout << std::endl;
    }
}


MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode)
{
    this->height = height;
    std::cout << height;
    this->width = width;
    this->mode = mode;
    firstMove = true;
    state = RUNNING;
    //firstAction=true;


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            board[i][j].hasFlag = 0;
            board[i][j].hasMine = 0;
            board[i][j].isRevealed = 0;

        }
    }
    int NumberOfMines = 0;
    switch (mode)
    {
    case EASY:
    {   NumberOfMines = width * height * 0.1;
    MineRandomizer(NumberOfMines);
    break;
    }
    case NORMAL:
    {
        NumberOfMines = width * height * 0.2;
        MineRandomizer(NumberOfMines);
        break;
    }
    case HARD:
    {   NumberOfMines = width * height * 0.3;
    MineRandomizer(NumberOfMines);
    break;
    }
    case DEBUG:
        
        Create_Debug_Board();
        break;
    }

}
int MinesweeperBoard::getBoardWidth() const {
    return width;
}

int MinesweeperBoard::getBoardHeight() const {
    return height;
}
int MinesweeperBoard::getMineCount() const {
    int mine_counter = 0;
    switch (mode) {
    case DEBUG: {
        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                if (board[row][col].hasMine)
                    mine_counter++;
            }
        }
    }
              break;
    case EASY: {
        mine_counter =(int) width * height * 0.1;
    }
             break;
    case NORMAL: {
        mine_counter =(int) width * height * 0.2;
    }
               break;
    case HARD: {
        mine_counter =(int) width * height * 0.3;
    }
             break;
    }
    
    return mine_counter;
}

bool MinesweeperBoard::isOutside(int row, int col) const
{
    if (row<0 or row>height or col<0 or col>width)
        return false;
    return true;
}
int MinesweeperBoard::countMines(int row, int col) const
{
    int count = 0;
    if (row > this->width || col > this->height)
        return -1;
    //if (!isRevealed(row,col))
        //return -1;
    for (row = -1; row <= 1; row++)
    {
        for (col = -1; col <= 1; col++)
        {
            if(isOutside(row,col))
            if (board[row][col].hasMine)
                count++;
        }
    }

    return count;
}
bool MinesweeperBoard::hasMine(int field_row, int field_col) const {
    if (board[field_row][field_col].hasMine)
        return true;
    return false;
}
bool MinesweeperBoard::hasFlag(int row, int col) const
{
    if (board[row][col].hasFlag)
        return true;
    return false;
}
void MinesweeperBoard::toggleFlag(int row, int col)
{
    if (isRevealed(row, col))
        return;
    if (getGameState() != RUNNING)
        return;  
    if (hasFlag(row, col))
        board[row][col].hasFlag = false;
    else
        board[row][col].hasFlag = true;
}
bool MinesweeperBoard::isRevealed(int row, int col) const
{
    if (board[row][col].isRevealed)
        return true;
    return false;
}
void MinesweeperBoard::revealField(int row, int col) 
{
    if (getGameState() != RUNNING)
        return;

    if (!isOutside(row, col))
        return;

    if (isRevealed(row, col))
        return;

    if (hasFlag(row, col))
        return;
    if (!isRevealed(row, col))
        if (!hasMine(row, col))
        {
            board[row][col].isRevealed = true;
            return;
        }
    if (hasMine(row, col))
    {
        if (firstMove)
        {
            if (mode != DEBUG)
            {
                MineRandomizer(1);
                board[row][col].hasMine = false;
                board[row][col].isRevealed = true;
            }
        }
    }
    else {
        board[row][col].isRevealed = true;
        state = FINISHED_LOSS;
    }
    firstMove = false;
 }
    


void MinesweeperBoard::MineRandomizer(int number_of_mines)
{


    while (true) {
        {
            int random_row = rand() % this->width;
            int random_col = rand() % this->height;
            if (board[random_row][random_col].hasMine == false)
            {
                board[random_row][random_col].hasMine = true;
                number_of_mines--;
            }
            if (number_of_mines == 0)
                break;
        }


    }
}
void MinesweeperBoard::Create_Debug_Board()
{
    height = 10;
    width = 10;
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            if (row == col or row == 0 or (col == 0 and row % 2 == 0))
                board[row][col].hasMine = true;
        }
    }
}
char MinesweeperBoard::getFieldInfo(int row, int col) const
{
    if (!isOutside(row, col))
    {
        return '#';
    }

    if (!isRevealed(row, col) and hasFlag(row, col))
    {
        return 'F';
    }


    if (!isRevealed(row, col) and !hasFlag(row, col))
    {
        return '_';
    }

    if (isRevealed(row, col) and hasMine(row, col))
    {
        return 'x';
    }

    if (isRevealed(row, col) and countMines(row, col) == 0)
    {
        return ' ';
    }

    if (isRevealed(row, col) and countMines(row, col) > 0)
    {
        return countMines(row, col);
    }
}
GameState MinesweeperBoard::getGameState() const
{
    if (state == FINISHED_LOSS)
    {
        return FINISHED_LOSS;
    }
    int fields = 0;
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            if (!board[row][col].hasMine and !board[row][col].isRevealed)
                fields++;
        }

    }
    if (fields == 0)
    {
        return FINISHED_WIN;
    }
    return RUNNING;
}