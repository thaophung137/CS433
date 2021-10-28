/**
 * "Virtual" CPU that also maintains track of system time.
 */

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "task.h"
#include "cpu.h"

using namespace std;

// run this task for the specified time slice
void run(Task *task, int slice) {
    printf("Running task = [%s] [%d] [%d] for %d units.\n",task->name, task->priority, task->burst, slice);

    //cout << "Running task = " << task->name << setw(5) << task->priority << setw(5) << task->burst << "for " << slice << " units" << endl;
}
