// Remember to add comments to your code

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include "pagetable.h"

using namespace std;

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
	int line;

	while(fin >> line)
  {

  }


	// Test 2: Read and simulate the large list of logical addresses from the input file "large_refs.txt"
	cout <<"\n================================Test 2==================================================\n";

  PageTable table;
	fstream fin2("large_refs.txt");
	int line2;

	while(fin2 >> line2)
  {
		int value = stoi(line2);
		int last = value % 10;
		bool dirtyBit;

		// find value in page_table
		int index = table.find(value); 

		// exists in the page_table
		if (index >= 0) 
    {
			table.page_table[index].dirty = dirtyBit;
			table.page_table[index].last = table.lineNum;
		}
    else //needs new table entry
    {
      PageEntry temp(value, true, table.lineNum);
			table.totalPageFaults++;
    }
	}

	cout << "****************Simulate FIFO replacement****************************" << endl;
	// TODO: Add your code to calculate number of page faults using FIFO replacement algorithm	
	// TODO: print the statistics and run-time
  table.FIFO(temp);
  table.display();

	cout << "****************Simulate Random replacement****************************" << endl;
	// TODO: Add your code to calculate number of page faults using Random replacement algorithm
	// TODO: print the statistics and run-time
  table.random(temp);
  table.display();

	cout << "****************Simulate LRU replacement****************************" << endl;
	// TODO: Add your code to calculate number of page faults using LRU replacement algorithm
	// TODO: print the statistics and run-time
  table.LRU(temp);
  table.display();

}