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

#include "Task.h"
#include "schedulers.h"
#include "FCFS.h"

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

    FILE *infile;
    char *temp;
    char task[SIZE];

    char *name;
    int priority;
    int burst;

    FCFS fcfs;
    
    /*infile = fopen(argv[1],"r");
    
    while (fgets(task,SIZE,infile) != NULL) {
        temp = strdup(task);
        name = strsep(&temp,",");
        priority = atoi(strsep(&temp,","));
        burst = atoi(strsep(&temp,","));

        // add the task to the scheduler's list of tasks
        fcfs.add(name,priority,burst);

        free(temp);
    }

    fclose(infile);*/
    name = (char*)"T1";
    fcfs.add(name, 4, 20);
    name = (char*)"T2";
    fcfs.add(name, 5, 21);
    name = (char*)"T3";
    fcfs.add(name, 6, 22);
    
    //fcfs.displayAll();
    


    // invoke the scheduler
    fcfs.schedule();
    //fcfs.displayStats();

    return 0;
}
