#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <string>
using namespace std;

#define CAPACITY 50000 // Size of the HashTable.
struct Ht_item
{
    string key;
    string value;
};

struct hashTable{
    Ht_item** items;
    int size;
    int count;
};

class HT{
    public:
    Ht_item* create_item(string key, string value);
    hashTable* create_table(int size);
    int HashFunction(string value);
};

#endif
