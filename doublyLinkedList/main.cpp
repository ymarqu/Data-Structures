#include "doubly.h"
#include <iostream>
using namespace std;

void searchHelper(int pos){

if(pos == -1){
    cout << "element was not found in list." << endl;
}else{
    cout << "element was found in list position " << pos << endl;
}

}


int main(){

    doublyLinkedList L1;

    L1.insertAtFront(10);
    L1.insertAtFront(8);
    L1.insertAtFront(6);
    L1.insertAtFront(4);
    L1.insertAtFront(2);
    L1.insertAtFront(1);

    L1.printList();
    L1.printListReverse();

    L1.insertAtTail(12);
    L1.insertAtTail(14);
    L1.insertAtTail(15);

    L1.printList();
    L1.printListReverse();

    cout << L1.deleteFromHead() << " removed from head." << endl;
    cout << L1.deleteFromHead() << " removed from head." << endl;
    cout << L1.deleteFromHead() << " removed from head." << endl;

   L1.printList();
   L1.printListReverse();

   L1.insertAtFront(10);

   L1.printList();
   L1.printListReverse();

   cout << L1.deleteFromTail() << " removed from tail." << endl;
   cout << L1.deleteFromTail() << " removed from tail." << endl;
   L1.printList();
   L1.printListReverse();

  L1.insertAtpos(2, 33);
  L1.insertAtpos(5, 90);

  L1.printList();
  L1.printListReverse();


  cout << L1.deleteAtPos(2) << " was deleted." << endl;
  cout << L1.deleteAtPos(4) << " was deleted." << endl;

  L1.printList();
  L1.printListReverse();


 int position = L1.search(10);

 searchHelper(position);

 position = L1.search(45);

 searchHelper(position);

 position = L1.search(8);

 searchHelper(position);


    return 0;


}
