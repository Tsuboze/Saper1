#include "MSSFMLView.h"
#include "Minesweeper_Board.h"
#include <cerrno>

MSSFMLView::MSSFMLView(MinesweeperBoard& b) :board(b)
{
	height = board.getBoardHeight();
	width = board.getBoardWidth();
	window_height = 40 * height;
	window_width = 40 * width;

	if (!font.loadFromFile("textures/arial.ttf"))
	{
		abort();
	}

	win.setString("YOU WIN!");
	win.setFont(font);
	win.setFillColor(sf::Color::Green);
	win.setCharacterSize(40);
	win.setPosition(window_width / 2 - 80, window_height / 2 - 40);

	lose.setString("YOU LOST!");
	lose.setFont(font);
	lose.setFillColor(sf::Color::Red);
	lose.setCharacterSize(40);
	lose.setPosition(window_width / 2 - 80, window_height / 2 - 40);

	if (!t_square.loadFromFile("textures/square.png"))
	{
		abort();
	}
	s_square.setTexture(t_square);

	if (!t_mine.loadFromFile("textures/mine.png"))
	{
		abort();
	}
	s_mine.setTexture(t_mine);

	if (!t_flag.loadFromFile("textures/flag.png"))
	{
		abort();
	}
	s_flag.setTexture(t_flag);

	if (!t_explode.loadFromFile("textures/explode.png"))
	{
		abort();
	}
	s_explode.setTexture(t_explode);

	if (!t_1.loadFromFile("textures/1.png"))
	{
		abort();
	}
	s_1.setTexture(t_1);

	if (!t_2.loadFromFile("textures/2.png"))
	{
		abort();
	}
	s_2.setTexture(t_2);

	if (!t_3.loadFromFile("textures/3.png"))
	{
		abort();
	}
	s_3.setTexture(t_3);

	if (!t_4.loadFromFile("textures/4.png"))
	{
		abort();
	}
	s_4.setTexture(t_4);
	if (!t_5.loadFromFile("textures/5.png"))
	{
		abort();
	}
	s_5.setTexture(t_5);
	if (!t_6.loadFromFile("textures/6.png"))
	{
		abort();
	}
	s_6.setTexture(t_6);

	if (!t_7.loadFromFile("textures/7.png"))
	{
		abort();
	}
	s_7.setTexture(t_7);

	if (!t_8.loadFromFile("textures/8.png"))
	{
		abort();
	}
	s_8.setTexture(t_8);

	if (!t_blank.loadFromFile("textures/blank.png"))
	{
		abort();
	}
	s_blank.setTexture(t_blank);
}

void MSSFMLView::Set_Sprites() {
	for (int col = 0; col < width; col++) {
		for (int row = 0; row < height; row++) {
			switch (board.getFieldInfo(row, col)) {
			case 'F':
				s_flag.setPosition((int)40 * row, 40 * col);
				s_flag.setScale(1, 1);
				Sprites.push_back(s_flag);
				break;

			case 'x':
				s_mine.setPosition((int)40 * row, 40 * col);
				s_mine.setScale(1, 1);
				Sprites.push_back(s_mine);
				break;

			case '_':
				s_square.setPosition((int)40 * row, 40 * col);
				s_square.setScale(1, 1);
				Sprites.push_back(s_square);
				break;

			case ' ':
				s_blank.setPosition((int)40 * row, 40 * col);
				s_blank.setScale(1, 1);
				Sprites.push_back(s_blank);
				break;

			case '1':
				s_1.setPosition((int)40 * row, 40 * col);
				s_1.setScale(1, 1);
				Sprites.push_back(s_1);
				break;

			case '2':
				s_2.setPosition((int)40 * row, 40 * col);
				s_2.setScale(1, 1);
				Sprites.push_back(s_2);
				break;

			case '3':
				s_3.setPosition((int)40 * row, 40 * col);
				s_3.setScale(1, 1);
				Sprites.push_back(s_3);
				break;

			case '4':
				s_4.setPosition((int)40 * row, 40 * col);
				s_4.setScale(1, 1);
				Sprites.push_back(s_4);
				break;

			case '5':
				s_5.setPosition((int)40 * row, 40 * col);
				s_5.setScale(1, 1);
				Sprites.push_back(s_5);
				break;

			case '6':
				s_6.setPosition((int)40 * row, 40 * col);
				s_6.setScale(1, 1);
				Sprites.push_back(s_6);
				break;

			case '7':
				s_7.setPosition((int)40 * row, 40 * col);
				s_7.setScale(1, 1);
				Sprites.push_back(s_7);
				break;

			case '8':
				s_8.setPosition((int)40 * row, 40 * col);
				s_8.setScale(1, 1);
				Sprites.push_back(s_8);
				break;

			default:
				break;
			}
		}
	}
}

void MSSFMLView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (size_t i = 0; i < Sprites.size(); i++) {
		target.draw(Sprites[i], states);
	}
	if (board.getGameState() == FINISHED_WIN) {
		target.draw(win, states);
	}
	if (board.getGameState() == FINISHED_LOSS) {
		target.draw(lose, states);
	}
}
