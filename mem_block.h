#include "page.h"

/**
 * @brief      A typical block of memory, contains a page, pointer to next node and pointer to prev node
 */
struct MemNode
{
	MemNode* next, prev;
	Page* page;
};

/**
 * @brief      This class describes list of memory Blocks.
 */
class MemBlockList
{
	public:
		MemBlockList(int);
		~MemBlockList();

		// Insert a page in the memory. If page is already present in the list, move it to the head of the list
		void updateHead(Page* page);

		// Remove the least recently used page of the list
		Page pop_back();

	private:
		// Head and tail of the memory blocklist
		MemNode* head, tail;
		Page** page_mem_map;

};