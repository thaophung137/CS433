#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sys/time.h>

#include "FCFS.h"
#include "schedulers.h"

using namespace std;

FCFS::FCFS() 
{
  
}

// add a new task to the list of tasks
void FCFS::add(char *name, int priority, int burst) 
{
  Task aTask;
  aTask.setName(name);
  aTask.setPriority(priority);
  aTask.setBurst(burst);
  
  data.push_back(aTask);
  copyData.push_back(aTask);

  initialSize = data.size();
	
}


Task FCFS::nextTask()
{
  if(data.empty())
  {
    cout << "Error: No tasks." << endl;
  }
  Task upNext = data[0];
  return upNext;
}

/**
 *  * Run the FCFS scheduler
 *   */
void FCFS::schedule() 
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

void FCFS::calcWaitTime()
{
  int waitingTime = 0;
  waitTime.push_back(0);
  for(int i = 1; i < copyData.size();i++)
  {
    waitingTime = waitTime[i-1] + copyData[i-1].getBurst();
    waitTime.push_back(waitingTime);
  }
  calcAvgWait();
}

double FCFS::calcAvgWait()
{
  double avgWaitTime = 0.0;

  for(int i = 0; i < copyData.size();i++)
  {
    avgWaitTime += waitTime[i];
  }
  return avgWaitTime/initialSize;
}

int FCFS::calcTurnTime()
{
  int turnAroundTime = 0;
  
  for(int i = 0; i < copyData.size(); i++)
  {
   
    if(i == 0)
    {
      turnTime.push_back(copyData[i].getBurst());
    }
    else
    {
      turnAroundTime = turnTime[i-1] + copyData[i].getBurst();
      turnTime.push_back(turnAroundTime);
      
    }
  }
  
  calcAvgTurn();
  return turnAroundTime;
}

double FCFS::calcAvgTurn()
{
  double avgTurnTime = 0.0;

  for(int i = 0; i < copyData.size();i++)
  {
    avgTurnTime += turnTime[i];
    
  }
  return avgTurnTime/initialSize;
}

void FCFS::displayStats()
{
  for(int i = 0; i < copyData.size(); i++)
  {
    cout << copyData[i].getName() << " turn-around time = ";
   
    cout << turnTime[i] << ", waiting time = " << waitTime[i] << endl;
  }
    double att = calcAvgTurn();
    double awt = calcAvgWait();
    cout << "Average turn-around time = " << att << ", Average waiting time = " << awt << endl;

}
