/********************************************************************************************
CS 433 Programming assignment 1
Author: Thao Phung and Sophia Nguyen
Course: CS 433 (Operating Systems)
*******************************************************************************************/

#include <stdio.h> 
#include <unistd.h>
#include <iostream>
#include <cstring>
#include "Shell.h"

using namespace std;


int main(void)
{
  cout << "CS 433 Programming Assignment 2" << endl;
  cout << "Author: Thao Phung and Sophia Nguyen" << endl;
  cout << "Date: 10/10/2021" << endl;
  cout << "Course: CS 433 (Operating Systems)" << endl;
  cout << "Description : Program to serve as a shell interface that accepts user commands and executes each command in a seperate process." << endl;
  cout << "=================================" << endl;

  char *args[MAX_LINE/2 + 1]; /* command line arguments */
  Shell shell;
  while (shell.should_run) 
  { 
    char userInput[100];
    
    cout << "osh>"; 
    fflush(stdout);

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
    if (strcmp(args[i-1], "&") == 0) {
		    args[i-1] = NULL;
		    shell.ampersand = true;
      }
    else {
	  	// terminated argument list with null
		  args[i] = NULL;
		  shell.ampersand = false;
	  }

    if(shell.checkValidCommand(args) == true)
    {
      shell.runUserCommand(args);
    }
    else 
    {
      shell.runShellCommand(args);
    }
   
    //should_run = 0;
  }
  return 0;
}
