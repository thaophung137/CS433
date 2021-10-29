#include <stdlib.h>
#include <stdio.h>

#include "Task.h"
#include "CPU.h"
#include <vector>

using namespace std;

class Priority{
  public:
    Priority();
    void add(char*, int, int);
    void schedule();
    void displayStats(Task);
    
  private:
    vector<Task> data;
    vector<Task> orderedData;
    int doOnce;
    vector<int>turnTime;
    vector<int>waitTime;
    int pos = 0;
    int initialSize;
    int highestPriority;
    Task nextTask();
    int calcTurnTime();
    void calcWaitTime();
    double calcAvgWait();
    double calcAvgTurn();
    
    
};