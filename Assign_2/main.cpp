/********************************************************************************************
CS 433 Programming assignment 1
Author: Thao Phung and Sophia Nguyen
Course: CS 433 (Operating Systems)
*******************************************************************************************/

#include <stdio.h> 
#include <unistd.h>
#include <iostream>
#include <cstring>

using namespace std;

#define MAX_LINE 80 /* The maximum length command */

int main(void)
{
  cout << "CS 433 Programming Assignment 2" << endl;
  cout << "Author: Thao Phung and Sophia Nguyen" << endl;
  cout << "Date: 10/10/2021" << endl;
  cout << "Course: CS 433 (Operating Systems)" << endl;
  cout << "Description : Program to serve as a shell interface that accepts user commands and executes each command in a seperate process." << endl;
  cout << "=================================" << endl;

  char *args[MAX_LINE/2 + 1]; /* command line arguments */
  int should_run = 1; /* flag to determine when to exit program */
  while (should_run) 
  { 
    char userInput[100];
    
    cout << "osh>"; 
    //fflush(stdout);

    //get user input
    cin.getline(userInput,100);

    char *ptr;
    int i = 0;

    //parse user input
    ptr = strtok(userInput," ");

    //store tokens in an array of character strings
    while(ptr!=NULL)
    {
      args[i] = ptr;
      cout << ptr << endl;
      ptr = strtok(NULL, " ");
      i++;
      
    }
    /**
    * After reading user input, the steps are:
    * (1) fork a child process using fork()
    * (2) the child process will invoke execvp()
    * (3) parent will invoke wait() unless command included & */
    should_run = 0;
  }
  return 0;
}
