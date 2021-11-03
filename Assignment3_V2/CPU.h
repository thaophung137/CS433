// length of a time quantum
#define QUANTUM 10

#pragma once
#include "Task.h"

class CPU{
  public:
    CPU();
    void run(Task task, int);
    
};