#pragma once
#include <vector>
#include<iostream>


using namespace std;
// Remember to add comments to your code

// A page table entry
class PageEntry
{
public:
	// Physical frame number for a given page
	int frame_num;
	// valid bit represents whether a page is in the physical memory
	bool valid;
	// dirty bit represents whether a page is changed
	bool dirty;
  int value;
  int last;
	//Default Constructor
	PageEntry(){
		frame_num = 0;
		valid = false;
		dirty = false; 
	}
  
  PageEntry(int valueP, bool validP, bool dirtyP int lastP) {
		value = valueP;
		valid = validV;
    dirty = dirtyP;
		last = lastV;
	}
};


/**
 * \brief A page table is like an array of page entries. The size of the page table should equal to the number of pages in logical memory
 */
class PageTable
{
  private:
	// TODO: Add your implementation of the page table here
	int totalReferences;
	
	int totalReplacements;
	int pageNumber;
	int frameNumber; 
  double timeElapsed;
  int lineCount;
  

  public: 
  vector<PageEntry> page_table; 
  int lineNum;
  int totalPageFaults;

  
	PageTable();
	~PageTable(); 

	void display();
	void insert(int size);
  int find(int);

	void random(PageEntry &page);
	void FIFO(PageEntry &page);
	void LRU(PageEntry &page);
};
