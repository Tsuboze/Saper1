#include "MouseController.h"
#include "MSSFMLView.h"
#include "Minesweeper_Board.h"
MouseController::MouseController(MinesweeperBoard& board, MSSFMLView& view) : Board(board), view(view)
{
}

void MouseController::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		int row;
		row = event.mouseButton.x / 40;
		int col;
		col = event.mouseButton.y / 40;
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				Board.revealField(row, col);
			}
			if (event.mouseButton.button == sf::Mouse::Right)
			{
				Board.toggleFlag(row, col);
			}
		}
	}
}