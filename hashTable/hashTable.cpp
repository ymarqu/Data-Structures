#include "hashTable.h"

Ht_item* HT::create_item(string key, string value){

    Ht_item* item = new Ht_item;
    item->key = key;
    item->value = value;

    return item;

}
hashTable* HT::create_table(int size){

    hashTable* table = new hashTable;
    table->size = size;
    table->count = 0;
    table->items = new Ht_item*[table->size];

    for(int i = 0; i < table->size; i++){
        table->items[i] = NULL;
    }

    return table;

}
int HT::HashFunction(string value){
    unsigned long i = 0;
    for (int j = 0; j < value.length(); j++){
        cout << j << endl;
        i += value[j];
    }
    return i % CAPACITY;
}
