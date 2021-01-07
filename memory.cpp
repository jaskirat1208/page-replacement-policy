#include <queue>
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
	this->pages_queue.push(page);
}

/**
 * @brief      Removes the page from the memory
 *
 * @return     { description_of_the_return_value }
 */
Page Memory::remove() {
	Page lru_page = this->pages_queue.front();
	this->pages_queue.pop();
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
void printQueue(queue<Page> q)
{
	//printing content of queue 
	while (!q.empty()){
		q.front().print();
		q.pop();
	}
}

/**
 * @brief      Prints memory and its contents
 */
void Memory::print() {
	printQueue(this->pages_queue);
}

