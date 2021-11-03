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

    schedulers s;

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
        s.add(c, priority, burst);
    }

    //invoke the scheduler
    s.schedule();

    return 0;
}
