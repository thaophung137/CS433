#include <stdio.h> 
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <sys/wait.h>
#include "Shell.h"

using namespace std;

Shell::Shell(){
  inputFlag = 0;
  outputFlag = 0;
  inFile = 0;
  outFile = 0;
  saveIn = 0;
  saveOut = 0;
}

void Shell::runShellCommand(char *args[])
{
   /**
    * After reading user input, the steps are:
    * (1) fork a child process using fork()
    * (2) the child process will invoke execvp()
    * (3) parent will invoke wait() unless command included & */

    pid_t pid;

    pid = fork(); //fork a child process

    //error occured
    if(pid < 0) {
      cout << "Error: Fork failed." << endl;
      
    }
    //child process
    else if(pid == 0) {
      execvp(args[0], args);
      cout << "Error: Command not found." << endl;
    }
    //parent process
    else{
      if(ampersand == false)
      
        wait(NULL);
    }
}

void Shell::runUserCommand(char *args[]){
  
  string command = args[0];
	int N;	
  
  // command is "!!" format, execute the most recent command
  if (command == "!!") {
	 

		// error: no recent command in the history
		if (history.empty()) {
			cout << "No commands in history." << endl;
			return;
		}

			N = history.size();
	  

    //echo command
    cout << history[N - 1] << endl; 

    //place command into history buffer as next command
    history.push_back(history[N - 1]);
    runShellCommand(args);
  }
  if(command == "exit") {
    should_run = 0;
    return;
  }
    
}

bool Shell::checkValidCommand(char *args[])
{
  string command = args[0];

  //it is a valid user command
  if(command == "!!" || command == "exit")
  {
    return true;
  }

  //it is not a valid user command - it is shell command
  else
  {
    return false;
  }
}

void Shell::checkRedirection(char *args[]){
  for(int i=0; args[i] != NULL; i++){
    if(strcmp(args[i], "<") == 0){
      inputFlag = 1;
      if(args[i+1] == NULL)
        cout << "Invalid command";
      else{
        inFile = i + 1;
      }
    }
    if(strcmp(args[i], ">") == 0){
      outputFlag = 1; 
       if(args[i+1] == NULL)
        cout << "Invalid command";
      else{
        outFile = i + 1;
      }
    }
  }
}
