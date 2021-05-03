#include <iostream>
#include "Minesweeper_Board.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include <SFML/Graphics.hpp>
#include "MSSFMLView.h"
#include "MouseController.h"
// Stworzone przez Piotr Puk(259627) i Patryk Trajdos(259645)

int main()
{
	srand(time(0));
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Saper", sf::Style::Default, settings);
	window.setVerticalSyncEnabled(1);

	MinesweeperBoard Board(10, 10, EASY);
	MSSFMLView View(Board);

	MouseController ctrl(Board, View);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			ctrl.handleEvent(event, window);
		}
		View.Set_Sprites();
		window.clear();
		window.draw(View);
		window.display();
	}

	return 0;
}