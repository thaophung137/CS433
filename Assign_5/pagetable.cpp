#include <stdlib.h>

#include "pagetable.h"

// TODO: Add your implementation of PageTable

PageTable::PageTable(){
    totalReferences = 0;
    totalPageFaults = 0;
    totalReplacements = 0;
    timeElapsed = 0.00;
    frameNumber = 0;

} 
PageTable::~PageTable(){
  
}

void PageTable::display(){
  cout << "Total memory references: " << totalReferences << endl;
	cout << "Total page faults: " << totalPageFaults << endl;
	cout << "Total replacements: " << totalReplacements << endl;
  cout << "Total time elapsed: " << timeElapsed << endl;
}

void PageTable::random(PageEntry &page)
{
  int randNum = rand() % page_table.size();
	int entry = randNum;
  
	page_table[entry] = page;  
}

void PageTable::FIFO(PageEntry &page)
{
	int replace = lineCount;
	lineCount++;

	page_table[replace] = page; 

}

void PageTable::LRU(PageEntry &page){
  int replace;

  if(page_table[lineCount].valid == false){
    replace = lineCount;
    lineCount++;
  }
  else{
    int index = lineCount;
    int min = currLine; 

    for(int i = 0; i < page_table.size(); i++){
      if(page_table[i].last < min){
        index = i;
        min = page_table[i].last;
      }
      replace = index;
    }
    page_table[replace] = page;
  }
}

int PageTable::find(int lookFor)
{
  for(int i = 0; i < page_table.size(); i++)
  {
    if(page_table[i].value == lookFor)
    {
      return i;
    }
    return -1;
  }
}
