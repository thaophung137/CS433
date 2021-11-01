#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

class schedulers{
  public:
    schedulers();
    void add(char*, int, int); // add a task to the list 
    void schedule(); // invoke the scheduler
    
};

/*#ifndef SCHEDULERS_H
#define SCHEDULERS_H

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

// add a task to the list
void add(char *name, int priority, int burst);

// invoke the scheduler
void schedule();

#endif*/