#pragma once
#include <SFML/Graphics.hpp>

namespace sf {
	class Event;
}

class MinesweeperBoard;
class MSSFMLView;

class MouseController
{
	MinesweeperBoard& Board;
	MSSFMLView& view;
public:
	MouseController(MinesweeperBoard& Board, MSSFMLView& view);
	void handleEvent(sf::Event& event, sf::RenderWindow& window);
};
