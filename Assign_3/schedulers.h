#include <stdlib.h>
#include <stdio.h>

#include "Task.h"
#include "CPU.h"
#include <vector>

using namespace std;

class schedulers{
  public:
    schedulers();
    void add(char*, int, int);
    void add(char*, int, int, int);
    void schedule();
    
    
  private:
    vector<Task> data;
    vector<Task> orderedData;
    vector<int>turnTime;
    vector<int>waitTime;
    void calcTurnTime(); 
    void calcWaitTime();
    double calcAvgWait();
    double calcAvgTurn();
    void displayStats();
    Task nextTask();
    int initialSize;
    int highestPriority = 0;
    int shortestIndex = 0;
    int remainBurst;

};
