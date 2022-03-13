//
// Created by Sulaiman on 10/03/2022.
//

#ifndef PROJECTCPP_TACHE_H
#define PROJECTCPP_TACHE_H
#include <vector>


class tache {
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
    int unefois=0;

    int startit = 0;
    int done=0;
    int done2 = 0;

    void automatic_fill();
    int lance = 0;
    std::vector<std::tuple<int, int> > intPairs;
    POINT p;


};


#endif //PROJECTCPP_TACHE2_H
