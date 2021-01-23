#include <unordered_map>
#include <list>

using namespace std;

#ifndef CACHE_LRU_H
#define CACHE_LRU_H 

template<class K, class V>	// Key value pairs
class LRUCache
{
	public:
		LRUCache(int, string, LRUCache<K,V>* next_cache=NULL);
		V get(K);
		void put(K, V);
		void print();
	
	private:
		int size;
		string cache_name;
		LRUCache<K, V>* next_cache;
		unordered_map<K, V> data;

		// Queue of all keys
		list<K> keys_queue;
		
		// Mapping from key to its position in the keys queue
		unordered_map<K, typename list<K>::iterator> hashmp;

		// Functions
		void move_to_front(K);
		void flush(K, V);
};

#include "lrucache.cpp"
#endif