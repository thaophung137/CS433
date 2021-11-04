/**
 * Representation of a task in the system.
 */

#pragma once


class Task {
  private:
    char *name;
    int priority;
    int burst;
    int remainBurst;
    int TQ;

  public:
    Task();
    Task(int);
    Task(char*,int,int);
    char* getName();
    int getPriority();
    int getBurst();
    int getRemainBurst();
    int getTQ();
    void setName(char*);
    void setPriority(int);
    void setBurst(int);
    void setRemainBurst(int);
    void setTQ(int);
};
