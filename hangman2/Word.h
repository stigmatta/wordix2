#pragma once
#include <iostream>
#include "Graphics.h"
using namespace std;
class Word:public Graphics
{
private:
	string userWord;
	int LEN;
	short* colors;//all white by default
public:
	Word();
	bool isWordRight();
	bool isInFile();
	string getUserWord();
	void setUserWord(string word);
	int getLen();
	int getColor(int index);
	void setColor(int index,int color);
	Word& operator=(const Word a);
	void gameBoardPrint();
};
