#include <iostream>

#include "page.h"

using namespace std;

/**
 * @brief      Page constructor
 *
 * @param[in]  page_num  The page number
 * @param[in]  content   The content
 */
Page::Page(int page_num, int content) {
	this-> page_num = page_num; 
	this-> content = content;
}

/**
 * @brief      Prints a page and its contents
 */
void Page::print() {
	cout<<"Page no: "<<this->page_num<<endl;
	cout<<"Content: "<<this->content<<endl;
}

/**
 * @brief      Gets the page content.
 *
 * @return     The page content.
 */
int Page::get_page_content() {
	return content;
}

/**
 * @brief      Gets the page number.
 *
 * @return     The page number.
 */
int Page::get_page_num() {
	return page_num;
}