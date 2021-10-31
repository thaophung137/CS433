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
    void displayStats();
    
  private:
    vector<Task> data;
    vector<Task> copyData;
    vector<int>turnTime;
    vector<int>waitTime;
    int initialSize;
    int calcTurnTime();
    void calcWaitTime();
    double calcAvgWait();
    double calcAvgTurn();
    Task nextTask();

};
