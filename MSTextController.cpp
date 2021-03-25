#include "MSTextController.h"
#include<iostream>

MSTextController::MSTextController(MinesweeperBoard& board, MSBoardTextView& view) :board(board),view(view){
}


void MSTextController::play() {
	int row, col;
	char option;
	std::cout << "Type row/col/option";
	std::cout << "[o]-reveal field";
	std::cout << "[f]-toggle flag";

	while (board.getGameState() == GameState::RUNNING)
	{
		board.Debug_Display();
		view.display();
	
		std::cin >> row >> col >> option;
		switch (option)
		{
		case 'o': {
			board.revealField(row, col);
		}
		case 'f': {
			board.toggleFlag(row, col);
		}
		}
	}
	view.display();
	if (board.getGameState() == GameState::FINISHED_WIN)
		std::cout << "YOU WON";
	else
		std::cout << "YOU LOSE";
}
