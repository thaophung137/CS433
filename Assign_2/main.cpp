#include <stdio.h> 
#include <unistd.h>
#include <iostream>
#include <cstring>

using namespace std;

#define MAX_LINE 80 /* The maximum length command */

int main(void)
{
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
