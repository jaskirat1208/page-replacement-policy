#ifndef CACHE_BASE_H
#define CACHE_BASE_H

template<typename K, typename V>	// Key value pairs
class BaseCache
{
	public:
		BaseCache(int size);
		virtual V get(K key) = 0;
		virtual void put(K key, V value) = 0;
		~BaseCache();

	// protected:
	// 	map<K, V> data;		
	
};

#endif
