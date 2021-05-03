#include <SFML/Graphics.hpp>

class MinesweeperBoard;

class MSSFMLView : public sf::Drawable
{
private:
	MinesweeperBoard& board;
	int height;
	int width;
	int window_height;
	int window_width;

	sf::Font font;
	sf::Text lose;
	sf::Text win;
	sf::Texture t_1, t_2, t_3, t_4, t_5, t_6, t_7, t_8, t_blank, t_square, t_mine, t_flag, t_explode;
	sf::Sprite s_1, s_2, s_3, s_4, s_5, s_6, s_7, s_8, s_flag, s_mine, s_blank, s_square, s_explode;

	std::vector<sf::Sprite> Sprites;
public:

	explicit MSSFMLView(MinesweeperBoard& b);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void Set_Sprites();
};
