/**
 * Representation of a task in the system.
 */

#pragma once

//using namespace std;

class Task {
  private:
    char *name;
    int priority;
    int burst;
    int remainBurst;

  public:
    Task();
    Task(int);
    Task(char*,int,int);
    char* getName();
    int getPriority();
    int getBurst();
    int getRemainBurst();
    void setName(char*);
    void setPriority(int);
    void setBurst(int);
    void setRemainBurst(int);
};
