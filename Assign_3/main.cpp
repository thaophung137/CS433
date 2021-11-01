/**
 * Driver.c
 *
 * Schedule is in the format
 *
 *  [name] [priority] [CPU burst]
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

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

    FILE *in;
    char *temp;
    char task[SIZE];

    char *name;
    int priority;
    int burst;

    FCFS fcfs;
    SJF sjf;
    Priority p;
    RoundRobin rr;

     in = fopen(argv[1],"r");
    
    while (fgets(task,SIZE,in) != NULL) {
        temp = strdup(task);
        name = strsep(&temp,",");
        priority = atoi(strsep(&temp,","));
        burst = atoi(strsep(&temp,","));

        // add the task to the scheduler's list of tasks
        rr.add(name,priority,burst);

        free(temp);
    }

    fclose(in);

    // invoke the scheduler
    rr.schedule();

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
