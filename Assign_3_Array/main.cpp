#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std; 
#define SIZE    100

int main(int argc, char *argv[])
{
    cout << "CS 433 Programming assignment 3" << endl;
    cout << "Author: Thao Phung and Sophia" << endl;
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

    in = fopen(argv[1],"r");
    
    while (fgets(task,SIZE,in) != NULL) {
        temp = strdup(task);
        name = strsep(&temp,",");
        priority = atoi(strsep(&temp,","));
        burst = atoi(strsep(&temp,","));

        // add the task to the scheduler's list of tasks
        add(name,priority,burst);

        free(temp);
    }

    fclose(in);

    // invoke the scheduler
    schedule();

    return 0;
}