#include "GameBoard.h"
#include "Graphics.h"
#include "Wordix.h"
#include <iomanip>
GameBoard::GameBoard()
{
    for (int i = 0; i < 6; i++)
        board[i].setUserWord("_____");
}
void GameBoard::gameBoardPrint(int index)
{
    for (int j = 0; j < board[index].getLen(); j++) {
        if (board[index].getColor(j) == Green) {
            green();
        }
        else if (board[index].getColor(j) == Blue) {
            blue();
        }
        else if (board[index].getColor(j) == Red) {
            red();
        }
        cout << setw(2) << board[index].getUserWord()[j];
        reset();
    }
    if (index >=3)
        cout << endl;
}
Word GameBoard::getWord(int index)
{
    return board[index];
}
Word GameBoard::operator[](int index)
{
    return board[index];
}