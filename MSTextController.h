#pragma once
#include "Minesweeper_Board.h"
#include "MSBoardTextView.h"
class MSTextController
{
	MSBoardTextView& view;
	MinesweeperBoard& board;
public:
	MSTextController(MinesweeperBoard& board, MSBoardTextView& view);
		void play();
};


