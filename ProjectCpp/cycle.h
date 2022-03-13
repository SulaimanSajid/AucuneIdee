//
// Created by Sulaiman on 10/03/2022.
//

#ifndef PROJECTCPP_CYCLE_H
#define PROJECTCPP_CYCLE_H


class Cycle {
private:
    int time_delay;
    char tabCycle{};
public :
    void click_left();
    void click_right();
    void cycle(char TabCycle[]);
    int time_delay;
    void cycle2(char Move);
    char TabCycle[1000];
    int PauseCycle[1000];
    char fill_TabCycle();
    int size;
    int timer_click = 0;

    void automatic_fill();
    int lance = 0;
};


#endif //PROJECTCPP_CYCLE_H
