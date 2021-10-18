#include <stdio.h> 
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <sys/wait.h>
#include "Shell.h"

using namespace std;

//PURPOSE: Constructor for Shell class
Shell::Shell(){
  inputFlag = 0;
  outputFlag = 0;
  inFile = 0;
  outFile = 0;
  saveIn = 0;
  saveOut = 0;
  ampersand = false;
  should_run = 1;
}

//PURPOSE: parse user input into seperate tokens and store as array of character strings
void Shell::parser(char userInput[], char *args[]) 
{
    char *ptr;
    int i = 0;

    //parse user input
    ptr = strtok(userInput," ");
   
    //store tokens in an array of character strings
    while(ptr!=NULL)
    {
      args[i] = ptr;
      ptr = strtok(NULL, " ");
      i++;
      
    }
    //check if user input has &
    if (strcmp(args[i-1], "&") == 0) {
		    args[i-1] = NULL;
		    ampersand = true;
      }
    else {
	  	//terminate argument with null
		  args[i] = NULL;
		  ampersand = false;
	  }
  
}

//PURPOSE: run shell command and fork child process
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

//PURPOSE: run the user command either !! or exit
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
    char buffer[MAX_LINE];
    strcpy(buffer, history[N-1].c_str());
    history.push_back(buffer);
    parser(buffer,args);
    runShellCommand(args);
  }
  if(command == "exit") {
    should_run = 0;
  }
    
}

//PURPOSE:check if it is a valid user command(!! or exit) 
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

//PURPOSE: check for redirection in user input
void Shell::checkRedirection(char *args[]){
  for(int i=0; args[i] != NULL; i++){
    if(strcmp(args[i-2], "<") == 0){
      args[i-2] = NULL;
      inputFlag = 1;
      inFile = i + 1;
    }
    if(strcmp(args[i-2], ">") == 0){
      args[i-2] = NULL;
      outputFlag = 1; 
      outFile = i + 1;
    }
  }
}
