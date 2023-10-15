#pragma once
#include <iostream>
using namespace std;
class Word
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
};
