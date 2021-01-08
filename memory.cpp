#include <iostream>
#include <list>
#include "memory.h"

using namespace std;

/**
 * @brief      Memory constructor
 *
 * @param[in]  size  Size of memory
 */
Memory::Memory(int size) {
	this-> size = size;
}

/**
 * @brief      Inserts a page into the memory
 *
 * @param[in]  page  The page
 */
void Memory::insert(Page page) {
	int page_num = page.get_page_num();
	
	// If page is present in the memory
	if (mp.find(page_num) != mp.end())
	{
		// Remove the page from memory and create a new page 
		this->pages_queue.erase(mp[page_num]);	
	}

	// Insert at the beginning and update page pointer
	this->pages_queue.push_front(page);
	mp[page_num] = this->pages_queue.begin();
}

/**
 * @brief      Removes the page from the memory
 *
 * @return     { description_of_the_return_value }
 */
Page Memory::remove() {

	Page lru_page = this->pages_queue.back();
	this->mp.erase(lru_page.get_page_num());
	this->pages_queue.pop_back();
	
	return lru_page;
}

int Memory::is_full() {
	if (this->pages_queue.size() > this->size)
	{
		return 1;
	}
	return 0;
}

/**
 * @brief      Prints a queue.
 *
 * @param[in]  q     Queue of pages 
 */
void printQueue(list<Page> q)
{
	//printing content of queue 
	while (!q.empty()){
		q.front().print();
		q.pop_front();
	}
}

/**
 * @brief      Prints memory and its contents
 */
void Memory::print() {
	printQueue(this->pages_queue);
}

