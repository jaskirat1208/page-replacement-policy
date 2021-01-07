#ifndef PAGE_H
#define PAGE_H

/**
 * @brief      This class describes a page in the disk. In this project, a page object will be loaded into memory which will then update it in the disk when memory is full
 */
class Page
{
	public:
		Page(int page_num, int content);

		int get_page_content();
		int get_page_num();
		void print();

	private:
		int page_num, content;
};

#endif