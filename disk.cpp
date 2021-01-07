#include <stdlib.h>

#include "disk.h"
#include "page.h"

/**
 * @brief      A disk is an array of pages
 *
 * @param[in]  size  The size of the disk
 */
Disk::Disk(int size) {
	this->size = size;
	this->pages = (Page*)calloc(size, sizeof(Page));
}

/**
 * @brief      Updates the given page.
 *
 * @param[in]  page  The page
 */
void Disk::update(Page page) {
	int page_num = page.get_page_num();
	this->pages[page_num] = page;
}

/**
 * @brief      Prints the disk and contents
 */
void Disk::print() {
	for (int i = 0; i < size; ++i)
	{
		this->pages[i].print();
	}
}