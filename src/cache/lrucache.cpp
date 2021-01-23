#include <unistd.h>
#include "lrucache.h"

/**
 * @brief      Constructs a new instance.of LRUCache
 *
 * @param[in]  size  Max no of elements contained in the cache
 * @param[in]  sleep Sleep time: a measure of latency
 */
template<class K, class V>
LRUCache<K, V>::LRUCache(int size, string name, LRUCache<K, V>* next_cache ) {
	this->size = size;
	this->next_cache = next_cache;
	this->cache_name = name;
}

/**
 * @brief      Gets the specified key.
 *
 * @param[in]  key   The key
 *
 * @tparam     K     Class of key
 * @tparam     V     Class of Value
 *
 * @return     Value object
 */
template<class K, class V>
V LRUCache<K, V>::get(K key) {
	cout<<"Looking for key "<<key<<" in cache "<<this->cache_name<<endl;
	if (this->data.find(key) == this->data.end())
	{
		if(this->next_cache == NULL)
			throw "Element not found"s;
		else {
			cout<<"Miss: Failed to find key "<<key<<" in cache "<<this->cache_name<<endl;

			// Get the value from the next cache
			V val = this->next_cache->get(key);
			
			// Put the value inside the cache
			this->put(key, val);
			return val;
		}
	}
	else {
		cout<<"Hit: Successfully got key "<<key<<" in cache "<<this->cache_name<<endl;

		this->move_to_front(key);
		return this->data[key];		
	}
}

/**
 * @brief      Updates the key value pair in the cache
 *
 * @param[in]  key   The key
 * @param[in]  val   The value
 *
 * @tparam     K     Class of key
 * @tparam     V     Class of Value
 */
template<class K, class V>
void LRUCache<K, V>::put(K key, V val) {
	cout<<"Looking for key "<<key<<" in cache "<<this->cache_name<<endl;
	this->move_to_front(key);
	while(this->keys_queue.size() > this->size )
	{
		K back_key = this->keys_queue.back();
		V back_val = this->data[back_key];

		// Remove the contents from the current cache
		this->keys_queue.pop_back();
		this->hashmp.erase(back_key);
		this->data.erase(back_key);

		// Update the key value pair in the next level cache
		this->flush(back_key, back_val);
	}
	this->data[key] = val;
}

/**
 * @brief      Moves the key element to the front of the linked list
 *
 * @param[in]  key   The key
 *
 * @tparam     K     Class of key
 * @tparam     V     Class of value
 */
template<class K, class V>
void LRUCache<K,V>::move_to_front(K key) {
	// Key already exists in the map
	if (this->hashmp.find(key) != this->hashmp.end())
	{
		// Remove the key from the list: cnstant time operation
		this->keys_queue.erase(this->hashmp[key]);
		// Erase the key from the map: constant time
		this->hashmp.erase(key);

	}

	// Make sure that there is not key present in the map at this step
	// Push the key in front of the linked list
	this->keys_queue.push_front(key);
	
	// Update the map
	this->hashmp[key] = this->keys_queue.begin();
}

/**
 * @brief      Used to flush the key-value pairs into the database
 *
 * @param[in]  key   The key
 * @param[in]  val   The value
 *
 * @tparam     K     Class of Key 
 * @tparam     V     Class of values
 */
template<class K, class V>
void LRUCache<K, V>::flush(K key, V val) {
	if (this->next_cache == NULL)
	{
		cout<<"The following have been flushed out of the system"<<endl;
		cout<<"Key: "<<key<<endl;
		cout<<"Val: "<<val<<endl;
		return;
	}
	this->next_cache->put(key, val);
	
	return;
}

/**
 * @brief      Prints the contents of cache
 *
 * @tparam     K     { description }
 * @tparam     V     { description }
 */
template<class K, class V>
void LRUCache<K, V>::print() {
	cout<<"List of keys:"<<endl;
	for (auto it = this->keys_queue.begin(); it != this->keys_queue.end(); ++it)
	{
		cout<<*it<<" -> "<<this->data[*it]<<endl;
	}

}