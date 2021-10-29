#include "Task.h"

//using namespace std;

Task::Task()
{

}

Task::Task(int x)
{

}

Task::Task(char *name, int priority, int burst)
{
  priority = 0;
  burst = 0;

}

char* Task::getName() 
{
  return name;
}

int Task::getPriority() 
{
  return priority;
}

int Task::getBurst() 
{
  return burst;
}

void Task::setName(char* nameTask)
{
  name = nameTask;
}

void Task::setPriority(int priorityTask)
{
  priority = priorityTask;
}

void Task::setBurst(int burstTask)
{
  burst = burstTask;
}
