#include "Key.h"
Key::Key()
{
	color = Red;
	letter = ' ';
}
void Key::setColor(int color)
{
	this->color = color;
}
void Key::setLetter(char letter)
{
	this->letter = letter;
}
int Key::getColor()const
{
	return color;
}
char Key::getLetter()const
{
	return letter;
}