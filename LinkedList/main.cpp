#include "Linkedlist.h"
#include <iostream>

using namespace std;

void searchResult(int elem, int position){

    if(position == -1){
        cout << elem << " not found in list." << endl;
    }else{
      cout << elem << " was found in position " << position << "." << endl;
    }

}


int main(){


    Linkedlist L1;

    L1.printList();
    L1.insertAtFront(5);
    L1.insertAtFront(4);
    L1.insertAtFront(3);
    L1.insertAtFront(2);
    L1.insertAtFront(1);

    L1.printList();

    L1.insertAtEnd(6);
    L1.insertAtEnd(7);
    L1.printList();

    L1.removeFromHead();
    L1.removeFromTail();
    L1.printList();

    int result = L1.search(2);

    searchResult(2, result);

    result = L1.search(9);
    searchResult(9, result);

    L1.printList();


    L1.insertAt(1, 0);
    L1.printList();
    L1.insertAt(0, 0);
    L1.printList();

    L1.insertAt(7, 7);
    L1.printList();
    L1.insertAt(8, 8);
    L1.printList();

    L1.insertAt(10, 2);
    L1.printList();
    L1.insertAt(20, 3);
    L1.printList();


    L1.removeAt(2);
    L1.removeAt(2);

    L1.printList();
    L1.insertAtEnd(100);
    L1.removeAt(0);

    L1.printList();

    L1.removeFromTail();

    L1.printList();

    return 0;
}
