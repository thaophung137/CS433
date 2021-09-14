#include "PCB.h"

// TODO: Add your implementation here
PCB::PCB(){
    id = 0;
    priority = 0;
    state = ProcState::NEW;
}

PCB::~PCB(){};

PCB::PCB(int pcbID, int PCBPriority, ProcState pcbState){
    id = pcbID;
    priority = PCBPriority;
    state = pcbState;
}

int PCB::getID(){
  return id;
}

int PCB::getPriority(){
  return priority;
}

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