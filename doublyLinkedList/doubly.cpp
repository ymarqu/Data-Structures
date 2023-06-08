   #include <iostream>
   using namespace std;
   #include "doubly.h"

    //constructor function set head and tail to NULL and count = 0 because list empty
   doublyLinkedList::doublyLinkedList(){
    head = NULL;
    tail = NULL;
    count = 0;
   }

   //Insert new node at the front of list if list empty
   //create a new node and set tail and head equal to new node.
   void doublyLinkedList::insertAtFront(int elem){
    if(head == NULL){
       head = new DLLNode;
       head->prev = NULL;
       head->next = NULL;
       head->data = elem;
       tail = head;
   }else{
    head->prev = new DLLNode;
    head->prev->data = elem;
    head->prev->next = head;
    head = head->prev;
   }
    count++;
   }
   //insert new node at postion porvided by user. If position is out
   //of range then print error message to screen
    void doublyLinkedList::insertAtpos(int pos, int elem){
        if(isEmpty()){
            insertAtFront(elem);
        }
        else if(pos == count){
            insertAtTail(elem);
        }
        else if(pos > count){
            cout << "The position is out of range. Cannot add" << endl;
        }else{
            int holder = 0;
            DLLNode *temp = head;
            while(holder < pos){
                temp = temp->next;
                holder++;
            }
            temp->prev->next = new DLLNode();
            temp->prev->next->prev = temp->prev;
            temp->prev->next->next = temp;
            temp->prev = temp->prev->next;
            temp->prev->data = elem;
            count++;
        }
    }
    //insert new node to the tail of the list.
    //if list is empty create new node and set head and tail equal to new node
    void doublyLinkedList::insertAtTail(int elem){
    if(head == NULL){
       head = new DLLNode;
       head->prev = NULL;
       head->next = NULL;
       head->data = elem;
       tail = head;
    }else{
       tail->next = new DLLNode;
       tail->next->prev = tail;
       tail = tail->next;
       tail->data = elem;
    }
    count++;
   }
    //delete the node currently at head
    int doublyLinkedList::deleteFromHead(){
        if(isEmpty()){
            return -1;
        }
        int elem = head->data;
        if(head == tail){
            DLLNode *temp = head;
            head = NULL; tail = NULL;
            delete temp;
        }else{
            DLLNode *temp = head;
            head = head->next;
            temp->next = NULL;
            head->prev = NULL;
            delete temp;
        }
        count--;
        return elem;
    }
    //delete node that is currently at tail
    int doublyLinkedList::deleteFromTail(){
     if(isEmpty()){
        return -1;
     }
     int elem = tail ->data;
     if(head == tail){
            DLLNode *temp = head;
            head = NULL; tail = NULL;
            delete temp;
        }else{
            DLLNode *temp = tail;
            tail = tail->prev;
            temp->prev = NULL;
            tail->next = NULL;
            delete temp;
        }
        count--;
        return elem;
    }
    //delete node at the postion provide by the user. If position is out
    //of bounds error message is printed.
    int doublyLinkedList::deleteAtPos(int pos){
        int elem = -1;
        if(pos == 0){
            elem = deleteFromHead();
        }
        else if(pos == count){
            elem = deleteFromTail();
        }
        else if(pos > count){
            cout << "position provided is out of bound. please enter a number between 0 and "<< count << "."<< endl;
        }
        else{
        int holder = 0;
        DLLNode *temp = head;
        while(holder < pos){
            temp = temp->next;
            holder++;
        }
        elem = temp->data;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
        count--;
       }
        return elem;
    }
    //Search list for the element provided by the user
    //if element is found in list return position. If element
    // is not found return -1
    int doublyLinkedList::search(int elem){

        if(isEmpty()){
            cout << "List is empty cannot search." << endl;
            return -1;
        }
        int pos = 0;
        DLLNode *temp = head;
        while(temp != NULL){
            if(temp->data == elem){
                return pos;
            }
            temp = temp->next;
            pos++;
        }
        return -1;
    }
    //print the list starting at head ending with tail
    void doublyLinkedList::printList(){

        if(isEmpty()){
            cout << "List is empty. Cannot print." << endl;
        }else{
            DLLNode *temp = head;
            cout << "x<=>";
            while(temp != NULL){
                cout << "[";
                cout << temp->data;
                cout <<"]<=>";
                temp = temp->next;
            }
            cout << "x" << endl;
            temp = NULL;
            delete temp;
        }
    }
    //print the list starting at tail and end with head
    void doublyLinkedList::printListReverse(){
        if(isEmpty()){
            cout << "List is empty. Cannot print." << endl;
        }else{
            DLLNode *temp = tail;
            cout << "x<=>";
            while(temp != NULL){

                cout << "[";
                cout << temp->data;
                cout << "]=>";
                temp = temp->prev;
            }
            cout << "x" << endl;\
            temp = NULL;
            delete temp;
        }
    }

    //utility function used to check current size of list
    bool doublyLinkedList::isEmpty(){
        if(count == 0){
            return true;
        }
        return false;
    }
