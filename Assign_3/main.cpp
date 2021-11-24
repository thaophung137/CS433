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
#include <fstream>
#include <sstream>
#include <string>

#include "Task.h"
#include "schedulers.h"
#include "CPU.h"

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
  cout<< "This program will accept three parameters: sleep time, number of producer threads, number of consumer threads. It will keep track and print out the content of the shared buffer during the execution of threads when an item is added or consumed." << endl;
  
  int TQ; //Time Quantum
  CPU cpu1;
  //Check that input file is provided at command line
  if(argc < 2)
  {
    cerr << "Usage: " << argv[0] << " <input_file> [<time_quantum>]" << endl;
    exit(1);
  }

  if(argc >= 3)
  {
    TQ = atoi(argv[2]);
  }

  string name;
  int priority;
  int burst;

  schedulers s;

  // open the input file
  ifstream infile(argv[1]);
  string line;
  while(getline(infile, line) ) {
    istringstream ss (line);
    // Get the task name
    getline(ss, name, ',');
        
    // Get the task priority 
    string token;
    getline(ss, token, ',');
    priority = stoi(token);

    // Get the task burst length 
    getline(ss, token, ',');
    burst = stoi(token);
        
    char* c = strcpy(new char[name.length() + 1], name.c_str());
    cout << c << " " << priority << " " << burst << endl;

    if(argc==2)
    {
      s.add(c, priority, burst);
    }

    else if(argc >= 3)
    {
      s.add(c, priority, burst,TQ);
    }
  }

  //invoke the scheduler
  s.schedule();

  return 0;
  
}
