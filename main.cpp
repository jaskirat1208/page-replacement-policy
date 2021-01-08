/*
Problem: Implementation of LRU policy as a program:
You have n pages, where 0 < n < 10^5 and a cache that can keep only m pages. Each page has 2 components: (page num, key)
Give an efficient solution to implement a caching mechanism 
Page: structure(num = 1, secret_key = 3)

FS: file system, an array of NPages Pages.
	FS will have a memory of size NPagesInMem. All the pages that are updated will go through the memory first, then they would go to disk
Page: entity of file system
*/
#include <iostream>

#include "page.h"
#include "memory.h"
#include "fs.h"

using namespace std;

int NPages = 10;
int NQueries = 10;
int NPagesInMem = 2;

int main(int argc, char const *argv[])
{
	// Initialize File system 
	FS fs = FS(NPages, NPagesInMem);
	// Memory mem = Memory(NPagesInMem);

	for (int i = 0; i < NQueries; ++i)
	{
		// Create page
		Page page = Page(i % NPages, i*i - 1);
		// Update page in file system. Performs an in-memory update, 
		// when the page goes out of memory due to more recent updates on other pages, the page will be updated on the disk.  
		fs.insert(page);
		// Print memory
		fs.print();
	}

	return 0;
}