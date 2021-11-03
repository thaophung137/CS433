#include "Task.h"

//PURPOSE: default constructor
Task::Task()
{

}

//Task constructor
Task::Task(int x)
{

}

//PURPOSE: Task constructor with name, priority, and burst attributes
Task::Task(char *name, int priority, int burst)
{
  priority = 0;
  burst = 0;

}

//PURPOSE: get the name of the task
char* Task::getName() 
{
  return name;
}

//PURPOSE: get the priority of the task
int Task::getPriority() 
{
  return priority;
}

//PURPOSE: get the burst of the task
int Task::getBurst() 
{
  return burst;
}

//PURPOSE: get the remaining burst of the task
int Task::getRemainBurst() 
{
  return remainBurst;
}

//PURPOSE: set the name of the task
void Task::setName(char* nameTask)
{
  name = nameTask;
}

//PURPOSE: set the priority of the task
void Task::setPriority(int priorityTask)
{
  priority = priorityTask;
}

//PURPOSE: set the burst of the task
void Task::setBurst(int burstTask)
{
  burst = burstTask;
}

//PURPOSE: set the remaining burst of the task
void Task::setRemainBurst(int remainBurstTask)
{
  remainBurst = remainBurstTask;
}
