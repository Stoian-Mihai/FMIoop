#pragma once

class gomoku
{
private:
	static const int gridV = 21;
	static const int gridH = 24;

	bool winHorizontal(int i, int j);
	bool winVertical(int i, int j);
	bool winDiagonal(int i, int j);
	bool validBounds(int i, int j);
public:
	int grid[gridH][gridV];
	gomoku();
	void makeMove(bool palyer, int i, int j);
	int checkForWin();
	void printGrid();
};