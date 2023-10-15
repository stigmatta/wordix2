#pragma once
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;
class GeneratedWord
{
	int random;
    string gen_word;
public:
	GeneratedWord();
	string getGenWord();
	bool doesWordHasTheSymb(char symb);
};

