#pragma once
#include <stdio.h>
class Graphics
{
protected:
    enum {
        Green = 0,
        Blue = 1,
        Red = 2,
        White = 3
    };
    void reset()const
    {
        printf("\033[0m");
    }
    void green()const
    {
        printf("\033[1;32m");
    }
    void blue()const
    {
        printf("\033[1;34m");
    }
    void red()const
    {
        printf("\033[1;31m");
    }
};

