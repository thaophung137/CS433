#include <stdio.h> 
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <sys/wait.h>
#include "Shell.h"

using namespace std;

void Shell::execCommandShell(char *args[])
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
      if(ampersand ==false)
      
        wait(NULL);
    }
}

void Shell::execCommandUser(char *args[]){
  
  string command(args[0]);
	int N;	

  // command is "!!" format, execute the most recent command
  if (command == "!!") {
	 

		// error: no recent command in the history
		if (history.empty()) {
			cout << "No commands in history." << endl;
			return;
		}

			N = history.size();
	  }

    //echo command
    cout << history[N - 1] << endl; 
}

void Shell::checkRedirection(char *args[]){
  for(int i=0; args[i] != NULL; i++){
    if(strcmp(args[i], "<") == 0){
      inputFlag = 1;
      if(args[i+1] == NULL)
        cout << "Invalid command";
      else{
        infile = i + 1;
      }
    }
    if(strcmp(args[i], ">") == 0){
      outputFlag = 1; 
       if(args[i+1] == NULL)
        cout << "Invalid command";
      else{
        outfile = i + 1;
      }
    }
  }
}
