//----------------------------------------------------------------------
// Author: Kevin Lunden
// Course: CPSC 223, Spring 2020
// Assign: 3
// File:   vector_collection.h
//
// TODO: Description here
//----------------------------------------------------------------------

#ifndef VECTOR_COLLECTION_H
#define VECTOR_COLLECTION_H

#include <vector>
#include <algorithm>            
#include "collection.h"


template<typename K, typename V>
class VectorCollection : public Collection<K,V>
{
public:

  // add a new key-value pair into the collection 
  void add(const K& a_key, const V& a_val);

  // remove a key-value pair from the collectiona
  void remove(const K& a_key);

  // find and return the value associated with the key
  bool find(const K& search_key, V& the_val) const;

  // find and return the values with keys >= to k1 and <= to k2 
  void find(const K& k1, const K& k2, std::vector<V>& vals) const;
  
  // return all of the keys in the collection 
  void keys(std::vector<K>& all_keys) const;

  // return all of the keys in ascending (sorted) order
  void sort(std::vector<K>& all_keys_sorted) const;

  // return the number of key-value pairs in the collection
  int size() const;

private:
  std::vector<std::pair<K,V>> kv_list;
};


// TODO: Implement member functions here ...

template <typename K, typename V>
// add a new key-value pair into the collection
void VectorCollection<K,V>::add(const K& key, const V& val)
{
 std::pair<K,V> p(key, val);
 kv_list.push_back(p);
}

void remove(const K& a_key)
{
 
}

int size() const
{
 
}

#endif
