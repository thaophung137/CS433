#include <iostream>
#include "PCB.h"

using namespace std;

//PURPOSE: Default constructor for PCB that initializes values
PCB::PCB(){
    id = 0;
    priority = 0;
    state = ProcState::NEW;
}

//PURPOSE: Constructor that sets the values of PCB objects
PCB::PCB(int pcbID, int PCBPriority, ProcState pcbState){
    id = pcbID;
    priority = PCBPriority;
    state = pcbState;
}

//PURPOSE: Deconstructor for PCB
PCB::~PCB(){};

//PURPOSE: get the ID number of PCB
int PCB::getID(){
  return id;
}

//PURPOSE: get the priority number of PCB
int PCB::getPriority(){
  return priority;
}

//PURPOSE: get the state of PCB
ProcState PCB::getState(){
  return state;
}

//PURPOSE: set the ID number of PCB
void PCB::setID(int pcdID) {
  id = pcdID;
}

//PURPOSE: set the priority number of PCB
void PCB::setPriority(int pcdPriority) {
  priority = pcdPriority;
}

//PURPOSE: set the state of PCB
void PCB::setState(ProcState pcdState) {
  state = pcdState;
}

//PURPOSE: format the state of PCB as a string
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
 
