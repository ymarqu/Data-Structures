#include "hashTable.h"
#include <iostream>
#include <string>
using namespace std;


int main(){

    HT HashMap;

    Ht_item* firstItem = HashMap.create_item("H", "Hey");
    cout << firstItem ->key << endl;
    cout << firstItem->value << endl;
    cout << firstItem << endl;

    hashTable* my_table = HashMap.create_table(10);

    cout << my_table << endl;

    return 0;


}
