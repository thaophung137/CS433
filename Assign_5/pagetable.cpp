#include <stdlib.h>

#include "pagetable.h"

// TODO: Add your implementation of PageTable

PageTable::PageTable(){
    totalReferences = 0;
    totalPageFaults = 0;
    totalReplacements = 0;
    timeElapsed = 0.00;

} 
PageTable::~PageTable(){
  
}

void PageTable::display(){
  cout << "Total memory references: " << totalReferences << endl;
	cout << "Total page faults: " << totalPageFaults << endl;
	cout << "Total replacements: " << totalReplacements << endl;
  cout << "Total time elapsed: " << timeElapsed << endl;
}

void PageTable::insert(int size)
{
  for (int i = 0; i < size; i++) {
		PageEntry page;
		page.dirty = false;
		page.valid = false;

		page_table.push_back(page);
	}
}

void PageTable::random(PageEntry &page)
{
  int randNum = rand() % page_table.size();
	int entry = randNum;
	page_table[entry] = page;  
}
