#pragma once
#include <vector>

using namespace std;

#define MAX_LINE 80 /* The maximum length command */

class Shell {
  public:
    Shell();//constructor for Shell class
    void parser(char userInput[], char *args[]);//parse user input
    void runShellCommand(char *args[]);//execute the shell command
    void runUserCommand(char *args[]); //execute the user command
    void checkRedirection(char *args[]); //check for redirection in the command
    bool checkValidCommand(char *args[]); //check if it is a valid user command 
    int should_run; //flag to determine when to exit program
    int inputFlag, outputFlag; 
    int inFile, outFile;
    int saveIn, saveOut;

  private:
    vector<string> history; //used to store history of commands
    bool ampersand; //check if there is ampersand 
};
