#include "UniqueSymbols.h"
#include "GeneratedWord.h"
#include <iostream>
#include <set>
using namespace std;
UniqueSymbols::UniqueSymbols()
{
    amount = code = 0;
}

short UniqueSymbols::getCode()
{
    return code;
}
short UniqueSymbols::getAmount()
{
    return amount;
}
void UniqueSymbols::setCode(short code)
{
    this->code = code;
}
void UniqueSymbols::setAmount(short amount)
{
    this->amount = amount;
}

