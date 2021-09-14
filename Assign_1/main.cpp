/********************************************************************************************
CS 433 Programming assignment 1
Author: Thao Phung and Sophia Nguyen
Course: CS 433 (Operating Systems)
*******************************************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include <sys/time.h>
#include "ReadyQueue.h"
#include "PCB.h"

using namespace std;

PCB createProcess(int value);

//This function creates a new Process with the value and set the state as NEW. 
PCB createProcess(int value){
    PCB *pcb = new PCB(value, value, ProcState::NEW);
    return *pcb;
}

int main(){
    //Print basic information about the program
        cout << "CS 433 Programming assignment 1" << endl;
        cout << "Author: Thao Phung and Sophia Nguyen" << endl;
        cout << "Date: 09/22/2021" << endl;
        cout << "Course: CS 433 (Operating Systems)" << endl;
        cout << "Description : Program to implement a priority ready queue of processes" << endl;
        cout << "=================================" << endl;

        // TODO: Add your code for Test 1
        cout << "Performing Test 1" << endl;
        cout << "----------------------------------" << endl;
        cout << "15, 6, 23, 39, and 8 to q1. Display the content of q1." << endl;

        ReadyQueue Q;
        Q.addPCB(createProcess(15));
        Q.addPCB(createProcess(6));
        Q.addPCB(createProcess(23));
        Q.addPCB(createProcess(39));
        Q.addPCB(createProcess(8));
        Q.display();

        cout << "Remove the process with the highest priority from q1 and diplay q1." << endl;
        Q.removehighestPCB();
        Q.display();


        cout << "47, 1, 37, and 5 to q1. Display the content of q1." << endl;
        Q.addPCB(createProcess(47));
        Q.addPCB(createProcess(1));
        Q.addPCB(createProcess(37));
        Q.addPCB(createProcess(5));
        Q.display();


        cout << "Remove the process with the highest priority from q1 and diplay q1." << endl;
        Q.removehighestPCB();
        Q.display();

        cout << "43, 17, 32, 12, and 19 to q1. Display the content of q1." << endl;
        Q.addPCB(createProcess(43));
        Q.addPCB(createProcess(17));
        Q.addPCB(createProcess(32));
        Q.addPCB(createProcess(12));
        Q.addPCB(createProcess(19));
        Q.display();

        cout << "One by one remove the process with the highest priority from the queue q1 and display the queue after each removal." << endl;
        while(!Q.isEmpty())
        {
          Q.removehighestPCB();
          Q.display();
        }

        // TODO: Add your code for Test 2
        cout << "Performing Test 2" << endl;
}
