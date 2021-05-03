#ifndef MINESBOARD_H__
#define MINESBOARD_H__
#include <string>
#include <iostream>

enum GameMode { DEBUG, EASY, NORMAL, HARD };
enum  GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

struct Field
{
	bool hasMine;
	bool hasFlag;
	bool isRevealed;
};
class MinesweeperBoard
{
	Field board[100][100];    // 100-elementowa tablica, 100-elementowych tablic typu Field
	int width;                // rzeczywista szeroko�� planszy
	int height;	// rzeczywista wysoko�� planszy
	bool firstMove;

	GameMode mode;
	GameState state;
	bool hasMine(int row, int col) const;
	bool isOutside(int row, int col) const;
	void Create_Debug_Board();
	void MineRandomizer(int number_of_mines);
	void revealEmptyField(int field_row, int field_col);
public:
	MinesweeperBoard(int width, int height, GameMode mode);
	void Debug_Display() const;

	int getBoardWidth() const;

	int getBoardHeight() const;

	int getMineCount() const;

	void revealField(int row, int col);

	int countMines(int row, int col) const;

	bool hasFlag(int row, int col) const;

	void toggleFlag(int row, int col);

	bool isRevealed(int row, int col) const;

	char getFieldInfo(int row, int col) const;

	GameState getGameState() const;
};

#endif