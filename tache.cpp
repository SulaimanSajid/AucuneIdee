//
// Created by Sulaiman on 10/03/2022.
//
#include <windows.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include "tache.h"
#include <unistd.h>
#include <string>
using namespace std;
#include <chrono>
int time_delay;
int size=1;
char TabCycle[1000];
double PauseCycle[1000];
int timer_click = 0;
int time_between_clicks = 0;
int time_between_clicks_2 = 0;
int lance = 0;
int startit = 1;
int done=0;
int lance_between_clicks = 0;
int PosX[1000];
int PosY[1000];
int unefois=0;
int done2 = 0;

POINT p;


void automatic_fill()
{
    int time_now = 0;
    double time_first_click;
    auto start = std::chrono::high_resolution_clock::now();
    while ( GetAsyncKeyState('A') == false ) {

        if (((GetKeyState(VK_LBUTTON) & 0x8000) != 0 || (GetKeyState(VK_RBUTTON) & 0x8000) != 0) && lance == 0)
        {
            if (timer_click==0)
            {
                if (GetCursorPos(&p))
                {
                    PosX[size-1] = p.x;
                    PosY[size-1] = p.y;
                }
            }
        }

        if (lance_between_clicks == 1) {
            if (unefois == 0) {
                unefois = 1;
            }

        }
        //printf("si ca se lance");
        if ((GetKeyState(VK_LBUTTON) & 0x8000) != 0 && lance == 0) {
            if (timer_click == 0) {
                TabCycle[size - 1] = 'L';

                if (lance_between_clicks == 1) {
                    //PauseCycle[size - 1] = time_between_clicks;
                    if (startit==1 && done==0)
                    {
                        auto finish = std::chrono::high_resolution_clock::now();
                        //auto start = std::chrono::high_resolution_clock::now();
                        std::chrono::duration<double> elapsed = finish - start;
                        printf("We start");
                        //std::cout << "Elapsed time: " << elapsed.count() << " s\n";
                        time_first_click = elapsed.count();
                        startit = 0;
                        done = 1;
                    }

                    else if (startit==0 && done==1)
                    {

                        printf("We stop");
                        auto finish = std::chrono::high_resolution_clock::now();
                        std::chrono::duration<double> elapsed = finish - start;
                        std::cout << "Elapsed time: " << elapsed.count() - time_first_click << " s\n";
                        std::cout << "First: " << time_first_click << " s\n";

                        if (done2==0)
                        {
                            PauseCycle[size-1] = elapsed.count() - time_first_click;
                            done2 = 1;
                        }

                        else if (done2==1)
                        {
                            PauseCycle[size-1] = elapsed.count() - time_first_click - PauseCycle[size-2];
                        }

                        auto start = std::chrono::high_resolution_clock::now();
                        printf("We restart");
                    }
                }

                size++;

                lance_between_clicks = 1;

            }

            lance = 1;

        }

        if ((GetKeyState(VK_RBUTTON) & 0x8000) != 0 && lance == 0) {
            if (timer_click == 0) {
                TabCycle[size - 1] = 'R';

                if (lance_between_clicks == 1) {
                    //PauseCycle[size - 1] = time_between_clicks;
                    if (startit==1 && done==0)
                    {
                        auto finish = std::chrono::high_resolution_clock::now();
                        //auto start = std::chrono::high_resolution_clock::now();
                        std::chrono::duration<double> elapsed = finish - start;
                        printf("We start");
                        //std::cout << "Elapsed time: " << elapsed.count() << " s\n";
                        time_first_click = elapsed.count();
                        startit = 0;
                        done = 1;
                    }

                    else if (startit==0 && done==1)
                    {

                        printf("We stop");
                        auto finish = std::chrono::high_resolution_clock::now();
                        std::chrono::duration<double> elapsed = finish - start;
                        std::cout << "Elapsed time: " << elapsed.count() - time_first_click << " s\n";
                        std::cout << "First: " << time_first_click << " s\n";

                        if (done2==0)
                        {
                            PauseCycle[size-1] = elapsed.count() - time_first_click;
                            done2 = 1;
                        }

                        else if (done2==1)
                        {
                            PauseCycle[size-1] = elapsed.count() - time_first_click - PauseCycle[size-2];
                        }

                        auto start = std::chrono::high_resolution_clock::now();
                        printf("We restart");
                    }
                }



                size++;
                lance_between_clicks = 1;
            }

            lance = 1;

        }

        if (lance == 1) {
            timer_click++;

            if (timer_click >= 70000) {
                timer_click = 0;
                lance = 0;
            }
        }

        if (lance_between_clicks == 1) {

            time_between_clicks++;
        }
    }
}

void fill_TabCycle()
{

    cout << "Enter size : " << endl;
    cin >> size;

    for (int j=0; j<size; j++)
    {
        printf("Enter the next one for Tab Cycle : ");
        cin >> TabCycle[j];


        /*printf("Enter the next one for Tab Cycle : ");
        cin >> PauseCycle[j];*/
    }


    for (int j=0; j<size; j++)
    {
        /*printf("Enter the next one for Tab Cycle : ");
        cin >> TabCycle[j];*/


        printf("Enter the next one for PauseCycle : ");
        cin >> PauseCycle[j];
    }




}

void click_left() {
    INPUT input{ 0 };
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(INPUT));

    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));
}


void click_right() {
    INPUT input{ 0 };
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
    SendInput(1, &input, sizeof(INPUT));

    input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
    SendInput(1, &input, sizeof(INPUT));
}


void cycle() {

    int sec = 1000000000;

    using namespace std::this_thread;
    using namespace std::chrono;

    int i;
    for (i = 0; i < size; i++)

    {

        if (TabCycle[i] == 'R')
        {
            click_right();
            printf("R");
        }

        else if (TabCycle[i] == 'L')
        {
            click_left();
            printf("L");
        }

        //sleep_for(nanoseconds(sec * PauseCycle[i]));
        sleep(PauseCycle[i]);

    }

}


void cycle2(char Move) {
    using namespace std::this_thread;
    using namespace std::chrono;


    if (Move == 'R')
    {
        click_right();
    }

    else if (Move == 'L')
    {
        click_left();

    }
}