#include <windows.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include "cycle.cpp"


int main()
{
    using namespace std::this_thread;
    using namespace std::chrono;
    INPUT input{ 0 };
    input.type = INPUT_MOUSE;

    bool Click = false;

    int pos=0;
    int timer_click=0;




    /*using Clock = std::chrono::steady_clock;
    std::chrono::time_point<std::chrono::steady_clock> start, now;
    std::chrono::milliseconds duration;*/

    // start = Clock::now();uu

    while (true)
    {
        if (GetAsyncKeyState('Z') & 1)
        {
            //printf("sommes nous rentres");
            automatic_fill();
        }

        if (GetAsyncKeyState('U') & 1)
            Click = true;

        if (Click)
        {
            //fill_TabCycle();



            cycle();
            Click = false;





        }
    }

    return 0;
}