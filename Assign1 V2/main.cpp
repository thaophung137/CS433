#include <iostream>
#include <cstdlib>
#include <string>
#include <sys/time.h>
#include "ReadyQueue.h"
#include "PCB.h"

using namespace std;

PCB createProcess(int value);

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


        /*
        PCB *pcb1 = new PCB(15,15,ProcState::NEW);
        PCB *pcb2 = new PCB(6,6,ProcState::NEW);
        PCB *pcb3 = new PCB(23,23,ProcState::NEW);
        PCB *pcb4 = new PCB(39,39,ProcState::NEW);
        PCB *pcb5 = new PCB(8,8,ProcState::NEW);

        Q.addPCB(*pcb1);
        Q.addPCB(*pcb2);
        Q.addPCB(*pcb3);
        Q.addPCB(*pcb4);
        Q.addPCB(*pcb5);
    */
        cout << "Remove the process with the highest priority from q1 and diplay q1." << endl;
        Q.removehighestPCB();
        Q.display();

        // TODO: Add your code for Test 2
        cout << "Performing Test 2" << endl;
}
