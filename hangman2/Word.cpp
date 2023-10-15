#include "Word.h"
#include <fstream>
#include "Graphics.h"
#include <iomanip>
Word::Word()
{
    LEN = 5;
    colors = new short[LEN];
    for (int i = 0; i < LEN; i++)
        colors[i] = White;
}
bool Word::isWordRight()
{
    if (userWord.size() != LEN)
        return false;
    for (int i = 0; i < LEN; i++) {
        if (!(userWord[i] >= 'A' && userWord[i] <= 'Z' || userWord[i] >= 'a' && userWord[i] <= 'z'))
            return false;
    }
    return true;
}
bool Word::isInFile()
{
    ifstream file("C:\\five.txt");
    try
    {
        if (file.is_open()) {
            string s;
            for (file >> s; !file.eof(); file >> s)
            {
                if (userWord == s)
                {
                    file.close();
                    return true;
                }
            }
            file.close();
        }
        else {
            throw 1;
        }
    }
    catch (int)
    {
        cout << "Cannot open file" << endl;
    }
    return false;
}
string Word::getUserWord()
{
    return userWord;
}

int Word::getLen()
{
    return LEN;
}
int Word::getColor(int index)
{
    return colors[index];
}
void Word::setColor(int index,int color)
{
    colors[index] = color;
}
void Word::setUserWord(string word)
{
    userWord = word;
}
Word& Word:: operator=(const Word a)
{
    userWord = a.userWord;
    LEN = a.LEN;
    delete[] colors;
    colors = new short[5];
    for (size_t i = 0; i < 5; i++)
        colors[i] = a.colors[i];
    return *this; 
}
void Word:: gameBoardPrint()
{
    for (int j = 0; j < LEN; j++) {
        if (colors[j] == Green) {
            green();
        }
        else if (colors[j] == Blue) {
            blue();
        }
        else if (colors[j] == Red) {
            red();
        }
        cout << setw(2) << userWord[j];
        reset();
    }
}