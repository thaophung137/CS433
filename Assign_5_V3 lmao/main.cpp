// Remember to add comments to your code

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include "pagetable.h"
#include <sys/time.h>

using namespace std;
#define Size 100

void runFIFO(int ps, int ms)
{
  cout << "****************Simulate FIFO replacement****************************" << endl;
  PageTable tableFIFO;
  fstream fin2("large_refs.txt");
  string line2;

  tableFIFO.pageSize = ps; 
  tableFIFO.memSize = ms;

  // make page table;
  int tableSizeF = tableFIFO.memSize / tableFIFO.pageSize;

  tableFIFO.insert(tableSizeF);

  struct timeval tim; 
  gettimeofday(&tim, NULL);  
  double startTime =tim.tv_sec+(tim.tv_usec/1000000.0);

  //initialize random seed
  srand(time(NULL));

  while(fin2 >> line2)
  {
    int value = stoi(line2);

    tableFIFO.totalReferences++;

    // find value in page_table
    int indexF = tableFIFO.find(value); 

    if (indexF >= 0)
    {
      tableFIFO.page_table[indexF].last = tableFIFO.lineNum;
      tableFIFO.page_table[indexF].dirty = false;
    }

    else //needs new table entry
    {
      PageEntry tempF(value, true, true, tableFIFO.lineNum);
      tableFIFO.totalPageFaults++;
    }
  }
    gettimeofday(&tim, NULL);  
    double endTime=tim.tv_sec+(tim.tv_usec/1000000.0);  
    tableFIFO.timeElapsed = endTime-startTime; 

    tableFIFO.display();
}

void runRandom(int ps, int ms)
{
  cout << "****************Simulate Random replacement****************************" << endl;
  PageTable tableRandom;
  fstream fin2("large_refs.txt");
  string line2;

  tableRandom.pageSize = ps; 
  tableRandom.memSize = ms;

  // make page table;
  int tableSizeR = tableRandom.memSize / tableRandom.pageSize;

  tableRandom.insert(tableSizeR);

  struct timeval tim; 
  gettimeofday(&tim, NULL);  
  double startTime =tim.tv_sec+(tim.tv_usec/1000000.0);

  //initialize random seed
  srand(time(NULL));

  while(fin2 >> line2)
  {
    int value = stoi(line2);

    tableRandom.totalReferences++;

    // find value in page_table
    int indexR = tableRandom.find(value); 

    if (indexR >= 0)
    {
      tableRandom.page_table[indexR].last = tableRandom.lineNum;
      tableRandom.page_table[indexR].dirty = false;
    }

    else //needs new table entry
    {
      PageEntry tempF(value, true, true, tableRandom.lineNum);
      tableRandom.totalPageFaults++;
    }
  }
    gettimeofday(&tim, NULL);  
    double endTime=tim.tv_sec+(tim.tv_usec/1000000.0);  
    tableRandom.timeElapsed = endTime-startTime; 

    tableRandom.display();
}

void runLRU(int ps, int ms)
{
  cout << "****************Simulate LRU replacement****************************" << endl;
  PageTable tableLRU;
  fstream fin2("large_refs.txt");
  string line2;

  tableLRU.pageSize = ps; 
  tableLRU.memSize = ms;

  // make page table;
  int tableSizeF = tableLRU.memSize / tableLRU.pageSize;

  tableLRU.insert(tableSizeF);

  struct timeval tim; 
  gettimeofday(&tim, NULL);  
  double startTime =tim.tv_sec+(tim.tv_usec/1000000.0);

  //initialize random seed
  srand(time(NULL));

  while(fin2 >> line2)
  {
    int value = stoi(line2);

    tableLRU.totalReferences++;

    // find value in page_table
    int indexL = tableLRU.find(value); 

    if (indexL >= 0)
    {
      tableLRU.page_table[indexL].last = tableLRU.lineNum;
      tableLRU.page_table[indexL].dirty = false;
    }

    else //needs new table entry
    {
      PageEntry tempF(value, true, true, tableLRU.lineNum);
      tableLRU.totalPageFaults++;
    }
  }
    gettimeofday(&tim, NULL);  
    double endTime=tim.tv_sec+(tim.tv_usec/1000000.0);  
    tableLRU.timeElapsed = endTime-startTime; 

    tableLRU.display();
}

// Check if an integer is power of 2
bool isPowerOfTwo(unsigned int x)
{
	/* First x in the below expression is for the case when x is 0 */
	return x && (!(x & (x - 1)));
}

int main(int argc, char* argv[]) {
	//Print basic information about the program
	cout << "=================================================================" << endl;
	cout << "CS 433 Programming assignment 5" << endl;
	cout << "Author: Thao Phung & Sophia Nguyen" << endl;
	cout << "Date: 12/2/2021" << endl;
	cout << "Course: CS433 (Operating Systems)" << endl;
	cout << "Description : Program to simulate different page replacement algorithms" << endl;
	cout << "=================================================================\n" << endl;

	if (argc < 3) {
		// user does not enter enough parameters
		cout << "You have entered too few parameters to run the program.  You must enter" << endl
			<< "two command-line arguments:" << endl
			<< " - page size (in bytes): between 256 and 8192, inclusive" << endl
			<< " - physical memory size (in megabytes): between 4 and 64, inclusive" << endl;
		exit(1);
	}
	
	// Page size and Physical memory size 
	// Their values should be read from command-line arguments, and always a power of 2
	unsigned int page_size = atoi(argv[1]);
	if(!isPowerOfTwo(page_size))
	{
		cout << "You have entered an invalid parameter for page size (bytes)" << endl
			<< "  (must be an power of 2 between 256 and 8192, inclusive)." << endl;
		return 1;
	}
	unsigned int phys_mem_size = atoi(argv[2]) << 20; // convert from MB to bytes
	if(!isPowerOfTwo(phys_mem_size))
	{
		cout << "You have entered an invalid parameter for physical memory size (MB)" << endl
			<< "  (must be an even integer between 4 and 64, inclusive)." << endl;
		return 1;
	}

	// calculate number of pages and frames;
	int logic_mem_bits = 27;		// 27-bit logical memory (128 MB logical memory assumed by the assignment)
	int phys_mem_bits = std::log2(phys_mem_size);		// Num of bits for physical memory addresses, calculated from physical memory size, e.g. 24 bits for 16 MB memory
	int page_offset_bits = std::log2(page_size);				// Num of bits for page offset, calculated from page size, e.g. 12 bits for 4096 byte page
	// Number of pages in logical memory = 2^(logic_mem_bits - page_bit)
	int num_pages = 1 << (logic_mem_bits - page_offset_bits);
	// Number of free frames in physical memory = 2^(phys_mem_bits - page_offset_bits)
	int num_frames = 1 << (phys_mem_bits - page_offset_bits);
	
	cout << "Page size = " << page_size << " bytes" << endl;
	cout << "Physical Memory size = " << phys_mem_size << " bytes" << endl;
	cout << "Number of pages = " << num_pages << endl; 
	cout << "Number of physical frames = " << num_frames << endl;
	// Test 1: Read and simulate the small list of logical addresses from the input file "small_refs.txt"
	cout <<"\n================================Test 1==================================================\n";
	// TODO: Add your code here for test 1 that prints out logical page #, frame # and whether page fault for each logical address

	fstream fin("small_refs.txt");
	string line;
	PageTable part1;

	int count = 0;
	int fNum = 0; 
	part1.insert(Size); 

	while(fin >> line)
	{
		int val = stoi(line);
		int pageNum = val/page_size;
		int idx = part1.find(pageNum);

		count++;
		if(idx >= 0){
			part1.page_table[count].value = pageNum; 
			part1.page_table[count].fault = false; 
			fNum = part1.page_table[idx].frame_num;
		}
		else{
			part1.page_table[count].value = pageNum; 
			part1.page_table[count].frame_num = fNum; 
			part1.totalPageFaults++;
		}
		 cout << "Logical address: " << val << ",        page number: " 
		 << pageNum << ",        frame number: " << fNum << ",        is page fault? " << part1.page_table[count].fault 
		 << endl;
		fNum++;
	}
	cout << "Total Page Fault: " << part1.totalPageFaults << endl;
	cout << "Total Replacements: " << part1.totalReplacements << endl;

	// Test 2: Read and simulate the large list of logical addresses from the input file "large_refs.txt"
	cout <<"\n================================Test 2==================================================\n";
  runFIFO(page_size,phys_mem_size);

  runRandom(page_size,phys_mem_size);

  runLRU(page_size,phys_mem_size);
	}
