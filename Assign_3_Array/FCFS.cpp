#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sys/time.h>

#include "FCFS.h"

using namespace std;

FCFS::FCFS() {
  
  
}

// add a new task to the list of tasks
void FCFS::add(char *name, int priority, int burst) 
{
  Task aTask;
  aTask.setName(name);
  aTask.setPriority(priority);
  aTask.setBurst(burst);
  initialSize = data.size();
  
  data.push_back(aTask);
  doOnce = 0;
	
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
    //avgTurnTime+=task1.getBurst();
    //cout << "TURN 1: " << avgTurnTime << endl;
    //turnTime.push_back(task1.getBurst());
    if(doOnce == 0)
    {
      calcTurnTime();
      calcWaitTime();
      displayStats(task1);
      doOnce++;
    }
    
    data.erase(data.begin());
    
  }
  //displayStats();
}

void FCFS::calcWaitTime()
{
  int waitingTime = 0;
  waitTime.push_back(0);
  for(int i = 0; i < data.size();i++)
  {
    //cout << "WAIT: " << data[i].getBurst() << endl;
    waitingTime = data[i].getBurst() + data[i-1].getBurst();
    waitTime.push_back(waitingTime);

    //cout << waitTime[i] << " " << endl;
    
  }
  calcAvgWait();
}

double FCFS::calcAvgWait()
{
  double avgWaitTime = 0.0;

  for(int i = 0; i < data.size();i++)
  {
    //cout << "WAIT: " << waitTime[i] << endl;
    avgWaitTime += waitTime[i];
    //cout << "HERE: " << avgWaitTime << endl;
  }
  return avgWaitTime;
}

int FCFS::calcTurnTime()
{
  int turnAroundTime = 0;
  
  for(int i = 0; i < data.size(); i++)
  {
    //cout <<"BEFORE: " << i<< "  "<< turnTime[i] << endl;
    if(i == 0)
    {
      //int thisBurst = data[i].getBurst();
      turnTime.push_back(data[i].getBurst());
      //cout << "LOOK 1: " << turnTime[0] << endl;
    }
    else{
      //cout << "HERE 1: " << turnTime[i-1] << endl;
      //cout << "HERE 2: " << data[i].getBurst() << endl;
      turnAroundTime = turnTime[i-1] + data[i].getBurst();
      //cout << "TURN: " << turnAroundTime << endl;
      turnTime.push_back(turnAroundTime);
      
    }
    //cout << "HERE: " << turnTime[i] << endl;
  }
  
  calcAvgTurn();
  return turnAroundTime;
}

double FCFS::calcAvgTurn()
{
  double avgTurnTime = 0.0;

  for(int i = 0; i < data.size();i++)
  {
    //cout << "WAIT: " << turnTime[i] << endl;
    avgTurnTime += turnTime[i];
    
  }
  //cout << "HERE: " << avgTurnTime << endl;
  return avgTurnTime;
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
