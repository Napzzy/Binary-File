#ifndef TIMER_H
#define TIMER_H
#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;
class Timer{
private:
    clock_t _start;
    clock_t _stop;
public:
    Timer():_start(clock()), _stop(clock()){}
    void start(){
        _start = clock();
    }
    void stop(){
        _stop = clock();
    }
    double duration(){
        //cout<<"["<<float(_stop)<<" - "<<float(_start)<<"] / "<<CLOCKS_PER_SEC<<endl;
        return double(_stop - _start)/CLOCKS_PER_SEC;
        //return ((float)(_stop - _start))/CLOCKS_PER_SEC*10000
    }
};

#endif // TIMER_H
