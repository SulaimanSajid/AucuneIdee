//
// Created by Sulaiman on 10/03/2022.
//

#ifndef CYCLE_HPP_INCLUDED
#define CYCLE_HPP_INCLUDED


class Cycle {
private:
    int time_delay;
    char tabCycle[1000];
    int pauseCycle[1000];
    int size;
    int timer_click = 0;
    int lance = 0;

public :
    void click_left();
    void click_right();
    void cycler(char tabCycle[]);
    void cycler2(char move);
    void fill_TabCycle();
    void automatic_fill();
};

#endif
