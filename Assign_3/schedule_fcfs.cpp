#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "cpu.h"

// add a new task to the list of tasks
 void add(char *name, int priority, int burst) 
{
	// TODO: add your implementation here
	node *temp;
	temp = (node*)malloc(sizeof(node));

	temp->task->name = name;
	temp->task->priority = priority;
	temp->task->burst = burst;

	temp->next = NULL;
	//Need to insert at the end of node

}

/**
 *  * Run the FCFS scheduler
 *   */
void schedule() 
{
	// TODO: add your implementation here
}
