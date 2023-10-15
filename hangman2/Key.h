#pragma once
#include "Graphics.h"
class Key:public Graphics
{
private:
    char letter;
    int color = White; //by default key is white
public:
    void setColor(int color);
    void setLetter(char letter); 
    int getColor()const;
    char getLetter()const;
    Key();
    Key(char letter, int color = White) : letter(letter), color(color) {};
};
