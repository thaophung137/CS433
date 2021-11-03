/**
 * Driver.c
 *
 * Schedule is in the format
 *
 *  [name] [priority] [CPU burst]
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Task.h"
#include "schedulers.h"
#include "FCFS.h"
#include "SJF.h"
#include "Priority.h"
#include "RoundRobin.h"

using namespace std; 

#define SIZE 100

int main(int argc, char *argv[])
{
    cout << "CS 433 Programming assignment 3" << endl;
    cout << "Author: Thao Phung and Sophia Nguyen" << endl;
    cout << "Date: 10/21/2021 " << endl;
    cout << "Course: CS433 (Operating Systems)" << endl;
    cout << "Description : **** " << endl;
    cout << "=================================" << endl;

    //char *name;
    string name;
    int priority;
    int burst;

    FCFS fcfs;
    SJF sjf;
    Priority p;
    RoundRobin rr;

    // open the input file
    ifstream infile(argv[1]);
    string line;
    while(getline(infile, line) ) {
        istringstream ss (line);
        // Get the task name
        getline(ss, name, ',');
        
        // Get the task priority 
        string token;
        getline(ss, token, ',');
        priority = stoi(token);

        // Get the task burst length 
        getline(ss, token, ',');
        burst = stoi(token);
        
        char* c = strcpy(new char[name.length() + 1], name.c_str());
        cout << c << " " << priority << " " << burst << endl;
        fcfs.add(c, priority, burst);
        // TODO: add the task to the scheduler's ready queue
        // You will need a data structure, i.e. PCB, to represent a task 
    }

    fcfs.schedule();
    //name = (char*)"T1";
    //fcfs.add(name, 4, 20);
    //sjf.add(name, 4, 22);
    //p.add(name, 4, 22);
    //rr.add(name, 4,22);
    //name = (char*)"T2";
    //fcfs.add(name, 5, 21);
    //sjf.add(name, 5, 20);
    //p.add(name, 5, 20);
    //rr.add(name, 5, 20);
    //name = (char*)"T3";
    //fcfs.add(name, 6, 22);
    //sjf.add(name, 6, 21);
    //p.add(name, 6, 21);
    //rr.add(name, 6, 21);
    
    
    // invoke the scheduler
    //fcfs.schedule();
    //sjf.schedule();
    //p.schedule();
    //rr.schedule();

    return 0;
}
