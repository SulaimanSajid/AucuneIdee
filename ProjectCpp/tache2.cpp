//
// Created by Sulaiman on 10/03/2022.
//
#include <windows.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include "tache.h"
#include <string>
using namespace std;

int time_delay;
int size;
char TabCycle[1000];
int PauseCycle[1000];
int timer_click = 0;
int time_between_clicks = 0;
int lance = 0;
int lance_between_clicks = 0;

void automatic_fill()
{
    if((GetKeyState(VK_LBUTTON) & 0x8000) != 0 && lance==0)
    {
        if (timer_click==0)
        {
            TabCycle[size-1] = 'L';
            size++;
            lance_between_clicks=1;

        }

        lance = 1;

    }

    if((GetKeyState(VK_RBUTTON) & 0x8000) != 0 && lance==0)
    {
        if (timer_click==0)
        {
            TabCycle[size-1] = 'R';
            size++;
            lance_between_clicks=1;
        }

        lance=1;

    }

    if (lance==1)
    {
        timer_click++;

        if (timer_click>=70000)
        {
            timer_click = 0;
            lance=0;
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

        sleep_for(nanoseconds(sec * PauseCycle[i]));

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