#pragma once
#include "Key.h"
class Keyboard:public Graphics
{
private:
	Key keyboard[3][10];
public:
	Keyboard();
	Key getKey(int row, int col)const;
	void keyboardPrint(int index)const;
};

