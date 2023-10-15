#pragma once
#include "Word.h"
#include "Graphics.h"
class GameBoard:public Graphics
{
	Word board[6];
public:
	GameBoard();
	void gameBoardPrint(int index);
	Word getWord(int index);
	Word operator[](int index);
};
