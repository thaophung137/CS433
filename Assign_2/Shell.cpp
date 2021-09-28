#include <stdio.h> 
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <sys/wait.h>
#include "Shell.h"

using namespace std;

void Shell::execCommandShell(char *args[]){
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
      //ADD LOGIC TO CHECK IF AMPERSAND(FALSE -> wait)
      wait(NULL);
    }
}

void Shell::execCommandUser(char *args[]){
  

}
