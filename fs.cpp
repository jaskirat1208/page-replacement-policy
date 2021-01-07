#include <iostream>

#include "fs.h"
#include "memory.h"
#include "page.h"

using namespace std;

FS::FS(int disk_size, int mem_size) {
	this->mem = new Memory(mem_size);
	this->disk = new Disk(disk_size);
}

/**
 * @brief      Insert page into file system
 *
 * @param[in]  page  The page
 */
void FS::insert(Page page) {
	// insert the page in the memory	
	this->mem->insert(page);

	// in case memory is full, remove the last page and update it in the disk
	if (this->mem->is_full())
	{
		// Remove the last page and update it in the disk
		Page lru_page = this->mem->remove();

		// Disk update code goes here
		this->disk->update(lru_page);
	}

}

/**
 * @brief      Prints memory of filesystem
 */
void FS::print() {
	cout<<"Printing Memory Contents:"<<endl;
	this->mem->print();

	cout<<"Printing disk:"<<endl;
	this->disk->print();
}