#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "process.h"
#include <vector>

using namespace std; 

class Schedule{
    public:
        Schedule();
        ~Schedule();

    void addTask(Process);

    private:
        vector<Process> task;

};

#endif