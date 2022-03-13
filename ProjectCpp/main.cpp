#include <windows.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include "cycle.cpp"

using namespace std::this_thread;
using namespace std::chrono;

int main()
{
    INPUT input{ 0 };
    input.type = INPUT_MOUSE;

    bool click = false;

    int pos=0;
    int timer_click=0;
    Cycle cycle;

    /*using Clock = std::chrono::steady_clock;
    std::chrono::time_point<std::chrono::steady_clock> start, now;
    std::chrono::milliseconds duration;*/

    // start = Clock::now();uu

    while (true)
    {
        if (GetAsyncKeyState('Z') & 1)
        {
            //printf("sommes nous rentres");
            cycle.automatic_fill();
        }

        if (GetAsyncKeyState('U') & 1) {
            click = true;
        }

        if (click)
        {
            //fill_TabCycle();

            cycle.cycler();
            click = false;
        }
    }

    return 0;
}