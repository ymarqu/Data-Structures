   #include <iostream>
   using namespace std;
   #include "doubly.h"


   doublyLinkedList::doublyLinkedList(){
    head = NULL;
    tail = NULL;
    count = 0;
   }
   void doublyLinkedList::insertAtFront(int elem){
    if(head == NULL){
       head = new DLLNode;
       head->prev = NULL;
       head->next = NULL;
       head->data = elem;
       tail = head;
   }else{
    head->prev = new DLLNode;
    head->prev->next = head;
    head = head->prev;
   }
    count++;
   }
    void doublyLinkedList::insertAtpos(int pos, int elem){

    }
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
    }
    count++;
   }

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
    int doublyLinkedList::deleteAtPos(int pos){

    }
    int doublyLinkedList::search(int elem){

    }
    void doublyLinkedList::printList(){

        if(isEmpty()){
            cout << "List is empty. Cannot print." << endl;
        }else{
            DLLNode *temp = head;
            while(temp != NULL){
                cout << "[";
                cout << temp->data;
                cout <<"]->";
                temp = temp->next;
            }
            cout << "x" << endl;
            temp = NULL;
            delete temp;
        }
    }
    void doublyLinkedList::printListReverse(){
        if(isEmpty()){
            cout << "List is empty. Cannot print." << endl;
        }else{
            DLLNode *temp = tail;
            while(temp != NULL){
                cout << "[";
                cout << temp->data;
                cout << "]->";
                temp = temp->prev;
            }
            cout << "x" << endl;\
            temp = NULL;
            delete temp;
        }
    }
    bool isEmpty(){
        if(count == 0){
            return true;
        }
        return false;
    }
