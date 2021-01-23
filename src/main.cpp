#include <iostream>
#include <string>
#include "cache/lrucache.h"

using namespace std;

int main(int argc, char const *argv[])
{
	LRUCache<int, string> cache(3);
	LRUCache<int, string> memory(15);

	cache.put(3,"3");
	cache.put(2,"2");
	cache.put(1,"1");
	cache.put(3,"-3");
	cache.put(4,"4");
	cache.put(5,"5");
	cache.put(6,"6");

	
	try{
		cout<<cache.get(3)<<endl;
		cout<<cache.get(2)<<endl;
		cout<<cache.get(1)<<endl;
	}
	catch(string str) {
		cout<<str<<endl;
	}
	return 0;
}