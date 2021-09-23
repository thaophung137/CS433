#include <iostream>
#include <cmath>
#include <iomanip>
#include "ReadyQueue.h"
#include "PCB.h"

using namespace std;
//PURPOSE: constructor for ReadyQueue
ReadyQueue::ReadyQueue(){

}

//PURPOSE: destructor for ReadyQueue
ReadyQueue::~ReadyQueue(){
    
}

//PURPOSE: get the size of the vector
int ReadyQueue::size(){
    return data.size();
}

//PURPOSE: check if vector is empty
bool ReadyQueue::isEmpty(){
    return data.empty();
}

//PURPOSE: Recursive function to bubbles down the tree to the correct position. 
void ReadyQueue::bubbleDown(int idx){
    int size = data.size();
    //get left and right child at the index. 
    int left = 2*idx + 1;              //left child
    int right = 2*idx + 2;              //right child

    int largest = idx;
    //if existing left is greater than index, set largest as the left child.
    if(left < size && data[left].getPriority() > data[idx].getPriority()){
        largest = left;
    }

    //if existing right is greater than the largest index, set largest as the right child.
    if(right < size && data[right].getPriority() > data[largest].getPriority()){
        largest = right;
    }
    //swap with a child of greater value and bubble down.
    if(largest != idx){
        PCB temp = data[idx];
        data[idx] = data[largest];
        data[largest] = temp;
        bubbleDown(largest);
    }
}

//PURPOSE: Recursive function to bubble up the tree to the correct position
void ReadyQueue::bubbleUp(int idx){
    //if idx is 0, we are at root so no need to bubble up. 
    if(idx == 0){
        return;
    }
    int parent = floor((idx - 1)/2);      //get the parent of index.

    //if the index and value of parent is less than the value of index, swap and bubble up. 
    if(idx && data[parent].getPriority() < data[idx].getPriority()){
        PCB temp = data[idx];               //temporary variable to hold index
        data[idx] = data[parent];           //set new index to be parent 
        data[parent] = temp;                //then get parent from temp
        bubbleUp(parent);                   //bubble up 
    }
}


//PURPOSE:Insert a new value into the heap
void ReadyQueue::addPCB(PCB value){
  value.setState(READY);
  data.emplace_back(value);
  bubbleUp(data.size()-1);
}

//PURPOSE:returns highest priority PCB
PCB ReadyQueue::removehighestPCB(){
    PCB temp = data[0];
    deleteMax();
    temp.setState(RUNNING);
    return temp;
}

//PURPOSE: get the highest priority
PCB ReadyQueue::getMax()
{
  return data[0];
}

//PURPOSE: delete the highest PCB and restructure the heap
void ReadyQueue::deleteMax()
{
    if(data.empty()){
        return;
    }
    data[0] = data.back();
    data.pop_back();
    bubbleDown(0);
}

//PURPOSE: check for duplicate priorities. If duplicate, remove process
bool ReadyQueue::checkDup(PCB pcb) {
  for(int i = 1; i < data.size(); i++)
  {
    if(pcb.getPriority() == data[i].getPriority())
    {
      int eraseAt = i-1;
      data.erase(data.begin()+eraseAt);
      return true;
    } 
  }
  return false;
}

//PURPOSE: display and format the attributes of the processes in the queue nicely
void ReadyQueue::display(){
    ProcState currentState;
    cout << "Queue: \n";
    cout << "ID" << "\t\t" << "Priority" "\t\t" << "State" << endl;
    cout << "---------------------------------------" << endl;
    for(int i = 0; i < data.size(); i++){
        currentState = data[i].getState();
        cout << data[i].getID() << "\t\t" << data[i].getPriority() << "\t\t\t\t" << data[i].formatState(currentState) << endl;
    }
}
