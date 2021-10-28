#include <iostream>
#include <vector>
#include "process.h"

Process::Process(){
    pid = 0;
    arrival = 0;
    burst = 0;
    priority = 0;

    waiting_time = 0;
    turnaround_time = 0;
    response_time = 0;
    exit_time = 0; 
}

int Process::getPID(){
    return pid;
}

int Process::getArrivalTime(){
    return arrival;
}

int Process::getBurstTime(){
    return burst;
}

int Process::getPriority(){
    return priority;
}
