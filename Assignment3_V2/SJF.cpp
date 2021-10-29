#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sys/time.h>

#include "SJF.h"

using namespace std;

SJF::SJF() 
{
  doOnce = 0;
	shortestIndex = 0;
  
}

// add a new task to the list of tasks
void SJF::add(char *name, int priority, int burst) 
{
  Task aTask;
  aTask.setName(name);
  aTask.setPriority(priority);
  aTask.setBurst(burst);
  
  data.push_back(aTask);

  initialSize = data.size();
}


Task SJF::nextTask()
{
  Task shortestTask;
  if(data.empty())
  {
    cout << "Error: No tasks." << endl;
  }
  else
  {
    shortestTask = data[0];
    for(int i = 0; i < data.size(); i++)
    {
      if(data[i].getBurst() < shortestTask.getBurst())
      {
        shortestTask = data[i];
        shortestIndex = i;
        orderedData.push_back(shortestTask);
      }
    }
  }
  return shortestTask;
}

/**
 *  * Run the FCFS scheduler
 *   */
void SJF::schedule() 
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
    
    data.erase(data.begin() + shortestIndex);
    
  }
}

void SJF::calcWaitTime()
{
  int waitingTime = 0;
  waitTime.push_back(0);
  for(int i = 0; i < orderedData.size();i++)
  {
    waitingTime = orderedData[i].getBurst() + orderedData[i-1].getBurst();
    waitTime.push_back(waitingTime);
    
  }
  calcAvgWait();
}

double SJF::calcAvgWait()
{
  double avgWaitTime = 0.0;

  for(int i = 0; i < orderedData.size();i++)
  {
    avgWaitTime += waitTime[i];
  }
  return avgWaitTime/initialSize;
}

int SJF::calcTurnTime()
{
  int turnAroundTime = 0;
  
  for(int i = 0; i < orderedData.size(); i++)
  {
    if(i == 0)
    {
      turnTime.push_back(orderedData[i].getBurst());
    }
    else{
      turnAroundTime = turnTime[i-1] + orderedData[i].getBurst();
      turnTime.push_back(turnAroundTime);
      
    }
  }
  
  calcAvgTurn();
  return turnAroundTime;
}

double SJF::calcAvgTurn()
{
  double avgTurnTime = 0.0;

  for(int i = 0; i < orderedData.size();i++)
  {
    avgTurnTime += turnTime[i];
    
  }
  return avgTurnTime/initialSize;
}

void SJF::displayStats(Task task)
{
    cout << task.getName() << " turn-around time = ";
   
    cout << turnTime[pos] << ", waiting time = " << waitTime[pos] << endl;
    
    double att = calcAvgTurn();
    double awt = calcAvgWait();
    cout << "Average turn-around time = " << att << ", Average waiting time = " << awt << endl;

    pos++;

}
