#pragma once
#include <vector>

using namespace std;

#define MAX_LINE 80 /* The maximum length command */

class Shell {
  public:
    void runShellCommand(char *args[]);
    void runUserCommand(char *args[]);
    void checkRedirection(char *args[]);
    bool checkValidCommand(char *args[]);
    bool ampersand = false;
    int should_run = 1; //flag to determine when to exit program

    int inputFlag, outputFlag;
    int inFile, outFile;
    int saveIn, saveOut;

  private:
    vector<string> history;
    
};
