#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sys/time.h>

#include "Priority.h"

using namespace std;

Priority::Priority() {
  highestPriority = 0;
  
}

// add a new task to the list of tasks
void Priority::add(char *name, int priority, int burst) 
{
  Task aTask;
  aTask.setName(name);
  aTask.setPriority(priority);
  aTask.setBurst(burst);
  
  data.push_back(aTask);
  initialSize = data.size();
	
}


Task Priority::nextTask()
{
  Task highPriority;
  highestPriority = 0;

  if(data.empty())
  {
    cout << "Error: No tasks." << endl;
  }
  else
  {
    highPriority = data[0];
    for(int i = 1; i < data.size(); i++)
    {
      if(data[i].getPriority() >= highPriority.getPriority())
      {
        if(data[i].getPriority() > highPriority.getPriority())
        {
          highPriority = data[i];
          highestPriority = i;
        }
      }
    }
  }
  orderedData.push_back(highPriority); 
  return highPriority;
}

/**
 *  * Run the FCFS scheduler
 *   */
void Priority::schedule() 
{
  
  while(!data.empty())
  {
    CPU cpu1;
    Task task1 = nextTask();
    cpu1.run(task1, task1.getBurst());
    data.erase(data.begin() + highestPriority);
    
  } 
  calcTurnTime();
  calcWaitTime();
  displayStats();
  
}

void Priority::calcWaitTime()
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

double Priority::calcAvgWait()
{
  double avgWaitTime = 0.0;

  for(int i = 0; i < orderedData.size();i++)
  {
    avgWaitTime += waitTime[i];
  }
  return avgWaitTime/initialSize;
}

int Priority::calcTurnTime()
{
  int turnAroundTime = 0;

  for(int i = 0; i < orderedData.size(); i++)
  {
    if(i == 0)
    {
      turnAroundTime = orderedData[i].getBurst();
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

double Priority::calcAvgTurn()
{
  double avgTurnTime = 0.0;

  for(int i = 0; i < orderedData.size();i++)
  {
    avgTurnTime += turnTime[i];
    
  }
  return avgTurnTime/initialSize;
}

void Priority::displayStats()
{
    for(int i = 0; i< orderedData.size();i++)
    {
      cout << orderedData[i].getName() << " turn-around time = ";
   
      cout << turnTime[i] << ", waiting time = " << waitTime[i] << endl;
    }
    
    double att = calcAvgTurn();
    double awt = calcAvgWait();
    cout << "Average turn-around time = " << att << ", Average waiting time = " << awt << endl;


}
