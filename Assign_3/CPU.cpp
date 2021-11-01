/**
 * "Virtual" CPU that also maintains track of system time.
 */

#include <stdio.h>

#include "Task.h"
#include "CPU.h"

CPU::CPU()
{
  
}
// run this task for the specified time slice
void CPU::run(Task task, int slice) {
    printf("Running task = [%s] [%d] [%d] for %d units.\n",task.getName(), task.getPriority(), task.getBurst(), slice);
}
