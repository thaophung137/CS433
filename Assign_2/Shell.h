#pragma once
#include <vector>

using namespace std;

#define MAX_LINE 80 /* The maximum length command */

class Shell {
  public:
    void execCommandShell(char *args[]);
    void execCommandUser(char *args[]);
    bool ampersand = false;

  private:
    vector<string> history;
};
