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
  
  data.push_back(aTask);
  orderedData.push_back(aTask);

  initialSize = data.size();
	
}

//PURPOSE: get the next Task needed
Task schedulers::nextTask()
{
  if(data.empty())
  {
    cout << "Error: No tasks." << endl;
  }
  Task upNext = data[0];
  return upNext;
}

//PURPOSE: run the FCFS scheduler
void schedulers::schedule() 
{
  while(!data.empty())
  {
    CPU cpu1;
    Task task1 = nextTask();
    cpu1.run(task1, task1.getBurst());
    data.erase(data.begin());
    
  }
  calcTurnTime();
  calcWaitTime();
  displayStats();
  
}

//PURPOSE:calculate the wait time 
void schedulers::calcWaitTime()
{
  int waitingTime = 0;
  waitTime.push_back(0);
  for(int i = 1; i < orderedData.size();i++)
  {
    waitingTime = waitTime[i-1] + orderedData[i-1].getBurst();
    waitTime.push_back(waitingTime);
  }
  calcAvgWait();
}

//PURPOSE: calculate the average wait time
double schedulers::calcAvgWait()
{
  double avgWaitTime = 0.0;

  for(int i = 0; i < orderedData.size();i++)
  {
    avgWaitTime += waitTime[i];
  }
  return avgWaitTime/initialSize;
}

//PURPOSE: calculate turn time
int schedulers::calcTurnTime()
{
  int turnAroundTime = 0;
  
  for(int i = 0; i < orderedData.size(); i++)
  {
   
    if(i == 0)
    {
      turnTime.push_back(orderedData[i].getBurst());
    }
    else
    {
      turnAroundTime = turnTime[i-1] + orderedData[i].getBurst();
      turnTime.push_back(turnAroundTime);
      
    }
  }
  
  calcAvgTurn();
  return turnAroundTime;
}

//PURPOSE: calculate average turn time
double schedulers::calcAvgTurn()
{
  double avgTurnTime = 0.0;

  for(int i = 0; i < orderedData.size();i++)
  {
    avgTurnTime += turnTime[i];
    
  }
  return avgTurnTime/initialSize;
}

//PURPOSE: display info nicely
void schedulers::displayStats()
{
  for(int i = 0; i < orderedData.size(); i++)
  {
    cout << orderedData[i].getName() << " turn-around time = ";
   
    cout << turnTime[i] << ", waiting time = " << waitTime[i] << endl;
  }
    double att = calcAvgTurn();
    double awt = calcAvgWait();
    cout << "Average turn-around time = " << att << ", Average waiting time = " << awt << endl;

}