/********************************************************************************************
CS 433 Programming assignment 1
Author: Thao Phung and Sophia Nguyen
Course: CS 433 (Operating Systems)
*******************************************************************************************/
#include <iostream>
#include "PCB.h"

using namespace std;

// TODO: Add your implementation here
//Constructor
PCB::PCB(){
    id = 0;
    priority = 0;
    state = ProcState::NEW;
}

//Destructor
PCB::~PCB(){};

PCB::PCB(int pcbID, int PCBPriority, ProcState pcbState){
    id = pcbID;
    priority = PCBPriority;
    state = pcbState;
}
//Return the ID of the process
int PCB::getID(){
  return id;
}
//Return of the priority of the process
int PCB::getPriority(){
  return priority;
}
//Return the state of the process
ProcState PCB::getState(){
  return state;
}

void PCB::setID(int pcdID) {
  id = pcdID;
}

void PCB::setPriority(int pcdPriority) {
  priority = pcdPriority;
}

void PCB::setState(ProcState pcdState) {
  state = pcdState;
}

string PCB::formatState(ProcState state) {
  switch (state)
  {
    case NEW:
    {
        return "New";
    }
    case READY:
    {
        return "Ready";
    }
    case RUNNING:
    {
        return "Running";
    }
    case WAITING:
    {
        return "Waiting";
    }
    case TERMINATED:
    {
        return "Terminated";
    }
  }
}
 
