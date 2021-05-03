#include "MSTextController.h"
#include<iostream>

MSTextController::MSTextController(MinesweeperBoard& board, MSBoardTextView& view) :board(board), view(view) {
}

void MSTextController::play() {
	int row, col;
	char option;
	std::cout << "Type row/col/option" << '\n';
	std::cout << "[o]-reveal field" << '\n';
	std::cout << "[f]-toggle flag" << '\n';

	while (board.getGameState() == GameState::RUNNING)
	{
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