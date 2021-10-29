#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sys/time.h>

#include "FCFS.h"

using namespace std;

FCFS::FCFS() 
{
   doOnce = 0;
  
}

// add a new task to the list of tasks
void FCFS::add(char *name, int priority, int burst) 
{
  Task aTask;
  aTask.setName(name);
  aTask.setPriority(priority);
  aTask.setBurst(burst);
  
  data.push_back(aTask);

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
    if(doOnce == 0)
    {
      calcTurnTime();
      calcWaitTime();
      displayStats(task1);
      doOnce++;
    }
    
    data.erase(data.begin());
    
  }
  
}

void FCFS::calcWaitTime()
{
  int waitingTime = 0;
  waitTime.push_back(0);
  for(int i = 0; i < data.size();i++)
  {
    waitingTime = data[i].getBurst() + data[i-1].getBurst();
    waitTime.push_back(waitingTime);
  }
  calcAvgWait();
}

double FCFS::calcAvgWait()
{
  double avgWaitTime = 0.0;

  for(int i = 0; i < data.size();i++)
  {
    avgWaitTime += waitTime[i];
  }
  return avgWaitTime/initialSize;
}

int FCFS::calcTurnTime()
{
  int turnAroundTime = 0;
  
  for(int i = 0; i < data.size(); i++)
  {
   
    if(i == 0)
    {
      turnTime.push_back(data[i].getBurst());
    }
    else
    {
      turnAroundTime = turnTime[i-1] + data[i].getBurst();
      turnTime.push_back(turnAroundTime);
      
    }
  }
  
  calcAvgTurn();
  return turnAroundTime;
}

double FCFS::calcAvgTurn()
{
  double avgTurnTime = 0.0;

  for(int i = 0; i < data.size();i++)
  {
    avgTurnTime += turnTime[i];
    
  }
  return avgTurnTime/initialSize;
}

void FCFS::displayStats(Task task)
{
    cout << task.getName() << " turn-around time = ";
   
    cout << turnTime[pos] << ", waiting time = " << waitTime[pos] << endl;
    
    double att = calcAvgTurn();
    double awt = calcAvgWait();
    cout << "Average turn-around time = " << att << ", Average waiting time = " << awt << endl;

    pos++;

}
