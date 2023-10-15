#include "Word.h"
#include <fstream>

Word::Word()
{
    LEN = 5;
    colors = new short[LEN];
    for (int i = 0; i < LEN; i++)
        colors[i] = 3; //white
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