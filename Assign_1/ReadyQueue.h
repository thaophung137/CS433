// Remember to add comments to your code
// ...

using namespace std;

#pragma once

#include <vector>
#include "PCB.h"

/**
 * ReadyQueue is a queue of PCB's that are in the READY state to be scheduled to run.
 * It should be a priority queue here uch that the process with the highest priority
 * can be selected next.
 */
class ReadyQueue {
public:
    ReadyQueue(); //default constructor
	

	void addPCB(PCB); // add a PCB representing a process into the ready queue.
	PCB removehighestPCB();  // remove and return the PCB with the highest priority from the queue           
	int size(); // Returns the number of elements in the queue.              
	void display();	// Prints the queue contents to standard output. Display the content of the heap
	void deleteMax();
  	bool isEmpty();
	bool checkDup(PCB);

private:
    vector<PCB> data; 
    void bubbleDown(int);
    void bubbleUp(int);

};
