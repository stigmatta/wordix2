#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <iomanip>
#include <cstring>
#include "Keyboard.h"
#include "Wordix.h"
using namespace std;
const int Wordix::needed_tries = 6;
int main()
{
	srand(time(0));
	Wordix wordix;
	wordix.start();
}