/********************************************************************************************
CS 433 Programming assignment 1
Author: Thao Phung and Sophia Nguyen
Course: CS 433 (Operating Systems)
*******************************************************************************************/

#include <stdio.h> 
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <fcntl.h>
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
    char userInput[MAX_LINE];
    
    cout << "osh>"; 
    fflush(stdout);

    //get user input
    cin.getline(userInput,MAX_LINE);
    shell.parser(userInput,args);

    if(shell.checkValidCommand(args) == true)
    {
      shell.runUserCommand(args);
    }
    else 
    {
      shell.runShellCommand(args);
    }
   
    shell.checkRedirection(args);

    if(shell.inputFlag == 1){
      shell.inFile = open(args[shell.inputFlag], O_RDONLY);

      if(shell.inFile < 0){
        cout << "Failed to open file";
        return 1;
      }
      else{
        shell.saveIn = dup(0);
        dup2(shell.inFile, 0);
        close(shell.inFile);
      }
    }

    if(shell.outputFlag == 1){
      shell.outFile = open(args[shell.outputFlag],  O_WRONLY | O_CREAT | O_TRUNC| S_IRUSR | S_IWUSR);
      if(shell.outFile < 0){
        cout << "Failed to open file";
        return 1;
      }  
      else{
        shell.saveOut = dup(1);
        dup2(shell.outFile, 1);
        close(shell.outFile);
      }
    }
  
  }
  return 0;
}
