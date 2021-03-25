#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "Minesweeper_Board.h"
#include "MSBoardTextView.h"
// Stworzone przez Piotr Puk(259627) i Patryk Trajdos(259645)







int main()
{
    srand(time(0));
    MinesweeperBoard board(20, 10, GameMode::EASY);
    MSBoardTextView view(board);
    view.display();
    board.revealField(0, 5);
    view.display();

    return 0;
    
}