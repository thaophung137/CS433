#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sys/time.h>

#include "RoundRobin.h"

using namespace std;

RoundRobin::RoundRobin() {
  highestPriority = 0;
  
}

// add a new task to the list of tasks
void RoundRobin::add(char *name, int priority, int burst) 
{
  Task aTask;
  aTask.setName(name);
  aTask.setPriority(priority);
  aTask.setBurst(burst);
  aTask.setRemainBurst(burst);
  
  data.push_back(aTask);
  copyData.push_back(aTask);
  initialSize = data.size();
	
}

Task RoundRobin::nextTask()
{
  if(copyData.empty())
  {
    cout << "Error: No tasks." << endl;
  }
  Task upNext = copyData[0];
  return upNext;
}

/**
 *  * Run the FCFS scheduler
 *   */
void RoundRobin::schedule() 
{
  int RunTime = 0;
  int wait_time;
  while(!copyData.empty())
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

      wait_time = RunTime - (copyData[0].getBurst());
      cout << "Wait time is: " << wait_time << endl;
      waitTime.push_back(wait_time);

      copyData.erase(copyData.begin());
    }
    else {
      RunTime += QUANTUM;
      cpu1.run(task1, QUANTUM);
      task1.setRemainBurst(task1.getRemainBurst()-QUANTUM);
      copyData.push_back(task1);
      copyData.erase(copyData.begin());
    }
  } 
  //calcTurnTime();
  //calcWaitTime();

  displayStats();
}

void runTurnTime(){
    
}

double RoundRobin::calcAvgTurn(){
  double totalTurnTime = 0;

  for(int i = 0; i< turnTime.size(); i++){
    totalTurnTime += turnTime[i];
  }

  return totalTurnTime/initialSize;
}

double RoundRobin::calcAvgWait()
{
  double totalWaitTime = 0;

  for(int i = 0; i < waitTime.size();i++)
  {
    totalWaitTime += waitTime[i];
  }
  return totalWaitTime/initialSize;
}

void RoundRobin::displayStats(){
    double att = calcAvgTurn();
    double awt = calcAvgWait();
    cout << "Average turn-around time = " << att << ", Average waiting time = " << awt << endl;
}

/*
void RoundRobin::displayStats()
{
    for(int i = 0; i< copyData.size();i++)
    {
      cout << copyData[i].getName() << " turn-around time = ";
      //cout << turnTime[i] << ", waiting time = " << waitTime[i] << endl;
    }
    
    double att = calcAvgTurn();
    double awt = calcAvgWait();
    cout << "Average turn-around time = " << att << ", Average waiting time = " << awt << endl;

}

double RoundRobin::calcAvgTurn()
{
  double avgTurnTime = 0.0;

  for(int i = 0; i < copyData.size();i++)
  {
    avgTurnTime += turnTime[i];
    
  }
  return avgTurnTime;
}

double RoundRobin::calcAvgWait()
{
  double avgWaitTime = 0.0;

  for(int i = 0; i < copyData.size();i++)
  {
    avgWaitTime += waitTime[i];
  }
  return avgWaitTime;
}

/*
void RoundRobin::calcWaitTime()
{
  int waitingTime = 0;
  waitTime.push_back(0);
  for(int i = 0; i < copyData.size();i++)
  {
    waitingTime = copyData[i].getBurst() + copyData[i-1].getBurst();
    waitTime.push_back(waitingTime);
  }
  calcAvgWait();
}

double RoundRobin::calcAvgWait()
{
  double avgWaitTime = 0.0;

  for(int i = 0; i < copyData.size();i++)
  {
    avgWaitTime += waitTime[i];
  }
  return avgWaitTime/initialSize;
}


int RoundRobin::calcTurnTime()
{
  int turnAroundTime = 0;

  for(int i = 0; i < copyData.size(); i++)
  {
    if(i == 0)
    {
      turnAroundTime = copyData[i].getBurst();
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

double RoundRobin::calcAvgTurn()
{
  double avgTurnTime = 0.0;

  for(int i = 0; i < copyData.size();i++)
  {
    avgTurnTime += turnTime[i];
    
  }
  return avgTurnTime/initialSize;
}
*/