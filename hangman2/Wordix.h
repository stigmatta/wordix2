#pragma once
#include "GeneratedWord.h"
#include "Word.h"
#include "Keyboard.h"
#include "UniqueSymbols.h"
#include "Timer.h"
class Wordix :public Graphics
{
	short your_tries=0;
	Keyboard game_keyboard;
	UniqueSymbols* uniqueSym;
	Word game_board[6];
	Timer timer;
	GeneratedWord gen_word;
	Word user_word;

public:
	static const int needed_tries;
	void wordCheck(Word& user_word, GeneratedWord& gen_word);
	void start();
	UniqueSymbols*& uniqueSymbols(GeneratedWord word);
	UniqueSymbols*& getUnique();
	GeneratedWord& getGenWord();
};