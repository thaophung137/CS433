#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sys/time.h>

#include "schedulers.h"

using namespace std;


// PURPOSE: add a new task to the list of tasks
void schedulers::add(char *name, int priority, int burst) 
{
  Task aTask;
  aTask.setName(name);
  aTask.setPriority(priority);
  aTask.setBurst(burst);
  aTask.setRemainBurst(burst);
  
  data.push_back(aTask);
  orderedData.push_back(aTask);
  initialSize = data.size();
	
}

//PURPOSE: get the next task
Task schedulers::nextTask()
{
  if(orderedData.empty())
  {
    cout << "Error: No tasks." << endl;
  }
  Task upNext = orderedData[0];
  return upNext;
}

//PURPOSE: run the RoundRobin scheduler
void schedulers::schedule() 
{
  int RunTime = 0;
  int wait_time;
  while(!orderedData.empty())
  {
    CPU cpu1;
    Task task1 = nextTask();
    if(task1.getRemainBurst() <= QUANTUM)
    {
      RunTime += task1.getRemainBurst();

      cpu1.run(task1, task1.getRemainBurst());
      task1.setRemainBurst(0);

      cout << "TurnAround time for " << task1.getName() << " is: " << RunTime << endl;

      turnTime.push_back(RunTime);

      wait_time = RunTime - (orderedData[0].getBurst());
      cout << "Wait time is: " << wait_time << endl;
      waitTime.push_back(wait_time);

      orderedData.erase(orderedData.begin());
    }
    else {
      RunTime += QUANTUM;
      cpu1.run(task1, QUANTUM);
      task1.setRemainBurst(task1.getRemainBurst()-QUANTUM);
      orderedData.push_back(task1);
      orderedData.erase(orderedData.begin());
    }
  } 
  //calcTurnTime();
  //calcWaitTime();

  displayStats();
}

void runTurnTime(){
    
}

//PURPOSE: calculate the average turn time
double schedulers::calcAvgTurn(){
  double totalTurnTime = 0;

  for(int i = 0; i< turnTime.size(); i++){
    totalTurnTime += turnTime[i];
  }

  return totalTurnTime/initialSize;
}

//PURPOSE: calculate the average wait time
double schedulers::calcAvgWait()
{
  double totalWaitTime = 0;

  for(int i = 0; i < waitTime.size();i++)
  {
    totalWaitTime += waitTime[i];
  }
  return totalWaitTime/initialSize;
}

//PURPOSE: nicely display the statistics of the scheduling algorithm
void schedulers::displayStats(){
    double att = calcAvgTurn();
    double awt = calcAvgWait();
    cout << "Average turn-around time = " << att << ", Average waiting time = " << awt << endl;
}
