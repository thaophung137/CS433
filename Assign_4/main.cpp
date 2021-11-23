#include <stdlib.h> /* required for rand() */
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h> 
#include <time.h> 
#include <unistd.h>
#include<iostream>

#include "buffer.h"

using namespace std;

pthread_mutex_t lock; //mutex lock
sem_t  empty, full;

void *producer(void *param) 
{ 
  buffer buff;
  buffer_item item;
  while (true) {
    /* sleep for a random period of time */ 
    //sleep(...);
    sleep(rand()%10);
    /* generate a random number */
    item = rand()%100;

    pthread_mutex_lock(&lock);

    if(buff.insert_item(item))
    {
      cout << "report error condition" << endl;
    }
    else
    {
      cout << "producer produced " << item << endl; 
    }
    //end of critical section

    pthread_mutex_unlock(&lock);
  }
}

void *consumer(void *param) 
{
  buffer buff;
  buffer_item item;

  pthread_mutex_lock(&lock);
  while (true) 
  {
    /* sleep for a random period of time */ 
    sleep(rand()%10);
    //sleep(...);
    if(buff.remove_item(&item))
    {
      cout << "report error condition" << endl;
    }
    else
    {
      cout << "consumer consumed "<< item << endl;
    }
    //end of critical section

    pthread_mutex_unlock(&lock);
  }
}


int main(int argc, char *argv[]) 
{
  if(argc < 4)
  {
    cout << "You have entered too few parameters to run the program.  You must enter three command-line arguments: " << endl;
    cout << "- amount of time to run the program(in seconds, positve integer that is not zero)" << endl;
    cout << "- number of producer threads to create(positive integer or zero)" << endl;
    cout << "- number of consumer threads to create(positive integer or zero)" << endl;
    exit(1);
  }

  if(argc > 4)
  {
    cout << "You have entered too many parameters to run the program.  You must enter only three command line arguments: " << endl;
    cout << "- amount of time to run the program(in seconds, positve integer that is not zero)" << endl;
    cout << "- number of producer threads to create(positive integer or zero)" << endl;
    cout << "- number of consumer threads to create(positive integer or zero)" << endl;
    exit(1);
  
  }

  /* 1. Get command line arguments argv[1],argv[2],argv[3] */ 
  int sleeptime = atoi(argv[1]);		
	int pthread = atoi(argv[2]);		
	int cthread = atoi(argv[3]);		

  /* 2. Initialize buffer */
  pthread_mutex_init(&lock, NULL);
  pthread_t producerThreads[pthread];
  pthread_t consumerThreads[cthread];
  
  /* 3. Create producer thread(s) */
    for(int i = 0; i < pthread; i++){
      pthread_create(&producerThreads[i], producer, NULL);
    }
  /* 4. Create consumer thread(s) */
    for(int j = 0; j < pthread; j++){
      pthread_create(&consumerThreads[i], consumer, NULL);
    }
  /* 5. Sleep */
  sleep(sleeptime);

  /* 6. Exit */
  exit(0);
}
