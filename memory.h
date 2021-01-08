#include <list>
#include <unordered_map>

#include "page.h"
using namespace std;


#ifndef MEMORY_H
#define MEMORY_H

/**
 * @brief      Memory, a queue of pages. Page replacement algorithms implemented.
 */
class Memory
{
	public:
		// Memory constructor
		Memory(int); 
		// Inserts a page into the memory
		void insert(Page);
		// Remove a page from the memory
		Page remove();

		void print();
		int is_full();

	private:
		// Size of the memory
		int size;
		// Queue of Pages
		list<Page> pages_queue;

		// Hash Map for page to memory location
		unordered_map<int, list<Page>::iterator> mp;
};

#endif