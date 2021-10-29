#include <stdlib.h>
#include <stdio.h>

#include "Task.h"
#include "CPU.h"
#include <vector>

using namespace std;

class FCFS{
  public:
    FCFS();
    void add(char*, int, int);
    void schedule();
    void displayStats(Task);
    
  private:
    vector<Task> data;
    int doOnce;
    vector<int>turnTime;
    vector<int>waitTime;
    int pos = 0;
    int calcTurnTime();
    void calcWaitTime();
    double calcAvgWait();
    double calcAvgTurn();
    Task nextTask();
    
    
    
};