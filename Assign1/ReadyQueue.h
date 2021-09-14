// Remember to add comments to your code
// ...

#pragma once

# include "PCB.h"
# include "MaxHeap.h"

/**
 * ReadyQueue is a queue of PCB's that are in the READY state to be scheduled to run.
 * It should be a priority queue here uch that the process with the highest priority
 * can be selected next.
 */

int const MAX = 50;

class ReadyQueue {
  private: 
    //PCB *pArray;
    PCB *pArray;
    int count; //how many PCB present
    
  public:
        ReadyQueue();
        ~ReadyQueue();
        // TODO: Implement the required functions. Add necessary member fields and functions
        // You may use different parameter signatures from the example below

        // add a PCB representing a process into the ready queue.
        void add(PCB* pcbPtr);

        // remove and return the PCB with the highest priority from the queue
        PCB* removeHighest();

        // Returns the number of elements in the queue.
        int size();

        // Prints the queue contents to standard output.
        void display();

        PCB getElement(int id);
};
