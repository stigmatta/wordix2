#pragma once
#include <ctime>
#include <iostream>
using namespace std;
class Timer
{
private:
    time_t start_time, end_time;
    struct tm start_tm, end_tm;
    int elapsed_minutes, elapsed_seconds;

public:
    void startTimer()
    {
        time(&start_time);
        localtime_s(&start_tm, &start_time);
    }

    void endTimer()
    {
        time(&end_time);
        localtime_s(&end_tm, &end_time);
    }

    void calculateElapsedTime()
    {
        int start_seconds = start_tm.tm_sec + start_tm.tm_min * 60;
        int end_seconds = end_tm.tm_sec + end_tm.tm_min * 60;
        int diff_seconds = end_seconds - start_seconds;
        elapsed_minutes = diff_seconds / 60;
        elapsed_seconds = diff_seconds % 60;
    }

    void printElapsedTime()
    {
        std::cout << "Вы играли " << elapsed_minutes << " минут и " << elapsed_seconds << " секунд" << std::endl;
    }
};
