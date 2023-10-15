#include "Keyboard.h"
#include <iostream>
#include <iomanip>
using namespace std;
Keyboard::Keyboard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
            keyboard[i][j].setColor(White);
    }
    keyboard[0][0].setLetter('q');
    keyboard[0][1].setLetter('w');
    keyboard[0][2].setLetter('e');
    keyboard[0][3].setLetter('r');
    keyboard[0][4].setLetter('t');
    keyboard[0][5].setLetter('y');
    keyboard[0][6].setLetter('u');
    keyboard[0][7].setLetter('i');
    keyboard[0][8].setLetter('o');
    keyboard[0][9].setLetter('p');
    keyboard[1][0].setLetter('a');
    keyboard[1][1].setLetter('s');
    keyboard[1][2].setLetter('d');
    keyboard[1][3].setLetter('f');
    keyboard[1][4].setLetter('g');
    keyboard[1][5].setLetter('h');
    keyboard[1][6].setLetter('j');
    keyboard[1][7].setLetter('k');
    keyboard[1][8].setLetter('l');
    keyboard[1][9].setLetter('z');
    keyboard[2][0].setLetter('x');
    keyboard[2][1].setLetter('c');
    keyboard[2][2].setLetter('v');
    keyboard[2][3].setLetter('b');
    keyboard[2][4].setLetter('n');
    keyboard[2][5].setLetter('m');
    keyboard[2][6].setLetter(' ');
    keyboard[2][7].setLetter(' ');
    keyboard[2][8].setLetter(' ');
    keyboard[2][9].setLetter(' ');
}
void Keyboard::keyboardPrint(int index)const
{
    cout << "\t";
    for (int j = 0; j < 10; j++) {
        if (keyboard[index][j].getColor() == Green)
            green();
        else if (keyboard[index][j].getColor() == Blue)
            blue();
        else if (keyboard[index][j].getColor() == Red)
            red();
        cout << setw(2) << keyboard[index][j].getLetter();
        reset();
    }
     cout << endl;
}
Key& Keyboard::getKey(int row,int col)
{
    return keyboard[row][col];
}
