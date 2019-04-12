#include <iostream>
#include "gomokuModel.h"

bool gomoku::winHorizontal(int i, int j)
{
	int ok = 1;
	for(int posH = j; posH<i+5;posH++)
	{
		
	}
	return 0;
}

bool gomoku::winVertical(int i, int j)
{
	int ok = 1;
	for(int posV = i; posV<i+5;posV++)
	{
		if (!validBounds(posV, j)) break;
		if (this->grid[i][j] != this->grid[posV][j]) ok = 0;
	}

	if (ok == 1) return 1;

	for(int posV = i; posV>i-5;posV--)
	{
		if (!validBounds(posV, j)) break;
		if (this->grid[i][j] != this->grid[posV][j]) ok = 0;

	}
	if (ok == 1) return 1;
	return 0;
}


bool gomoku::validBounds(int i, int j)
{
	if (i < 1 || i > gridV) return 0;
	if (j < 1 || j > gridH) return 0;
	return 1;
}

gomoku::gomoku()
{
	for(int i = 0; i<=gridV; i++)
	{
		for (int j = 0; j <= gridH; j++)
			this->grid[i][j] = -1;
	}
}

void gomoku::makeMove(bool palyer, int i, int j)
{
	this->grid[i][j] = palyer;
}

int gomoku::checkForWin()
{
	for (int i = 1; i <= gridV; i++)
	{
		for (int j = 1; j <= gridH; j++)
		{
			if (winVertical(i, j)) return this->grid[i][j];
			
		}
	}
	return -1;
}

void gomoku::printGrid()
{
	for (int i = 1; i <= gridV; i++)
	{
		for (int j = 1; j <= gridH; j++)
			std::cout << this->grid[i][j] << "  ";
		std::cout << "\n";
	}
}

