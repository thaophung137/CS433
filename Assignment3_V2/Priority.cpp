#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sys/time.h>

#include "Priority.h"

using namespace std;

Priority::Priority() {
  doOnce = 0;
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
  if(data.empty())
  {
    cout << "Error: No tasks." << endl;
  }
  else
  {
    highPriority = data[0];
    for(int i = 0; i < data.size(); i++)
    {
      if(data[i].getPriority() > highPriority.getPriority())
      {
        highPriority = data[i];
        highestPriority = i;
        orderedData.push_back(highPriority);
        
      }
    }
  }
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
    if(doOnce == 0)
    {
      calcTurnTime();
      calcWaitTime();
      displayStats(task1);
      doOnce++;
    }
    
    data.erase(data.begin() + highestPriority);
    
  }
  
}

void Priority::calcWaitTime()
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

double Priority::calcAvgWait()
{
  double avgWaitTime = 0.0;

  for(int i = 0; i < data.size();i++)
  {
    avgWaitTime += waitTime[i];
  }
  return avgWaitTime/initialSize;
}

int Priority::calcTurnTime()
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

double Priority::calcAvgTurn()
{
  double avgTurnTime = 0.0;

  for(int i = 0; i < data.size();i++)
  {
    avgTurnTime += turnTime[i];
    
  }
  return avgTurnTime/initialSize;
}

void Priority::displayStats(Task task)
{
    cout << task.getName() << " turn-around time = ";
   
    cout << turnTime[pos] << ", waiting time = " << waitTime[pos] << endl;
    
    double att = calcAvgTurn();
    double awt = calcAvgWait();
    cout << "Average turn-around time = " << att << ", Average waiting time = " << awt << endl;

    pos++;

}