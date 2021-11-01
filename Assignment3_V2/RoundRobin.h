#include <stdlib.h>
#include <stdio.h>

#include "Task.h"
#include "CPU.h"
#include <vector>

using namespace std;


class RoundRobin{
  public:
    RoundRobin();
    void add(char*, int, int);
    void schedule();
    void displayStats();
    
  private:
    vector<Task> data;
    vector<Task> copyData;
    vector<int>turnTime;
    vector<int>waitTime;
    int remainBurst;
    int initialSize;
    int highestPriority;
    Task nextTask();
    //int calcTurnTime();
    //void calcWaitTime();
    double calcAvgWait();
    double calcAvgTurn();
    
    
};
