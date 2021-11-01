#include <stdlib.h>
#include <stdio.h>

#include "Task.h"
#include "CPU.h"
#include <vector>

using namespace std;

class SJF{
  public:
    SJF();
    void add(char*, int, int);
    void schedule();
    void displayStats();
    
  private:
    vector<Task> data;
    vector<Task> orderedData;
    vector<int>turnTime;
    vector<int>waitTime;
    int initialSize;
    int shortestIndex;
    Task nextTask();
    int calcTurnTime();
    void calcWaitTime();
    double calcAvgWait();
    double calcAvgTurn();
    
    
};
