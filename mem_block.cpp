#include "mem_block.h"

/**
 * @brief      Constructor of memory block list
 */
MemBlock::MemBlock(int disk_size) {
	this->start = NULL;
	this->end = NULL;

	this->page_mem_map=(Page**)calloc(disk_size, sizeof(Page*));
}

/**
 * @brief      Updates the head of the memory. 
 * 
 * With each new page inserted into the memory, it checks whther the page exists or not.
 * If it exists, it will move the page to the front, while removing it from its current position.
 * Else, if will just create a new memory block at the head.
 *
 * @param      page  The page
 */
void update_head(Page* page) {
	// get the page number of the page to be inserted
	int page_num = page->get_page_num();

	// Case when the page exists in memory
	if (this->page_mem_map[page_num] != NULL)
	{
		// Shuffle the pointers such that the page becomes head
		MemNode* idx = this->page_mem_map[page_num];
		
	}

	// In
}