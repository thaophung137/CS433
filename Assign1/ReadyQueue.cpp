#include <iostream>
#include "ReadyQueue.h"

using namespace std;

// TODO: Add your implementation of ReadyQueue functions here

ReadyQueue::ReadyQueue()
{
  //pArray = new PCB[50];
  count = 0; //initialize to no PCB for now
}

ReadyQueue::~ReadyQueue()
{

}


PCB ReadyQueue::getElement(int id) {
  return pArray[id];
}

void ReadyQueue::add(PCB* pcbPtr)
{
  //FINISH function
  if(count < MAX) {
    pArray[count] = *pcbPtr;
    count++;
    //trickleup(); // moves the job to the right place
  }
}

//ADD PCB REMOVEHIGHEST FUNCTION HERE

int ReadyQueue::size() 
{
  return count;
}

void ReadyQueue:: display() 
{
  //FINISH function
  cout << "Display Processes in ReadyQueue:" << endl;

  for(int i = 0; i <= count; i++) {
    //cout << Q[i] << " ";
    cout << pArray[i].id << pArray[i].priority; //<< ProcStates::pArray[i].state;
  }
  cout << endl;
  
}
