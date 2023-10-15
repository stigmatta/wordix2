#include "GeneratedWord.h"
#include "Word.h"
GeneratedWord::GeneratedWord()
{
    random = 1 + rand() % 5757;
    ifstream file("C:\\five.txt");
    try
    {
        if (file.is_open()) {
            string s;
            for (int i = 0; i < random; i++)
                file >> gen_word;
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
}
string GeneratedWord::getGenWord()
{
    return gen_word;
}
bool GeneratedWord::doesWordHasTheSymb(char symb)
{
    for (size_t i = 0; i < gen_word.size(); i++)
    {
        if (gen_word[i]==symb)
            return true;
    }
    return false;
}
