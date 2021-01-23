#include <iostream>
#include <string>
#include "cache/lrucache.h"

using namespace std;

int main(int argc, char const *argv[])
{
	LRUCache<int, string> l3_cache(7, "L3 cache");
	LRUCache<int, string> l2_cache(5, "L2 cache", &l3_cache);
	LRUCache<int, string> l1_cache(3, "L1 cache", &l2_cache);

	l1_cache.put(3,"3");
	l1_cache.put(2,"-2");
	l1_cache.put(1,"1");
	l1_cache.put(3,"-3");
	l1_cache.put(4,"4");
	l1_cache.put(5,"5");
	l1_cache.put(6,"6");
	l1_cache.put(6,"6");
	l1_cache.put(7,"6");
	l1_cache.put(8,"6");
	l1_cache.put(9,"6");
	l1_cache.put(10,"6");
	l1_cache.put(11,"6");

	
	try{
		l1_cache.print();
		l2_cache.print();
		cout<<l1_cache.get(3)<<endl;
		cout<<l1_cache.get(2)<<endl;
		l1_cache.print();
		l2_cache.print();
		// cout<<l1_cache.get(1)<<endl;
	}
	catch(string str) {
		cout<<str<<endl;
	}
	return 0;
}