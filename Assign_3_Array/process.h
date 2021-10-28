#ifndef PROCESS_H
#define PROCESS_H

class Process{
private:
    int pid;
    int arrival;
    int burst;
    int priority;
public:    
    Process();

    int getPID();
    int getArrivalTime();
    int getBurstTime();
    int getPriority();
    void progress();

    float waiting_time;
    float turnaround_time;
    float response_time; 
    float exit_time;
};

#endif