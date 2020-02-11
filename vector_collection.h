//----------------------------------------------------------------------
// Author: Kevin Lunden
// Course: CPSC 223, Spring 2020
// Assign: 3
// File:   vector_collection.h
//
// Work with key/vector pairs and implements various abilities
//----------------------------------------------------------------------

#ifndef VECTOR_COLLECTION_H
#define VECTOR_COLLECTION_H

#include <vector>
#include <algorithm>            
#include "collection.h"

using namespace std;

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
void VectorCollection<K,V>::add(const K& a_key, const V& a_val)
{
 pair<K,V> p(a_key, a_val);
 kv_list.push_back(p);
}

template <typename K, typename V>
// remove a key-value pair from the collection
void VectorCollection <K,V>::remove(const K& a_key)
{
 int i = 0;
 for (std::pair<K,V> P : kv_list)
 {
  if (P.first == a_key)
   kv_list.erase(kv_list.begin() + i);
  i++;
 } 
}

template <typename K, typename V>
// find and return the value associated with the key
bool VectorCollection<K,V>::find(const K& search_key, V& the_val) const
{
 for (pair<K,V> P : kv_list)
 {
  if (P.first == search_key)
  {
   the_val = P.second;
   return true;
  }
 } 
 return false; 
}

template <typename K, typename V>
// find and return the values with keys >= to k1 and <= to k2 
void VectorCollection <K,V>::find(const K& k1, const K& k2, std::vector<V>& vals) const
{
 for (pair<K,V> P : kv_list)
 {
  if(P.first >= k1 && P.first <= k2)
   vals.push_back(P.second);
 }
}

template <typename K, typename V>
// return all of the keys in the collection
void VectorCollection <K,V>::keys(std::vector <K>& all_keys) const
{
 if(kv_list.size() != 0)
 {
  for(pair<K,V> P : kv_list)
   all_keys.push_back(P.first);
 }
}

template <typename K, typename V>
// return all of the keys in ascending (sorted) order
void VectorCollection <K,V>::sort(std::vector <K>& all_keys_sorted) const
{
 vector <pair<K,V>> copy = kv_list;
 std::sort(copy.begin(), copy.end());

 if(kv_list.size() != 0)
 {
  for(pair<K,V> P : copy)
   all_keys_sorted.push_back(P.first);
 }
}

template <typename K, typename V>
// return the number of keys in collection
int VectorCollection <K,V>::size() const
{
  return kv_list.size();
}

#endif
