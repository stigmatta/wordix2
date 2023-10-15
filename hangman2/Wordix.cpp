#include "Wordix.h"
void Wordix::wordCheck(Word& user_word, GeneratedWord& gen_word)
{

    for (int i = 0; i < user_word.getLen(); i++)
    {
        if (user_word.getUserWord()[i] == gen_word.getGenWord()[i])
        {
            for (int m = 0; m < 3; m++) // [3][10] - size of the keyboard
            {
                for (int k = 0; k < 10; k++)
                {
                    if ((user_word.getUserWord()[i] == game_keyboard.getKey(m, k).getLetter()) && (game_keyboard.getKey(m, k).getColor() == Blue || game_keyboard.getKey(m, k).getColor() == White))
                        game_keyboard.getKey(m, k).setColor(Green);
                }
            }
            for (int j = 0; j < 5; j++)
            {
                if (gen_word.getGenWord()[i] == uniqueSym[j].getCode() && uniqueSym[j].getAmount() > 0)
                {
                    uniqueSym[j].setAmount(uniqueSym[j].getAmount() - 1);
                    game_board.getWord(your_tries).setColor(i, Green);
                }
            }
        }
    }
    for (int i = 0; i < user_word.getLen(); i++)
    {
        if((gen_word.doesWordHasTheSymb(user_word.getUserWord()[i])&&game_board.getWord(your_tries).getColor(i)!=Green))
        {
            for (int m = 0; m < 3; m++)
            {
                for (int k = 0; k < 10; k++)
                {
                    if ((user_word.getUserWord()[i] == game_keyboard.getKey(m,k).getLetter()) && (game_keyboard.getKey(m,k).getColor() == White))
                        game_keyboard.getKey(m,k).setColor(Blue);
                }
            }
            for (int j = 0; j < 5; j++)
            {
                if(user_word.getUserWord()[i]==uniqueSym[j].getCode()&&(uniqueSym[j].getAmount()))
                {
                    uniqueSym[j].setAmount(uniqueSym[j].getAmount() - 1);
                    game_board.getWord(your_tries).setColor(i, Blue);
                    break;
                }
                else
                {
                    if (!(game_board.getWord(your_tries).getColor(i) < 2)) {
                        for (int m = 0; m < 3; m++)
                        {
                            for (int k = 0; k < 10; k++)
                            {
                                if ((user_word.getUserWord()[i] == game_keyboard.getKey(m, k).getLetter()) && (game_keyboard.getKey(m, k).getColor() == White))
                                    game_keyboard.getKey(m, k).setColor(Red);
                            }
                        }
                        game_board.getWord(your_tries).setColor(i, Red);
                    }
                }
            }
        }
        else
        {
            if(!(game_board.getWord(your_tries).getColor(i)<2))
            {
                game_board.getWord(your_tries).setColor(i, Red);
                for (int m = 0; m < 3; m++)
                {
                    for (int k = 0; k < 10; k++)
                    {
                        if ((user_word.getUserWord()[i] == game_keyboard.getKey(m, k).getLetter()) && game_keyboard.getKey(m, k).getColor() == White)
                            game_keyboard.getKey(m, k).setColor(Red);
                    }
                }
            }

        }

    }
}
UniqueSymbols* Wordix:: uniqueSymbols(GeneratedWord word)
{
    int tmp = 0;
    string str = word.getGenWord();
    set <char> uniSet;
    for (int i = 0; i < 5; i++)
        uniSet.insert(str[i]);
    UniqueSymbols* array = new UniqueSymbols[uniSet.size()];
    for (set <char>::iterator iter = uniSet.begin(); iter != uniSet.end(); iter++, tmp++)
        array[tmp].setCode(*iter);
    for (short i = 0; i < uniSet.size(); i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (array[i].getCode() == word.getGenWord()[j])
                array[i].setAmount(array[i].getAmount() + 1);
        }
    }
    return array;
}
UniqueSymbols* Wordix::getUnique()
{
    return uniqueSym;
}
GeneratedWord Wordix::getGenWord()
{
    return gen_word;
}

void Wordix::start()
{
    timer.startTimer();
    your_tries = 0;
    uniqueSym = new UniqueSymbols[5];
    cout << "Type a word:" << endl;
    string str;
    int counter = 0;
    while(your_tries < Wordix::needed_tries)
    {
        uniqueSym = uniqueSymbols(gen_word);
        counter = 0;
        do {
            if (counter > 0)
            {
                system("cls");
                for (int i = 0; i < 6; i++)
                {
                    game_board.gameBoardPrint(i);
                    if (i < 3)
                        game_keyboard.keyboardPrint(i);
                }
                cout << "Incorrect word. Try again" << endl;
            }
            cin >> str;
            user_word.setUserWord(str);
            cout << endl;
            counter++;
        } while (!(user_word.isWordRight()) || (!(user_word.isInFile())));
        wordCheck(user_word, gen_word);
        game_board[your_tries] = user_word;
        system("cls");
        for (int i = 0; i < 6; i++)
        {
            game_board.gameBoardPrint(i);
            if (i < 3)
                game_keyboard.keyboardPrint(i);
        }
        if(user_word.getUserWord()==gen_word.getGenWord())
        {
            cout << "You won" << endl;
            break;
        }
        your_tries++;
    }
    if (your_tries == Wordix::needed_tries)
        cout << "You lost. Correct word was " << gen_word.getGenWord() << endl;
    timer.endTimer();
    timer.calculateElapsedTime();
    timer.printElapsedTime();
}
