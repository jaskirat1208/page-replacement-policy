#include "page.h"

/**
 * @brief      This class describes a disk.
 */
class Disk
{
	public:
		Disk(int);
		void update(Page page);
		void print();

	private:
		int size;
		Page* pages;	
};