#include "memory.h"
#include "disk.h"

#ifndef FS_H
#define FS_H

/**
 * @brief      File system: has 2 components, memory and disk
 */
class FS
{
	public:
		FS(int, int);

		void insert(Page page);
		void print();

	private:
		Memory* mem;
		Disk* disk;
};

#endif