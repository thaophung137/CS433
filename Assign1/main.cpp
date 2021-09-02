// Remember to add comments to your code

#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include "ReadyQueue.h"

using namespace std;

int main(int argc, char* argv[]) {

  ReadyQueue queue;
  PCB pcb;
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

        //ADD PCB TO QUEUE USING ADD FUNCTION?

        queue.display();

        cout << "Remove the process with the highest priority from q1 and diplay q1." << endl;
        queue.removeHighest();
        queue.display();

        cout << "Add processes 47, 1, 37, and 5 into q1 and display q1." << endl;
        // ADD PCB TO QUEUE AND DISPLAY BY CALLING ADD FUNCTION
        
        queue.display();





        // TODO: Add your code for Test 2
        cout << "Performing Test 2" << endl;
}
