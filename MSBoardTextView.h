#pragma once
#include "Minesweeper_Board.h"



class MSBoardTextView
{
	MinesweeperBoard &board;
public:
	 MSBoardTextView(MinesweeperBoard & board);
	void display();
};

