// https://practice.geeksforgeeks.org/problems/lru-cache/1
#include <bits/stdc++.h>

using namespace std;

class LRUCache {
 private:
  list<pair<int, int>> ll;
  unordered_map<int, list<pair<int, int>>::iterator> map;
  int cap;

 public:
  LRUCache(int cap) { this->cap = cap; }

  int GET(int key) {
    // no mapping exist means pair is not present
    if (map.find(key) == map.end()) return -1;

    int value = (*map[key]).second;

    // delete the key-value pair from the ll
    ll.erase(map[key]);

    // insert new pair to front of ll
    ll.push_front({key, value});

    // alter the mapping
    map[key] = ll.begin();

    return value;
  }

  void SET(int key, int value) {
    // pair not present
    if (map.find(key) == map.end()) {
      // cache cap is full, need to delete least used item
      if (map.size() == cap) {
        auto leastUsedKey = ll.back().first;
        auto leastUsedValue = ll.back().second;
        // delete the pair
        ll.erase(map[leastUsedKey]);
        // delete the mapping
        map.erase(leastUsedKey);
      }
    } else {
      ll.erase(map[key]);
    }

    // insert new pair to front of ll
    ll.push_front({key, value});
    // alter the mapping
    map[key] = ll.begin();
  }
};